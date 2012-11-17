// ----------------------------------------------------------------------------------------------
// Copyright (c) Mårten Rånge.
// ----------------------------------------------------------------------------------------------
// This source code is subject to terms and conditions of the Microsoft Public License. A 
// copy of the license can be found in the License.html file at the root of this distribution. 
// If you cannot locate the  Microsoft Public License, please send an email to 
// dlr@microsoft.com. By using this source code in any fashion, you are agreeing to be bound 
//  by the terms of the Microsoft Public License.
// ----------------------------------------------------------------------------------------------
// You must not remove this notice, or any other, from this software.
// ----------------------------------------------------------------------------------------------
#include "stdafx.h"
#include "session.hpp"
// -----------------------------------------------------------------------------
#include "resource.h"
// -----------------------------------------------------------------------------
#include <chrono>
#include <condition_variable>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>
// -----------------------------------------------------------------------------
#include <strsafe.h>
// -----------------------------------------------------------------------------
#include <D2d1.h>
#include <D3D10_1.h>
#include <DWrite.h>
#include <DXGI.h>
#include <WinCodec.h>
// -----------------------------------------------------------------------------
#include "cptr.hpp"
#include "opt.hpp"
#include "utility.hpp"
#include "../InteractiveGraphics.Lib/Generated_MessageSerializerCpp.hpp"
#include "../InteractiveGraphics.Lib/Generated_MessageReceiver.hpp"
// -----------------------------------------------------------------------------
#pragma comment (lib, "D2d1.lib"    )
#pragma comment (lib, "D3D10_1.lib"   )
#pragma comment (lib, "DWrite.lib"  )
// -----------------------------------------------------------------------------
extern HMODULE Shared__Module;
// -----------------------------------------------------------------------------

#undef max
#undef min

#define WM_ACCEPT_MESSAGE       WM_USER + 1
#define WM_NEXT_FRAME           WM_USER + 2



// When this is called the implementor is guaranteed that 2 bytes are available.
// For other limits it's up to the implementor making sure the buffer is not overrun 
bool message_unpacker__unpack (
        wchar_t const *             name
    ,   unsigned __int8 const *     bytes
    ,   __int32                     size   
    ,   __int32 &                   current   
    ,   std::wstring & value
    )
{
    static_assert (sizeof (wchar_t) == 2, "sizeof (wchar_t) must be 2");
    UNREFERENCED_PARAMETER (name);
    unsigned __int16 length = 0;
    auto pbytes = reinterpret_cast<__int8*>(&length); 
    pbytes[0] = bytes[current++];
    pbytes[1] = bytes[current++];

    value.clear ();

    if (length < 1)
    {
        return true;
    }

    if (size - current < sizeof (wchar_t) * length)
    {
        return false;
    }

    value.reserve (length);

    for (unsigned __int16 iter = 0; iter < length; ++iter)
    {
        wchar_t cvalue = 0;
        auto pbytes = reinterpret_cast<__int8*>(&cvalue); 
        pbytes[0] = bytes[current++];
        pbytes[1] = bytes[current++];

        value.push_back (cvalue);
    }

    return true;
}
// When this is called the implementor is guaranteed that 4 bytes are available.
// For other limits it's up to the implementor making sure the buffer is not overrun 
bool message_unpacker__unpack (
        wchar_t const *             name
    ,   unsigned __int8 const *     bytes
    ,   __int32                     size   
    ,   __int32 &                   current   
    ,   std::vector<unsigned __int8> & value
    )
{
    static_assert (sizeof (unsigned __int8) == 1, "sizeof (unsigned __int8) must be 1");
    UNREFERENCED_PARAMETER (name);
    __int32 length = 0;
    auto pbytes = reinterpret_cast<__int8*>(&length); 
    pbytes[0] = bytes[current++];
    pbytes[1] = bytes[current++];
    pbytes[2] = bytes[current++];
    pbytes[3] = bytes[current++];

    value.clear ();

    if (length < 1)
    {
        return true;
    }

    if (size - current < sizeof (unsigned __int8) * length)
    {
        return false;
    }

    value.reserve (length);

    for (auto iter = 0; iter < length; ++iter)
    {
        value.push_back (bytes[current++]);
    }

    return true;
}

namespace
{
    SIZE size_of (RECT const & rect)
    {
        SIZE size;
        size.cx     = std::abs (rect.right - rect.left);
        size.cy     = std::abs (rect.bottom - rect.top);
        return size;
    }

    D2D1_POINT_2F center_of (D2D1_RECT_F const & rect)
    {
        D2D1_POINT_2F point;
        point.x = (rect.left + rect.right) / 2;
        point.y = (rect.top + rect.bottom) / 2;
        return point;
    }

    D2D1_POINT_2F min_corner (D2D1_RECT_F const & rect)
    {
        D2D1_POINT_2F point;
        point.x = std::min (rect.left, rect.right);
        point.y = std::min (rect.top, rect.bottom);
        return point;
    }

    D2D1_POINT_2F max_corner (D2D1_RECT_F const & rect)
    {
        D2D1_POINT_2F point;
        point.x = std::max (rect.left, rect.right);
        point.y = std::max (rect.top, rect.bottom);
        return point;
    }

    D2D1_SIZE_F size_of (D2D1_RECT_F const & rect)
    {
        D2D1_SIZE_F size;
        size.width  = std::abs (rect.right - rect.left);
        size.height = std::abs (rect.bottom - rect.top);
        return size;
    }

    D2D1_SIZE_F to_size (D2D1_POINT_2F const & point)
    {
        D2D1_SIZE_F size;
        size.width  = point.x;
        size.height = point.y;
        return size;
    }

    D2D1_POINT_2F to_point (D2D1_SIZE_F const & size)
    {
        D2D1_POINT_2F point;
        point.x     = size.width;
        point.y     = size.height;
        return point;
    }

    D2D1_RECT_F construct_from_xywh (float x, float y, float width, float height)
    {
        auto left   = x;
        auto right  = x + width;

        auto top    = y;
        auto bottom = y + height;

        D2D1_RECT_F rect;
        rect.left   = std::min (left, right);
        rect.right  = std::max (left, right);
        rect.top    = std::min (top, bottom);
        rect.bottom = std::max (top, bottom);

        return rect;
    }




    typedef std::vector<unsigned __int8> bytes;

    bytes load_resource_as_bytes (int resource_id)
    {
        bytes result;
        if (!Shared__Module)
        {
            return result;
        }

        auto resource_location = FindResourceEx (
                Shared__Module
            ,   L"PNG"
            ,   MAKEINTRESOURCE (resource_id)
            ,   MAKELANGID (LANG_NEUTRAL, SUBLANG_NEUTRAL)
            );

        if (!resource_location)
        {
            return result;
        }

        auto resource_handle = LoadResource (
                Shared__Module
            ,   resource_location
            );

        if (!resource_handle)
        {
            return result;
        }

        auto size_of_resource = SizeofResource (
                Shared__Module
            ,   resource_location
            );

        if (size_of_resource == 0)
        {
            return result;
        }

        auto memory = reinterpret_cast<unsigned __int8*> (LockResource (
            resource_handle
            ));

        if (!memory)
        {
            return result;
        }

        result.reserve (size_of_resource);

        for (auto iter = 0U; iter < size_of_resource; ++iter)
        {
            result.push_back (memory[iter]);
        }

        return result;
    }

    template<typename TInterface>
    HRESULT create_com_object (
            CLSID const & clsid
        ,   cptr<TInterface> & ptr
        )
    {
        return CoCreateInstance (
                clsid
            ,   nullptr
            ,   CLSCTX_INPROC_SERVER
            ,   ptr.get_iid ()
            ,   ptr.get_outptr ()
            );
    }


    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    typedef cptr<ID2D1Factory>                  ID2D1FactoryPtr                 ; 
    typedef cptr<ID2D1HwndRenderTarget>         ID2D1HwndRenderTargetPtr        ;
    typedef cptr<ID2D1RenderTarget>             ID2D1RenderTargetPtr            ;
    typedef cptr<ID2D1SolidColorBrush>          ID2D1SolidColorBrushPtr         ;
    typedef cptr<ID2D1GradientStopCollection>   ID2D1GradientStopCollectionPtr  ;
    typedef cptr<ID2D1LinearGradientBrush>      ID2D1LinearGradientBrushPtr     ;
    typedef cptr<ID2D1RadialGradientBrush>      ID2D1RadialGradientBrushPtr     ;
    typedef cptr<ID2D1Bitmap>                   ID2D1BitmapPtr                  ;
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    typedef cptr<IWICImagingFactory>            IWICImagingFactoryPtr           ;
    typedef cptr<IWICStream>                    IWICStreamPtr                   ;
    typedef cptr<IWICBitmapDecoder>             IWICBitmapDecoderPtr            ;
    typedef cptr<IWICBitmapFrameDecode>         IWICBitmapFrameDecodePtr        ;
    typedef cptr<IWICFormatConverter>           IWICFormatConverterPtr          ;
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    typedef cptr<IDWriteFactory>                IDWriteFactoryPtr               ;
    typedef cptr<IDWriteTextFormat>             IDWriteTextFormatPtr            ;
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    typedef cptr<ID3D10Device1>                 ID3D10Device1Ptr                ;
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    typedef cptr<IDXGISwapChain>                IDXGISwapChainPtr               ;
    typedef cptr<IDXGISurface>                  IDXGISurfacePtr                 ;
    // ------------------------------------------------------------------------


    struct ResourceContext : noncopyable
    {
        ResourceContext (
                ID2D1RenderTarget   & drt
            ,   IWICImagingFactory  & wif
            ,   IDWriteFactory      & dwf
            )
            :   render_target   (drt)
            ,   imaging_factory (wif)
            ,   dwrite_factory  (dwf)
        {
        }

        ID2D1RenderTarget   & render_target     ;
        IWICImagingFactory  & imaging_factory   ;
        IDWriteFactory      & dwrite_factory    ;
    };

    struct brush_definition
    {
        brush_definition ()
            :   brush                   (nullptr)
            ,   relative_coordinates    (false)
        {
        }

        brush_definition (
                ID2D1Brush *    brush
            ,   bool            relative_coordinates
            )
            :   brush                   (brush)
            ,   relative_coordinates    (relative_coordinates)
        {
        }

        brush_definition (brush_definition && bd)
            :   brush                   (move_ptr (bd.brush))
            ,   relative_coordinates    (bd.relative_coordinates)
        {
        }


        ID2D1Brush *    brush               ;
        bool            relative_coordinates;
    };

    struct Resource : noncopyable
    {
        typedef std::tr1::shared_ptr<Resource> ptr;

        virtual ~Resource () throw () {}

        virtual void create (ResourceContext & resource_context)
        {
            UNREFERENCED_PARAMETER (resource_context);
        }

        virtual void release (ResourceContext & resource_context) throw ()
        {
            UNREFERENCED_PARAMETER (resource_context);
        }

        virtual brush_definition get_brush () const throw ()
        {
            return brush_definition ();
        }

        virtual ID2D1Bitmap* get_bitmap () const throw ()
        {
            return nullptr;
        }

        virtual IDWriteTextFormat * get_text_format () const throw () 
        {
            return nullptr;
        }

        virtual void add_gradient_stop (
                D2D1::ColorF color
            ,   float offset
            )
        {
            UNREFERENCED_PARAMETER (color);
            UNREFERENCED_PARAMETER (offset);
        }

        virtual void clear_gradient_stops (
            )
        {
        }

        Message::ptr Message;
    };

    typedef std::map<std::wstring, Resource::ptr> Resources;

    template<typename TMessage>
    struct ResourceEx : Resource
    {
        TMessage * get_message () const throw ()
        {
            return dynamic_cast<TMessage*> (Message.get ());
        }
    };
    int parse_hexnumber (wchar_t ch)
    {
        switch (ch)
        {
        case '0':
            return 0x0;
        case '1':
            return 0x1;
        case '2':
            return 0x2;
        case '3':
            return 0x3;
        case '4':
            return 0x4;
        case '5':
            return 0x5;
        case '6':
            return 0x6;
        case '7':
            return 0x7;
        case '8':
            return 0x8;
        case '9':
            return 0x9;
        case 'A':
        case 'a':
            return 0xa;
        case 'B':
        case 'b':
            return 0xb;
        case 'C':
        case 'c':
            return 0xc;
        case 'D':
        case 'd':
            return 0xd;
        case 'E':
        case 'e':
            return 0xe;
        case 'F':
        case 'f':
            return 0xf;
        default:
            return 0;
        }
    }

    D2D1_GAMMA parse_gamma (std::wstring const & color)
    {
        if (color == L"2.2")
        {
            return D2D1_GAMMA_2_2;
        }
        else if (color == L"1.0")
        {
            return D2D1_GAMMA_1_0;
        }
        else
        {
            return D2D1_GAMMA_2_2;
        }
    }

    D2D1_EXTEND_MODE parse_extend_mode (std::wstring const & extend_mode)
    {
        if (extend_mode == L"CLAMP")
        {
            return D2D1_EXTEND_MODE_CLAMP;
        }
        else if (extend_mode == L"WRAP")
        {
            return D2D1_EXTEND_MODE_WRAP;
        }
        else if (extend_mode == L"MIRROR")
        {
            return D2D1_EXTEND_MODE_MIRROR;
        }
        else
        {
            return D2D1_EXTEND_MODE_CLAMP;
        }
    }

    D2D1::ColorF parse_color (std::wstring const & color) throw ()
    {
        float r = 1;
        float g = 0;
        float b = 0;
        float a = 1;      

        if (color.empty () || color[0] != L'#')
        {
            return D2D1::ColorF (D2D1::ColorF::Red);
        }

        switch (color.length ())
        {
        case 4:
            r = parse_hexnumber (color[1]) / 15.0f;
            g = parse_hexnumber (color[2]) / 15.0f;
            b = parse_hexnumber (color[3]) / 15.0f;
            break;
        case 5:
            a = parse_hexnumber (color[1]) / 15.0f;
            r = parse_hexnumber (color[2]) / 15.0f;
            g = parse_hexnumber (color[3]) / 15.0f;
            b = parse_hexnumber (color[4]) / 15.0f;
            break;
        case 7:
            r = (parse_hexnumber (color[1]) * 16 + parse_hexnumber (color[2])) / 255.0f;
            g = (parse_hexnumber (color[3]) * 16 + parse_hexnumber (color[4])) / 255.0f;
            b = (parse_hexnumber (color[5]) * 16 + parse_hexnumber (color[6])) / 255.0f;
            break;
        case 9:
            a = (parse_hexnumber (color[1]) * 16 + parse_hexnumber (color[2])) / 255.0f;
            r = (parse_hexnumber (color[3]) * 16 + parse_hexnumber (color[4])) / 255.0f;
            g = (parse_hexnumber (color[5]) * 16 + parse_hexnumber (color[6])) / 255.0f;
            b = (parse_hexnumber (color[7]) * 16 + parse_hexnumber (color[8])) / 255.0f;
            break;
        }
        return D2D1::ColorF (r,g,b,a);
    }

    void log_hr_failure (
            wchar_t const * file
        ,   int line_no
        ,   wchar_t const * function
        ,   HRESULT hr
        )
    {
        if (SUCCEEDED (hr))
        {
            return;
        }

        if (IsDebuggerPresent  ())
        {
            DebugBreak ();
        }

        const int size = 255;
        wchar_t output[size + 1];

        if (SUCCEEDED (StringCchPrintf (
                output
            ,   size
            ,   L"%s (%d): %s: FAILURE: 0x%X"
            ,   file
            ,   line_no
            ,   function
            ,   hr
            )))
        {
            OutputDebugString (output);
        }

    }
#define LOG_HR_FAILURE(hr)    \
    log_hr_failure (__FILEW__, __LINE__, __FUNCTIONW__, hr)

    bool load_bitmap_from_bytes (
            ResourceContext & resource_context
        ,   bytes & bytes
        ,   int use_frame
        ,   ID2D1BitmapPtr & bitmap
        )
    {
        if (bytes.size () < 1)
        {
            return false;
        }

        IWICStreamPtr stream;
        auto hr__create_stream = resource_context.imaging_factory.CreateStream (
            stream.get_outptr ()
            );

        LOG_HR_FAILURE (hr__create_stream);
        if (FAILED (hr__create_stream))
        {
            return false;
        }

        auto hr__initialize_from_memory = stream->InitializeFromMemory (
                &bytes.front ()
            ,   static_cast<DWORD> (bytes.size ())
            );

        LOG_HR_FAILURE (hr__initialize_from_memory);
        if (FAILED (hr__initialize_from_memory))
        {
            return false;
        }

        IWICBitmapDecoderPtr decoder;
        auto hr__create_decoder_from_stream = resource_context.imaging_factory.CreateDecoderFromStream (
                stream.get_ptr ()
            ,   nullptr
            ,   WICDecodeMetadataCacheOnLoad
            ,   decoder.get_outptr ()
            );

        LOG_HR_FAILURE (hr__create_decoder_from_stream);
        if (FAILED (hr__create_decoder_from_stream))
        {
            return false;
        }

        UINT frame_count = 0;
        auto hr__get_framecount = decoder->GetFrameCount (&frame_count);

        LOG_HR_FAILURE (hr__get_framecount);
        if (FAILED (hr__get_framecount) && frame_count < 1)
        {
            return false;
        }

        auto clamped_use_frame = clamp<int> (use_frame, 0, frame_count - 1);

        IWICBitmapFrameDecodePtr frame;
        auto hr__get_frame = decoder->GetFrame (clamped_use_frame, frame.get_outptr ());

        LOG_HR_FAILURE (hr__get_frame);
        if (FAILED (hr__get_frame))
        {
            return false;
        }

        IWICFormatConverterPtr converter;
        auto hr__create_format_converter = resource_context.imaging_factory.CreateFormatConverter (
                converter.get_outptr ()
            );

        LOG_HR_FAILURE (hr__create_format_converter);
        if (FAILED (hr__create_format_converter))
        {
            return false;
        }

        auto hr__initialize = converter->Initialize (
                frame.get_ptr ()
            ,   GUID_WICPixelFormat32bppPBGRA
            ,   WICBitmapDitherTypeNone
            ,   nullptr
            ,   0
            ,   WICBitmapPaletteTypeMedianCut
            );

        LOG_HR_FAILURE (hr__initialize);
        if (FAILED (hr__initialize))
        {
            return false;
        }

        auto hr__create_bitmap_from_wic_bitmap = resource_context.render_target.CreateBitmapFromWicBitmap (
                converter.get_ptr ()
            ,   nullptr
            ,   bitmap.get_outptr ()
            );

        LOG_HR_FAILURE (hr__create_bitmap_from_wic_bitmap);
        if (FAILED (hr__create_bitmap_from_wic_bitmap))
        {
            return false;
        }

        return true;
    }

    struct Resource__Fallback : ResourceEx<void>
    {
        ID2D1SolidColorBrushPtr Default_Brush;
        IDWriteTextFormatPtr    Default_TextFormat;
        ID2D1BitmapPtr          Default_Bitmap;

        virtual void create (ResourceContext & resource_context) override
        {
            if (!Default_Brush)
            {
                auto hr__create_solid_color_brush = resource_context.render_target.CreateSolidColorBrush (
                        D2D1::ColorF (D2D1::ColorF::White)
                    ,   Default_Brush.get_outptr ()
                    );
                LOG_HR_FAILURE (hr__create_solid_color_brush);
            }

            if (!Default_TextFormat)
            {
                auto hr__create_text_format = resource_context.dwrite_factory.CreateTextFormat (
                        L"Courier New"
                    ,   nullptr
                    ,   DWRITE_FONT_WEIGHT_NORMAL
                    ,   DWRITE_FONT_STYLE_NORMAL
                    ,   DWRITE_FONT_STRETCH_NORMAL
                    ,   20
                    ,   L"en-us"
                    ,   Default_TextFormat.get_outptr ()
                    );

                LOG_HR_FAILURE (hr__create_text_format);
            }

            if (!Default_Bitmap)
            {
                auto bytes = load_resource_as_bytes (IDB_DEFAULT_BITMAP);

                load_bitmap_from_bytes (
                        resource_context
                    ,   bytes
                    ,   0
                    ,   Default_Bitmap
                    );
            }
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            Default_Bitmap.reset  ();
            Default_TextFormat.reset ();
            Default_Brush.reset ();
        }
    };

    struct Resource__SolidBrush : ResourceEx<Message__New_SolidBrush>
    {
        ID2D1SolidColorBrushPtr SolidColorBrush;

        virtual brush_definition get_brush () const throw () override 
        {
            return brush_definition (SolidColorBrush.get_ptr (), false);
        }

        virtual void create (ResourceContext & resource_context) override
        {
            auto message = get_message ();
            if (!SolidColorBrush && message)
            {
                auto hr__create_solid_color_brush = resource_context.render_target.CreateSolidColorBrush (
                        parse_color (message->Color)
                    ,   SolidColorBrush.get_outptr ()
                    );
                LOG_HR_FAILURE (hr__create_solid_color_brush);
            }
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            SolidColorBrush.reset (); 
        }
    };

    struct Resource__LinearGradientBrush : ResourceEx<Message__New_LinearGradientBrush>
    {
        ID2D1LinearGradientBrushPtr LinearGradientBrush;

        std::vector<D2D1_GRADIENT_STOP> GradientStops;

        virtual brush_definition get_brush () const throw () override 
        {
            auto message = get_message ();
            if (message)
            {
                return brush_definition (LinearGradientBrush.get_ptr (), message->RelativeCoordinates);
            }
            else
            {
                return brush_definition (LinearGradientBrush.get_ptr (), false);
            }
        }

        virtual void add_gradient_stop (
                D2D1::ColorF color
            ,   float offset
            ) override
        {
            GradientStops.push_back (D2D1::GradientStop (offset, color));
            LinearGradientBrush.reset ();
        }

        virtual void clear_gradient_stops (
            ) override
        {
            GradientStops.clear ();
            LinearGradientBrush.reset ();
        }

        virtual void create (ResourceContext & resource_context) override
        {
            auto message = get_message ();
            if (!LinearGradientBrush && message && GradientStops.size () > 0)
            {                
                ID2D1GradientStopCollectionPtr gradient_stops;
                auto hr__create_gradient_stops = resource_context.render_target.CreateGradientStopCollection (
                        &GradientStops.front ()
                    ,   static_cast<UINT32> (GradientStops.size ())
                    ,   parse_gamma (message->Gamma)
                    ,   parse_extend_mode (message->ExtendMode)
                    ,   gradient_stops.get_outptr ()
                    );

                LOG_HR_FAILURE (hr__create_gradient_stops);
                if (FAILED (hr__create_gradient_stops))
                {
                    return;
                }

                auto hr__create_linear_gradient_brush = resource_context.render_target.CreateLinearGradientBrush (
                        D2D1::LinearGradientBrushProperties (
                            D2D1::Point2F (message->StartX, message->StartY)
                        ,   D2D1::Point2F (message->EndX, message->EndY)
                        )
                    ,   D2D1::BrushProperties ()
                    ,   gradient_stops.get_ptr ()
                    ,   LinearGradientBrush.get_outptr ()
                    );
                LOG_HR_FAILURE (hr__create_linear_gradient_brush);
            }
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            LinearGradientBrush.reset (); 
        }
    };

    struct Resource__RadialGradientBrush : ResourceEx<Message__New_RadialGradientBrush>
    {
        ID2D1RadialGradientBrushPtr RadialGradientBrush;

        std::vector<D2D1_GRADIENT_STOP> GradientStops;

        virtual brush_definition get_brush () const throw () override 
        {
            auto message = get_message ();
            if (message)
            {
                return brush_definition (RadialGradientBrush.get_ptr (), message->RelativeCoordinates);
            }
            else
            {
                return brush_definition (RadialGradientBrush.get_ptr (), false);
            }
        }

        virtual void add_gradient_stop (
                D2D1::ColorF color
            ,   float offset
            ) override
        {
            GradientStops.push_back (D2D1::GradientStop (offset, color));
            RadialGradientBrush.reset ();
        }

        virtual void clear_gradient_stops (
            ) override
        {
            GradientStops.clear ();
            RadialGradientBrush.reset ();
        }

        virtual void create (ResourceContext & resource_context) override
        {
            auto message = get_message ();
            if (!RadialGradientBrush && message && GradientStops.size () > 0)
            {                
                ID2D1GradientStopCollectionPtr gradient_stops;
                auto hr__create_gradient_stops = resource_context.render_target.CreateGradientStopCollection (
                        &GradientStops.front ()
                    ,   static_cast<UINT32> (GradientStops.size ())
                    ,   D2D1_GAMMA_2_2
                    ,   D2D1_EXTEND_MODE_CLAMP
                    ,   gradient_stops.get_outptr ()
                    );

                LOG_HR_FAILURE (hr__create_gradient_stops);
                if (FAILED (hr__create_gradient_stops))
                {
                    return;
                }

                auto hr__create_linear_gradient_brush = resource_context.render_target.CreateRadialGradientBrush (
                        D2D1::RadialGradientBrushProperties (
                            D2D1::Point2F (message->CenterX, message->CenterY)
                        ,   D2D1::Point2F (message->OffsetX, message->OffsetY)
                        ,   message->RadiusX
                        ,   message->RadiusY
                        )
                    ,   D2D1::BrushProperties ()
                    ,   gradient_stops.get_ptr ()
                    ,   RadialGradientBrush.get_outptr ()
                    );
                LOG_HR_FAILURE (hr__create_linear_gradient_brush);
            }
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            RadialGradientBrush.reset (); 
        }
    };

    struct Resource__Bitmap : ResourceEx<Message__New_BitmapResourceFromBytes>
    {
        ID2D1BitmapPtr Bitmap;

        virtual ID2D1Bitmap* get_bitmap () const throw ()
        {
            return Bitmap.get_ptr ();
        }

        virtual void create (ResourceContext & resource_context) override
        {
            if (Bitmap)
            {
                return;
            }

            auto message = get_message ();
            if (!message)
            {
                return;
            }

            load_bitmap_from_bytes (
                    resource_context
                ,   message->Bytes
                ,   message->UseFrame
                ,   Bitmap
                );
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            Bitmap.reset ();
        }
    };

    struct Resource__Font : ResourceEx<Message__New_FontResource>
    {
        IDWriteTextFormatPtr TextFormat;

        virtual IDWriteTextFormat * get_text_format () const throw () override 
        {
            return TextFormat.get_ptr ();
        }

        virtual void create (ResourceContext & resource_context) override
        {
            auto message = get_message ();
            if (!TextFormat && message)
            {
                auto hr__create_text_format = resource_context.dwrite_factory.CreateTextFormat (
                        message->FontFamily.c_str ()
                    ,   nullptr
                    ,   DWRITE_FONT_WEIGHT_NORMAL
                    ,   DWRITE_FONT_STYLE_NORMAL
                    ,   DWRITE_FONT_STRETCH_NORMAL
                    ,   message->FontSize
                    ,   L"en-us"
                    ,   TextFormat.get_outptr ()
                    );

                LOG_HR_FAILURE (hr__create_text_format);
            }
        }

        virtual void release (ResourceContext & resource_context) throw () override
        {
            UNREFERENCED_PARAMETER (resource_context);
            TextFormat.reset ();
        }
    };

    struct RenderContext : noncopyable
    {
        RenderContext (
                Resource__Fallback & fallback_rs
            ,   Resources & rs
            ,   ID2D1RenderTarget & rt
            )
            :   render_target           (rt)
            ,   m__fallback_resources   (fallback_rs)
            ,   m__resources            (rs)
        {
        }

        ID2D1RenderTarget & render_target;

        Resource* get_resource (std::wstring const & name) const throw ()
        {
            auto find = m__resources.find (name);
            auto result = find != m__resources.end () ? find->second.get () : nullptr;
            return result;
        }

        brush_definition get_brush (std::wstring const & name) const throw ()
        {
            auto resource = get_resource (name);
            auto result = resource ? resource->get_brush () : brush_definition ();
            if (!result.brush)
            {
                result.brush = m__fallback_resources.Default_Brush.get_ptr ();
            }
            return result;
        }

        ID2D1Brush* get_transformed_brush (
                std::wstring const & name
            ,   D2D1_RECT_F const & rect
            ,   float opacity
            ) const throw ()
        {
            auto brush_definition   = get_brush (name);
            auto brush              = brush_definition.brush;
            auto relative_coord     = brush_definition.relative_coordinates;
            if (brush)
            {
                if (relative_coord)
                {
                    auto translation    = D2D1::Matrix3x2F::Translation (to_size (min_corner (rect)));
                    auto scale          = D2D1::Matrix3x2F::Scale (size_of (rect));

                    auto complete       = scale * translation;
                    brush->SetTransform (complete);
                }
                else
                {
                    brush->SetTransform (D2D1::Matrix3x2F::Identity ());
                }

                brush->SetOpacity (opacity);

                return brush;
            }
            else
            {
                return brush;
            }
        }

        ID2D1Bitmap* get_bitmap (std::wstring const & name) const throw ()
        {
            auto resource = get_resource (name);
            auto result = resource ? resource->get_bitmap () : nullptr;
            if (!result)
            {
                result = m__fallback_resources.Default_Bitmap.get_ptr ();
            }
            return result;
        }

        IDWriteTextFormat* get_text_format (std::wstring const & name) const throw ()
        {
            auto resource = get_resource (name);
            auto result = resource ? resource->get_text_format () : nullptr;
            if (!result)
            {
                result = m__fallback_resources.Default_TextFormat.get_ptr ();
            }
            return result;
        }

    private:
        Resource__Fallback  & m__fallback_resources ;
        Resources           & m__resources          ;
    };

    struct object_state
    {
        D2D1_RECT_F rect;
        float       opacity;

        object_state () throw ()
            :   rect    (D2D1::RectF ())
            ,   opacity (0)
        {
        }

        object_state (D2D1_RECT_F const r, float o) throw ()
            :   rect    (r)
            ,   opacity (o)
        {
        }

        object_state (object_state && s) throw ();
    };

    template<typename TMessage>
    object_state do_get_object_state (
            TMessage const * message
        )
    {
        if (message)
        {
            auto rect = construct_from_xywh (
                    message->X
                ,   message->Y
                ,   message->Width
                ,   message->Height
                );
            return object_state (rect, message->Opacity);
        }
        else
        {
            return object_state ();
        }
    }

    template<typename TMessage>
    object_state do_get_object_state (
            TMessage const * message
        ,   float default_width
        ,   float default_height
        )
    {
        if (message)
        {
            auto rect = construct_from_xywh (
                    message->X
                ,   message->Y
                ,   message->Width.get_value (default_width)
                ,   message->Height.get_value (default_height)
                );
            return object_state (rect, message->Opacity);
        }
        else
        {
            return object_state ();
        }
    }

    template<typename TMessage>
    void do_set_object_state (
            TMessage * message
        ,   object_state const & os
        )
    {
        if (message)
        {
            auto mc         = min_corner (os.rect)  ;
            auto sz         = size_of (os.rect)     ;
            message->X      = mc.x                  ;
            message->Y      = mc.y                  ;
            message->Width  = sz.width              ;
            message->Height = sz.height             ;
            message->Opacity= os.opacity            ;
        }
    }

    struct Renderable : noncopyable
    {
        typedef std::tr1::shared_ptr<Renderable> ptr;

        virtual ~Renderable () throw () {}

        virtual object_state get_object_state () const throw ()
        {
            return object_state ();
        }

        virtual void set_object_state (object_state const & os) throw ()
        {
            UNREFERENCED_PARAMETER (os);
        }

        void set_object (
                opt<float> ox
            ,   opt<float> oy
            ,   opt<float> owidth
            ,   opt<float> oheight
            ,   opt<float> oopacity
            )
        {
            auto os     = get_object_state ();

            auto mc     = min_corner (os.rect);
            auto sz     = size_of (os.rect);
            auto x      = ox.get_value (mc.x);
            auto y      = oy.get_value (mc.y);
            auto width  = owidth.get_value (sz.width);
            auto height = oheight.get_value (sz.height);
            auto opacity= oopacity.get_value (os.opacity);

            os.rect         = construct_from_xywh (x, y, width, height);
            os.opacity      = opacity;

            set_object_state (os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            UNREFERENCED_PARAMETER (render_context);
        }

        void append_transform (
                RenderContext & render_context
            ,   D2D1_MATRIX_3X2_F const & m
            )
        {
            D2D1_MATRIX_3X2_F transform;
            render_context.render_target.GetTransform (&transform);
            auto final_transform = transform * m;
            render_context.render_target.SetTransform (final_transform);
        }

        Message::ptr Message;
    };

    typedef std::map<std::wstring, Renderable::ptr> Renderables;

    template<typename TMessage>
    struct RenderableEx : Renderable
    {
        TMessage * get_message () const throw ()
        {
            return dynamic_cast<TMessage*> (Message.get ());
        }
    };

    struct Renderable__Line : RenderableEx<Message__New_Line>
    {
        virtual object_state get_object_state () const throw () override
        {
            auto message = get_message ();
            if (message)
            {
                auto rect = D2D1::RectF (
                        std::min (message->StartX, message->EndX)
                    ,   std::min (message->StartY, message->EndY)
                    ,   std::max (message->StartX, message->EndX)
                    ,   std::max (message->StartY, message->EndY)
                    );

                return object_state (rect, message->Opacity);
            }
            else
            {
                return object_state ();
            }
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            auto message = get_message ();
            if (message)
            {
                auto current_os = get_object_state ();

                auto current_center = center_of (current_os.rect);
                auto center         = center_of (os.rect);

                auto current_size   = size_of (current_os.rect);
                auto size           = size_of (os.rect);

                auto to_center      = D2D1::Matrix3x2F::Translation (-current_center.x, -current_center.y);
                auto scale          = D2D1::Matrix3x2F::Scale (size.width / current_size.width, size.height / current_size.height);
                auto to_coord       = D2D1::Matrix3x2F::Translation (center.x, center.y);

                auto transform      = to_center * scale * to_coord;

                auto start          = transform.TransformPoint (D2D1::Point2F (message->StartX, message->StartY));
                auto end            = transform.TransformPoint (D2D1::Point2F (message->EndX, message->EndY));

                message->StartX     = start.x       ;
                message->StartY     = start.y       ;
                message->EndX       = end.x         ;
                message->EndY       = end.y         ;
                message->Opacity    = os.opacity    ;

            }
        }

        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    render_context.render_target.DrawLine (
                            D2D1::Point2F (message->StartX, message->StartY)
                        ,   D2D1::Point2F (message->EndX, message->EndY)
                        ,   brush
                        ,   message->StrokeWidth
                        );
                }
            }
        }
    };

    struct Renderable__Ellipse : RenderableEx<Message__New_Ellipse>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    auto center = center_of (rect);
                    auto size   = size_of (rect);
                    render_context.render_target.DrawEllipse (
                            D2D1::Ellipse (center, size.width/2, size.height/2)
                        ,   brush
                        ,   message->StrokeWidth
                        );
                }
            }
        }
    };

    struct Renderable__Rectangle : RenderableEx<Message__New_Rectangle>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }


        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    render_context.render_target.DrawRectangle (
                            rect
                        ,   brush
                        ,   message->StrokeWidth
                        );
                }
            }
        }
    };

    struct Renderable__RoundedRectangle : RenderableEx<Message__New_RoundedRectangle>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }


        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                auto os             = get_object_state ();
                auto rect           = os.rect;
                auto rounded_rect   = D2D1::RoundedRect (rect, message->RadiusX, message->RadiusY);

                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    render_context.render_target.DrawRoundedRectangle (
                            rounded_rect
                        ,   brush
                        ,   message->StrokeWidth
                        );
                }
            }
        }
    };

    struct Renderable__FilledEllipse : RenderableEx<Message__New_FilledEllipse>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    auto center = center_of (rect);
                    auto size   = size_of (rect);
                    render_context.render_target.FillEllipse (
                            D2D1::Ellipse (center, size.width/2, size.height/2)
                        ,   brush
                        );
                }
            }
        }
    };

    struct Renderable__FilledRectangle : RenderableEx<Message__New_FilledRectangle>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    render_context.render_target.FillRectangle (
                            rect
                        ,   brush
                        );
                }
            }
        }

    };

    struct Renderable__FilledRoundedRectangle : RenderableEx<Message__New_FilledRoundedRectangle>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            auto message = get_message ();
            if (message)
            {
                auto os             = get_object_state ();
                auto rect           = os.rect;
                auto rounded_rect   = D2D1::RoundedRect (rect, message->RadiusX, message->RadiusY);
                auto brush = render_context.get_transformed_brush (
                        message->NameOfBrush
                    ,   rect
                    ,   os.opacity
                    );
                if (brush)
                {
                    render_context.render_target.FillRoundedRectangle (
                            rounded_rect
                        ,   brush
                        );
                }
            }
        }

    };

    struct Renderable__Bitmap : RenderableEx<Message__New_Bitmap>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (
                    get_message ()
                ,   std::numeric_limits<float>::infinity ()
                ,   std::numeric_limits<float>::infinity ()
                );
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            auto message = get_message ();
            if (message)
            {
                auto os     = get_object_state ();
                auto rect   = os.rect;
                auto bitmap = render_context.get_bitmap (
                        message->NameOfBitmapResource
                    );

                if (bitmap)
                {
                    auto size = bitmap->GetSize ();
                    if (rect.right > std::numeric_limits<float>::max ())
                    {
                        rect.right = rect.left + size.width;
                    }

                    if (rect.bottom > std::numeric_limits<float>::max ())
                    {
                        rect.bottom = rect.top + size.height;
                    }

                    render_context.render_target.DrawBitmap (
                            bitmap
                        ,   rect
                        ,   os.opacity
                        );
                }
            }
        }

    };

    struct Renderable__Text : RenderableEx<Message__New_Text>
    {
        virtual object_state get_object_state () const throw () override
        {
            return do_get_object_state (get_message ());
        }

        virtual void set_object_state (object_state const & os) throw () override
        {
            return do_set_object_state (get_message (), os);
        }

        virtual void render (
                RenderContext & render_context
            )
        {
            auto message = get_message ();
            if (message)
            {
                auto os             = get_object_state ();
                auto rect           = os.rect;
                auto text_format    = render_context.get_text_format (message->NameOfFontResource);
                auto brush          = render_context.get_transformed_brush (message->NameOfBrush, rect, message->Opacity);

                if (text_format && brush)
                {
                    render_context.render_target.DrawTextW (
                            message->Text.c_str ()
                        ,   static_cast<UINT32> (message->Text.size ())
                        ,   text_format
                        ,   rect
                        ,   brush
                        );
                }
            }
        }

    };

    struct Renderable__ClearTransform : RenderableEx<Message__Clear_Transform>
    {
        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                render_context.render_target.SetTransform (D2D1::Matrix3x2F::Identity ());
            }
        }
    };

    struct Renderable__TranslateTransform : RenderableEx<Message__New_TranslateTransform>
    {
        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                append_transform (
                        render_context
                    ,   D2D1::Matrix3x2F::Translation (message->X, message->Y)
                    );
            }
        }
    };

    struct Renderable__RotateTransform : RenderableEx<Message__New_RotateTransform>
    {
        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                append_transform (
                        render_context
                        ,   D2D1::Matrix3x2F::Rotation (
                                message->Angle
                            ,   D2D1::Point2F (message->CenterX.get_value (0), message->CenterY.get_value (0))
                            )
                    );
            }
        }
    };

    struct Renderable__ScaleTransform : RenderableEx<Message__New_ScaleTransform>
    {
        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                append_transform (
                        render_context
                        ,   D2D1::Matrix3x2F::Scale (
                                message->ScaleX
                            ,   message->ScaleY
                            ,   D2D1::Point2F (message->CenterX.get_value (0), message->CenterY.get_value (0))
                            )
                    );
            }
        }
    };

    struct Renderable__SkewTransform : RenderableEx<Message__New_SkewTransform>
    {
        virtual void render (
                RenderContext & render_context
            ) override
        {
            auto message = get_message ();
            if (message)
            {
                append_transform (
                        render_context
                        ,   D2D1::Matrix3x2F::Skew (
                                message->AngleX
                            ,   message->AngleY
                            ,   D2D1::Point2F (message->CenterX.get_value (0), message->CenterY.get_value (0))
                            )
                    );
            }
        }
    };

    TCHAR const szTitle[]         = L"Interactive Graphics";					
    TCHAR const szWindowClass[]   = L"CLASS_INTERACTIVE_GRAPHICS";

    LRESULT CALLBACK	WndProc (HWND, UINT, WPARAM, LPARAM);

    struct global_state : noncopyable
    {
        ATOM    atom;
        HACCEL  accelerators;

        global_state ()
        {
            auto wcex = create_pod<WNDCLASSEX> ();

	        wcex.cbSize = sizeof (WNDCLASSEX);

	        wcex.style			= CS_HREDRAW | CS_VREDRAW;
	        wcex.lpfnWndProc	= WndProc;
	        wcex.cbClsExtra		= 0;
	        wcex.cbWndExtra		= 0;
	        wcex.hInstance		= Shared__Module;
	        wcex.hIcon			= LoadIcon (Shared__Module, MAKEINTRESOURCE (IDI_MAIN_ICON));
	        wcex.hCursor		= LoadCursor (nullptr, IDC_ARROW);
	        wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	        wcex.lpszMenuName	= nullptr;
	        wcex.lpszClassName	= szWindowClass;
	        wcex.hIconSm		= LoadIcon (Shared__Module, MAKEINTRESOURCE (IDI_SMALL_ICON));

	        atom                = RegisterClassEx (&wcex);

            accelerators        = LoadAccelerators (Shared__Module, MAKEINTRESOURCE (IDC_ACCELERATORS));
        }

    };

    std::recursive_mutex mutex__global_state;

    global_state & get_no_lock__global_state ()
    {
        static global_state gs;

        return gs;
    }

    global_state & get_global_state ()
    {
        std::lock_guard<std::recursive_mutex> lock__global_state (mutex__global_state);
        return get_no_lock__global_state ();
    }

    struct window_manager : noncopyable, i__message_receiver
    {
        static const int max_fps                = 999;
        static const int buffer_count           = 2;

        ID2D1FactoryPtr                         m__d2d_factory          ;
        ID2D1RenderTargetPtr                    m__render_target        ;

        IWICImagingFactoryPtr                   m__imaging_factory      ;

        IDWriteFactoryPtr                       m__dwrite_factory       ;

        ID3D10Device1Ptr                        m__d3d_device           ;

        IDXGISwapChainPtr                       m__dxgi_swap_chain      ;
        IDXGISurfacePtr                         m__dxgi_back_buffer     ;

        Resource__Fallback                      m__fallback_resources   ;
        Resources                               m__resources            ;
        Renderables                             m__renderables          ;

        HWND                                    m__hwnd                 ;
        D2D1::ColorF                            m__background_color     ;
        bool                                    m__create_resources     ;
        bool                                    m__show_fps             ;

        int                                     m__total_frame_count    ;
        int                                     m__measured_frame_count ;
        opt<DWORD>                              m__start_time           ;

        std::condition_variable &               m__synchronize_frame    ;


        window_manager (std::condition_variable & synchronize_frame)
            :   m__hwnd                 (nullptr)
            ,   m__background_color     (D2D1::ColorF (D2D1::ColorF::DarkBlue))
            ,   m__create_resources     (true)
            ,   m__show_fps             (false)
            ,   m__total_frame_count    (0)
            ,   m__measured_frame_count (0)
            ,   m__synchronize_frame    (synchronize_frame)
        {
            // Ensures window class is registered

            get_global_state ();
            m__hwnd = CreateWindow (
                    szWindowClass
                ,   szTitle
                ,   WS_OVERLAPPEDWINDOW
                ,   CW_USEDEFAULT
                ,   0
                ,   CW_USEDEFAULT
                ,   0
                ,   nullptr
                ,   nullptr
                ,   Shared__Module
                ,   nullptr
                );

            if (!m__hwnd)
            {
                return;
            }

            SetWindowLongPtr (m__hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR> (this));

            ShowWindow (m__hwnd, SW_SHOW);

            recreate_device_independent_resources ();
            recreate_device_dependent_resources ();
            recreate_size_dependent_resources ();

            // SetTimer (m__hwnd, 19740531, 1000/120, nullptr);

        }
        
        ~window_manager () throw ()
        {
            discard_resources ();

            release_size_dependent_resources ();
            release_device_dependent_resources ();
            release_device_independent_resources ();

            if (!m__hwnd)
            {
                return;
            }

            DestroyWindow (move_ptr (m__hwnd));
        }

        RECT get_client_rect () const throw ()
        {
            auto client_rect = create_pod<RECT> ();

            if (!m__hwnd)
            {
                return client_rect;
            }

            auto result__get_client_rect = GetClientRect (m__hwnd, &client_rect);

            if (!result__get_client_rect)
            {
                return client_rect;
            }

            return client_rect;
        }

        void release_device_independent_resources ()
        {
            m__imaging_factory.reset ();
            m__dwrite_factory.reset ();
            m__d2d_factory.reset ();
            m__dxgi_swap_chain.reset ();
            m__d3d_device.reset ();

        }

        void recreate_device_independent_resources ()
        {
            release_device_independent_resources ();

            auto client_rect = get_client_rect ();
            auto client_size = size_of (client_rect);

            auto swap_chain_desc = create_pod<DXGI_SWAP_CHAIN_DESC> ();


            swap_chain_desc.BufferDesc.Width            = client_size.cx                        ;
            swap_chain_desc.BufferDesc.Height           = client_size.cy                        ;
            swap_chain_desc.BufferDesc.Format           = DXGI_FORMAT_R8G8B8A8_UNORM            ;
            swap_chain_desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED  ;
            swap_chain_desc.BufferDesc.Scaling          = DXGI_MODE_SCALING_CENTERED            ;


            swap_chain_desc.BufferDesc.RefreshRate.Numerator    = 60                            ;
            swap_chain_desc.BufferDesc.RefreshRate.Denominator  = 1                             ;
    
            // TODO: Turn on multi sampling
            swap_chain_desc.SampleDesc.Count    = 1                                             ;
            swap_chain_desc.SampleDesc.Quality  = 0                                             ;

            swap_chain_desc.BufferUsage     = DXGI_USAGE_RENDER_TARGET_OUTPUT                   ;
            swap_chain_desc.BufferCount     = buffer_count                                      ;
            swap_chain_desc.OutputWindow    = m__hwnd                                           ;
            swap_chain_desc.Windowed        = TRUE                                              ;
            swap_chain_desc.SwapEffect      = DXGI_SWAP_EFFECT_DISCARD                          ;
            swap_chain_desc.Flags           = 0                                                 ;
     
            // TODO: Enum devices
            auto hr__create_d3d_device = D3D10CreateDeviceAndSwapChain1  (
                    nullptr
                ,   D3D10_DRIVER_TYPE_HARDWARE
                ,   nullptr
                ,   D3D10_CREATE_DEVICE_SINGLETHREADED | D3D10_CREATE_DEVICE_BGRA_SUPPORT
                ,   D3D10_FEATURE_LEVEL_9_1
                ,   D3D10_1_SDK_VERSION
                ,   &swap_chain_desc
                ,   m__dxgi_swap_chain.get_outptr ()
                ,   m__d3d_device.get_outptr ()
                );
            LOG_HR_FAILURE (hr__create_d3d_device);

            auto hr__create_imaging_factory = create_com_object (
//                    TODO:
//                    CLSID_WICImagingFactory
                    CLSID_WICImagingFactory1
                ,   m__imaging_factory
                );
            LOG_HR_FAILURE (hr__create_imaging_factory);

            auto hr__dwrite_create_factory = DWriteCreateFactory (
                    DWRITE_FACTORY_TYPE_SHARED
                ,   m__dwrite_factory.get_iid ()
                ,   m__dwrite_factory.get_outptr ()
                );
            LOG_HR_FAILURE (hr__dwrite_create_factory);

            auto hr__d2d_factory = D2D1CreateFactory (
                    D2D1_FACTORY_TYPE_SINGLE_THREADED
                ,   m__d2d_factory.get_iid ()
                ,   m__d2d_factory.get_outptr ()
                );
            LOG_HR_FAILURE (hr__d2d_factory);
        }

        void release_device_dependent_resources ()
        {
        }

        void recreate_device_dependent_resources ()
        {
            release_device_dependent_resources ();

        }

        void release_size_dependent_resources ()
        {
            m__render_target.reset ();
            m__dxgi_back_buffer.reset ();
        }

        void recreate_size_dependent_resources ()
        {
            release_size_dependent_resources ();

            if (!m__d3d_device)
            {
                return;
            }

            if (!m__dxgi_swap_chain)
            {
                return;
            }

            if (!m__d2d_factory)
            {
                return;
            }

            m__d3d_device->ClearState ();

            auto client_rect = get_client_rect ();
            auto client_size = size_of (client_rect);

            auto hr__resize_buffers = m__dxgi_swap_chain->ResizeBuffers (
                        buffer_count
                    ,   client_size.cx
                    ,   client_size.cy
                    ,   DXGI_FORMAT_UNKNOWN
                    ,   0
                    );
            LOG_HR_FAILURE (hr__resize_buffers);        

            auto hr__get_buffer = m__dxgi_swap_chain->GetBuffer (
                    0
                ,   m__dxgi_back_buffer.get_iid ()
                ,   m__dxgi_back_buffer.get_outptr ()
                );
            LOG_HR_FAILURE (hr__get_buffer);

            auto dpi_x = 0.0f;
            auto dpi_y = 0.0f;
            m__d2d_factory->GetDesktopDpi (&dpi_x, &dpi_y);

            auto props =                                 
                D2D1::RenderTargetProperties (
                        D2D1_RENDER_TARGET_TYPE_DEFAULT
                    ,   D2D1::PixelFormat (DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED)
                    ,   dpi_x
                    ,   dpi_y
                    );

            auto hr__create_render_target = m__d2d_factory->CreateDxgiSurfaceRenderTarget (
                    m__dxgi_back_buffer.get_ptr ()
                ,   &props
                ,   m__render_target.get_outptr ()
                );
            LOG_HR_FAILURE (hr__create_render_target);

        }

        void invalidate_window ()
        {
            if (m__hwnd)
            {
                InvalidateRect (
                        m__hwnd
                    ,   nullptr
                    ,   FALSE
                    );
                //UpdateWindow (m__hwnd);
            }
        }

        void process_windows_messages ()
        {
            if (!m__hwnd)
            {
                return;
            }

            global_state & gs = get_global_state ();

            auto msg = create_pod<MSG> ();
            auto pmsg = &msg;

            while (GetMessage (pmsg, m__hwnd, 0, 0))
	        {
                if (!TranslateAccelerator (msg.hwnd, gs.accelerators, &msg))
		        {
			        TranslateMessage (&msg);
			        DispatchMessage (&msg);
		        }
	        }
        }

        void recreate_all_resources ()
        {
            discard_resources ();
            recreate_device_dependent_resources ();
            recreate_size_dependent_resources ();
            create_resources ();
        }

        void discard_resources ()
        {
            if (!m__render_target)
            {
                return;
            }

            if (!m__imaging_factory)
            {
                return;
            }

            if (!m__dwrite_factory)
            {
                return;
            }

            m__create_resources = true;

            ResourceContext rc (*m__render_target.get_ptr (), *m__imaging_factory.get_ptr (), *m__dwrite_factory.get_ptr ());
            for (auto kv : m__resources)
            {
                auto r = kv.second;
                if (r)
                {
                    r->release (rc);
                }
            }

            m__fallback_resources.release (rc);
        }

        void create_resources_if_necessary ()
        {
            if (m__create_resources)
            {
                create_resources ();
            }
        }

        void create_resources ()
        {
            if (!m__render_target)
            {
                return;
            }

            if (!m__imaging_factory)
            {
                return;
            }

            if (!m__dwrite_factory)
            {
                return;
            }

            ResourceContext rc (*m__render_target.get_ptr (), *m__imaging_factory.get_ptr (), *m__dwrite_factory.get_ptr ());
            for (auto kv : m__resources)
            {
                auto r = kv.second;
                if (r)
                {
                    r->create (rc);
                }
            }

            m__fallback_resources.create (rc);

            m__create_resources = false;
        }

        void draw_frame ()
        {
            bool paint_complete = false;
            while (m__render_target && !paint_complete)
            {
                create_resources_if_necessary ();

                m__render_target->BeginDraw ();

                m__render_target->SetTransform (D2D1::Matrix3x2F::Identity ());

                m__render_target->Clear (m__background_color);

                RenderContext rc (
                        m__fallback_resources
                    ,   m__resources
                    ,   *m__render_target.get_ptr ()
                    );

                for (auto kv : m__renderables)
                {
                    auto renderable = kv.second;

                    if (renderable)
                    {
                        renderable->render (rc);
                    }
                }

                if (
                        m__show_fps
                    &&  m__start_time
                    &&  m__render_target
                    &&  m__fallback_resources.Default_Brush
                    &&  m__fallback_resources.Default_TextFormat
                    )
                {
                    unsigned __int64 start_time = m__start_time.get_value (0);
                    unsigned __int64 now = GetTickCount () + 0x100000000ui64;

                    auto diff = static_cast<DWORD> ((now - start_time) & 0xFFFFFFFF); 

                    auto diff_in_seconds = diff / 1000.0;

                    auto fps = diff_in_seconds > 0
                        ?   m__measured_frame_count / diff_in_seconds
                        :   30
                        ;

                    const int size = 255;
                    wchar_t output[size + 1];

                    size_t real_size = 0;

                    if (
                        SUCCEEDED (StringCchPrintf (
                                output
                            ,   size
                            ,   L"FPS: %.1f"
                            ,   fps
                            ))
                        &&  SUCCEEDED (StringCchLength (
                                output
                            ,   size
                            ,   &real_size))
                        )
                    {
                        m__render_target->SetTransform (D2D1::Matrix3x2F::Identity ());
                        m__render_target->DrawTextW (
                                output
                            ,   static_cast<UINT32> (real_size)
                            ,   m__fallback_resources.Default_TextFormat.get_ptr ()
                            ,   D2D1::RectF (0,0,400,24)
                            ,   m__fallback_resources.Default_Brush.get_ptr ()
                            );
                    }

                }

                auto hr__end_draw = m__render_target->EndDraw ();
                if (hr__end_draw == D2DERR_RECREATE_TARGET)
                {
                    recreate_all_resources ();
                }
                else
                {
                    paint_complete = true;
                }
            }

            m__synchronize_frame.notify_all ();

            if (m__total_frame_count % (60 * 10) == 0)
            {
                m__measured_frame_count = 0;
                m__start_time = GetTickCount ();
            }
            else
            {
                ++m__measured_frame_count;
            }
            ++m__total_frame_count;
        }

        LRESULT window_proc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
        {
            LRESULT lresult = 0;

	        switch (message)
	        {
            case WM_TIMER:
                invalidate_window ();
                UpdateWindow (hWnd);
                break;
            case WM_NEXT_FRAME:
                {
                    //RedrawWindow (
                    //        hWnd
                    //    ,   nullptr
                    //    ,   nullptr
                    //    ,   RDW_INTERNALPAINT
                    //    );
                    invalidate_window ();
                }
                break;
            case WM_ACCEPT_MESSAGE:
                {
                    auto message = Message::aptr (reinterpret_cast<Message*> (lParam));

                    if (message.get ())
                    {
                        visit_message (message, *this);
                    }
                }
                break;
            case WM_ERASEBKGND:
                {
                    lresult = 1;
                }
                break;
            case WM_GETMINMAXINFO:
                {
                    auto pinfo = reinterpret_cast<MINMAXINFO*> (lParam);

                    if (pinfo)
                    {
                        pinfo->ptMinTrackSize.x = 320;
                        pinfo->ptMinTrackSize.y = 200;
                    }
                }
                break;
	        case WM_PAINT:
                {
                    PAINTSTRUCT ps;
                    auto hdc = BeginPaint (hWnd, &ps);
                    UNREFERENCED_PARAMETER (hdc);

                    draw_frame ();

                    EndPaint (hWnd, &ps);

                    m__dxgi_swap_chain->Present (1, 0);

                    PostMessage (hWnd, WM_NEXT_FRAME, 0, 0);
                }
		        break;
            case WM_SIZE:
                {
                    //auto width = LOWORD (lParam); 
                    //auto height = HIWORD (lParam);

                    recreate_size_dependent_resources ();
                }
                break;
            case WM_CLOSE:


                break;
	        case WM_DESTROY:
		        PostQuitMessage (0);
		        break;
	        default:
		        lresult = DefWindowProc (hWnd, message, wParam, lParam);
	        }
	        return lresult;
        }

        template<typename TResource>
        void add_resource (
                std::wstring const & name
            ,   Message::aptr & message
            )
        {
            if (message.get ())
            {
                auto r = Resource::ptr (new TResource ());
                r->Message = Message::ptr (message.release ());
                m__resources[name] = r;

                m__create_resources  = true;
            }
        }

        template<typename TRenderable>
        void add_renderable (
                std::wstring const & name
            ,   Message::aptr & message
            )
        {
            if (message.get ())
            {
                auto r = Renderable::ptr (new TRenderable ());
                r->Message = Message::ptr (message.release ());
                m__renderables[name] = r;
            }
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Set_Window & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);

            auto x              = specific_message.X.get_value (0);
            auto y              = specific_message.Y.get_value (0);
            auto cx             = specific_message.Width.get_value (0);
            auto cy             = specific_message.Height.get_value (0);
            auto show_window    = specific_message.ShowWindow.get_value (false);
            auto color          = specific_message.Color;
            auto show_fps       = specific_message.ShowFPS.get_value (m__show_fps);
            auto title          = specific_message.Title;

            auto is_moved       =       specific_message.X.has_value ()
                                    &&  specific_message.Y.has_value ()             ;
            auto is_resized     =       specific_message.Width.has_value ()       
                                    &&  specific_message.Height.has_value ()        ;
            auto is_shown_hidden=       specific_message.ShowWindow.has_value ()    ;

            if (m__hwnd)
            {
                RECT client_rect;
                client_rect.left = 0;
                client_rect.right = cx;
                client_rect.top = 0;
                client_rect.bottom = cy;

                auto window_style       = GetWindowLong (m__hwnd, GWL_STYLE);
                auto ex_window_style    = GetWindowLong (m__hwnd, GWL_STYLE);

                if (specific_message.ClientSize && AdjustWindowRectEx (
                        &client_rect
                    ,   window_style
                    ,   FALSE
                    ,   ex_window_style
                    ))
                {
                    cx = client_rect.right - client_rect.left;
                    cy = client_rect.bottom - client_rect.top;
                }

                auto flags = 0                         
                    |   (is_moved           ? 0 : SWP_NOMOVE)
                    |   (is_resized         ? 0 : SWP_NOSIZE)
                    |   (is_shown_hidden    ? (show_window ? SWP_SHOWWINDOW : SWP_HIDEWINDOW) : 0) 
                    ;
                auto result__set_window_pos = SetWindowPos (
                        m__hwnd
                    ,   nullptr
                    ,   x
                    ,   y
                    ,   cx
                    ,   cy
                    ,   flags   
                    );
                UNREFERENCED_PARAMETER  (result__set_window_pos);

                if (title.size () > 0)
                {
                    auto result__set_window_text = SetWindowText (
                            m__hwnd
                        ,   title.c_str ()
                        );
                    UNREFERENCED_PARAMETER  (result__set_window_text);
                }
            }

            if (color.size () > 0)
            {
                m__background_color = parse_color (color);
            }

            m__show_fps = show_fps;
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Wait_StateIsPresented & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);
            UNREFERENCED_PARAMETER (specific_message);

            // Handled by the preprocessor
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_SolidBrush & specific_message    
            ) override
        {
            add_resource<Resource__SolidBrush> (
                    specific_message.NameOfBrush
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_LinearGradientBrush & specific_message    
            ) override
        {
            add_resource<Resource__LinearGradientBrush> (
                    specific_message.NameOfBrush
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_RadialGradientBrush & specific_message    
            ) override
        {
            add_resource<Resource__RadialGradientBrush> (
                    specific_message.NameOfBrush
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Add_GradientStop & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);

            auto find = m__resources.find (specific_message.NameOfBrush);
            if (find != m__resources.end ())
            {
                auto r = find->second;
                if (r)
                {
                    r->add_gradient_stop (
                            parse_color (specific_message.Color)
                        ,   specific_message.Offset
                        );
                    m__create_resources = true;
                }
            }
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Clear_GradientStops & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);

            auto find = m__resources.find (specific_message.NameOfBrush);
            if (find != m__resources.end ())
            {
                auto r = find->second;
                if (r)
                {
                    r->clear_gradient_stops ();
                    m__create_resources = true;
                }
            }
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_BitmapResourceFromBytes & specific_message    
            ) override
        {
            add_resource<Resource__Bitmap> (
                    specific_message.NameOfBitmapResource
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_FontResource & specific_message    
            ) override
        {
            add_resource<Resource__Font> (
                    specific_message.NameOfFontResource
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Set_Object & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);

            auto find = m__renderables.find (specific_message.NameOfObject);
            if (find != m__renderables.end () && find->second)
            {
                find->second->set_object (
                        specific_message.X
                    ,   specific_message.Y
                    ,   specific_message.Width
                    ,   specific_message.Height
                    ,   specific_message.Opacity
                    );
            }
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_Line & specific_message    
            ) override
        {
            add_renderable<Renderable__Line> (
                    specific_message.NameOfLine
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_Ellipse & specific_message    
            ) override
        {
            add_renderable<Renderable__Ellipse> (
                    specific_message.NameOfEllipse
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_Rectangle & specific_message    
            ) override
        {
            add_renderable<Renderable__Rectangle> (
                    specific_message.NameOfRectangle
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_RoundedRectangle & specific_message    
            ) override
        {
            add_renderable<Renderable__RoundedRectangle> (
                    specific_message.NameOfRectangle
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_FilledEllipse & specific_message    
            ) override
        {
            add_renderable<Renderable__FilledEllipse> (
                    specific_message.NameOfEllipse
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_FilledRectangle & specific_message    
            ) override
        {
            add_renderable<Renderable__FilledRectangle> (
                    specific_message.NameOfRectangle
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_FilledRoundedRectangle & specific_message    
            ) override
        {
            add_renderable<Renderable__FilledRoundedRectangle> (
                    specific_message.NameOfRectangle
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_Bitmap & specific_message    
            ) override
        {
            add_renderable<Renderable__Bitmap> (
                    specific_message.NameOfBitmap
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_Text & specific_message    
            ) override
        {
            add_renderable<Renderable__Text> (
                    specific_message.NameOfText
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Clear_State & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);
            UNREFERENCED_PARAMETER (specific_message);
            m__renderables.clear ();
            m__resources.clear ();
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Remove_Object & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);
            m__renderables.erase (specific_message.NameOfObject);
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Remove_Resource & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);
            m__resources.erase (specific_message.NameOfResource);
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_TranslateTransform & specific_message    
            ) override
        {
            add_renderable<Renderable__TranslateTransform> (
                    specific_message.NameOfTransform
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_RotateTransform & specific_message    
            ) override
        {
            add_renderable<Renderable__RotateTransform> (
                    specific_message.NameOfTransform
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_ScaleTransform & specific_message    
            ) override
        {
            add_renderable<Renderable__ScaleTransform> (
                    specific_message.NameOfTransform
                ,   message
                );
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__New_SkewTransform & specific_message    
            ) override
        {
            add_renderable<Renderable__SkewTransform> (
                    specific_message.NameOfTransform
                ,   message
                );
        }


        virtual void accept_message (
                Message::aptr & message
            ,   Message__Clear_Transform & specific_message    
            ) override
        {
            add_renderable<Renderable__ClearTransform> (
                    specific_message.NameOfTransform
                ,   message
                );
        }


    };


}

struct session::impl : noncopyable
{
    std::mutex              m__mutex                ;
    std::condition_variable m__synchronize_startup  ;
    std::condition_variable m__synchronize_frame    ;

    HWND                    m__not_owned__hwnd;

    std::thread             m__thread               ;
    
    impl ()
        :   m__not_owned__hwnd (nullptr)
#pragma warning (disable: 4355)
            // Disabled: warning C4355: 'this' : used in base member initializer list
            // m__thread is initialized last (because of member ordering)
            // In addition virtual methods aren't used
            // Therefore 4355 doesn't apply here
        ,   m__thread ([=] () {thread_proc ();})
#pragma warning (default: 4355)
    {
        {
            std::unique_lock<std::mutex> lock  (m__mutex);

            m__synchronize_startup.wait (lock);
        }
    }

    ~impl () throw ()
    {
        if (m__not_owned__hwnd)
        {
            PostMessage (
                    m__not_owned__hwnd
                ,   WM_QUIT
                ,   0
                ,   0
                );
        }

        if (m__thread.joinable ())
        {
            m__thread.join ();
        }
    }

    void thread_proc ()
    {
        CoInitialize (0);
        try
        {
            window_manager mgr (m__synchronize_frame);

            {
                std::unique_lock<std::mutex> lock  (m__mutex);
                m__not_owned__hwnd = mgr.m__hwnd;
                m__synchronize_startup.notify_one ();
            }

            mgr.process_windows_messages ();
        }
        catch (...)
        {
            // TODO: Log
        }

        {
            std::unique_lock<std::mutex> lock  (m__mutex);
            m__not_owned__hwnd = nullptr;
        }
        CoUninitialize ();
    }

    enum class preprocess_action 
    {
        send_message        ,
        synchronize_frame   ,
    };

    struct preprocessor_message_receiver : base__message_receiver
    {
        preprocess_action   action              ;
        preprocessor_message_receiver ()
            :   action              (preprocess_action::send_message)
        {
        }

        virtual void accept_message (
                Message::aptr & message
            ,   Message__Wait_StateIsPresented & specific_message    
            ) override
        {
            UNREFERENCED_PARAMETER (message);
            UNREFERENCED_PARAMETER (specific_message);
            action = preprocess_action::synchronize_frame;
        }

    };

    void accept_message (__int32 size_of_message, unsigned __int8 const * bytes)
    {
        auto message = unpack_message (size_of_message, bytes);

        // TODO: Log if message is null
        if (m__not_owned__hwnd && message.get ())
        {
            preprocessor_message_receiver preprocessor;
            visit_message (message, preprocessor);

            switch (preprocessor.action)
            {
            case preprocess_action::synchronize_frame:
                {
                    std::unique_lock<std::mutex> lock  (m__mutex);
                    //auto wait_for = (2 * 1000) / 60;
                    //auto status = m__synchronize_frame.wait_for (lock, std::chrono::microseconds (wait_for));
                    m__synchronize_frame.wait (lock);
                }
                break;
            case preprocess_action::send_message:
            default:
                {
                    auto raw_message = reinterpret_cast<LPARAM> (message.release ());
                    PostMessage (
                            m__not_owned__hwnd
                        ,   WM_ACCEPT_MESSAGE
                        ,   0
                        ,   raw_message
                        );
                }
                break;
            }
        }
    }

};

namespace
{
    LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        auto wm = reinterpret_cast<window_manager*> (GetWindowLongPtr (hWnd, GWLP_USERDATA)); 
        if (wm)
        {
            return wm->window_proc (hWnd, message, wParam, lParam); 
        }
        else
        {
    		return DefWindowProc (hWnd, message, wParam, lParam);
        }
    }
}

session::session ()
    :   m__impl (new impl ())
{
}

session::~session ()
{
    delete m__impl;
}

void session::accept_message (__int32 size_of_message, unsigned __int8 const * message)
{
    m__impl->accept_message (size_of_message, message);
}
