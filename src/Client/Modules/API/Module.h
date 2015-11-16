#pragma once

#ifndef _WIN32
#error O kurwa nie ten OS
#endif

#include <Windows.h>

template <typename INTERFACE_TYPE>
class Module
{
private:
	//! Module interface.
	INTERFACE_TYPE *m_interface;

	//! DLL handle.
	HMODULE			m_module;

	typedef INTERFACE_TYPE *(*GetInterface_t)(void);
	GetInterface_t	GetInterface;

	typedef void(*FreeInterface_t)(INTERFACE_TYPE *const interfacePtr);
	FreeInterface_t	FreeInterface;

public:
	Module(void) : m_interface(nullptr), m_module(NULL) {}
	~Module(void)
	{
		if (m_interface) {
			FreeInterface(m_interface);
		}

		if (m_module) {
			FreeLibrary(m_module);
			m_module = NULL;
		}
	}

	INTERFACE_TYPE *Get(void)
	{
		if (m_interface)
			return m_interface;

		if (!m_module) {
			char dllPath[MAX_PATH] = { 0 };
			char currentPath[MAX_PATH] = { 0 };

			GetModuleFileName(GetModuleHandle("Core.dll"), currentPath, MAX_PATH);
			for (unsigned int i = strlen(currentPath); i > 0; --i) {
				if (currentPath[i] == '\\') {
					currentPath[i] = '\0';
					break;
				}
			}

			sprintf(dllPath, "%s\\%s", currentPath, INTERFACE_TYPE::DLL_NAME);

			m_module = LoadLibrary(dllPath);

			// TOOD: m_module assert
		}

		GetInterface = reinterpret_cast<GetInterface_t>(GetProcAddress(m_module, "GetInterface"));
		FreeInterface = reinterpret_cast<FreeInterface_t>(GetProcAddress(m_module, "FreeInterface"));

		// TODO: Check GetInterface and FreeInterface
		// TODO: Versioning mechanism.

		m_interface = GetInterface();
		printf("%s:%u - DEBUG - ", __FILE__, __LINE__);
		// TODO: Some checking? Maybe client should check it?

		return m_interface;
	}

	operator INTERFACE_TYPE*(void)
	{
		return Get();
	}

	INTERFACE_TYPE *operator->(void)
	{
		return Get();
	}
};

/* EOF */
