//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#pragma pack(push, 1)
class vector
{
public:
	float x;
	float y;
	float z;

	//! Default ctor.
	vector(void)
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	//! Create vector from triplet of components.
	vector(float the_x, float the_y, float the_z)
	{
		x = the_x;
		y = the_y;
		z = the_z;
	}
};
#pragma pack(pop)

/* EOF */
