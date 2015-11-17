//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "spawn_data.h"

spawn_data::~spawn_data(void)
{
	destroy();
}

void _declspec(naked) spawn_data::destroy(void)
{
	_asm {
		mov eax, 0x47D030
		jmp eax
	}
}

/* EOF */
