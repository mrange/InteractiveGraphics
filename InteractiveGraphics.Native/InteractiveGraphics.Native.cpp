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
#include "stdafx.h"
#include "InteractiveGraphics.Native.h"
// -----------------------------------------------------------------------------
#include "resource.h"
// -----------------------------------------------------------------------------
#include "session.hpp"
// -----------------------------------------------------------------------------

#define API_PRELUDE()   \
    try                 \
    {

#define API_EPILOGUE()  \
    }                   \
    catch (...)         \
    {                   \
    }


// -----------------------------------------------------------------------------
INTERACTIVEGRAPHICSNATIVE_API void* __stdcall InteractiveGraphics_Initialize ()
{
    API_PRELUDE ()
        return new session ();
    API_EPILOGUE ()

    return nullptr;
}
// -----------------------------------------------------------------------------
INTERACTIVEGRAPHICSNATIVE_API void  __stdcall InteractiveGraphics_Terminate (void* s)
{
    API_PRELUDE ()
        auto ts = reinterpret_cast<session*> (s);
        delete ts;
    API_EPILOGUE ()
}
INTERACTIVEGRAPHICSNATIVE_API void  __stdcall InteractiveGraphics_AcceptMessage (
        void* s
    ,   __int32 size_of_message
    ,   unsigned __int8 const * message 
    )
{
    API_PRELUDE ()
        if (s && size_of_message > 0 && message)
        {
            auto ts = reinterpret_cast<session*> (s);
            ts->accept_message (size_of_message, message);              
        }
    API_EPILOGUE ()
}
// -----------------------------------------------------------------------------
