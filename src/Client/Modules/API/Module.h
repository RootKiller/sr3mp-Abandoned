//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#ifndef OS_WINDOWS
#	error Module wrapper is not designed to work under your operating system.
#endif

#include <Windows.h>

#include "Debug.h"
#include "System.h"

/**
 * Module loader wrapper class.
 */
template <typename INTERFACE_TYPE>
class Module
{
private:
	//! Module interface.
	INTERFACE_TYPE *m_interface;

	//! DLL handle.
	HMODULE			m_module;

	//! GetInterface method.
	typedef INTERFACE_TYPE *(*AllocInterface_t)(const char *const name, const unsigned version);
	AllocInterface_t AllocInterface;

	//! FreeInterface method.
	typedef void(*FreeInterface_t)(void);
	FreeInterface_t	FreeInterface;

public:
	Module(void) : m_interface(nullptr), m_module(NULL) {}
	~Module(void)
	{
		if (m_interface) {
			FreeInterface();
		}

		if (m_module) {
			FreeLibrary(m_module);
			m_module = NULL;
		}
	}

	INTERFACE_TYPE *Get(void)
	{
		if (m_interface) {
			return m_interface;
		}

		if (!m_module) {
			PathString dllPath;
			dllPath.Format("%s\\%s", System::GetCurrentModulePath().CStr(), INTERFACE_TYPE::DLL_NAME);
			m_module = LoadLibrary(dllPath);

			ASSERT(m_module);
		}

		ASSERT(AllocInterface	= reinterpret_cast<AllocInterface_t>(GetProcAddress(m_module, "AllocInterface")));
		ASSERT(FreeInterface	= reinterpret_cast<FreeInterface_t>(GetProcAddress(m_module, "FreeInterface")));

		m_interface = AllocInterface(INTERFACE_TYPE::NAME, INTERFACE_TYPE::VERSION);
		ASSERT(m_interface);
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
