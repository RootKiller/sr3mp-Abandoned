//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "physical_object.h"

#include "spawn/vehicle_spawn_data.h"

class vehicle : public physical_object
{
public:
	bool sub_A79560(int a2);
};

int vehicle_name_to_id(const char *const name);

/* EOF */
