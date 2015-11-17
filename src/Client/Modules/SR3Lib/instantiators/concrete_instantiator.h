//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "objects/player.h"
#include "objects/vehicle.h"

#include "object_instantiator.h"

template <typename OBJECT_TYPE>
class concrete_instantiator : public object_instantiator
{
};

template <>
class concrete_instantiator<player> : public object_instantiator
{
public:
};

template <>
class concrete_instantiator<vehicle> : public object_instantiator
{
public:
};

concrete_instantiator<player> *get_player_instantiator(void);
concrete_instantiator<vehicle> *get_vehicle_instantiator(void);

/* EOF */
