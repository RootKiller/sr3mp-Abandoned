//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "Hooks.h"

namespace Memory {
namespace Hooks {

static address	g_baseAddress = 0;
static bool		baseAddressCalculated = false;

address GetBaseAddress(void)
{
	if (!baseAddressCalculated) {
		g_baseAddress = reinterpret_cast<address>(GetModuleHandleA(0)) - 0x400000;

		printf("Base address: %X\n", g_baseAddress);
		baseAddressCalculated = true;
	}

	return g_baseAddress;
}

void Initialize(void)
{
	const PBYTE imageBase				= reinterpret_cast<PBYTE>(GetModuleHandleA(NULL));
	const PIMAGE_DOS_HEADER dosHeader	= reinterpret_cast<PIMAGE_DOS_HEADER>(imageBase);
	const PIMAGE_NT_HEADERS ntHeaders	= reinterpret_cast<PIMAGE_NT_HEADERS>(imageBase + dosHeader->e_lfanew);
	PIMAGE_SECTION_HEADER sectionPtr	= IMAGE_FIRST_SECTION(ntHeaders);

	for (int section = 0; section < ntHeaders->FileHeader.NumberOfSections; ++section, ++sectionPtr) {
		const char *const sectionName = reinterpret_cast<const char *>(sectionPtr->Name);
		if (!strcmp(sectionName, ".text") || !strcmp(sectionName, ".rdata")) {
			DWORD tmp = 0;
			VirtualProtect(static_cast<void *>(imageBase + sectionPtr->VirtualAddress), ((sectionPtr->Misc.VirtualSize + 4095) & ~4095), PAGE_EXECUTE_READWRITE, &tmp);
		}
	}
}

void Noop(const address hookAddress, const unsigned size)
{
	memset(reinterpret_cast<void *>(hookAddress), 0x90, static_cast<size_t>(size));
}

} /* namespace Hooks */
} /* namespace Memory */

/* EOF */