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
#include <xutility>
// -----------------------------------------------------------------------------
#undef max
#undef min
template<typename TPtr>
static TPtr* move_ptr (TPtr*& ptr)
{
    auto result = ptr;
    ptr = nullptr;
    return result;
}

template<typename T>
static T clamp (T value, T inclusiveMin, T inclusiveMax)
{
    return std::min (inclusiveMax, std::max (inclusiveMin, value));
}

template<typename T>
static T create_pod ()
{
    static_assert (std::tr1::is_pod<T>::value, "T must be POD");

    T pod;
    memset (&pod, 0, sizeof (pod));
    return pod;
}

// -----------------------------------------------------------------------------
