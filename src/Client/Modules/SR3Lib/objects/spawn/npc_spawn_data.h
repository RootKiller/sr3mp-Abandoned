//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "spawn_data.h"

#include "math/vector.h"
#include "math/matrix.h"

class npc_spawn_data : public spawn_data
{
public:
	int					set_removal_permission		(int permission);

	int					set_info					(int human_preset, const vector &position, const matrix33 &orient, int allocation_client, int human_creation_flags);
};

/* EOF */
