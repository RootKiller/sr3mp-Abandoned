//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "objects/ctg_object.h"

/**
 * Base class for game entity.
 *
 * All virtual methods of the IGameEntity should be implemented
 * inside object specify class.
 */
class GameEntity
{
public:
	/**
	 * Destroy method.
	 *
	 * Call it only from Game::Destroy* methods.
	 */
	virtual void Destroy(void) = 0;

	//! Get game engine object of the entity.
	virtual ctg_object *GetGameObject(void) = 0;

	//! Object destroy notification callback.
	virtual void OnObjectDestroy(void) = 0;
};

/* EOF */

