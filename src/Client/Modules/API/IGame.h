//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

class IGame
{
public:
	virtual void		Initialize(class IClient *client) = 0;
	virtual void		Shutdown(void) = 0;

	static const char *	DLL_NAME;		// <The name of the DLL containing the implementation.
	static unsigned		VERSION;		// <The interface version.
	static const char * NAME;			// <The interface name without I prefix.
};

const char *IGame::DLL_NAME = "Game.dll";
unsigned	IGame::VERSION	= 1;
const char *IGame::NAME		= "Game";

/* EOF */
