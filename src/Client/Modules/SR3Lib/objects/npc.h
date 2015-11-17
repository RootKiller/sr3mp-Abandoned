//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "human.h"

#include "spawn/npc_spawn_data.h"

class npc : public human
{
public:
	void			set_invulnerable_to_gunfire				(bool);
	void			set_player_group_ignore					(bool);
	void			set_always_show_on_minimap				(bool);
	void			set_detection_events_enabled			(bool);
	void			set_dont_attack_me_on_sight				(bool);
	void			set_dont_affect_notoriety				(bool);
	void			set_dont_drop_weapon_on_ragdoll			(bool);
	void			set_dont_drop_weapon_on_death			(bool);
	void			set_dont_drop_cash						(bool);
};

int npc_name_to_id(const char *const name);

/* EOF */
