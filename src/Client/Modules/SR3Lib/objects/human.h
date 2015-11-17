//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "physical_object.h"

class human : public physical_object
{
public:
	void		set_never_die(bool);
	void		set_invulnerable(bool);
};

/* EOF */
