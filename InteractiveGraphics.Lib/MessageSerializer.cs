using System;

namespace InteractiveGraphics.Lib
{
    partial class MessageSerializer 
    {
        partial void Partial_Add (string name, byte[] value)
        {
            NoHeader_Add (name, value.Length);
            for (var iter = 0; iter <value.Length; ++iter)
            {
                m_bytes.Add (value[iter]);
            }
        }

        partial void Partial_Add (string name, string value)
        {
            var length = (UInt16)Math.Min (value.Length, UInt16.MaxValue);

            unsafe
            {
                var ptr = (byte*) &length;
                m_bytes.Add (ptr[0]);
                m_bytes.Add (ptr[1]);

                for (var iter = 0; iter < length; ++iter)
                {
                    var ch = value[iter];
                    ptr = (byte*) &ch;
                    m_bytes.Add (ptr[0]);
                    m_bytes.Add (ptr[1]);
                }
            }
        }

    }
}