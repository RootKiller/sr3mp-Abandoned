//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <Windows.h>
#include <stdio.h>

/**
 * Inject DLL into process.
 *
 * @param[in] process Process handle.
 * @param[in] dllPath DLL path.
 * @return @c false on case of injection failure @c true otherwise.
 */
bool InjectDll(const HANDLE process, const char *const dllPath)
{
	const size_t libPathLen = strlen(dllPath) + 1;
	SIZE_T bytesWritten = 0;

	void *const remoteLibPath = VirtualAllocEx(process, NULL, libPathLen, MEM_COMMIT, PAGE_READWRITE);
	if (!remoteLibPath) {
		return false;
	}

	if (!WriteProcessMemory(process, remoteLibPath, dllPath, libPathLen, &bytesWritten)) {
		VirtualFreeEx(process, remoteLibPath, sizeof(remoteLibPath), MEM_RELEASE);
		return false;
	}

	const HMODULE kernel32dll = GetModuleHandle("Kernel32");
	if (!kernel32dll) {
		VirtualFreeEx(process, remoteLibPath, sizeof(remoteLibPath), MEM_RELEASE);
		return false;
	}

	const FARPROC pfnLoadLibraryA = GetProcAddress(kernel32dll, "LoadLibraryA");
	if (!pfnLoadLibraryA) {
		FreeModule(kernel32dll);
		VirtualFreeEx(process, remoteLibPath, sizeof(remoteLibPath), MEM_RELEASE);
		return false;
	}

	const HANDLE hThread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)pfnLoadLibraryA, remoteLibPath, 0, NULL);
	if (!hThread) {
		FreeModule(kernel32dll);
		VirtualFreeEx(process, remoteLibPath, sizeof(remoteLibPath), MEM_RELEASE);
		return false;
	}

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	FreeModule(kernel32dll);
	VirtualFreeEx(process, remoteLibPath, sizeof(remoteLibPath), MEM_RELEASE);
	return true;
}

/**
 * Launcher entry point.
 *
 * @see https://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char GameExePath[MAX_PATH] = { 0 },
		GamePath[MAX_PATH] = { 0 },
		Path[MAX_PATH] = { 0 };

	// TODO: Registry read /write

	strcat(GamePath, "G:\\Program Files\\steam\\steamapps\\common\\Saints Row the Third");
	sprintf(GameExePath, "%s\\SaintsRowTheThird_DX11.exe", GamePath);

	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };
	startupInfo.cb = sizeof(startupInfo);

	SetEnvironmentVariable("SteamAppID", "55230");

	if (!CreateProcess(GameExePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, GamePath, &startupInfo, &processInformation)) {
		MessageBox(NULL, "Cannot create game process.", "Fatal error", MB_ICONERROR);
		return false;
	}

	GetModuleFileName(NULL, Path, MAX_PATH);
	for (unsigned int i = strlen(Path); i > 0; --i) {
		if (Path[i] == '\\') {
			Path[i] = '\0';
			break;
		}
	}
	strcat(Path, "\\Core.dll");

	// TODO: Check if core.dll exists.

	if (!InjectDll(processInformation.hProcess, Path)) {
		MessageBox(NULL, "Could not inject dll into the game process. Please try launching the game again.", "Fatal error", MB_ICONERROR);
		TerminateProcess(processInformation.hProcess, 0);
		return false;
	}

	ResumeThread(processInformation.hThread);
	return 1;
}

/* EOF */
