//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "npc.h"
#include "vehicle.h"

class object_factory
{
public:
	static vehicle *	create_vehicle		(vehicle_spawn_data * data);
	static npc *		create_npc			(npc_spawn_data * data);
};

/* EOF */
