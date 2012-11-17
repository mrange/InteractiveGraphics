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

using System;
using System.IO;
using System.Linq;
using System.Management.Automation;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using Microsoft.SmallBasic.Library;

// ReSharper disable InconsistentNaming


namespace InteractiveGraphics.Lib
{
    public partial class Session : IDisposable
    {
        const string NativeDll = "InteractiveGraphics.Native.dll";
        const CallingConvention NativeCallingConvention = CallingConvention.StdCall;
        [DllImport (NativeDll, CallingConvention = NativeCallingConvention)] 
        static extern IntPtr InteractiveGraphics_Initialize ();
        [DllImport (NativeDll, CallingConvention = NativeCallingConvention)] 
        static extern void InteractiveGraphics_Terminate (IntPtr session);
        [DllImport (NativeDll, CallingConvention = NativeCallingConvention)]
        static extern IntPtr InteractiveGraphics_AcceptMessage (
                IntPtr session
            ,   Int32 size_of_message
            ,   byte[] message 
            );

        IntPtr m_session;

        public Session ()
        {
            m_session = InteractiveGraphics_Initialize ();
        }

        ~Session ()
        {
            DisposeMe ();            
        }

        public void Dispose ()
        {
            GC.SuppressFinalize (this);
            DisposeMe ();          
        }

        private void DisposeMe ()
        {
            var session = Interlocked.Exchange (ref m_session, IntPtr.Zero);
            if (session != IntPtr.Zero)
            {
                InteractiveGraphics_Terminate (session);
            }
        }

        void SendMessage (MessageSerializer messageSerializer)
        {
            var bytes = messageSerializer.ToBytes ();
            if (m_session != IntPtr.Zero)
            {
                InteractiveGraphics_AcceptMessage (
                    m_session,
                    bytes.Length,
                    bytes
                    );
            }
        }

        partial void Partial_OnException (string methodName, Exception exc)
        {
            // TODO: Log
        }

        static bool IsRecognizedImageExtension (string extension)
        {
            extension = extension ?? "";
            var upper = extension.ToUpperInvariant ();

            switch (upper)
            {
                case ".PNG":
                case ".JPG":
                    return true;
                default:
                    return false;
            }
        }

        partial void Partial_New_BitmapResourceFromFileName (string nameOfBitmapResource, string imageFileName, int useFrame)
        {
            imageFileName = imageFileName ?? Constants.ImageFileName;

            if (string.IsNullOrEmpty (imageFileName))
            {
                var picturesPath = Environment.GetFolderPath (Environment.SpecialFolder.MyPictures);
                imageFileName = Directory
                    .GetFiles (picturesPath, "*.*", SearchOption.AllDirectories)
                    .FirstOrDefault (path => IsRecognizedImageExtension (Path.GetExtension (path)));
            }

            if (!string.IsNullOrEmpty (imageFileName) && System.IO.File.Exists (imageFileName))
            {
                var bytes = System.IO.File.ReadAllBytes (imageFileName);
                New_BitmapResourceFromBytes (nameOfBitmapResource, bytes, useFrame);
            }
            else
            {
                // TODO: Log
            }
        }

        partial void Partial_New_BitmapResourceFromUrl (
            string nameOfBitmapResource,
            string imageUrl,
            bool loadAsync,
            int useFrame
            )
        {
            var wc = new WebClient ();
            var address = new Uri (imageUrl ?? Constants.ImageUrl, UriKind.Absolute);

            if (!loadAsync)
            {
                    var bytes = wc.DownloadData (imageUrl ?? Constants.ImageUrl);
                    New_BitmapResourceFromBytes (nameOfBitmapResource, bytes, useFrame);
            }
            else
            {
                wc.DownloadDataCompleted += (s, e) => BitmapDownloaded (nameOfBitmapResource, useFrame, e);
                wc.DownloadDataAsync (address);
            }
        }

        void BitmapDownloaded (
            string nameOfBitmapResource,
            int useFrame,
            DownloadDataCompletedEventArgs e
            )
        {
            if (e.Error != null)
            {
                OnException ("New_BitmapResourceFromUrl", e.Error);
            }
            else if (e.Cancelled)
            {
                // TODO: Log                                 
            }
            else
            {
                New_BitmapResourceFromBytes (nameOfBitmapResource, e.Result, useFrame);
            }
        }
    }

#if !SUPPRESS_POWERSHELL_API
    static class SessionHolder
    {
        public static Session Session;
    }

    [Cmdlet (VerbsCommon.Open, "IGWindow")]
    public sealed class Open_IGWindow : Cmdlet
    {
        protected override void EndProcessing ()
        {
            if (SessionHolder.Session == null)
            {
                SessionHolder.Session = new Session ();
            }
        }
    }

    [Cmdlet (VerbsCommon.Close, "IGWindow")]
    public sealed class Close_IGWindow : Cmdlet
    {
        protected override void EndProcessing ()
        {
            var session = Interlocked.Exchange (ref SessionHolder.Session, null);
            if (session != null)
            {
                session.Dispose ();
            }
        }
    }

    [Cmdlet (VerbsCommon.Show, "IGAllCommands")]
    public sealed class Show_IGAllCommands : Cmdlet
    {
        protected override void EndProcessing ()
        {
            var sb = GetDescription (CommandRuntime.Host.UI.RawUI.BufferSize.Width - 2);

            WriteObject (sb);
        }

        static string GetDescription (int bufferWidth)
        {
            var descriptions =
                new[]
                    {
                        new { CmdLet = "CmdLet", ShortDescription = "Description"},
                        new { CmdLet = "------", ShortDescription = "-----------"},
                    }
                    .Concat (Session.GetCommandDescriptions ().OrderBy (x => x.Noun).Select (x => new { CmdLet = x.Verb + "-IG" + x.Noun, x.ShortDescription }))
                    .ToArray ()
                ;
            var sb = new StringBuilder ();

            var widthCmdLet = descriptions.Max (x => x.CmdLet.Length) + 2;

            var descriptionSize = bufferWidth - widthCmdLet;
            var indent = new string (' ', widthCmdLet);

            foreach (var description in descriptions)
            {
                var cmdLet = description.CmdLet;
                var shortDescription = description.ShortDescription;

                sb.Append (cmdLet);
                sb.Append (' ', widthCmdLet - cmdLet.Length);

                if (descriptionSize < 20)
                {
                    sb.AppendLine (shortDescription);
                }
                else
                {
                    var lines = shortDescription.Length/descriptionSize + (shortDescription.Length%descriptionSize == 0 ? 0 : 1);

                    for (var iter = 0; iter < lines; ++iter)
                    {
                        if (iter > 0)
                        {
                            sb.Append (indent);
                        }
                        sb.Append (shortDescription, iter * descriptionSize, System.Math.Min (descriptionSize, shortDescription.Length - iter * descriptionSize));
                        sb.AppendLine ();
                    }
                }


            }
            return sb.ToString ();
        }
    }

#endif

#if !SUPPRESS_SMALLBASIC_API
    [SmallBasicType]
    public static partial class FastGraphics
    {
        static Session Session;
        
        public static Primitive OpenWindow ()
        {
            if (Session == null)
            {
                Session = new Session ();
            }

            return true;
        }

        public static Primitive CloseWindow ()
        {
            var session = Interlocked.Exchange (ref Session, null);
            if (session != null)
            {
                session.Dispose ();
            }

            return true;
        }
    }
#endif

}

