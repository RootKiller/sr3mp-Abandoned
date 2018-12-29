#pragma once

#include "Modules/API/IClient.h"

class IGame;

/**
 * Client core class.
 */
class Client : public IClient
{
private:
	//! Game module.
	Module<IGame>		m_game;

public:
			Client		(void);
			~Client		(void);

	void	Pulse		(void) override;
};
/* EOF */
