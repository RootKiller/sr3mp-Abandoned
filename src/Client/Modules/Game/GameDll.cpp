//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "Modules/API/IClient.h"
#include "Modules/API/IGame.h"

#include <Windows.h>

class Game : public IGame
{
public:
	void Initialize(IClient *client) override
	{
		MessageBox(NULL, "Game kurwa", "\\o/", NULL);
	}

	void Shutdown(void) override
	{

	}
};

extern "C" __declspec(dllexport) IGame * GetInterface(void)
{
	return new Game();
}

extern "C" __declspec(dllexport) void FreeInterface(IGame *const gamePtr)
{
	delete gamePtr;
}

/* EOF */
