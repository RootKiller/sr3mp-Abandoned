//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "human.h"

void __declspec(naked) human::set_never_die(bool)
{
	_asm {
		mov eax, 0x945F30
		jmp eax
	}
}

void __declspec(naked) human::set_invulnerable(bool)
{
	_asm {
		mov eax, 0x945690
		jmp eax
	}
}

/* EOF */
