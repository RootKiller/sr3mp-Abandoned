//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "spawn_data.h"

#include "math/vector.h"
#include "math/matrix.h"

#include "status_flags.h"

class vehicle_spawn_data : public spawn_data
{
public:
	int					set_forward_speed			(const int speed);
	int					set_removal_permission		(const int permission);

	int					set_info					(const int resource_uid, const vector &position, const matrix33 &orient, int allocation_client, const status_flags &status_flags_);
};

/* EOF */
