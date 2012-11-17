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

// ############################################################################
// #                                                                          #
// #        ---==>  T H I S  F I L E  I S   G E N E R A T E D  <==---         #
// #                                                                          #
// # This means that any edits to the .cs file will be lost when its          #
// # regenerated. Changes should instead be applied to the corresponding      #
// # template file (.tt)                                                      #
// ############################################################################








#pragma once
#pragma warning (push)
#   pragma warning (disable:4100)

namespace
{


enum MessageId : byte
{
    MessageId__Set_Window = 1,
    MessageId__Wait_StateIsPresented = 2,
    MessageId__Clear_State = 3,
    MessageId__Remove_Object = 4,
    MessageId__Remove_Resource = 5,
    MessageId__New_SolidBrush = 6,
    MessageId__New_LinearGradientBrush = 7,
    MessageId__New_RadialGradientBrush = 8,
    MessageId__Add_GradientStop = 9,
    MessageId__Clear_GradientStops = 10,
    MessageId__New_BitmapResourceFromBytes = 11,
    MessageId__New_FontResource = 12,
    MessageId__Set_Object = 13,
    MessageId__New_Line = 14,
    MessageId__New_Ellipse = 15,
    MessageId__New_Rectangle = 16,
    MessageId__New_RoundedRectangle = 17,
    MessageId__New_FilledEllipse = 18,
    MessageId__New_FilledRectangle = 19,
    MessageId__New_FilledRoundedRectangle = 20,
    MessageId__New_Bitmap = 21,
    MessageId__New_Text = 22,
    MessageId__Clear_Transform = 23,
    MessageId__New_RotateTransform = 24,
    MessageId__New_TranslateTransform = 25,
    MessageId__New_ScaleTransform = 26,
    MessageId__New_SkewTransform = 27,
};

struct Message : noncopyable
{
    typedef std::tr1::shared_ptr<Message> ptr;
    typedef std::auto_ptr<Message> aptr;

    MessageId Id;

    virtual ~Message () throw ()
    {
    }
};


struct Message__Set_Window : Message
{
    opt<int> X;
    opt<int> Y;
    opt<int> Width;
    opt<int> Height;
    bool ClientSize;
    opt<bool> ShowWindow;
    opt<bool> ShowFPS;
    std::wstring Color;
    std::wstring Title;
};
struct Message__Wait_StateIsPresented : Message
{
};
struct Message__Clear_State : Message
{
};
struct Message__Remove_Object : Message
{
    std::wstring NameOfObject;
};
struct Message__Remove_Resource : Message
{
    std::wstring NameOfResource;
};
struct Message__New_SolidBrush : Message
{
    std::wstring NameOfBrush;
    std::wstring Color;
};
struct Message__New_LinearGradientBrush : Message
{
    std::wstring NameOfBrush;
    bool RelativeCoordinates;
    std::wstring Gamma;
    std::wstring ExtendMode;
    float StartX;
    float StartY;
    float EndX;
    float EndY;
};
struct Message__New_RadialGradientBrush : Message
{
    std::wstring NameOfBrush;
    bool RelativeCoordinates;
    std::wstring Gamma;
    std::wstring ExtendMode;
    float CenterX;
    float CenterY;
    float OffsetX;
    float OffsetY;
    float RadiusX;
    float RadiusY;
};
struct Message__Add_GradientStop : Message
{
    std::wstring NameOfBrush;
    float Offset;
    std::wstring Color;
};
struct Message__Clear_GradientStops : Message
{
    std::wstring NameOfBrush;
};
struct Message__New_BitmapResourceFromBytes : Message
{
    std::wstring NameOfBitmapResource;
    std::vector<unsigned __int8> Bytes;
    int UseFrame;
};
struct Message__New_FontResource : Message
{
    std::wstring NameOfFontResource;
    std::wstring FontFamily;
    float FontSize;
};
struct Message__Set_Object : Message
{
    std::wstring NameOfObject;
    opt<float> X;
    opt<float> Y;
    opt<float> Width;
    opt<float> Height;
    opt<float> Opacity;
};
struct Message__New_Line : Message
{
    std::wstring NameOfLine;
    std::wstring NameOfBrush;
    float StartX;
    float StartY;
    float EndX;
    float EndY;
    float Opacity;
    float StrokeWidth;
};
struct Message__New_Ellipse : Message
{
    std::wstring NameOfEllipse;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
    float StrokeWidth;
};
struct Message__New_Rectangle : Message
{
    std::wstring NameOfRectangle;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
    float StrokeWidth;
};
struct Message__New_RoundedRectangle : Message
{
    std::wstring NameOfRectangle;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
    float RadiusX;
    float RadiusY;
    float StrokeWidth;
};
struct Message__New_FilledEllipse : Message
{
    std::wstring NameOfEllipse;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
};
struct Message__New_FilledRectangle : Message
{
    std::wstring NameOfRectangle;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
};
struct Message__New_FilledRoundedRectangle : Message
{
    std::wstring NameOfRectangle;
    std::wstring NameOfBrush;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
    float RadiusX;
    float RadiusY;
};
struct Message__New_Bitmap : Message
{
    std::wstring NameOfBitmap;
    std::wstring NameOfBitmapResource;
    float X;
    float Y;
    opt<float> Width;
    opt<float> Height;
    float Opacity;
};
struct Message__New_Text : Message
{
    std::wstring NameOfText;
    std::wstring NameOfBrush;
    std::wstring NameOfFontResource;
    std::wstring Text;
    float X;
    float Y;
    float Width;
    float Height;
    float Opacity;
};
struct Message__Clear_Transform : Message
{
    std::wstring NameOfTransform;
};
struct Message__New_RotateTransform : Message
{
    std::wstring NameOfTransform;
    float Angle;
    opt<float> CenterX;
    opt<float> CenterY;
};
struct Message__New_TranslateTransform : Message
{
    std::wstring NameOfTransform;
    float X;
    float Y;
};
struct Message__New_ScaleTransform : Message
{
    std::wstring NameOfTransform;
    float ScaleX;
    float ScaleY;
    opt<float> CenterX;
    opt<float> CenterY;
};
struct Message__New_SkewTransform : Message
{
    std::wstring NameOfTransform;
    float AngleX;
    float AngleY;
    opt<float> CenterX;
    opt<float> CenterY;
};

struct i__message_receiver
{
    virtual void accept_message (
            Message::aptr & message
        ,   Message__Set_Window & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Wait_StateIsPresented & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_State & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Remove_Object & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Remove_Resource & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_SolidBrush & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_LinearGradientBrush & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RadialGradientBrush & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Add_GradientStop & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_GradientStops & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_BitmapResourceFromBytes & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FontResource & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Set_Object & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Line & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Ellipse & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Rectangle & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RoundedRectangle & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledEllipse & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledRectangle & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledRoundedRectangle & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Bitmap & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Text & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_Transform & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RotateTransform & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_TranslateTransform & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_ScaleTransform & specific_message    
        ) = 0;

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_SkewTransform & specific_message    
        ) = 0;


};

struct base__message_receiver : i__message_receiver
{
    virtual void accept_message (
            Message::aptr & message
        ,   Message__Set_Window & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Wait_StateIsPresented & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_State & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Remove_Object & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Remove_Resource & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_SolidBrush & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_LinearGradientBrush & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RadialGradientBrush & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Add_GradientStop & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_GradientStops & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_BitmapResourceFromBytes & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FontResource & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Set_Object & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Line & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Ellipse & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Rectangle & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RoundedRectangle & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledEllipse & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledRectangle & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_FilledRoundedRectangle & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Bitmap & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_Text & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__Clear_Transform & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_RotateTransform & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_TranslateTransform & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_ScaleTransform & specific_message    
        ) override
    {
    }

    virtual void accept_message (
            Message::aptr & message
        ,   Message__New_SkewTransform & specific_message    
        ) override
    {
    }


};

void visit_message (
        Message::aptr & message
    ,   i__message_receiver & receiver
    )
{

    switch (message->Id)
    {
        case MessageId__Set_Window:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Set_Window*>(message.get ())
                );
            break;
        case MessageId__Wait_StateIsPresented:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Wait_StateIsPresented*>(message.get ())
                );
            break;
        case MessageId__Clear_State:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Clear_State*>(message.get ())
                );
            break;
        case MessageId__Remove_Object:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Remove_Object*>(message.get ())
                );
            break;
        case MessageId__Remove_Resource:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Remove_Resource*>(message.get ())
                );
            break;
        case MessageId__New_SolidBrush:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_SolidBrush*>(message.get ())
                );
            break;
        case MessageId__New_LinearGradientBrush:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_LinearGradientBrush*>(message.get ())
                );
            break;
        case MessageId__New_RadialGradientBrush:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_RadialGradientBrush*>(message.get ())
                );
            break;
        case MessageId__Add_GradientStop:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Add_GradientStop*>(message.get ())
                );
            break;
        case MessageId__Clear_GradientStops:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Clear_GradientStops*>(message.get ())
                );
            break;
        case MessageId__New_BitmapResourceFromBytes:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_BitmapResourceFromBytes*>(message.get ())
                );
            break;
        case MessageId__New_FontResource:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_FontResource*>(message.get ())
                );
            break;
        case MessageId__Set_Object:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Set_Object*>(message.get ())
                );
            break;
        case MessageId__New_Line:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_Line*>(message.get ())
                );
            break;
        case MessageId__New_Ellipse:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_Ellipse*>(message.get ())
                );
            break;
        case MessageId__New_Rectangle:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_Rectangle*>(message.get ())
                );
            break;
        case MessageId__New_RoundedRectangle:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_RoundedRectangle*>(message.get ())
                );
            break;
        case MessageId__New_FilledEllipse:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_FilledEllipse*>(message.get ())
                );
            break;
        case MessageId__New_FilledRectangle:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_FilledRectangle*>(message.get ())
                );
            break;
        case MessageId__New_FilledRoundedRectangle:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_FilledRoundedRectangle*>(message.get ())
                );
            break;
        case MessageId__New_Bitmap:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_Bitmap*>(message.get ())
                );
            break;
        case MessageId__New_Text:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_Text*>(message.get ())
                );
            break;
        case MessageId__Clear_Transform:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__Clear_Transform*>(message.get ())
                );
            break;
        case MessageId__New_RotateTransform:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_RotateTransform*>(message.get ())
                );
            break;
        case MessageId__New_TranslateTransform:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_TranslateTransform*>(message.get ())
                );
            break;
        case MessageId__New_ScaleTransform:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_ScaleTransform*>(message.get ())
                );
            break;
        case MessageId__New_SkewTransform:
            receiver.accept_message (
                    message
                ,   *static_cast<Message__New_SkewTransform*>(message.get ())
                );
            break;
    }
}

Message::aptr unpack_message (
        __int32 size_of_message
    ,   unsigned __int8 const * bytes
    )
{
    if (size_of_message > 0 && bytes)
    {
        message_unserializer unpacker (size_of_message, bytes);
        
        unsigned __int8 messageId = 0;
        if (!unpacker.unpack (L"MessageId", messageId))
        {
            // TODO: Log
            return Message::aptr ();
        }

        switch (messageId)
        {
        case MessageId__Set_Window:
            {
                std::auto_ptr<Message__Set_Window> message (new Message__Set_Window ());
                message->Id = MessageId__Set_Window;
                auto result = true
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"ClientSize", message->ClientSize)
                    &&  unpacker.unpack (L"ShowWindow", message->ShowWindow)
                    &&  unpacker.unpack (L"ShowFPS", message->ShowFPS)
                    &&  unpacker.unpack (L"Color", message->Color)
                    &&  unpacker.unpack (L"Title", message->Title)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Wait_StateIsPresented:
            {
                std::auto_ptr<Message__Wait_StateIsPresented> message (new Message__Wait_StateIsPresented ());
                message->Id = MessageId__Wait_StateIsPresented;
                auto result = true
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Clear_State:
            {
                std::auto_ptr<Message__Clear_State> message (new Message__Clear_State ());
                message->Id = MessageId__Clear_State;
                auto result = true
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Remove_Object:
            {
                std::auto_ptr<Message__Remove_Object> message (new Message__Remove_Object ());
                message->Id = MessageId__Remove_Object;
                auto result = true
                    &&  unpacker.unpack (L"NameOfObject", message->NameOfObject)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Remove_Resource:
            {
                std::auto_ptr<Message__Remove_Resource> message (new Message__Remove_Resource ());
                message->Id = MessageId__Remove_Resource;
                auto result = true
                    &&  unpacker.unpack (L"NameOfResource", message->NameOfResource)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_SolidBrush:
            {
                std::auto_ptr<Message__New_SolidBrush> message (new Message__New_SolidBrush ());
                message->Id = MessageId__New_SolidBrush;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"Color", message->Color)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_LinearGradientBrush:
            {
                std::auto_ptr<Message__New_LinearGradientBrush> message (new Message__New_LinearGradientBrush ());
                message->Id = MessageId__New_LinearGradientBrush;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"RelativeCoordinates", message->RelativeCoordinates)
                    &&  unpacker.unpack (L"Gamma", message->Gamma)
                    &&  unpacker.unpack (L"ExtendMode", message->ExtendMode)
                    &&  unpacker.unpack (L"StartX", message->StartX)
                    &&  unpacker.unpack (L"StartY", message->StartY)
                    &&  unpacker.unpack (L"EndX", message->EndX)
                    &&  unpacker.unpack (L"EndY", message->EndY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_RadialGradientBrush:
            {
                std::auto_ptr<Message__New_RadialGradientBrush> message (new Message__New_RadialGradientBrush ());
                message->Id = MessageId__New_RadialGradientBrush;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"RelativeCoordinates", message->RelativeCoordinates)
                    &&  unpacker.unpack (L"Gamma", message->Gamma)
                    &&  unpacker.unpack (L"ExtendMode", message->ExtendMode)
                    &&  unpacker.unpack (L"CenterX", message->CenterX)
                    &&  unpacker.unpack (L"CenterY", message->CenterY)
                    &&  unpacker.unpack (L"OffsetX", message->OffsetX)
                    &&  unpacker.unpack (L"OffsetY", message->OffsetY)
                    &&  unpacker.unpack (L"RadiusX", message->RadiusX)
                    &&  unpacker.unpack (L"RadiusY", message->RadiusY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Add_GradientStop:
            {
                std::auto_ptr<Message__Add_GradientStop> message (new Message__Add_GradientStop ());
                message->Id = MessageId__Add_GradientStop;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"Offset", message->Offset)
                    &&  unpacker.unpack (L"Color", message->Color)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Clear_GradientStops:
            {
                std::auto_ptr<Message__Clear_GradientStops> message (new Message__Clear_GradientStops ());
                message->Id = MessageId__Clear_GradientStops;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_BitmapResourceFromBytes:
            {
                std::auto_ptr<Message__New_BitmapResourceFromBytes> message (new Message__New_BitmapResourceFromBytes ());
                message->Id = MessageId__New_BitmapResourceFromBytes;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBitmapResource", message->NameOfBitmapResource)
                    &&  unpacker.unpack (L"Bytes", message->Bytes)
                    &&  unpacker.unpack (L"UseFrame", message->UseFrame)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_FontResource:
            {
                std::auto_ptr<Message__New_FontResource> message (new Message__New_FontResource ());
                message->Id = MessageId__New_FontResource;
                auto result = true
                    &&  unpacker.unpack (L"NameOfFontResource", message->NameOfFontResource)
                    &&  unpacker.unpack (L"FontFamily", message->FontFamily)
                    &&  unpacker.unpack (L"FontSize", message->FontSize)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Set_Object:
            {
                std::auto_ptr<Message__Set_Object> message (new Message__Set_Object ());
                message->Id = MessageId__Set_Object;
                auto result = true
                    &&  unpacker.unpack (L"NameOfObject", message->NameOfObject)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_Line:
            {
                std::auto_ptr<Message__New_Line> message (new Message__New_Line ());
                message->Id = MessageId__New_Line;
                auto result = true
                    &&  unpacker.unpack (L"NameOfLine", message->NameOfLine)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"StartX", message->StartX)
                    &&  unpacker.unpack (L"StartY", message->StartY)
                    &&  unpacker.unpack (L"EndX", message->EndX)
                    &&  unpacker.unpack (L"EndY", message->EndY)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    &&  unpacker.unpack (L"StrokeWidth", message->StrokeWidth)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_Ellipse:
            {
                std::auto_ptr<Message__New_Ellipse> message (new Message__New_Ellipse ());
                message->Id = MessageId__New_Ellipse;
                auto result = true
                    &&  unpacker.unpack (L"NameOfEllipse", message->NameOfEllipse)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    &&  unpacker.unpack (L"StrokeWidth", message->StrokeWidth)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_Rectangle:
            {
                std::auto_ptr<Message__New_Rectangle> message (new Message__New_Rectangle ());
                message->Id = MessageId__New_Rectangle;
                auto result = true
                    &&  unpacker.unpack (L"NameOfRectangle", message->NameOfRectangle)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    &&  unpacker.unpack (L"StrokeWidth", message->StrokeWidth)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_RoundedRectangle:
            {
                std::auto_ptr<Message__New_RoundedRectangle> message (new Message__New_RoundedRectangle ());
                message->Id = MessageId__New_RoundedRectangle;
                auto result = true
                    &&  unpacker.unpack (L"NameOfRectangle", message->NameOfRectangle)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    &&  unpacker.unpack (L"RadiusX", message->RadiusX)
                    &&  unpacker.unpack (L"RadiusY", message->RadiusY)
                    &&  unpacker.unpack (L"StrokeWidth", message->StrokeWidth)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_FilledEllipse:
            {
                std::auto_ptr<Message__New_FilledEllipse> message (new Message__New_FilledEllipse ());
                message->Id = MessageId__New_FilledEllipse;
                auto result = true
                    &&  unpacker.unpack (L"NameOfEllipse", message->NameOfEllipse)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_FilledRectangle:
            {
                std::auto_ptr<Message__New_FilledRectangle> message (new Message__New_FilledRectangle ());
                message->Id = MessageId__New_FilledRectangle;
                auto result = true
                    &&  unpacker.unpack (L"NameOfRectangle", message->NameOfRectangle)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_FilledRoundedRectangle:
            {
                std::auto_ptr<Message__New_FilledRoundedRectangle> message (new Message__New_FilledRoundedRectangle ());
                message->Id = MessageId__New_FilledRoundedRectangle;
                auto result = true
                    &&  unpacker.unpack (L"NameOfRectangle", message->NameOfRectangle)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    &&  unpacker.unpack (L"RadiusX", message->RadiusX)
                    &&  unpacker.unpack (L"RadiusY", message->RadiusY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_Bitmap:
            {
                std::auto_ptr<Message__New_Bitmap> message (new Message__New_Bitmap ());
                message->Id = MessageId__New_Bitmap;
                auto result = true
                    &&  unpacker.unpack (L"NameOfBitmap", message->NameOfBitmap)
                    &&  unpacker.unpack (L"NameOfBitmapResource", message->NameOfBitmapResource)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_Text:
            {
                std::auto_ptr<Message__New_Text> message (new Message__New_Text ());
                message->Id = MessageId__New_Text;
                auto result = true
                    &&  unpacker.unpack (L"NameOfText", message->NameOfText)
                    &&  unpacker.unpack (L"NameOfBrush", message->NameOfBrush)
                    &&  unpacker.unpack (L"NameOfFontResource", message->NameOfFontResource)
                    &&  unpacker.unpack (L"Text", message->Text)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    &&  unpacker.unpack (L"Width", message->Width)
                    &&  unpacker.unpack (L"Height", message->Height)
                    &&  unpacker.unpack (L"Opacity", message->Opacity)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__Clear_Transform:
            {
                std::auto_ptr<Message__Clear_Transform> message (new Message__Clear_Transform ());
                message->Id = MessageId__Clear_Transform;
                auto result = true
                    &&  unpacker.unpack (L"NameOfTransform", message->NameOfTransform)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_RotateTransform:
            {
                std::auto_ptr<Message__New_RotateTransform> message (new Message__New_RotateTransform ());
                message->Id = MessageId__New_RotateTransform;
                auto result = true
                    &&  unpacker.unpack (L"NameOfTransform", message->NameOfTransform)
                    &&  unpacker.unpack (L"Angle", message->Angle)
                    &&  unpacker.unpack (L"CenterX", message->CenterX)
                    &&  unpacker.unpack (L"CenterY", message->CenterY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_TranslateTransform:
            {
                std::auto_ptr<Message__New_TranslateTransform> message (new Message__New_TranslateTransform ());
                message->Id = MessageId__New_TranslateTransform;
                auto result = true
                    &&  unpacker.unpack (L"NameOfTransform", message->NameOfTransform)
                    &&  unpacker.unpack (L"X", message->X)
                    &&  unpacker.unpack (L"Y", message->Y)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_ScaleTransform:
            {
                std::auto_ptr<Message__New_ScaleTransform> message (new Message__New_ScaleTransform ());
                message->Id = MessageId__New_ScaleTransform;
                auto result = true
                    &&  unpacker.unpack (L"NameOfTransform", message->NameOfTransform)
                    &&  unpacker.unpack (L"ScaleX", message->ScaleX)
                    &&  unpacker.unpack (L"ScaleY", message->ScaleY)
                    &&  unpacker.unpack (L"CenterX", message->CenterX)
                    &&  unpacker.unpack (L"CenterY", message->CenterY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        case MessageId__New_SkewTransform:
            {
                std::auto_ptr<Message__New_SkewTransform> message (new Message__New_SkewTransform ());
                message->Id = MessageId__New_SkewTransform;
                auto result = true
                    &&  unpacker.unpack (L"NameOfTransform", message->NameOfTransform)
                    &&  unpacker.unpack (L"AngleX", message->AngleX)
                    &&  unpacker.unpack (L"AngleY", message->AngleY)
                    &&  unpacker.unpack (L"CenterX", message->CenterX)
                    &&  unpacker.unpack (L"CenterY", message->CenterY)
                    ;
                if (result)
                {
                    return Message::aptr (message.release ());
                }
                else
                {
                    // TODO: Log
                }
            }
            break;
        default:
            // TODO: Log
            break;
        }

    }
    return Message::aptr ();
}


}
#pragma warning (pop)

