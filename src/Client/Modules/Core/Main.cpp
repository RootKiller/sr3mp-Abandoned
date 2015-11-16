//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "CorePCH.h"

#include "Modules/API/Module.h"
#include "Client.h"

Client *g_client = nullptr;

// See: https://msdn.microsoft.com/en-us/library/windows/desktop/ms682583(v=vs.85).aspx
BOOL WINAPI DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH: {
				DisableThreadLibraryCalls(hinstDLL);

				MessageBoxW(NULL, L"OOO KURWA", L"JA PIERDOLE", MB_ICONHAND);

				g_client = new Client();
			} break;
		case DLL_PROCESS_DETACH: {
				delete g_client;
			} break;
	}

	return TRUE;
}

/* EOF */
