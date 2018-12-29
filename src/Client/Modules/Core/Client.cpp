#include "CorePCH.h"

#include "Modules/API/IGame.h"
#include "Modules/API/Module.h"

#include "Client.h"

#include "Modules/API/Entities/IGameCharacter.h"
#include "Modules/API/Entities/IGameVehicle.h"

Client::Client(void)
{
	Debug::SpawnSystemConsole();

	m_game->Initialize(this);
}

Client::~Client(void)
{
	m_game->Shutdown();

	Debug::KillSystemConsole();
}

bool F6 = false;
bool F7 = false;

void Client::Pulse(void)
{
	if (GetAsyncKeyState(VK_F6)) {
		if (!F6) {
			IGameCharacter *const localCharacter = m_game->GetLocalCharacter();
			ASSERT(localCharacter);

			Math::Vector3 position = localCharacter->GetPosition();
			Math::Matrix33 orientation = localCharacter->GetOrientation();

			position.X += 10.0f;

			IGameCharacter *const character = m_game->CreateCharacter("npc_cop", position, orientation);
			ASSERT(character);

			// character->SetPosition(localCharacter->GetPosition());
			F6 = true;
		}
	}
	else F6 = false;

	if (GetAsyncKeyState(VK_F7)) {
		if(!F7) {
			IGameCharacter *const localCharacter = m_game->GetLocalCharacter();
			ASSERT(localCharacter);

			Math::Vector3 position = localCharacter->GetPosition();
			Math::Matrix33 orientation = localCharacter->GetOrientation();

			position.X += 10.0f;
			position.Y += 1.0f;

			IGameVehicle *const vehicle = m_game->CreateVehicle("CAR_2DR_COMPACT04", position, orientation);
			ASSERT(vehicle);
			F7 = true;
		}
	}
	else F7 = false;
}
/* EOF */
