//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "human.h"

class player : public human
{
public:
	// unsigned char pad[10448];

	bool			unknown_fn_1(int a2);
};

// static_assert(sizeof(player) == 0x28D0, "SizeOf player does not match game.");

/* EOF */
