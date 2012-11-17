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








namespace InteractiveGraphics.Lib
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;

    sealed partial class MessageSerializer 
    {
        [Flags]
        enum SerializedType : byte
        {
            Int32 = 1,
            Single = 2,
            String = 3,
            Boolean = 4,
            Byte = 5,
            Bytes = 6,
            IsNull = 0x80,
        }

        readonly List<Byte> m_bytes = new List<Byte> (32);

        public Byte[] ToBytes ()
        {
            return m_bytes.ToArray ();
        }

        public void Add (string name, Int32? value)
        {
            if (value != null)
            {
                Add (name, value.Value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.Int32));
            }
        }

        public void Add (string name, Int32 value)
        {
            m_bytes.Add ((Byte)SerializedType.Int32);
            NoHeader_Add (name, value);
        }

        void NoHeader_Add (string name, Int32 value)
        {
            Debug.Assert (sizeof (Int32) == 4);
            unsafe
            {         
                var ptr = (Byte*)&value;
                m_bytes.Add (ptr[0]);
                m_bytes.Add (ptr[1]);
                m_bytes.Add (ptr[2]);
                m_bytes.Add (ptr[3]);
            }

        }

        public void Add (string name, Single? value)
        {
            if (value != null)
            {
                Add (name, value.Value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.Single));
            }
        }

        public void Add (string name, Single value)
        {
            m_bytes.Add ((Byte)SerializedType.Single);
            NoHeader_Add (name, value);
        }

        void NoHeader_Add (string name, Single value)
        {
            Debug.Assert (sizeof (Single) == 4);
            unsafe
            {         
                var ptr = (Byte*)&value;
                m_bytes.Add (ptr[0]);
                m_bytes.Add (ptr[1]);
                m_bytes.Add (ptr[2]);
                m_bytes.Add (ptr[3]);
            }

        }

        partial void Partial_Add (string name, String value);

        public void Add (string name, String value)
        {
            if (value != null)
            {
                m_bytes.Add ((Byte)(SerializedType.String));
                Partial_Add (name, value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.String));
            }
        }
        public void Add (string name, Boolean? value)
        {
            if (value != null)
            {
                Add (name, value.Value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.Boolean));
            }
        }

        public void Add (string name, Boolean value)
        {
            m_bytes.Add ((Byte)SerializedType.Boolean);
            NoHeader_Add (name, value);
        }

        void NoHeader_Add (string name, Boolean value)
        {
            Debug.Assert (sizeof (Boolean) == 1);
            unsafe
            {         
                var ptr = (Byte*)&value;
                m_bytes.Add (ptr[0]);
            }

        }

        public void Add (string name, Byte? value)
        {
            if (value != null)
            {
                Add (name, value.Value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.Byte));
            }
        }

        public void Add (string name, Byte value)
        {
            m_bytes.Add ((Byte)SerializedType.Byte);
            NoHeader_Add (name, value);
        }

        void NoHeader_Add (string name, Byte value)
        {
            Debug.Assert (sizeof (Byte) == 1);
            unsafe
            {         
                var ptr = (Byte*)&value;
                m_bytes.Add (ptr[0]);
            }

        }

        partial void Partial_Add (string name, Byte[] value);

        public void Add (string name, Byte[] value)
        {
            if (value != null)
            {
                m_bytes.Add ((Byte)(SerializedType.Bytes));
                Partial_Add (name, value);
            }
            else
            {
                m_bytes.Add ((Byte)(SerializedType.IsNull | SerializedType.Bytes));
            }
        }
       
    }

}
