//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "vehicle_model_data.h"

vehicle_model_data _declspec(naked) *get_vehicle_model_data_from_resource_id(const int resource_id)
{
	_asm
	{
		mov eax, 0xAC0970
		jmp eax
	}
}

bool _declspec(naked) sub_BC01B0(char, char, char)
{
	_asm
	{
		mov eax, 0xBC01B0
		jmp eax
	}
}

/* EOF */
