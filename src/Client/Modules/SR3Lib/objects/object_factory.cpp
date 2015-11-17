//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "object_factory.h"

vehicle _declspec(naked)* object_factory::create_vehicle(vehicle_spawn_data * data)
{
	_asm {
		mov eax, 0x00BB7F40
		jmp eax
	}
}

npc _declspec(naked)* object_factory::create_npc(npc_spawn_data * data)
{
	_asm {
		mov eax, 0x00BB7FD0
		jmp eax
	}
}

/* EOF */
