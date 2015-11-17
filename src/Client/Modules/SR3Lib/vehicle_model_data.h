//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

struct vehicle_model_data
{
	unsigned char pad[28];			// 00-28
	unsigned char unknown_bool;		// 28-29
};

vehicle_model_data *	get_vehicle_model_data_from_resource_id	(const int resource_id);
bool					sub_BC01B0								(char, char, char);

/* EOF */
