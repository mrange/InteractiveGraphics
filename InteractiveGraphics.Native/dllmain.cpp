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
// -----------------------------------------------------------------------------
HMODULE Shared__Module = nullptr;
// -----------------------------------------------------------------------------
BOOL APIENTRY DllMain ( 
        HMODULE hModule
    ,   DWORD  ul_reason_for_call
    ,   LPVOID lpReserved
    )
{
    UNREFERENCED_PARAMETER (lpReserved);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        Shared__Module = hModule;
        break;
	case DLL_PROCESS_DETACH:
        Shared__Module = nullptr;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
// -----------------------------------------------------------------------------

