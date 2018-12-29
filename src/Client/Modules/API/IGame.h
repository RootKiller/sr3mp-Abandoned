//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "Math/Vector3.h"
#include "Math/Matrix33.h"

#include "Strings.h"

class IGameCharacter;
class IGameVehicle;

class IGame
{
public:
	virtual void			Initialize			(class IClient *client) = 0;
	virtual void			Shutdown			(void) = 0;

	virtual IGameCharacter *GetLocalCharacter	(void) = 0;
	virtual IGameCharacter *CreateCharacter		(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation) = 0;
	virtual void			DestroyCharacter	(IGameCharacter *const character) = 0;

	virtual IGameVehicle *	CreateVehicle		(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation) = 0;
	virtual void			DestroyVehicle		(IGameVehicle *const vehicle) = 0;

	static const char *	DLL_NAME;		// <The name of the DLL containing the implementation.
	static unsigned		VERSION;		// <The interface version.
	static const char * NAME;			// <The interface name without I prefix.
};

const char *IGame::DLL_NAME = "Game.dll";
unsigned	IGame::VERSION	= 1;
const char *IGame::NAME		= "Game";

/* EOF */
