//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "vehicle.h"

bool _declspec(naked) vehicle::sub_A79560(int a2)
{
	_asm {
		mov eax, 0xA79560
		jmp eax
	}
}

int _declspec(naked) vehicle_name_to_id(const char *const name)
{
	_asm {
		mov eax, 0xAC18D0
		jmp eax
	}
}

/* EOF */
