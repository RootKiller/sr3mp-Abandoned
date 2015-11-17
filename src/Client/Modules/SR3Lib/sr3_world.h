//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "Modules/Game/Memory/Hooks.h"

#include "objects/ctg_object.h"

class sr3_world /*: public ctg_world*/
{
public:
	int destroy_object(ctg_object *const object, int, int);
};

inline sr3_world *get_world(void)
{
	return Memory::Hooks::Read<sr3_world *>(0x05849CD0);
}

/* EOF */
