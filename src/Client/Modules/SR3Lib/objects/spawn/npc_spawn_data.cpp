//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "npc_spawn_data.h"

int _declspec(naked) npc_spawn_data::set_removal_permission(int permission)
{
	_asm {
		mov eax, 0x009D3060
		jmp eax
	}
}

int	_declspec(naked) npc_spawn_data::set_info(int human_preset, const vector &position, const matrix33 &orient, int allocation_client, int human_creation_flags)
{
	_asm {
		mov eax, 0x009D68A0
		jmp eax
	}
}

/* EOF */
