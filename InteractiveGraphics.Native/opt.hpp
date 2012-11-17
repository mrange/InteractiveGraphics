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
#pragma once
// -----------------------------------------------------------------------------
#include <type_traits>
// -----------------------------------------------------------------------------
template<typename TValue>
struct opt
{
    opt () throw ()
        :   m__has_value (false)
    {
    }

    opt (TValue const & value)
        :   m__has_value (true)
    {
        new (get_unsafe_ptr ()) TValue (value);
    }
        
    opt (opt const & value)
        :   m__has_value (value.m__has_value)
    {
        auto ptr = value.get_ptr ();
        if (ptr)
        {
            new (get_unsafe_ptr  ()) TValue (*ptr);
        }
    }
        
    opt& operator= (opt const & value)
    {
        if (this != &value)
        {
            auto ptr = get_ptr ();
            if (ptr)
            {
                ptr->~TValue ();
            }

            auto new_ptr = value.get_ptr ();
            if (new_ptr)
            {
                new (get_unsafe_ptr  ()) TValue (*new_ptr);
            }

            m__has_value = value.m__has_value;
        }

        return *this;
    }
        
    ~opt () throw ()
    {
        auto ptr = get_ptr ();
        m__has_value = false;
        if (ptr)
        {
            ptr->~TValue ();
        }
    }

    bool has_value () const throw ()
    {
        return m__has_value;
    }

    TValue const * get_ptr () const throw ()
    {
        if (m__has_value)
        {
            return get_unsafe_ptr ();
        }
        else
        {
            return nullptr;
        }
    }

    TValue * get_ptr () throw ()
    {
        if (m__has_value)
        {
            return get_unsafe_ptr ();
        }
        else
        {
            return nullptr;
        }
    }

    TValue const & get_value (TValue const & default_value) const throw ()
    {
        auto ptr = get_ptr ();
        if (ptr)
        {
            return *ptr;
        }
        else
        {
            return default_value;
        }
    }

    TValue & get_value (TValue & default_value) throw ()
    {
        auto ptr = get_ptr ();
        if (ptr)
        {
            return *ptr;
        }
        else
        {
            return default_value;
        }
    }

    typedef bool (opt::*unspecified_bool_type)() const throw ();

    operator unspecified_bool_type () const throw ()
    {
        return has_value () ? &opt::has_value : nullptr;
    }

    bool operator ! () const throw ()
    {
        return !has_value ();
    }

private:
    TValue const * get_unsafe_ptr () const throw ()
    {
        return reinterpret_cast<TValue const *> (&m__storage);
    }

    TValue * get_unsafe_ptr () throw ()
    {
        return reinterpret_cast<TValue*> (&m__storage);
    }

    typedef 
        typename std::tr1::aligned_storage<
                sizeof (TValue)
            ,   std::tr1::alignment_of<TValue>::value
            >::type            
        aligned_storage
        ;
    aligned_storage m__storage;
    bool            m__has_value;
};
// ----------------------------------------------------------------------------------------------
