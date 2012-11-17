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
#include <Unknwn.h>
// -----------------------------------------------------------------------------
#include "noncopyable.hpp"
#include "utility.hpp"
// -----------------------------------------------------------------------------
template<typename TInterface>
struct coutptr;

template<typename TInterface>
struct cptr
{
    cptr (TInterface * ptr  = nullptr, bool addref = true) throw ()
        :   m__ptr (ptr)
    {
        if (addref && m__ptr)
        {
            m__ptr->AddRef ();
        }
    }

    ~cptr () throw ()
    {
        reset ();
    }

    cptr (cptr && ptr) throw ()
        :   m__ptr (move_ptr (ptr.m__ptr))
    {
    }
        
    cptr (cptr const & ptr) throw ()
        :   m__ptr (ptr.m__ptr)
    {
        if (m__ptr)
        {
            m__ptr->AddRef ();
        }
    }

    cptr& operator= (cptr const & ptr) throw ()
    {
        cptr<TInterface> copy (ptr);
        swap (copy);
        return *this;
    }

    void swap (cptr & ptr) throw ()
    {
        std::swap (m__ptr, ptr.m__ptr);
    }

    void reset () throw ()
    {
        auto ptr = move_ptr (m__ptr);
        if (ptr)
        {
            ptr->Release ();
        }
    }

    TInterface* release () throw ()
    {
        auto ptr = move_ptr (m__ptr);
    }

    TInterface* get_ptr () const throw ()
    {
        return m__ptr;
    }

    TInterface* operator-> () const throw ()
    {
        auto result = get_ptr ();
        return result;
    }

    bool has_value () const throw ()
    {
        return get_ptr () != nullptr;
    }

    typedef bool (cptr::*unspecified_bool_type)() const throw ();

    operator unspecified_bool_type () const throw ()
    {
        return has_value () ? &cptr::has_value : nullptr;
    }

    bool operator ! () const throw ()
    {
        return !has_value ();
    }

    coutptr<TInterface> get_outptr () throw ()
    {
        return coutptr<TInterface> (*this);
    }

    IID get_iid () const throw ()
    {
        return __uuidof (TInterface);
    }

private:
    TInterface * m__ptr;
};

template<typename TInterface>
struct coutptr : noncopyable
{
    explicit coutptr (cptr<TInterface> & ptr) throw ()
        :   m__cptr (&ptr)
        ,   m__ptr (nullptr)
    {
    }

    ~coutptr () throw ()
    {
        if (m__cptr)
        {
            cptr<TInterface> tmp (m__ptr, false);
            m__cptr->swap (tmp);
        }
    }

    coutptr (coutptr && outptr) throw ()
    {
        m__cptr = move_ptr (outptr.m__cptr);
        m__ptr = move_ptr (outptr.m__ptr);
    }

    operator TInterface** () throw ()
    {
        return &m__ptr;
    }

    operator IUnknown** () throw ()
    {
        return reinterpret_cast<IUnknown**>(&m__ptr);
    }

    operator void** () throw ()
    {
        return reinterpret_cast<void**>(&m__ptr);
    }

private:
    cptr<TInterface>* m__cptr;
    TInterface* m__ptr;
};
// ----------------------------------------------------------------------------------------------
