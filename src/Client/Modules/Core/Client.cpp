#include "CorePCH.h"

#include "Modules/API/IGame.h"
#include "Modules/API/Module.h"

#include "Client.h"

Client::Client(void)
{
#ifdef DEBUG_BUILD
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
#endif

	m_game->Initialize(this);
}

Client::~Client(void)
{
	m_game->Shutdown();
}
/* EOF */
