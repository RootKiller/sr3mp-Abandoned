//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "ctg_object.h"

address* ctg_object::_get_vtable(void)
{
	return *reinterpret_cast<address **>(this);
}

/* EOF */
