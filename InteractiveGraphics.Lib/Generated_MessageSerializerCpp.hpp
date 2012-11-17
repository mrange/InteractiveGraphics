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







// ----------------------------------------------------------------------------------------------
#include "noncopyable.hpp"
// ----------------------------------------------------------------------------------------------
#undef max
#undef min
// ----------------------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <xutility>
// ----------------------------------------------------------------------------------------------
#include "opt.hpp"
// ----------------------------------------------------------------------------------------------

        // When this is called the implementor is guaranteed that 2 bytes are available.
        // For other limits it's up to the implementor making sure the buffer is not overrun 
        extern bool message_unpacker__unpack (
                wchar_t const *             name
            ,   unsigned __int8 const *     bytes
            ,   __int32                     size   
            ,   __int32 &                   current   
            ,   std::wstring & value
            );
        // When this is called the implementor is guaranteed that 4 bytes are available.
        // For other limits it's up to the implementor making sure the buffer is not overrun 
        extern bool message_unpacker__unpack (
                wchar_t const *             name
            ,   unsigned __int8 const *     bytes
            ,   __int32                     size   
            ,   __int32 &                   current   
            ,   std::vector<unsigned __int8> & value
            );
    struct message_unserializer : noncopyable
    {
        
        enum class unpack_header_result
        {
            success_has_value               ,
            success_is_null                 ,
            message_not_of_expected_type    ,
            message_too_short               ,
        };

        enum SerializedType : unsigned __int8
        {
            Int32 = 1,
            Single = 2,
            String = 3,
            Boolean = 4,
            Byte = 5,
            Bytes = 6,
            IsNull = 0x80,
        };

        message_unserializer (
                __int32 size_of_message
            ,   unsigned __int8 const * bytes
            )  throw ()
            :   m__size (std::max (size_of_message, 0))
            ,   m__bytes (bytes)
            ,   m__current (0)
        {
        }

        __int32 get_remaining () const throw ()
        {
            return std::max (0, m__size - m__current);
        }      
         
        bool unpack (wchar_t const * name, opt<__int32> & value) throw ()
        {
            __int32 non_null_value;
            auto result = unpack_impl (name, non_null_value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    value = non_null_value;
                    return true;
                case unpack_header_result::success_is_null:
                    value = opt<__int32> ();
                    return true;
                default:
                    return false;
            }
        }

        bool unpack (wchar_t const * name, __int32 & value) throw ()
        {
            auto result = unpack_impl (name, value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                case unpack_header_result::success_is_null:
                    return true;
                default:
                    return false;
            }
        }

        unpack_header_result unpack_impl (wchar_t const * name, __int32 & value) throw ()
        {
            static_assert (sizeof (__int32) == 4, "sizeof value for __int32 must be 4");

            auto saved_position = m__current;

            auto result = unpack_header (name, SerializedType::Int32, 4);
            
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    {
                        auto ptr = reinterpret_cast<unsigned __int8*> (&value);
                        ptr[0] = m__bytes[m__current++];
                        ptr[1] = m__bytes[m__current++];
                        ptr[2] = m__bytes[m__current++];
                        ptr[3] = m__bytes[m__current++];
                    }
                    break;
                case unpack_header_result::success_is_null:
                    value =  __int32 ();
                    break;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    break;
            }

            return result;
        }



        bool unpack (wchar_t const * name, opt<float> & value) throw ()
        {
            float non_null_value;
            auto result = unpack_impl (name, non_null_value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    value = non_null_value;
                    return true;
                case unpack_header_result::success_is_null:
                    value = opt<float> ();
                    return true;
                default:
                    return false;
            }
        }

        bool unpack (wchar_t const * name, float & value) throw ()
        {
            auto result = unpack_impl (name, value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                case unpack_header_result::success_is_null:
                    return true;
                default:
                    return false;
            }
        }

        unpack_header_result unpack_impl (wchar_t const * name, float & value) throw ()
        {
            static_assert (sizeof (float) == 4, "sizeof value for float must be 4");

            auto saved_position = m__current;

            auto result = unpack_header (name, SerializedType::Single, 4);
            
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    {
                        auto ptr = reinterpret_cast<unsigned __int8*> (&value);
                        ptr[0] = m__bytes[m__current++];
                        ptr[1] = m__bytes[m__current++];
                        ptr[2] = m__bytes[m__current++];
                        ptr[3] = m__bytes[m__current++];
                    }
                    break;
                case unpack_header_result::success_is_null:
                    value =  float ();
                    break;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    break;
            }

            return result;
        }





        bool unpack (wchar_t const * name, std::wstring & value)
        {
            auto saved_position = m__current;

            auto unpack_header_result = unpack_header (name, SerializedType::String, 2);
            
            switch (unpack_header_result)
            {
                case unpack_header_result::success_has_value:
                    if (message_unpacker__unpack (
                            name
                        ,   m__bytes
                        ,   m__size
                        ,   m__current   
                        ,   value
                        ))
                    {
                        return true;
                    }
                    else
                    {
                        // TODO: Log
                        m__current = saved_position;
                        return false;
                    }
                case unpack_header_result::success_is_null:
                    value =  std::wstring ();
                    return true;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    return false;
            }
        }

        bool unpack (wchar_t const * name, opt<bool> & value) throw ()
        {
            bool non_null_value;
            auto result = unpack_impl (name, non_null_value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    value = non_null_value;
                    return true;
                case unpack_header_result::success_is_null:
                    value = opt<bool> ();
                    return true;
                default:
                    return false;
            }
        }

        bool unpack (wchar_t const * name, bool & value) throw ()
        {
            auto result = unpack_impl (name, value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                case unpack_header_result::success_is_null:
                    return true;
                default:
                    return false;
            }
        }

        unpack_header_result unpack_impl (wchar_t const * name, bool & value) throw ()
        {
            static_assert (sizeof (bool) == 1, "sizeof value for bool must be 1");

            auto saved_position = m__current;

            auto result = unpack_header (name, SerializedType::Boolean, 1);
            
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    {
                        auto ptr = reinterpret_cast<unsigned __int8*> (&value);
                        ptr[0] = m__bytes[m__current++];
                    }
                    break;
                case unpack_header_result::success_is_null:
                    value =  bool ();
                    break;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    break;
            }

            return result;
        }



        bool unpack (wchar_t const * name, opt<unsigned __int8> & value) throw ()
        {
            unsigned __int8 non_null_value;
            auto result = unpack_impl (name, non_null_value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    value = non_null_value;
                    return true;
                case unpack_header_result::success_is_null:
                    value = opt<unsigned __int8> ();
                    return true;
                default:
                    return false;
            }
        }

        bool unpack (wchar_t const * name, unsigned __int8 & value) throw ()
        {
            auto result = unpack_impl (name, value);
            switch (result)
            {
                case unpack_header_result::success_has_value:
                case unpack_header_result::success_is_null:
                    return true;
                default:
                    return false;
            }
        }

        unpack_header_result unpack_impl (wchar_t const * name, unsigned __int8 & value) throw ()
        {
            static_assert (sizeof (unsigned __int8) == 1, "sizeof value for unsigned __int8 must be 1");

            auto saved_position = m__current;

            auto result = unpack_header (name, SerializedType::Byte, 1);
            
            switch (result)
            {
                case unpack_header_result::success_has_value:
                    {
                        auto ptr = reinterpret_cast<unsigned __int8*> (&value);
                        ptr[0] = m__bytes[m__current++];
                    }
                    break;
                case unpack_header_result::success_is_null:
                    value =  unsigned __int8 ();
                    break;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    break;
            }

            return result;
        }





        bool unpack (wchar_t const * name, std::vector<unsigned __int8> & value)
        {
            auto saved_position = m__current;

            auto unpack_header_result = unpack_header (name, SerializedType::Bytes, 4);
            
            switch (unpack_header_result)
            {
                case unpack_header_result::success_has_value:
                    if (message_unpacker__unpack (
                            name
                        ,   m__bytes
                        ,   m__size
                        ,   m__current   
                        ,   value
                        ))
                    {
                        return true;
                    }
                    else
                    {
                        // TODO: Log
                        m__current = saved_position;
                        return false;
                    }
                case unpack_header_result::success_is_null:
                    value =  std::vector<unsigned __int8> ();
                    return true;
                default:
                    // TODO: Log
                    m__current = saved_position;
                    return false;
            }
        }

    private:
        unpack_header_result unpack_header (
                wchar_t const * name
            ,   SerializedType expected_type
            ,   __int32 expected_size
            )
        {
            UNREFERENCED_PARAMETER (name);

            if (get_remaining () < 1)
            {
                return unpack_header_result::message_too_short;
            }

            auto type = static_cast<SerializedType> (m__bytes[m__current++]);

            auto non_null_type = static_cast<SerializedType> ((type & ~SerializedType::IsNull)); 

            if (non_null_type != expected_type)
            {
                return unpack_header_result::message_not_of_expected_type;
            }

            if (type == non_null_type && get_remaining () < expected_size)
            {
                return unpack_header_result::message_too_short;
            }

            if (type == non_null_type)
            {
                return unpack_header_result::success_has_value;
            }
            else
            {
                return unpack_header_result::success_is_null;
            }
        }


        __int32                     m__size     ;
        unsigned __int8 const *     m__bytes    ;
        __int32                     m__current  ;
    };
// ----------------------------------------------------------------------------------------------
