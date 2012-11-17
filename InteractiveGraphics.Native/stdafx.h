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
#include "targetver.h"
// -----------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
// -----------------------------------------------------------------------------
#include <chrono>
#include <condition_variable>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>
// -----------------------------------------------------------------------------
#include <strsafe.h>
// -----------------------------------------------------------------------------
#include <D2d1.h>
#include <D3D10_1.h>
#include <DWrite.h>
#include <DXGI.h>
#include <WinCodec.h>
// -----------------------------------------------------------------------------
