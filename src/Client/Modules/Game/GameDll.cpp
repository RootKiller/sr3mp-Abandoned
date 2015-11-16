//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <Windows.h>

#include "Modules/API/IClient.h"
#include "Modules/API/IGame.h"

#include "Debug.h"
#include "Allocators.h"

class Game : public IGame
{
public:
	void Initialize(IClient *client) override
	{
		MessageBox(NULL, "Game kurwa", "\\o/", NULL);
	}

	void Shutdown(void) override
	{
		MessageBox(NULL, "Shutdown kurwa", "\\o/", NULL);
	}
};

DynamicHeapAllocator<Game> m_gameAllocator;
Game *g_game = nullptr;

/**
 * Get interface method implementation.
 *
 * @param[in] name The name of the interface.
 * @param[in] version The version of the interface.
 * @return Pointer to the game implementation @c NULL in case of problem.
 */
extern "C" __declspec(dllexport) IGame * AllocInterface(const char *const name, const unsigned version)
{
	if (strcmp(name, IGame::NAME) != 0) {
		return nullptr;
	}

	if (version != IGame::VERSION) {
		return nullptr;
	}

	ASSERT(!g_game);
	g_game = m_gameAllocator.Alloc();
	new (g_game) Game();
	return g_game;
}

/**
 * Free interface from memory.
 */
extern "C" __declspec(dllexport) void FreeInterface(void)
{
	MessageBox(NULL, "FreeInstance", NULL, NULL);
	ASSERT(g_game);
	m_gameAllocator.Free();
}

/* EOF */
