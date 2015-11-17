#include "Modules/Game/Memory/Hooks.h"
#include "Modules/Game/Memory/Offsets.h"

#include "concrete_instantiator.h"

concrete_instantiator<player> *get_player_instantiator(void)
{
	return reinterpret_cast<concrete_instantiator<player> *>(Memory::Offsets::concrete_instantiator__player::instance);
}

concrete_instantiator<vehicle> *get_vehicle_instantiator(void)
{
	return reinterpret_cast<concrete_instantiator<vehicle> *>(Memory::Offsets::concrete_instantiator__vehicle::instance);
}

/* EOF */
