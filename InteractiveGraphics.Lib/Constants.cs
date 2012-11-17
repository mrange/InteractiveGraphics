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

namespace InteractiveGraphics.Lib
{
    static class Constants
    {
        public const string Empty           = ""            ;
        public const string White           = "#FFFFFF"     ;
        
        public const string ImageUrl        = "http://upload.wikimedia.org/wikipedia/commons/6/63/Wikipedia-logo.png"   ;
        public const string ImageFileName   = ""            ;

        public const string Gamma           = "2.2"         ;
        public const string ExtendMode      = "CLAMP"       ;

        public const string DefaultFont     = "Arial"       ;
        public const string DefaultText     = "Text"        ;

        public const float DefaultFontSize  = 24            ;
        public const float Angle            = 30            ;
        public const float AngleX           = 30            ;
        public const float AngleY           = 60            ;
        public const float ScaleX           = 1.2F          ;
        public const float ScaleY           = 1.2F          ;
        public const float RadiusX          = 5             ;
        public const float RadiusY          = 5             ;
        public const float StartX           = 50            ;
        public const float StartY           = 50            ;
        public const float EndX             = 100           ;
        public const float EndY             = 100           ;
        public const float X                = 50            ;
        public const float Y                = 50            ;
        public const float Width            = 50            ;
        public const float Height           = 50            ;
        public const float Opacity          = 1             ;
        public const float StrokeWidth      = 3             ;

        public static class CmdLet
        {
            public static class ShortDescription
            {
                public const string Set_Window                          = "Sets properties (such as visibility) on the graphics windows.";
                public const string Wait_StateIsPresented               = "Pauses the program until the current state is presented to the screen. LCD screens updates roughly 60 times per second. Used to create delays in order to get smooth animation of objects.";
                public const string Clear_State                         = "Removes all resources and renderable objects in effect clearing the graphics window.";
                public const string Remove_Object                       = "Removes a named renderable object from the state.";
                public const string Remove_Resource                     = "Removes a named resource object from the state.";
                public const string New_SolidBrush                      = "Creates a new solid color brush.";
                public const string New_LinearGradientBrush             = "Creates a new linear gradient brush. Linear gradient brushes are excellent to create for instance a skyline.";
                public const string New_RadialGradientBrush             = "Creates a new radial gradient brush. Radial gradient brushes are excellent to create for instance a sun or a ball.";
                public const string Add_GradientStop                    = "Adds a gradient stop to a named gradient brush. The gradient is built up from several stops where the offset determine the distance from the top and where the color interpolated between the color in each stop.";
                public const string Clear_GradientStops                 = "Removes all gradients stops from a named gradient brush.";
                public const string New_BitmapResourceFromBytes         = "Creates a new bitmap resource from a byte array.";
                public const string New_BitmapResourceFromUrl           = "Creates a new bitmap resource from a url (the image is downloaded from the network using the url).";
                public const string New_BitmapResourceFromFileName      = "Creates a new bitmap resource from a file name.";
                public const string New_FontResource                    = "Creates a new font resource.";
                public const string Set_Object                          = "Sets properties (such as X,Y,...) of a renderable object.";
                public const string New_Line                            = "Creates a new line renderable.";
                public const string New_Ellipse                         = "Creates a new ellipse renderable.";
                public const string New_Rectangle                       = "Creates a new rectangle renderable.";
                public const string New_RoundedRectangle                = "Creates a new rectangle with rounded corners renderable.";
                public const string New_FilledEllipse                   = "Creates a new filled ellipse renderable.";
                public const string New_FilledRectangle                 = "Creates a new filled rectangle renderable.";
                public const string New_FilledRoundedRectangle          = "Creates a new filled rectangle with rounded corners renderable.";
                public const string New_Bitmap                          = "Creates a new bitmap renderable, use this together with bitmap resources to draw images.";
                public const string New_Text                            = "Creates a new text renderable, use this together with font resources to draw texts.";
                public const string Clear_Transform                     = "Removes a named transform renderable";
                public const string New_RotateTransform                 = "Creates a new rotate transform renderable, this is used to apply a rotiation to all renderables drawn after the transform";
                public const string New_TranslateTransform              = "Creates a new translate transform renderable, this is used to apply a translation (ie move them) to all renderables drawn after the transform";
                public const string New_ScaleTransform                  = "Creates a new scale transform renderable, this is used to apply a scaling (ie resize them) to all renderables drawn after the transform";
                public const string New_SkewTransform                   = "Creates a new skew transform renderable, this is used to apply a skewing (ie linear distortion) to all renderables drawn after the transform";
            }
        }
    }
}