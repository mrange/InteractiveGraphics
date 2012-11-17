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








// ReSharper disable ConvertToAutoProperty
// ReSharper disable InconsistentNaming
// ReSharper disable RedundantDefaultFieldInitializer

namespace InteractiveGraphics.Lib
{
    using System;

    enum MessageId : byte
    {
        Set_Window = 1,
        Wait_StateIsPresented = 2,
        Clear_State = 3,
        Remove_Object = 4,
        Remove_Resource = 5,
        New_SolidBrush = 6,
        New_LinearGradientBrush = 7,
        New_RadialGradientBrush = 8,
        Add_GradientStop = 9,
        Clear_GradientStops = 10,
        New_BitmapResourceFromBytes = 11,
        New_FontResource = 12,
        Set_Object = 13,
        New_Line = 14,
        New_Ellipse = 15,
        New_Rectangle = 16,
        New_RoundedRectangle = 17,
        New_FilledEllipse = 18,
        New_FilledRectangle = 19,
        New_FilledRoundedRectangle = 20,
        New_Bitmap = 21,
        New_Text = 22,
        Clear_Transform = 23,
        New_RotateTransform = 24,
        New_TranslateTransform = 25,
        New_ScaleTransform = 26,
        New_SkewTransform = 27,
    }

    public sealed class CommandDescription
    {
        public string Verb;
        public string Noun;
        public string ShortDescription;
    }

    sealed partial class Session
    {
        partial void Partial_OnException (string methodName, Exception exc);

        void OnException (string methodName, Exception exc)
        {
            Partial_OnException (methodName, exc);
        }


        public static CommandDescription[] GetCommandDescriptions ()
        {
            return new []
                {
                    new CommandDescription
                        {
                            Verb                = "Set",
                            Noun                = "Window",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Set_Window,
                        },
                    new CommandDescription
                        {
                            Verb                = "Wait",
                            Noun                = "StateIsPresented",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Wait_StateIsPresented,
                        },
                    new CommandDescription
                        {
                            Verb                = "Clear",
                            Noun                = "State",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Clear_State,
                        },
                    new CommandDescription
                        {
                            Verb                = "Remove",
                            Noun                = "Object",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Remove_Object,
                        },
                    new CommandDescription
                        {
                            Verb                = "Remove",
                            Noun                = "Resource",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Remove_Resource,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "SolidBrush",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_SolidBrush,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "LinearGradientBrush",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_LinearGradientBrush,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "RadialGradientBrush",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_RadialGradientBrush,
                        },
                    new CommandDescription
                        {
                            Verb                = "Add",
                            Noun                = "GradientStop",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Add_GradientStop,
                        },
                    new CommandDescription
                        {
                            Verb                = "Clear",
                            Noun                = "GradientStops",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Clear_GradientStops,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "BitmapResourceFromBytes",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_BitmapResourceFromBytes,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "BitmapResourceFromUrl",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_BitmapResourceFromUrl,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "BitmapResourceFromFileName",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_BitmapResourceFromFileName,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "FontResource",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_FontResource,
                        },
                    new CommandDescription
                        {
                            Verb                = "Set",
                            Noun                = "Object",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Set_Object,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "Line",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_Line,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "Ellipse",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_Ellipse,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "Rectangle",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_Rectangle,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "RoundedRectangle",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_RoundedRectangle,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "FilledEllipse",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_FilledEllipse,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "FilledRectangle",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_FilledRectangle,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "FilledRoundedRectangle",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_FilledRoundedRectangle,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "Bitmap",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_Bitmap,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "Text",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_Text,
                        },
                    new CommandDescription
                        {
                            Verb                = "Clear",
                            Noun                = "Transform",
                            ShortDescription    = Constants.CmdLet.ShortDescription.Clear_Transform,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "RotateTransform",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_RotateTransform,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "TranslateTransform",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_TranslateTransform,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "ScaleTransform",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_ScaleTransform,
                        },
                    new CommandDescription
                        {
                            Verb                = "New",
                            Noun                = "SkewTransform",
                            ShortDescription    = Constants.CmdLet.ShortDescription.New_SkewTransform,
                        },
                    
                };
        }
        // --------------------------------------------------------------------
        //  Set_Window method
        // --------------------------------------------------------------------
        public void Set_Window (
                int? x  = null
            ,   int? y  = null
            ,   int? width  = null
            ,   int? height  = null
            ,   bool clientSize  = true
            ,   bool? showWindow  = null
            ,   bool? showFPS  = null
            ,   string color  = null
            ,   string title  = null
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Set_Window);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("ClientSize", clientSize);
            messageSerializer.Add ("ShowWindow", showWindow);
            messageSerializer.Add ("ShowFPS", showFPS);
            messageSerializer.Add ("Color", color);
            messageSerializer.Add ("Title", title);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Wait_StateIsPresented method
        // --------------------------------------------------------------------
        public void Wait_StateIsPresented (
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Wait_StateIsPresented);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Clear_State method
        // --------------------------------------------------------------------
        public void Clear_State (
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Clear_State);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Remove_Object method
        // --------------------------------------------------------------------
        public void Remove_Object (
                string nameOfObject  = Constants.Empty
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Remove_Object);
            messageSerializer.Add ("NameOfObject", nameOfObject);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Remove_Resource method
        // --------------------------------------------------------------------
        public void Remove_Resource (
                string nameOfResource  = Constants.Empty
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Remove_Resource);
            messageSerializer.Add ("NameOfResource", nameOfResource);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_SolidBrush method
        // --------------------------------------------------------------------
        public void New_SolidBrush (
                string nameOfBrush  = Constants.Empty
            ,   string color  = Constants.White
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_SolidBrush);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("Color", color);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_LinearGradientBrush method
        // --------------------------------------------------------------------
        public void New_LinearGradientBrush (
                string nameOfBrush  = Constants.Empty
            ,   bool relativeCoordinates  = true
            ,   string gamma  = Constants.Gamma
            ,   string extendMode  = Constants.ExtendMode
            ,   float startX  = 0
            ,   float startY  = 0
            ,   float endX  = 0
            ,   float endY  = 1
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_LinearGradientBrush);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("RelativeCoordinates", relativeCoordinates);
            messageSerializer.Add ("Gamma", gamma);
            messageSerializer.Add ("ExtendMode", extendMode);
            messageSerializer.Add ("StartX", startX);
            messageSerializer.Add ("StartY", startY);
            messageSerializer.Add ("EndX", endX);
            messageSerializer.Add ("EndY", endY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_RadialGradientBrush method
        // --------------------------------------------------------------------
        public void New_RadialGradientBrush (
                string nameOfBrush  = Constants.Empty
            ,   bool relativeCoordinates  = true
            ,   string gamma  = Constants.Gamma
            ,   string extendMode  = Constants.ExtendMode
            ,   float centerX  = 0.5F
            ,   float centerY  = 0.5F
            ,   float offsetX  = 0
            ,   float offsetY  = 0
            ,   float radiusX  = 0.5F
            ,   float radiusY  = 0.5F
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_RadialGradientBrush);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("RelativeCoordinates", relativeCoordinates);
            messageSerializer.Add ("Gamma", gamma);
            messageSerializer.Add ("ExtendMode", extendMode);
            messageSerializer.Add ("CenterX", centerX);
            messageSerializer.Add ("CenterY", centerY);
            messageSerializer.Add ("OffsetX", offsetX);
            messageSerializer.Add ("OffsetY", offsetY);
            messageSerializer.Add ("RadiusX", radiusX);
            messageSerializer.Add ("RadiusY", radiusY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Add_GradientStop method
        // --------------------------------------------------------------------
        public void Add_GradientStop (
                string nameOfBrush  = Constants.Empty
            ,   float offset  = 0
            ,   string color  = Constants.White
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Add_GradientStop);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("Offset", offset);
            messageSerializer.Add ("Color", color);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Clear_GradientStops method
        // --------------------------------------------------------------------
        public void Clear_GradientStops (
                string nameOfBrush  = Constants.Empty
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Clear_GradientStops);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_BitmapResourceFromBytes method
        // --------------------------------------------------------------------
        public void New_BitmapResourceFromBytes (
                string nameOfBitmapResource  = Constants.Empty
            ,   byte[] bytes  = null
            ,   int useFrame  = 0
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_BitmapResourceFromBytes);
            messageSerializer.Add ("NameOfBitmapResource", nameOfBitmapResource);
            messageSerializer.Add ("Bytes", bytes);
            messageSerializer.Add ("UseFrame", useFrame);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_BitmapResourceFromUrl method
        // --------------------------------------------------------------------
        public void New_BitmapResourceFromUrl (
                string nameOfBitmapResource  = Constants.Empty
            ,   string imageUrl  = Constants.ImageUrl
            ,   bool loadAsync  = false
            ,   int useFrame  = 0
            )
        {
            try
            {
                Partial_New_BitmapResourceFromUrl (
                        nameOfBitmapResource 
                    ,   imageUrl 
                    ,   loadAsync 
                    ,   useFrame 
                    );
            }
            catch (Exception exc)
            {
                OnException (
                        "New_BitmapResourceFromUrl"
                    ,   exc
                    );
            }

        }
        // --------------------------------------------------------------------
        partial void Partial_New_BitmapResourceFromUrl (
                string nameOfBitmapResource
            ,   string imageUrl
            ,   bool loadAsync
            ,   int useFrame
            );
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_BitmapResourceFromFileName method
        // --------------------------------------------------------------------
        public void New_BitmapResourceFromFileName (
                string nameOfBitmapResource  = Constants.Empty
            ,   string imageFileName  = Constants.ImageFileName
            ,   int useFrame  = 0
            )
        {
            try
            {
                Partial_New_BitmapResourceFromFileName (
                        nameOfBitmapResource 
                    ,   imageFileName 
                    ,   useFrame 
                    );
            }
            catch (Exception exc)
            {
                OnException (
                        "New_BitmapResourceFromFileName"
                    ,   exc
                    );
            }

        }
        // --------------------------------------------------------------------
        partial void Partial_New_BitmapResourceFromFileName (
                string nameOfBitmapResource
            ,   string imageFileName
            ,   int useFrame
            );
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_FontResource method
        // --------------------------------------------------------------------
        public void New_FontResource (
                string nameOfFontResource  = Constants.Empty
            ,   string fontFamily  = Constants.DefaultFont
            ,   float fontSize  = Constants.DefaultFontSize
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_FontResource);
            messageSerializer.Add ("NameOfFontResource", nameOfFontResource);
            messageSerializer.Add ("FontFamily", fontFamily);
            messageSerializer.Add ("FontSize", fontSize);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Set_Object method
        // --------------------------------------------------------------------
        public void Set_Object (
                string nameOfObject  = Constants.Empty
            ,   float? x  = null
            ,   float? y  = null
            ,   float? width  = null
            ,   float? height  = null
            ,   float? opacity  = null
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Set_Object);
            messageSerializer.Add ("NameOfObject", nameOfObject);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_Line method
        // --------------------------------------------------------------------
        public void New_Line (
                string nameOfLine  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float startX  = Constants.StartX
            ,   float startY  = Constants.StartY
            ,   float endX  = Constants.EndX
            ,   float endY  = Constants.EndY
            ,   float opacity  = Constants.Opacity
            ,   float strokeWidth  = Constants.StrokeWidth
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_Line);
            messageSerializer.Add ("NameOfLine", nameOfLine);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("StartX", startX);
            messageSerializer.Add ("StartY", startY);
            messageSerializer.Add ("EndX", endX);
            messageSerializer.Add ("EndY", endY);
            messageSerializer.Add ("Opacity", opacity);
            messageSerializer.Add ("StrokeWidth", strokeWidth);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_Ellipse method
        // --------------------------------------------------------------------
        public void New_Ellipse (
                string nameOfEllipse  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            ,   float strokeWidth  = Constants.StrokeWidth
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_Ellipse);
            messageSerializer.Add ("NameOfEllipse", nameOfEllipse);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            messageSerializer.Add ("StrokeWidth", strokeWidth);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_Rectangle method
        // --------------------------------------------------------------------
        public void New_Rectangle (
                string nameOfRectangle  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            ,   float strokeWidth  = Constants.StrokeWidth
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_Rectangle);
            messageSerializer.Add ("NameOfRectangle", nameOfRectangle);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            messageSerializer.Add ("StrokeWidth", strokeWidth);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_RoundedRectangle method
        // --------------------------------------------------------------------
        public void New_RoundedRectangle (
                string nameOfRectangle  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            ,   float radiusX  = Constants.RadiusX
            ,   float radiusY  = Constants.RadiusY
            ,   float strokeWidth  = Constants.StrokeWidth
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_RoundedRectangle);
            messageSerializer.Add ("NameOfRectangle", nameOfRectangle);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            messageSerializer.Add ("RadiusX", radiusX);
            messageSerializer.Add ("RadiusY", radiusY);
            messageSerializer.Add ("StrokeWidth", strokeWidth);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_FilledEllipse method
        // --------------------------------------------------------------------
        public void New_FilledEllipse (
                string nameOfEllipse  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_FilledEllipse);
            messageSerializer.Add ("NameOfEllipse", nameOfEllipse);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_FilledRectangle method
        // --------------------------------------------------------------------
        public void New_FilledRectangle (
                string nameOfRectangle  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_FilledRectangle);
            messageSerializer.Add ("NameOfRectangle", nameOfRectangle);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_FilledRoundedRectangle method
        // --------------------------------------------------------------------
        public void New_FilledRoundedRectangle (
                string nameOfRectangle  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            ,   float radiusX  = Constants.RadiusX
            ,   float radiusY  = Constants.RadiusY
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_FilledRoundedRectangle);
            messageSerializer.Add ("NameOfRectangle", nameOfRectangle);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            messageSerializer.Add ("RadiusX", radiusX);
            messageSerializer.Add ("RadiusY", radiusY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_Bitmap method
        // --------------------------------------------------------------------
        public void New_Bitmap (
                string nameOfBitmap  = Constants.Empty
            ,   string nameOfBitmapResource  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float? width  = null
            ,   float? height  = null
            ,   float opacity  = Constants.Opacity
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_Bitmap);
            messageSerializer.Add ("NameOfBitmap", nameOfBitmap);
            messageSerializer.Add ("NameOfBitmapResource", nameOfBitmapResource);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_Text method
        // --------------------------------------------------------------------
        public void New_Text (
                string nameOfText  = Constants.Empty
            ,   string nameOfBrush  = Constants.Empty
            ,   string nameOfFontResource  = Constants.Empty
            ,   string text  = Constants.DefaultText
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            ,   float width  = Constants.Width
            ,   float height  = Constants.Height
            ,   float opacity  = Constants.Opacity
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_Text);
            messageSerializer.Add ("NameOfText", nameOfText);
            messageSerializer.Add ("NameOfBrush", nameOfBrush);
            messageSerializer.Add ("NameOfFontResource", nameOfFontResource);
            messageSerializer.Add ("Text", text);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            messageSerializer.Add ("Width", width);
            messageSerializer.Add ("Height", height);
            messageSerializer.Add ("Opacity", opacity);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  Clear_Transform method
        // --------------------------------------------------------------------
        public void Clear_Transform (
                string nameOfTransform  = Constants.Empty
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.Clear_Transform);
            messageSerializer.Add ("NameOfTransform", nameOfTransform);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_RotateTransform method
        // --------------------------------------------------------------------
        public void New_RotateTransform (
                string nameOfTransform  = Constants.Empty
            ,   float angle  = Constants.Angle
            ,   float? centerX  = null
            ,   float? centerY  = null
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_RotateTransform);
            messageSerializer.Add ("NameOfTransform", nameOfTransform);
            messageSerializer.Add ("Angle", angle);
            messageSerializer.Add ("CenterX", centerX);
            messageSerializer.Add ("CenterY", centerY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_TranslateTransform method
        // --------------------------------------------------------------------
        public void New_TranslateTransform (
                string nameOfTransform  = Constants.Empty
            ,   float x  = Constants.X
            ,   float y  = Constants.Y
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_TranslateTransform);
            messageSerializer.Add ("NameOfTransform", nameOfTransform);
            messageSerializer.Add ("X", x);
            messageSerializer.Add ("Y", y);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_ScaleTransform method
        // --------------------------------------------------------------------
        public void New_ScaleTransform (
                string nameOfTransform  = Constants.Empty
            ,   float scaleX  = Constants.ScaleX
            ,   float scaleY  = Constants.ScaleY
            ,   float? centerX  = null
            ,   float? centerY  = null
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_ScaleTransform);
            messageSerializer.Add ("NameOfTransform", nameOfTransform);
            messageSerializer.Add ("ScaleX", scaleX);
            messageSerializer.Add ("ScaleY", scaleY);
            messageSerializer.Add ("CenterX", centerX);
            messageSerializer.Add ("CenterY", centerY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

        // --------------------------------------------------------------------
        //  New_SkewTransform method
        // --------------------------------------------------------------------
        public void New_SkewTransform (
                string nameOfTransform  = Constants.Empty
            ,   float angleX  = Constants.AngleX
            ,   float angleY  = Constants.AngleY
            ,   float? centerX  = null
            ,   float? centerY  = null
            )
        {

            var messageSerializer = new MessageSerializer ();
            messageSerializer.Add ("MessageId", (byte)MessageId.New_SkewTransform);
            messageSerializer.Add ("NameOfTransform", nameOfTransform);
            messageSerializer.Add ("AngleX", angleX);
            messageSerializer.Add ("AngleY", angleY);
            messageSerializer.Add ("CenterX", centerX);
            messageSerializer.Add ("CenterY", centerY);
            SendMessage (messageSerializer);
        }
        // --------------------------------------------------------------------
        // --------------------------------------------------------------------

    }
}

#if !SUPPRESS_POWERSHELL_API

namespace InteractiveGraphics.Lib
{
    using System.Management.Automation;
    [Cmdlet ("Set", "IGWindow")]
    public sealed class Set_IGWindow : Cmdlet
    {

        int? m_x = null;
        [Parameter (
                Mandatory = false
            )]
        public int? X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        int? m_y = null;
        [Parameter (
                Mandatory = false
            )]
        public int? Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        int? m_width = null;
        [Parameter (
                Mandatory = false
            )]
        public int? Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        int? m_height = null;
        [Parameter (
                Mandatory = false
            )]
        public int? Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        bool m_clientSize = true;
        [Parameter (
                Mandatory = false
            )]
        public bool ClientSize 
        { 
            get { return m_clientSize; } 
            set { m_clientSize = value;}
        }


        bool? m_showWindow = null;
        [Parameter (
                Mandatory = false
            )]
        public bool? ShowWindow 
        { 
            get { return m_showWindow; } 
            set { m_showWindow = value;}
        }


        bool? m_showFPS = null;
        [Parameter (
                Mandatory = false
            )]
        public bool? ShowFPS 
        { 
            get { return m_showFPS; } 
            set { m_showFPS = value;}
        }


        string m_color = null;
        [Parameter (
                Mandatory = false
            )]
        public string Color 
        { 
            get { return m_color; } 
            set { m_color = value;}
        }


        string m_title = null;
        [Parameter (
                Mandatory = false
            )]
        public string Title 
        { 
            get { return m_title; } 
            set { m_title = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Set_Window (
                        X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   ClientSize
                    ,   ShowWindow
                    ,   ShowFPS
                    ,   Color
                    ,   Title
                    );
            }
        }
    }
    [Cmdlet ("Wait", "IGStateIsPresented")]
    public sealed class Wait_IGStateIsPresented : Cmdlet
    {

        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Wait_StateIsPresented (
                    );
            }
        }
    }
    [Cmdlet ("Clear", "IGState")]
    public sealed class Clear_IGState : Cmdlet
    {

        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Clear_State (
                    );
            }
        }
    }
    [Cmdlet ("Remove", "IGObject")]
    public sealed class Remove_IGObject : Cmdlet
    {

        string m_nameOfObject = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfObject 
        { 
            get { return m_nameOfObject; } 
            set { m_nameOfObject = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Remove_Object (
                        NameOfObject
                    );
            }
        }
    }
    [Cmdlet ("Remove", "IGResource")]
    public sealed class Remove_IGResource : Cmdlet
    {

        string m_nameOfResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfResource 
        { 
            get { return m_nameOfResource; } 
            set { m_nameOfResource = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Remove_Resource (
                        NameOfResource
                    );
            }
        }
    }
    [Cmdlet ("New", "IGSolidBrush")]
    public sealed class New_IGSolidBrush : Cmdlet
    {

        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        string m_color = Constants.White;
        [Parameter (
                Mandatory = false
            )]
        public string Color 
        { 
            get { return m_color; } 
            set { m_color = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_SolidBrush (
                        NameOfBrush
                    ,   Color
                    );
            }
        }
    }
    [Cmdlet ("New", "IGLinearGradientBrush")]
    public sealed class New_IGLinearGradientBrush : Cmdlet
    {

        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        bool m_relativeCoordinates = true;
        [Parameter (
                Mandatory = false
            )]
        public bool RelativeCoordinates 
        { 
            get { return m_relativeCoordinates; } 
            set { m_relativeCoordinates = value;}
        }


        string m_gamma = Constants.Gamma;
        [Parameter (
                Mandatory = false
            )]
        public string Gamma 
        { 
            get { return m_gamma; } 
            set { m_gamma = value;}
        }


        string m_extendMode = Constants.ExtendMode;
        [Parameter (
                Mandatory = false
            )]
        public string ExtendMode 
        { 
            get { return m_extendMode; } 
            set { m_extendMode = value;}
        }


        float m_startX = 0;
        [Parameter (
                Mandatory = false
            )]
        public float StartX 
        { 
            get { return m_startX; } 
            set { m_startX = value;}
        }


        float m_startY = 0;
        [Parameter (
                Mandatory = false
            )]
        public float StartY 
        { 
            get { return m_startY; } 
            set { m_startY = value;}
        }


        float m_endX = 0;
        [Parameter (
                Mandatory = false
            )]
        public float EndX 
        { 
            get { return m_endX; } 
            set { m_endX = value;}
        }


        float m_endY = 1;
        [Parameter (
                Mandatory = false
            )]
        public float EndY 
        { 
            get { return m_endY; } 
            set { m_endY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_LinearGradientBrush (
                        NameOfBrush
                    ,   RelativeCoordinates
                    ,   Gamma
                    ,   ExtendMode
                    ,   StartX
                    ,   StartY
                    ,   EndX
                    ,   EndY
                    );
            }
        }
    }
    [Cmdlet ("New", "IGRadialGradientBrush")]
    public sealed class New_IGRadialGradientBrush : Cmdlet
    {

        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        bool m_relativeCoordinates = true;
        [Parameter (
                Mandatory = false
            )]
        public bool RelativeCoordinates 
        { 
            get { return m_relativeCoordinates; } 
            set { m_relativeCoordinates = value;}
        }


        string m_gamma = Constants.Gamma;
        [Parameter (
                Mandatory = false
            )]
        public string Gamma 
        { 
            get { return m_gamma; } 
            set { m_gamma = value;}
        }


        string m_extendMode = Constants.ExtendMode;
        [Parameter (
                Mandatory = false
            )]
        public string ExtendMode 
        { 
            get { return m_extendMode; } 
            set { m_extendMode = value;}
        }


        float m_centerX = 0.5F;
        [Parameter (
                Mandatory = false
            )]
        public float CenterX 
        { 
            get { return m_centerX; } 
            set { m_centerX = value;}
        }


        float m_centerY = 0.5F;
        [Parameter (
                Mandatory = false
            )]
        public float CenterY 
        { 
            get { return m_centerY; } 
            set { m_centerY = value;}
        }


        float m_offsetX = 0;
        [Parameter (
                Mandatory = false
            )]
        public float OffsetX 
        { 
            get { return m_offsetX; } 
            set { m_offsetX = value;}
        }


        float m_offsetY = 0;
        [Parameter (
                Mandatory = false
            )]
        public float OffsetY 
        { 
            get { return m_offsetY; } 
            set { m_offsetY = value;}
        }


        float m_radiusX = 0.5F;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusX 
        { 
            get { return m_radiusX; } 
            set { m_radiusX = value;}
        }


        float m_radiusY = 0.5F;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusY 
        { 
            get { return m_radiusY; } 
            set { m_radiusY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_RadialGradientBrush (
                        NameOfBrush
                    ,   RelativeCoordinates
                    ,   Gamma
                    ,   ExtendMode
                    ,   CenterX
                    ,   CenterY
                    ,   OffsetX
                    ,   OffsetY
                    ,   RadiusX
                    ,   RadiusY
                    );
            }
        }
    }
    [Cmdlet ("Add", "IGGradientStop")]
    public sealed class Add_IGGradientStop : Cmdlet
    {

        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_offset = 0;
        [Parameter (
                Mandatory = false
            )]
        public float Offset 
        { 
            get { return m_offset; } 
            set { m_offset = value;}
        }


        string m_color = Constants.White;
        [Parameter (
                Mandatory = false
            )]
        public string Color 
        { 
            get { return m_color; } 
            set { m_color = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Add_GradientStop (
                        NameOfBrush
                    ,   Offset
                    ,   Color
                    );
            }
        }
    }
    [Cmdlet ("Clear", "IGGradientStops")]
    public sealed class Clear_IGGradientStops : Cmdlet
    {

        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Clear_GradientStops (
                        NameOfBrush
                    );
            }
        }
    }
    [Cmdlet ("New", "IGBitmapResourceFromBytes")]
    public sealed class New_IGBitmapResourceFromBytes : Cmdlet
    {

        string m_nameOfBitmapResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBitmapResource 
        { 
            get { return m_nameOfBitmapResource; } 
            set { m_nameOfBitmapResource = value;}
        }


        byte[] m_bytes = null;
        [Parameter (
                Mandatory = false
            )]
        public byte[] Bytes 
        { 
            get { return m_bytes; } 
            set { m_bytes = value;}
        }


        int m_useFrame = 0;
        [Parameter (
                Mandatory = false
            )]
        public int UseFrame 
        { 
            get { return m_useFrame; } 
            set { m_useFrame = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_BitmapResourceFromBytes (
                        NameOfBitmapResource
                    ,   Bytes
                    ,   UseFrame
                    );
            }
        }
    }
    [Cmdlet ("New", "IGBitmapResourceFromUrl")]
    public sealed class New_IGBitmapResourceFromUrl : Cmdlet
    {

        string m_nameOfBitmapResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBitmapResource 
        { 
            get { return m_nameOfBitmapResource; } 
            set { m_nameOfBitmapResource = value;}
        }


        string m_imageUrl = Constants.ImageUrl;
        [Parameter (
                Mandatory = false
            )]
        public string ImageUrl 
        { 
            get { return m_imageUrl; } 
            set { m_imageUrl = value;}
        }


        bool m_loadAsync = false;
        [Parameter (
                Mandatory = false
            )]
        public bool LoadAsync 
        { 
            get { return m_loadAsync; } 
            set { m_loadAsync = value;}
        }


        int m_useFrame = 0;
        [Parameter (
                Mandatory = false
            )]
        public int UseFrame 
        { 
            get { return m_useFrame; } 
            set { m_useFrame = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_BitmapResourceFromUrl (
                        NameOfBitmapResource
                    ,   ImageUrl
                    ,   LoadAsync
                    ,   UseFrame
                    );
            }
        }
    }
    [Cmdlet ("New", "IGBitmapResourceFromFileName")]
    public sealed class New_IGBitmapResourceFromFileName : Cmdlet
    {

        string m_nameOfBitmapResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBitmapResource 
        { 
            get { return m_nameOfBitmapResource; } 
            set { m_nameOfBitmapResource = value;}
        }


        string m_imageFileName = Constants.ImageFileName;
        [Parameter (
                Mandatory = false
            )]
        public string ImageFileName 
        { 
            get { return m_imageFileName; } 
            set { m_imageFileName = value;}
        }


        int m_useFrame = 0;
        [Parameter (
                Mandatory = false
            )]
        public int UseFrame 
        { 
            get { return m_useFrame; } 
            set { m_useFrame = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_BitmapResourceFromFileName (
                        NameOfBitmapResource
                    ,   ImageFileName
                    ,   UseFrame
                    );
            }
        }
    }
    [Cmdlet ("New", "IGFontResource")]
    public sealed class New_IGFontResource : Cmdlet
    {

        string m_nameOfFontResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfFontResource 
        { 
            get { return m_nameOfFontResource; } 
            set { m_nameOfFontResource = value;}
        }


        string m_fontFamily = Constants.DefaultFont;
        [Parameter (
                Mandatory = false
            )]
        public string FontFamily 
        { 
            get { return m_fontFamily; } 
            set { m_fontFamily = value;}
        }


        float m_fontSize = Constants.DefaultFontSize;
        [Parameter (
                Mandatory = false
            )]
        public float FontSize 
        { 
            get { return m_fontSize; } 
            set { m_fontSize = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_FontResource (
                        NameOfFontResource
                    ,   FontFamily
                    ,   FontSize
                    );
            }
        }
    }
    [Cmdlet ("Set", "IGObject")]
    public sealed class Set_IGObject : Cmdlet
    {

        string m_nameOfObject = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfObject 
        { 
            get { return m_nameOfObject; } 
            set { m_nameOfObject = value;}
        }


        float? m_x = null;
        [Parameter (
                Mandatory = false
            )]
        public float? X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float? m_y = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float? m_width = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float? m_height = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float? m_opacity = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Set_Object (
                        NameOfObject
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    );
            }
        }
    }
    [Cmdlet ("New", "IGLine")]
    public sealed class New_IGLine : Cmdlet
    {

        string m_nameOfLine = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfLine 
        { 
            get { return m_nameOfLine; } 
            set { m_nameOfLine = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_startX = Constants.StartX;
        [Parameter (
                Mandatory = false
            )]
        public float StartX 
        { 
            get { return m_startX; } 
            set { m_startX = value;}
        }


        float m_startY = Constants.StartY;
        [Parameter (
                Mandatory = false
            )]
        public float StartY 
        { 
            get { return m_startY; } 
            set { m_startY = value;}
        }


        float m_endX = Constants.EndX;
        [Parameter (
                Mandatory = false
            )]
        public float EndX 
        { 
            get { return m_endX; } 
            set { m_endX = value;}
        }


        float m_endY = Constants.EndY;
        [Parameter (
                Mandatory = false
            )]
        public float EndY 
        { 
            get { return m_endY; } 
            set { m_endY = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        float m_strokeWidth = Constants.StrokeWidth;
        [Parameter (
                Mandatory = false
            )]
        public float StrokeWidth 
        { 
            get { return m_strokeWidth; } 
            set { m_strokeWidth = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_Line (
                        NameOfLine
                    ,   NameOfBrush
                    ,   StartX
                    ,   StartY
                    ,   EndX
                    ,   EndY
                    ,   Opacity
                    ,   StrokeWidth
                    );
            }
        }
    }
    [Cmdlet ("New", "IGEllipse")]
    public sealed class New_IGEllipse : Cmdlet
    {

        string m_nameOfEllipse = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfEllipse 
        { 
            get { return m_nameOfEllipse; } 
            set { m_nameOfEllipse = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        float m_strokeWidth = Constants.StrokeWidth;
        [Parameter (
                Mandatory = false
            )]
        public float StrokeWidth 
        { 
            get { return m_strokeWidth; } 
            set { m_strokeWidth = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_Ellipse (
                        NameOfEllipse
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    ,   StrokeWidth
                    );
            }
        }
    }
    [Cmdlet ("New", "IGRectangle")]
    public sealed class New_IGRectangle : Cmdlet
    {

        string m_nameOfRectangle = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfRectangle 
        { 
            get { return m_nameOfRectangle; } 
            set { m_nameOfRectangle = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        float m_strokeWidth = Constants.StrokeWidth;
        [Parameter (
                Mandatory = false
            )]
        public float StrokeWidth 
        { 
            get { return m_strokeWidth; } 
            set { m_strokeWidth = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_Rectangle (
                        NameOfRectangle
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    ,   StrokeWidth
                    );
            }
        }
    }
    [Cmdlet ("New", "IGRoundedRectangle")]
    public sealed class New_IGRoundedRectangle : Cmdlet
    {

        string m_nameOfRectangle = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfRectangle 
        { 
            get { return m_nameOfRectangle; } 
            set { m_nameOfRectangle = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        float m_radiusX = Constants.RadiusX;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusX 
        { 
            get { return m_radiusX; } 
            set { m_radiusX = value;}
        }


        float m_radiusY = Constants.RadiusY;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusY 
        { 
            get { return m_radiusY; } 
            set { m_radiusY = value;}
        }


        float m_strokeWidth = Constants.StrokeWidth;
        [Parameter (
                Mandatory = false
            )]
        public float StrokeWidth 
        { 
            get { return m_strokeWidth; } 
            set { m_strokeWidth = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_RoundedRectangle (
                        NameOfRectangle
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    ,   RadiusX
                    ,   RadiusY
                    ,   StrokeWidth
                    );
            }
        }
    }
    [Cmdlet ("New", "IGFilledEllipse")]
    public sealed class New_IGFilledEllipse : Cmdlet
    {

        string m_nameOfEllipse = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfEllipse 
        { 
            get { return m_nameOfEllipse; } 
            set { m_nameOfEllipse = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_FilledEllipse (
                        NameOfEllipse
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    );
            }
        }
    }
    [Cmdlet ("New", "IGFilledRectangle")]
    public sealed class New_IGFilledRectangle : Cmdlet
    {

        string m_nameOfRectangle = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfRectangle 
        { 
            get { return m_nameOfRectangle; } 
            set { m_nameOfRectangle = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_FilledRectangle (
                        NameOfRectangle
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    );
            }
        }
    }
    [Cmdlet ("New", "IGFilledRoundedRectangle")]
    public sealed class New_IGFilledRoundedRectangle : Cmdlet
    {

        string m_nameOfRectangle = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfRectangle 
        { 
            get { return m_nameOfRectangle; } 
            set { m_nameOfRectangle = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        float m_radiusX = Constants.RadiusX;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusX 
        { 
            get { return m_radiusX; } 
            set { m_radiusX = value;}
        }


        float m_radiusY = Constants.RadiusY;
        [Parameter (
                Mandatory = false
            )]
        public float RadiusY 
        { 
            get { return m_radiusY; } 
            set { m_radiusY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_FilledRoundedRectangle (
                        NameOfRectangle
                    ,   NameOfBrush
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    ,   RadiusX
                    ,   RadiusY
                    );
            }
        }
    }
    [Cmdlet ("New", "IGBitmap")]
    public sealed class New_IGBitmap : Cmdlet
    {

        string m_nameOfBitmap = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfBitmap 
        { 
            get { return m_nameOfBitmap; } 
            set { m_nameOfBitmap = value;}
        }


        string m_nameOfBitmapResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBitmapResource 
        { 
            get { return m_nameOfBitmapResource; } 
            set { m_nameOfBitmapResource = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float? m_width = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float? m_height = null;
        [Parameter (
                Mandatory = false
            )]
        public float? Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_Bitmap (
                        NameOfBitmap
                    ,   NameOfBitmapResource
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    );
            }
        }
    }
    [Cmdlet ("New", "IGText")]
    public sealed class New_IGText : Cmdlet
    {

        string m_nameOfText = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfText 
        { 
            get { return m_nameOfText; } 
            set { m_nameOfText = value;}
        }


        string m_nameOfBrush = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfBrush 
        { 
            get { return m_nameOfBrush; } 
            set { m_nameOfBrush = value;}
        }


        string m_nameOfFontResource = Constants.Empty;
        [Parameter (
                Mandatory = false
            )]
        public string NameOfFontResource 
        { 
            get { return m_nameOfFontResource; } 
            set { m_nameOfFontResource = value;}
        }


        string m_text = Constants.DefaultText;
        [Parameter (
                Mandatory = false
            )]
        public string Text 
        { 
            get { return m_text; } 
            set { m_text = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        float m_width = Constants.Width;
        [Parameter (
                Mandatory = false
            )]
        public float Width 
        { 
            get { return m_width; } 
            set { m_width = value;}
        }


        float m_height = Constants.Height;
        [Parameter (
                Mandatory = false
            )]
        public float Height 
        { 
            get { return m_height; } 
            set { m_height = value;}
        }


        float m_opacity = Constants.Opacity;
        [Parameter (
                Mandatory = false
            )]
        public float Opacity 
        { 
            get { return m_opacity; } 
            set { m_opacity = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_Text (
                        NameOfText
                    ,   NameOfBrush
                    ,   NameOfFontResource
                    ,   Text
                    ,   X
                    ,   Y
                    ,   Width
                    ,   Height
                    ,   Opacity
                    );
            }
        }
    }
    [Cmdlet ("Clear", "IGTransform")]
    public sealed class Clear_IGTransform : Cmdlet
    {

        string m_nameOfTransform = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfTransform 
        { 
            get { return m_nameOfTransform; } 
            set { m_nameOfTransform = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.Clear_Transform (
                        NameOfTransform
                    );
            }
        }
    }
    [Cmdlet ("New", "IGRotateTransform")]
    public sealed class New_IGRotateTransform : Cmdlet
    {

        string m_nameOfTransform = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfTransform 
        { 
            get { return m_nameOfTransform; } 
            set { m_nameOfTransform = value;}
        }


        float m_angle = Constants.Angle;
        [Parameter (
                Mandatory = false
            )]
        public float Angle 
        { 
            get { return m_angle; } 
            set { m_angle = value;}
        }


        float? m_centerX = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterX 
        { 
            get { return m_centerX; } 
            set { m_centerX = value;}
        }


        float? m_centerY = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterY 
        { 
            get { return m_centerY; } 
            set { m_centerY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_RotateTransform (
                        NameOfTransform
                    ,   Angle
                    ,   CenterX
                    ,   CenterY
                    );
            }
        }
    }
    [Cmdlet ("New", "IGTranslateTransform")]
    public sealed class New_IGTranslateTransform : Cmdlet
    {

        string m_nameOfTransform = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfTransform 
        { 
            get { return m_nameOfTransform; } 
            set { m_nameOfTransform = value;}
        }


        float m_x = Constants.X;
        [Parameter (
                Mandatory = false
            )]
        public float X 
        { 
            get { return m_x; } 
            set { m_x = value;}
        }


        float m_y = Constants.Y;
        [Parameter (
                Mandatory = false
            )]
        public float Y 
        { 
            get { return m_y; } 
            set { m_y = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_TranslateTransform (
                        NameOfTransform
                    ,   X
                    ,   Y
                    );
            }
        }
    }
    [Cmdlet ("New", "IGScaleTransform")]
    public sealed class New_IGScaleTransform : Cmdlet
    {

        string m_nameOfTransform = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfTransform 
        { 
            get { return m_nameOfTransform; } 
            set { m_nameOfTransform = value;}
        }


        float m_scaleX = Constants.ScaleX;
        [Parameter (
                Mandatory = false
            )]
        public float ScaleX 
        { 
            get { return m_scaleX; } 
            set { m_scaleX = value;}
        }


        float m_scaleY = Constants.ScaleY;
        [Parameter (
                Mandatory = false
            )]
        public float ScaleY 
        { 
            get { return m_scaleY; } 
            set { m_scaleY = value;}
        }


        float? m_centerX = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterX 
        { 
            get { return m_centerX; } 
            set { m_centerX = value;}
        }


        float? m_centerY = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterY 
        { 
            get { return m_centerY; } 
            set { m_centerY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_ScaleTransform (
                        NameOfTransform
                    ,   ScaleX
                    ,   ScaleY
                    ,   CenterX
                    ,   CenterY
                    );
            }
        }
    }
    [Cmdlet ("New", "IGSkewTransform")]
    public sealed class New_IGSkewTransform : Cmdlet
    {

        string m_nameOfTransform = Constants.Empty;
        [Parameter (
                Mandatory = false
            ,   Position = 0
            )]
        public string NameOfTransform 
        { 
            get { return m_nameOfTransform; } 
            set { m_nameOfTransform = value;}
        }


        float m_angleX = Constants.AngleX;
        [Parameter (
                Mandatory = false
            )]
        public float AngleX 
        { 
            get { return m_angleX; } 
            set { m_angleX = value;}
        }


        float m_angleY = Constants.AngleY;
        [Parameter (
                Mandatory = false
            )]
        public float AngleY 
        { 
            get { return m_angleY; } 
            set { m_angleY = value;}
        }


        float? m_centerX = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterX 
        { 
            get { return m_centerX; } 
            set { m_centerX = value;}
        }


        float? m_centerY = null;
        [Parameter (
                Mandatory = false
            )]
        public float? CenterY 
        { 
            get { return m_centerY; } 
            set { m_centerY = value;}
        }


        protected override void EndProcessing ()
        {
            var session = SessionHolder.Session;
            if (session != null)
            {
                session.New_SkewTransform (
                        NameOfTransform
                    ,   AngleX
                    ,   AngleY
                    ,   CenterX
                    ,   CenterY
                    );
            }
        }
    }
}

#endif


#if !SUPPRESS_SMALLBASIC_API

namespace InteractiveGraphics.Lib
{
    using Microsoft.SmallBasic.Library;

    public static partial class FastGraphics
    {
        public static Primitive Set_Window (
                Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive clientSize
            ,   Primitive showWindow
            ,   Primitive showFPS
            ,   Primitive color
            ,   Primitive title
            )
        {
            if (Session != null)
            {
                Session.Set_Window (
                        x
                    ,   y
                    ,   width
                    ,   height
                    ,   clientSize
                    ,   showWindow
                    ,   showFPS
                    ,   color
                    ,   title
                    );
            }

            return true;
        }

        public static Primitive Wait_StateIsPresented (
            )
        {
            if (Session != null)
            {
                Session.Wait_StateIsPresented (
                    );
            }

            return true;
        }

        public static Primitive Clear_State (
            )
        {
            if (Session != null)
            {
                Session.Clear_State (
                    );
            }

            return true;
        }

        public static Primitive Remove_Object (
                Primitive nameOfObject
            )
        {
            if (Session != null)
            {
                Session.Remove_Object (
                        nameOfObject
                    );
            }

            return true;
        }

        public static Primitive Remove_Resource (
                Primitive nameOfResource
            )
        {
            if (Session != null)
            {
                Session.Remove_Resource (
                        nameOfResource
                    );
            }

            return true;
        }

        public static Primitive New_SolidBrush (
                Primitive nameOfBrush
            ,   Primitive color
            )
        {
            if (Session != null)
            {
                Session.New_SolidBrush (
                        nameOfBrush
                    ,   color
                    );
            }

            return true;
        }

        public static Primitive New_LinearGradientBrush (
                Primitive nameOfBrush
            ,   Primitive relativeCoordinates
            ,   Primitive gamma
            ,   Primitive extendMode
            ,   Primitive startX
            ,   Primitive startY
            ,   Primitive endX
            ,   Primitive endY
            )
        {
            if (Session != null)
            {
                Session.New_LinearGradientBrush (
                        nameOfBrush
                    ,   relativeCoordinates
                    ,   gamma
                    ,   extendMode
                    ,   startX
                    ,   startY
                    ,   endX
                    ,   endY
                    );
            }

            return true;
        }

        public static Primitive New_RadialGradientBrush (
                Primitive nameOfBrush
            ,   Primitive relativeCoordinates
            ,   Primitive gamma
            ,   Primitive extendMode
            ,   Primitive centerX
            ,   Primitive centerY
            ,   Primitive offsetX
            ,   Primitive offsetY
            ,   Primitive radiusX
            ,   Primitive radiusY
            )
        {
            if (Session != null)
            {
                Session.New_RadialGradientBrush (
                        nameOfBrush
                    ,   relativeCoordinates
                    ,   gamma
                    ,   extendMode
                    ,   centerX
                    ,   centerY
                    ,   offsetX
                    ,   offsetY
                    ,   radiusX
                    ,   radiusY
                    );
            }

            return true;
        }

        public static Primitive Add_GradientStop (
                Primitive nameOfBrush
            ,   Primitive offset
            ,   Primitive color
            )
        {
            if (Session != null)
            {
                Session.Add_GradientStop (
                        nameOfBrush
                    ,   offset
                    ,   color
                    );
            }

            return true;
        }

        public static Primitive Clear_GradientStops (
                Primitive nameOfBrush
            )
        {
            if (Session != null)
            {
                Session.Clear_GradientStops (
                        nameOfBrush
                    );
            }

            return true;
        }

        public static Primitive New_BitmapResourceFromUrl (
                Primitive nameOfBitmapResource
            ,   Primitive imageUrl
            ,   Primitive loadAsync
            ,   Primitive useFrame
            )
        {
            if (Session != null)
            {
                Session.New_BitmapResourceFromUrl (
                        nameOfBitmapResource
                    ,   imageUrl
                    ,   loadAsync
                    ,   useFrame
                    );
            }

            return true;
        }

        public static Primitive New_BitmapResourceFromFileName (
                Primitive nameOfBitmapResource
            ,   Primitive imageFileName
            ,   Primitive useFrame
            )
        {
            if (Session != null)
            {
                Session.New_BitmapResourceFromFileName (
                        nameOfBitmapResource
                    ,   imageFileName
                    ,   useFrame
                    );
            }

            return true;
        }

        public static Primitive New_FontResource (
                Primitive nameOfFontResource
            ,   Primitive fontFamily
            ,   Primitive fontSize
            )
        {
            if (Session != null)
            {
                Session.New_FontResource (
                        nameOfFontResource
                    ,   fontFamily
                    ,   fontSize
                    );
            }

            return true;
        }

        public static Primitive Set_Object (
                Primitive nameOfObject
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            )
        {
            if (Session != null)
            {
                Session.Set_Object (
                        nameOfObject
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    );
            }

            return true;
        }

        public static Primitive New_Line (
                Primitive nameOfLine
            ,   Primitive nameOfBrush
            ,   Primitive startX
            ,   Primitive startY
            ,   Primitive endX
            ,   Primitive endY
            ,   Primitive opacity
            ,   Primitive strokeWidth
            )
        {
            if (Session != null)
            {
                Session.New_Line (
                        nameOfLine
                    ,   nameOfBrush
                    ,   startX
                    ,   startY
                    ,   endX
                    ,   endY
                    ,   opacity
                    ,   strokeWidth
                    );
            }

            return true;
        }

        public static Primitive New_Ellipse (
                Primitive nameOfEllipse
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            ,   Primitive strokeWidth
            )
        {
            if (Session != null)
            {
                Session.New_Ellipse (
                        nameOfEllipse
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    ,   strokeWidth
                    );
            }

            return true;
        }

        public static Primitive New_Rectangle (
                Primitive nameOfRectangle
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            ,   Primitive strokeWidth
            )
        {
            if (Session != null)
            {
                Session.New_Rectangle (
                        nameOfRectangle
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    ,   strokeWidth
                    );
            }

            return true;
        }

        public static Primitive New_RoundedRectangle (
                Primitive nameOfRectangle
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            ,   Primitive radiusX
            ,   Primitive radiusY
            ,   Primitive strokeWidth
            )
        {
            if (Session != null)
            {
                Session.New_RoundedRectangle (
                        nameOfRectangle
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    ,   radiusX
                    ,   radiusY
                    ,   strokeWidth
                    );
            }

            return true;
        }

        public static Primitive New_FilledEllipse (
                Primitive nameOfEllipse
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            )
        {
            if (Session != null)
            {
                Session.New_FilledEllipse (
                        nameOfEllipse
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    );
            }

            return true;
        }

        public static Primitive New_FilledRectangle (
                Primitive nameOfRectangle
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            )
        {
            if (Session != null)
            {
                Session.New_FilledRectangle (
                        nameOfRectangle
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    );
            }

            return true;
        }

        public static Primitive New_FilledRoundedRectangle (
                Primitive nameOfRectangle
            ,   Primitive nameOfBrush
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            ,   Primitive radiusX
            ,   Primitive radiusY
            )
        {
            if (Session != null)
            {
                Session.New_FilledRoundedRectangle (
                        nameOfRectangle
                    ,   nameOfBrush
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    ,   radiusX
                    ,   radiusY
                    );
            }

            return true;
        }

        public static Primitive New_Bitmap (
                Primitive nameOfBitmap
            ,   Primitive nameOfBitmapResource
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            )
        {
            if (Session != null)
            {
                Session.New_Bitmap (
                        nameOfBitmap
                    ,   nameOfBitmapResource
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    );
            }

            return true;
        }

        public static Primitive New_Text (
                Primitive nameOfText
            ,   Primitive nameOfBrush
            ,   Primitive nameOfFontResource
            ,   Primitive text
            ,   Primitive x
            ,   Primitive y
            ,   Primitive width
            ,   Primitive height
            ,   Primitive opacity
            )
        {
            if (Session != null)
            {
                Session.New_Text (
                        nameOfText
                    ,   nameOfBrush
                    ,   nameOfFontResource
                    ,   text
                    ,   x
                    ,   y
                    ,   width
                    ,   height
                    ,   opacity
                    );
            }

            return true;
        }

        public static Primitive Clear_Transform (
                Primitive nameOfTransform
            )
        {
            if (Session != null)
            {
                Session.Clear_Transform (
                        nameOfTransform
                    );
            }

            return true;
        }

        public static Primitive New_RotateTransform (
                Primitive nameOfTransform
            ,   Primitive angle
            ,   Primitive centerX
            ,   Primitive centerY
            )
        {
            if (Session != null)
            {
                Session.New_RotateTransform (
                        nameOfTransform
                    ,   angle
                    ,   centerX
                    ,   centerY
                    );
            }

            return true;
        }

        public static Primitive New_TranslateTransform (
                Primitive nameOfTransform
            ,   Primitive x
            ,   Primitive y
            )
        {
            if (Session != null)
            {
                Session.New_TranslateTransform (
                        nameOfTransform
                    ,   x
                    ,   y
                    );
            }

            return true;
        }

        public static Primitive New_ScaleTransform (
                Primitive nameOfTransform
            ,   Primitive scaleX
            ,   Primitive scaleY
            ,   Primitive centerX
            ,   Primitive centerY
            )
        {
            if (Session != null)
            {
                Session.New_ScaleTransform (
                        nameOfTransform
                    ,   scaleX
                    ,   scaleY
                    ,   centerX
                    ,   centerY
                    );
            }

            return true;
        }

        public static Primitive New_SkewTransform (
                Primitive nameOfTransform
            ,   Primitive angleX
            ,   Primitive angleY
            ,   Primitive centerX
            ,   Primitive centerY
            )
        {
            if (Session != null)
            {
                Session.New_SkewTransform (
                        nameOfTransform
                    ,   angleX
                    ,   angleY
                    ,   centerX
                    ,   centerY
                    );
            }

            return true;
        }

    }
}
#endif
