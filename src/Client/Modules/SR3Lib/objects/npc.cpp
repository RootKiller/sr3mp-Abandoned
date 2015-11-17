//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "npc.h"

void _declspec(naked) npc::set_invulnerable_to_gunfire(bool)
{
	_asm {
		mov eax, 0x9D55F0
		jmp eax
	}
}

void _declspec(naked) npc::set_player_group_ignore(bool)
{
	_asm {
		mov eax, 0x9D6000
		jmp eax
	}
}

void _declspec(naked) npc::set_always_show_on_minimap(bool)
{
	_asm {
		mov eax, 0x9D4900
		jmp eax
	}
}

void _declspec(naked) npc::set_detection_events_enabled(bool)
{
	_asm {
		mov eax, 0x9D4A70
		jmp eax
	}
}

void _declspec(naked) npc::set_dont_attack_me_on_sight(bool)
{
	_asm {
		mov eax, 0x9D4D50
		jmp eax
	}
}

void _declspec(naked) npc::set_dont_affect_notoriety(bool)
{
	_asm {
		mov eax, 0x9D4BE0
		jmp eax
	}
}

void _declspec(naked) npc::set_dont_drop_weapon_on_ragdoll(bool)
{
	_asm {
		mov eax, 0x9D51A0
		jmp eax
	}
}

void _declspec(naked) npc::set_dont_drop_weapon_on_death(bool)
{
	_asm {
		mov eax, 0x9D5030
		jmp eax
	}
}

void _declspec(naked) npc::set_dont_drop_cash(bool)
{
	_asm {
		mov eax, 0x9D4EC0
		jmp eax
	}
}

int _declspec(naked) npc_name_to_id(const char *const name)
{
	_asm {
		mov eax, 0xBE7590
		jmp eax
	}
}


/* EOF */
