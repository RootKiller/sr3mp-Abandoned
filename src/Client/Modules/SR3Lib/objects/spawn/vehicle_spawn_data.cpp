//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "vehicle_spawn_data.h"

int _declspec(naked) vehicle_spawn_data::set_forward_speed(const int speed)
{
	_asm {
		mov eax, 0x00A777E0
		jmp eax
	}
}

int _declspec(naked) vehicle_spawn_data::set_removal_permission(const int permission)
{
	_asm {
		mov eax, 0x00A77810
		jmp eax
	}
}

int _declspec(naked) vehicle_spawn_data::set_info(const int resource_uid, const vector &position, const matrix33 &orient, int allocation_client, const status_flags &status_flags_)
{
	_asm {
		mov eax, 0x00A79260
		jmp eax
	}
}

/* EOF */
