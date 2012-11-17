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
#include "noncopyable.hpp"
// -----------------------------------------------------------------------------
struct session : noncopyable
{
    struct impl;


    session ();
    ~session () throw ();

    void accept_message (__int32 size_of_message, unsigned __int8 const * message);

private:
    impl * const m__impl;
};
// -----------------------------------------------------------------------------
