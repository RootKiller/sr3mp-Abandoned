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

	static const char *	DLL_NAME;
};

const char *IGame::DLL_NAME = "Game.dll";

/* EOF */
