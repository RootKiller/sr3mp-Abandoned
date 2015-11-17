//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "sr3_world.h"

int sr3_world::destroy_object(ctg_object *const object, int, int)
{
	_asm {
		mov		eax, 0x47DAB0
		jmp		eax
	}
}

/* EOF */
