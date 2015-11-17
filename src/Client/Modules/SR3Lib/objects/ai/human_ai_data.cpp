//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "human_ai_data.h"

void _declspec(naked) human_ai_data::set_combat_enable(bool)
{
	_asm {
		mov eax, 0x4DFAA0
		jmp eax
	}
}

void _declspec(naked) human_ai_data::set_deaf(bool)
{
	_asm {
		mov eax, 0x4DFC20
		jmp eax
	}
}

void _declspec(naked) human_ai_data::set_cant_attack(bool)
{
	_asm {
		mov eax, 0x4DF1A0
		jmp eax
	}
}

/* EOF */
