//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <Windows.h>
#include <stdio.h>

#define VERSION_SAFE_STEAM_API_INTERFACES
#include "SteamAPI/steam_api.h"

#include "Strings.h"

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

//! Steam api wrapper.
struct SteamWrapper
{
	CSteamAPIContext *context;

	SteamWrapper(void)
		: context(nullptr)
	{
	}

	bool Init(void)
	{
		if (!SteamAPI_IsSteamRunning()) {
			MessageBox(NULL, "To run Saints Row The Third Multiplayer your Steam client must be running.", "Fatal error", MB_ICONERROR);
			return false;
		}

		ASSERT(SteamAPI_InitSafe());

		context = new CSteamAPIContext();
		context->Init();
		ASSERT(context->SteamApps());
		return true;
	}

	~SteamWrapper(void)
	{
		if (context) {
			delete context;
			context = nullptr;
		}
	}
};

/**
 * Launcher entry point.
 *
 * @see https://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SteamWrapper steam;
	if (!steam.Init()) {
		return 0;
	}

	ISteamApps *const steamApps = steam.context->SteamApps();
	const AppId_t saintsRowAppid = 55230;

	if (!steamApps->BIsAppInstalled(saintsRowAppid)) {
		MessageBox(NULL, "To run Saints Row The Third Multiplayer you need to have installed Saints Row The Third game.", "Fatal error", MB_ICONERROR);
		return 0;
	}

	char installFolder[MAX_PATH];
	steamApps->GetAppInstallDir(saintsRowAppid, installFolder, MAX_PATH);

	AFixedString<MAX_PATH> gamePath(installFolder);
	AFixedString<MAX_PATH> gameExePath(gamePath);
	gameExePath += "\\SaintsRowTheThird_DX11.exe";

	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };
	startupInfo.cb = sizeof(startupInfo);

	SetEnvironmentVariable("SteamAppID", "55230");

	if (GetFileAttributes(gameExePath) == INVALID_FILE_ATTRIBUTES) {
		MessageBox(NULL, "Unable to find game .exe file.\n\nGame file: " + gameExePath, "Fatal error", MB_ICONERROR);
		return 0;
	}

	if (!CreateProcess(gameExePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, gamePath, &startupInfo, &processInformation)) {
		const unsigned lastError = GetLastError();
		MessageBox(NULL, "Cannot create game process.\n\nGame file: " + gameExePath + "\nDirectory: "+ gamePath +"\n\n(Error code: " + lastError + ")", "Fatal error", MB_ICONERROR);
		return 0;
	}

	char cPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, cPath, MAX_PATH);
	AFixedString<MAX_PATH> path(cPath);

	const unsigned lastPathSeparator = path.FindLast('\\');
	ASSERT(NotNil(lastPathSeparator));
	path.CutAt(lastPathSeparator);
	path += "\\Core.dll";

	if (GetFileAttributes(path) == INVALID_FILE_ATTRIBUTES) {
		MessageBox(NULL, "Cannot find Core.dll file.", "Error", MB_ICONERROR);
		return 0;
	}

	if (!InjectDll(processInformation.hProcess, path)) {
		MessageBox(NULL, "Could not inject dll into the game process. Please try launching the game again.", "Fatal error", MB_ICONERROR);
		TerminateProcess(processInformation.hProcess, 0);
		return 0;
	}

	ResumeThread(processInformation.hThread);
	return 1;
}

/* EOF */
