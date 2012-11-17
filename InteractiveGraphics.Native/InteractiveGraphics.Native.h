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
#ifdef INTERACTIVEGRAPHICSNATIVE_EXPORTS
#define INTERACTIVEGRAPHICSNATIVE_API extern "C" __declspec(dllexport)
#else
#define INTERACTIVEGRAPHICSNATIVE_API extern "C" __declspec(dllimport)
#endif
// -----------------------------------------------------------------------------
INTERACTIVEGRAPHICSNATIVE_API void* __stdcall InteractiveGraphics_Initialize ();
INTERACTIVEGRAPHICSNATIVE_API void  __stdcall InteractiveGraphics_Terminate (void* session);
INTERACTIVEGRAPHICSNATIVE_API void  __stdcall InteractiveGraphics_AcceptMessage (
        void* session
    ,   __int32 size_of_message
    ,   unsigned __int8 const * message 
    );
// -----------------------------------------------------------------------------
