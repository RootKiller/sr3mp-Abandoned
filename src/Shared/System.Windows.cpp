//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

// Windows system layer implementation.

#include "System.h"

#include <windows.h>

namespace System {

extern "C" IMAGE_DOS_HEADER __ImageBase;
PathString GetCurrentModulePath(void)
{
	const HINSTANCE moduleInstance = reinterpret_cast<HINSTANCE>(&__ImageBase);

	char currentPath[MAX_PATH] = { 0 };
	GetModuleFileName(moduleInstance, currentPath, MAX_PATH);
	PathString result(currentPath);
	const unsigned pathSepratorPos = result.FindLast('\\');
	ASSERT(NotNil(pathSepratorPos));
	result.CutAt(pathSepratorPos);
	return result;
}

}

/* EOF */
