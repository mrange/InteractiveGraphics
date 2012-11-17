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

// 15.  Little bit jumpy (although no tearing), need to investigate why
// 17.  Seems to have slow memory leak in the reander loop
// 16.  Plot polygon trains
// 13.  Is it benefical to cache objects as images?
// 6.   Report back unpack failures from C++ to C#


using System;
using System.IO;
using System.Linq;
using InteractiveGraphics.Lib;

namespace InteractiveGraphics
{
    class Program
    {
        const string MyBrush            = "MyBrush"             ;
        const string MyBitmap           = "MyBitmap"            ;
        const string MyFont             = "MyFont"              ;
        const string PinkGradientBrush  = "PinkGradientBrush"   ;
        const string SkyBrush           = "SkyBrush"            ;

        const string TransfromPrefix = "00_Transform_";
        const string SkyPrefix      = "10_Sky_"      ;
        const string ImagePrefix    = "20_Image_"    ;
        const string RasterPrefix   = "30_Raster_"   ;
        const string BallPrefix     = "40_Ball_"     ;
        const string TextPrefix     = "50_Text_"     ;

        [STAThread]
        static void Main (string[] args)
        {
            Environment.CurrentDirectory = AppDomain.CurrentDomain.BaseDirectory;
            var bytes = File.ReadAllBytes (@".\bitmap.png");

            using (var session = new Session ())
            {
                session.Set_Window (width:640, height:480, color:"#000", showFPS:true, title:"Mårten Rånge 2012");

                session.New_LinearGradientBrush (
                    PinkGradientBrush,
                    relativeCoordinates:false,
                    endX:0,
                    endY:480
                    );
                session.Add_GradientStop (PinkGradientBrush  , offset: 0      , color: "#414");
                session.Add_GradientStop (PinkGradientBrush  , offset: 0.4F   , color: "#F3F");
                session.Add_GradientStop (PinkGradientBrush  , offset: 0.5F   , color: "#FFF");
                session.Add_GradientStop (PinkGradientBrush  , offset: 0.6F   , color: "#F3F");
                session.Add_GradientStop (PinkGradientBrush  , offset: 1      , color: "#414");

                session.New_LinearGradientBrush (
                    SkyBrush
                    );
                session.Add_GradientStop (SkyBrush   , offset: 1.0F  , color: "#354B84"  );
                session.Add_GradientStop (SkyBrush   , offset: 0.3F  , color: "#C4D3F7"  );
                session.Add_GradientStop (SkyBrush   , offset: 0.0F  , color: "#EEE"     );

                session.New_FontResource (MyFont, "Calibri", 80);

                session.New_BitmapResourceFromBytes (MyBitmap, bytes:bytes);
                //session.New_BitmapResourceFromFileName (MyBitmap);
                //session.New_BitmapResourceFromUrl (MyBitmap);

                session.New_RadialGradientBrush (
                    MyBrush,
                    offsetX:-0.25F,
                    offsetY:-0.25F
                    );
                session.Add_GradientStop (MyBrush, offset: 0, color:"#FFF");
                session.Add_GradientStop (MyBrush, offset: 0.5F, color: "#88E");
                session.Add_GradientStop (MyBrush, offset: 1, color: "#224");

                session.New_FilledRectangle (SkyPrefix + "0", SkyBrush, 0, 0, 640, 480);

                var images = Enumerable
                    .Range (0, 5)
                    .Select (x => ImagePrefix + x.ToString ("000"))
                    .ToArray ();

                var objects = Enumerable
                    .Range (0, 20)
                    .Select (x => BallPrefix + x.ToString ("000"))
                    .ToArray ();

                var rasters_spec =
                    new[]
                        {
                            "#FF0",
                            "#F0F",
                            "#0FF",
                            "#00F",
                            "#0F0",
                            "#F00",
                        };

                var minOpacity = 0.2F;
                var maxOpacity = 1F;

                for (int index = 0; index < images.Length; index++)
                {
                    var img = images[index];
                    var opacity = (minOpacity + ((maxOpacity - minOpacity)*index)/(images.Length - 1));
                    session.New_Bitmap (img, MyBitmap, x:0, y:0, opacity:opacity);
                }

                foreach (var obj in objects)
                {
                    session.New_FilledEllipse (obj, MyBrush, 0, 0, 80, 80);                    
                }

                var rasters = rasters_spec
                    .Select ((raster_spec, index) =>
                                {
                                    var  name = RasterPrefix + index.ToString ("000") + "_" + raster_spec;
                                    session.New_LinearGradientBrush (name);
                                    session.Add_GradientStop (name, offset: 0        , color: "#222"     );
                                    session.Add_GradientStop (name, offset: 0.5F     , color: raster_spec);
                                    session.Add_GradientStop (name, offset: 1        , color: "#222"     );

                                    var opacity = (minOpacity + ((maxOpacity - minOpacity) * index) / (rasters_spec.Length - 1));
                                    session.New_FilledRectangle (name, name, 0, 0, 640, 37, opacity);

                                    return name;
                                })
                    .ToArray ()
                    ;

                session.New_Text (
                    TextPrefix + "0",
                    PinkGradientBrush,
                    MyFont,
                    "Interactive Graphics",
                    width:800,
                    height:64
                    );

                var then = DateTime.Now;

                while (!Console.KeyAvailable)
                {
                    var diff = DateTime.Now - then;
                    var iter = diff.TotalSeconds;

                    var phase = 0.0;

                    phase = Math.PI * iter / 10.0;

                    session.New_ScaleTransform (
                            TransfromPrefix + "000"
                        ,   scaleX:(float) (1.2 + 0.2 * Math.Sin (phase))
                        ,   scaleY:(float) (1.2 + 0.2* Math.Cos (1.7 * phase))
                        ,   centerX:320
                        ,   centerY:240
                        );

                    phase = Math.PI * iter / 5.0;

                    foreach (var img in images)
                    {
                        session.Set_Object (
                            img,
                            y: (float)(Math.Cos (phase) * 100 - 200)
                            );

                        phase += 0.4;
                    }

                    phase = Math.PI * iter / 2;

                    for (int index = 0; index < objects.Length; index++)
                    {
                        var obj = objects[index];
                        session.Set_Object (
                            obj,
                            x: (float)(320 + (Math.Sin (2.7 * phase) * 150) * (10.0 + index) / (10.0 + objects.Length)),
                            y: (float)(200 + (Math.Cos (phase) * 150) * (10.0 + index) / (10.0 + objects.Length))
                            );

                        phase += 0.2;
                    }

                    phase = Math.PI * iter / 1.0;

                    foreach (var raster in rasters)
                    {
                        session.Set_Object (
                            raster,
                            y: (float) (200 + Math.Cos (phase)*100)
                            );

                        phase += 0.3;
                    }

                    phase = Math.PI * iter / 3.0;

                    session.Set_Object (
                        TextPrefix + "0",
                        x: (float)(Math.Sin (phase) * 100),
                        y: (float)(200 + Math.Cos (3.3*phase) * 200)
                        );

                    session.Wait_StateIsPresented ();
                }

            }
        }
    }
}
