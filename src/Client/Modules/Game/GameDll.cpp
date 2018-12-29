//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <Windows.h>
#include <stdio.h>

// TODO: Own List class.
#include <list>

#include "Modules/API/IClient.h"
#include "Modules/API/IGame.h"

#include "Debug.h"
#include "Allocators.h"

#include "STypes.h"
#include "Memory/Hooks.h"
#include "Memory/Offsets.h"

#include "Entities/GameCharacter.h"
#include "Entities/GameVehicle.h"
#include "Entities/GameLocalCharacter.h"

#include "Strings.h"

#include "objects/types.h"

/*bool _declspec(naked) sub_90E530(const uint64 some_id)
{
	_asm {
		mov eax, 0x90E530
		jmp eax
	}
}

unsigned _declspec(naked) sub_8F0450(vehicle *const veh, const unsigned unk)
{
	_asm {
		mov eax, 0x8F0450
		jmp eax
	}
}


void DoPlayersTest(void)
{
	if(GetAsyncKeyState(VK_F7)) {
		g_player = Memory::Hooks::Read<player *>(0x05A3637C);
		vector spawnPos = g_player->position;
		spawnPos.x += 2.0f;


		int human_preset = npc_name_to_id("npc_cop");
		if(!human_preset) {
			printf("O KURWA\n");
			return;
		}

		npc_spawn_data spawn_data;
		spawn_data.set_info(human_preset, spawnPos, matrix33_identity, 8, 0);
		spawn_data.set_removal_permission(2);

		npc *const npc = create_npc(&spawn_data);
		if (!npc) return;

		npc->set_invulnerable_to_gunfire	(false);
		npc->set_player_group_ignore		(true);
		npc->set_always_show_on_minimap		(true);
		npc->set_detection_events_enabled	(false);
		npc->set_dont_attack_me_on_sight	(true);
		npc->set_dont_affect_notoriety		(true);

		human_ai_data *const ai_data = reinterpret_cast<human_ai_data *>(reinterpret_cast<address>(npc) + 688);

		ai_data->set_combat_enable			(false);
		ai_data->set_deaf					(true);
		ai_data->set_cant_attack			(true);
	}
}

void DoVehiclesTest(void)
{
	if(GetAsyncKeyState(VK_F6)) {

		g_player = Memory::Hooks::Read<player *>(0x05A3637C);
		vector spawnPos = g_player->position;
		// spawnPos.x += 2.0f;
		spawnPos.y += 5.0f;

		const int resource_id = vehicle_name_to_id("CAR_2DR_COMPACT04" "SP_VTOL01_CS");
		printf("resource_id: %X\n", resource_id);

		const vehicle_model_data *const model_data = get_vehicle_model_data_from_resource_id(resource_id);
		if(!model_data) {
			printf("no model data\n");
			return;
		}

		const bool unknownBool = sub_BC01B0(model_data->unknown_bool, 1, 0);
		printf("unknownBool: %s\n", unknownBool?"true":"false");
		if (!unknownBool) {
			return;
		}

		vehicle_spawn_data spawn_data;
		status_flags flags;
		spawn_data.set_info(resource_id, spawnPos, matrix33_identity, 7, flags);
		spawn_data.set_forward_speed(0);
		spawn_data.set_removal_permission(2);
		vehicle *const vehicle_ = create_vehicle(&spawn_data);
		if (! vehicle_) {
			printf("Unable to create vehicle.\n");
			return;
		}

		printf("Vehicle created (ptr: %p, vtable: %p)\n", vehicle_, vehicle_->_get_vtable());
#if 0
		// TODO: Finish reversing the rest of the code

		const address vvehicle = reinterpret_cast<address>(vehicle_);
		const uint64 some_id = *(uint64 *)(vvehicle + 8);
		printf("some_id = %llu\n", some_id);

		*(byte *)(vvehicle + 5693) &= 0xF7u;

		if(!sub_90E530(some_id)) {
			const address unknown = *(address *)(vvehicle + 7680);
			printf("unknown: %X\n", unknown);
			if(!unknown || !(*(byte *)(unknown + 116) & 1)) {
				sub_8F0450(vehicle_, 1);
			}
		}

		const unsigned u_unknown = *(unsigned *)(vvehicle + 0xA79560);
		printf("u_unknown: %X\n",u_unknown);
		if(u_unknown != 0xFFFFFFFF) {
			vehicle_->sub_A79560(5);
		}

		const address sub_A76EA0 = 0x00A76EA0;
		_asm {
			push 500
			push vehicle_
			call sub_A76EA0
			add esp, 8h
		}
#endif
	}
}*/

/*	printf("KURWA MAIN LOOP DZIA£CZY WOWOOHOHOHOHOHOHO KURWA!!!!\n");

	SetWindowText(Memory::Hooks::Read<HWND>(Memory::Offsets::Engine::WindowHandle), "SR3MP");

	sr3_world = Memory::Hooks::Read<address>(0x05849CD0);
	if(sr3_world) {
		for (int i = -(10 * 4); i < (4 * 10); i += 4) {
			printf("VTAB: %p\n", *(address *)(sr3_world + 9812 + i));
		}
	}

	g_player = Memory::Hooks::Read<player *>(0x05A3637C);
	if (g_player) {
		printf("> Player:\n");
		printf("\tobject_name = %s (vtable: %p)\n", g_player->object_name, g_player->_get_vtable());

		printf("\tPlayer pos [vector]: { x: %f, y: %f, z: %f }\n", g_player->position.x, g_player->position.y, g_player->position.z);
		playerPosition = g_player->position;

		playerRotation = g_player->orientation;
		printf("\tPlayer rotation [matrix33]:\n");
		for(int i = 0; i < 3; ++i) {
			printf("\t\t{ %f, %f, %f }\n", playerRotation.m[i][0], playerRotation.m[i][1], playerRotation.m[i][2]);
		}
		printf("> Player end:\n");

		if(GetAsyncKeyState(VK_F5)) {

			playerPosition.y += 2.0f;
			g_player->set_transform(playerPosition, playerRotation, 1);
			playerPosition.y -= 2.0f;
			printf("POS\n");
		}
	}

	DoVehiclesTest();
	DoPlayersTest();

	// Wyczyœæ ja! Wyczyœæ!
	// system("cls");
*/


void _cdecl OnMainLoopPulse(void);

void _declspec(naked) MainLoopHook(void)
{
	OnMainLoopPulse();

	_asm
	{
		pushad
		call OnMainLoopPulse
		popad
		push	0
		sub		esp, 8
		jmp		Memory::Offsets::Hooks::MainLoopRetn
	}
}

uint32 object_type = 0;
address xref = 0;
unsigned param2 = 0;
unsigned retn_Addr = 0x0047DA65;
void _declspec(naked) CreateObjectHook(void)
{
	_asm {
		push eax
		mov		eax, [esp + 4]
		mov		xref, eax
		mov		eax, [esp + 8]
		mov		object_type, eax
		mov		eax, [esp + 0Ch]
		mov		param2, eax
		pop eax
		pushad
	}

	// if (object_type == 7) { // 33 -player, 7 -vehicle
	//	printf("TYPE: %d (%X, %s)\n", object_type, xref, *(const char**)(param2));
	// }

	_asm {
		popad
		mov		al, [esp+4]
		push	ebx
		jmp		retn_Addr
	}
}

void OnObjectDestroy(ctg_object *const object);

const address sr3world__destroy_objectRetn = 0x0047D936;
ctg_object *destroyed_object = NULL;
void _declspec(naked) sr3world__destroy_object(void)
{
	_asm {
		push	eax
		mov		eax, [esp + 4]
		mov		xref, eax
		mov		eax, [esp + 8]
		mov		destroyed_object, eax
		pop		eax
		pushad
	}

	// printf("sr3world__destroy_object (xref: %X)\n", xref);
	OnObjectDestroy(destroyed_object);

	_asm {
		popad
		push	ecx
		push	ebx
		mov		ebx, [esp+0Ch]
		jmp		sr3world__destroy_objectRetn
	}
}

bool __declspec(naked) sub_9065A0(int)
{
	_asm {
		mov eax, 0x9065A0
		jmp eax
	}
}

bool __declspec(naked) sub_904FB0(int)
{
	_asm {
		mov eax, 0x904FB0
		jmp eax
	}
}

int __declspec(naked) sub_90EA20(int, bool)
{
	_asm {
		mov eax, 0x90EA20
		jmp eax
	}
}

class Game : public IGame
{
private:
	Memory::Hooks::JumpHook		jmp_MainLoopHook;

	Memory::Hooks::JumpHook		jmp_CreateObject;

	Memory::Hooks::JumpHook		jmp_sr3world__destroy_object;

	IClient						*m_client;

	GameLocalCharacter			*m_localCharacter;

	std::list<GameCharacter *>	m_characters;
	std::list<GameVehicle *>	m_vehicles;

	bool						m_handleDestroyCallback;
public:
	Game(void)
		: m_client(nullptr)
		, m_localCharacter(nullptr)
		, m_handleDestroyCallback(true)
	{
	}

	~Game(void)
	{
		ASSERT(m_characters.empty());
		ASSERT(m_vehicles.empty());
	}

	void Initialize(IClient *client) override
	{
		m_client = client;

		Memory::Hooks::Initialize();
		Memory::Offsets::Initialize();

		// Disable debug break
		// Hooks::Noop(Hooks::GetBaseAddress() + 0x00D4B81F, 1);

		// Disable generating of pedestrians and vehicles.
		// TODO: Disable ambient vehicles drawn faaar away from camera.
		// Memory::Hooks::Noop(0x0090EB39, 0x4A);

		// Memory::Hooks::Noop(0x0090EB39, 5);
		// Memory::Hooks::Noop(0x0090EB39 + 5, 5);
		// Memory::Hooks::Noop(0x0090EB39 + 10, 5);
		// Memory::Hooks::Noop(0x0090EB39 + 15, 5);
		// Memory::Hooks::Noop(0x0090EB39 + 20, 5);
		// Memory::Hooks::Noop(0x0090EB52, 5); // traffic_generate
		// Memory::Hooks::Write<uint8>(0x0090C480, 0xC3); // jle > jge

		// Memory::Hooks::Noop(0x0090EB39 + 30, 5); // crash if disabled
		// Memory::Hooks::Noop(0x0090EB63, 5); // mov     dword_130C9A4, eax

		// Peds
			// Memory::Hooks::Noop(0x0090EB5C, 7); // cmp     byte_5A10931, 0
			// Memory::Hooks::Noop(0x0090EB68, 2); // jnz     short loc_90EB74

			// Memory::Hooks::Noop(0x0090EB6A, 5); // generate peds
			// Memory::Hooks::Noop(0x0090EB6A + 5, 5); // generate busy peds (peds that are talking using phone etc)
		// End peds

		// Memory::Hooks::Noop(0x0090EB6A + 10, 5); // parked_vehicles_generate
		// Memory::Hooks::Noop(0x0090EB6A + 15, 5); // touching npcs - not really needed to be disabled
		// Memory::Hooks::Noop(0x0090EB6A + 20, 5);

		// Memory::Hooks::Noop(0x0090EB6A, 2 * 5);
		// Memory::Hooks::Noop(0x0090EB74, 3 * 5);

		// Disable some crashy stuff.
		// Memory::Hooks::Write<uint8>(0x007E0F70, 0xC3);

		// Set proper window title.
		StrCpy(reinterpret_cast<char *>(Memory::Hooks::GetBaseAddress() + 0x01126E98), "SR3MP Build (" __DATE__ " " __TIME__ ")");

		jmp_MainLoopHook.Setup(Memory::Offsets::Hooks::MainLoop);
		jmp_MainLoopHook.Install(&MainLoopHook);

		jmp_CreateObject.Setup(0x0047DA60);
		jmp_CreateObject.Install(&CreateObjectHook);

		jmp_sr3world__destroy_object.Setup(0x0047D930);
		jmp_sr3world__destroy_object.Install(&sr3world__destroy_object);
	}

	// TODO: Fix shutdown
	void Shutdown(void) override
	{
		if (m_localCharacter) {
			delete m_localCharacter;
			m_localCharacter = nullptr;
		}
	
		jmp_MainLoopHook.Uninstall();
		jmp_CreateObject.Uninstall();
		jmp_sr3world__destroy_object.Uninstall();

		MessageBox(NULL, "Shutdown kurwa", "\\o/", NULL);
	}

	IGameCharacter *GetLocalCharacter(void) override
	{
		if (!m_localCharacter) {
			m_localCharacter = new GameLocalCharacter();
		}
		return m_localCharacter;
	}

	IGameCharacter *CreateCharacter(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation) override
	{
		GameCharacter *character = new GameCharacter(model, position, orientation);
		m_characters.push_back(character);
		return character;
	}

	void DestroyCharacter(IGameCharacter *const character) override
	{
		ASSERT(character);
		ASSERT(std::find(m_characters.begin(), m_characters.end(), character) != m_characters.end());


		GameCharacter *const _character = static_cast<GameCharacter *>(character);

		m_characters.remove(_character);

		m_handleDestroyCallback = false;
		_character->Destroy();
		delete character;
		m_handleDestroyCallback = true;
	}

	IGameVehicle *CreateVehicle(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation) override
	{
		GameVehicle *vehicle = new GameVehicle(model, position, orientation);
		m_vehicles.push_back(vehicle);
		return vehicle;
	}

	void DestroyVehicle(IGameVehicle *const vehicle)
	{
		ASSERT(vehicle);
		ASSERT(std::find(m_vehicles.begin(), m_vehicles.end(), vehicle) != m_vehicles.end());

		GameVehicle *const _vehicle = static_cast<GameVehicle *>(vehicle);
		m_vehicles.remove(_vehicle);

		m_handleDestroyCallback = false;
		_vehicle->Destroy();
		delete _vehicle;
		m_handleDestroyCallback = true;
	}

	/**
	 * Engine object destroy callback.
	 */
	void OnObjectDestroy(ctg_object *const object)
	{
		if (!m_handleDestroyCallback) {
			return;
		}

		const uint8 objectType = object->type;
		switch(objectType) {
			case OBJECT_TYPE_PLAYER:
				if (m_localCharacter->GetGameObject() == object) {
					m_localCharacter->OnObjectDestroy();
				}
				break;
			case OBJECT_TYPE_NPC:
				for (GameCharacter *character : m_characters) {
					if (character->GetGameObject() == object) {
						character->OnObjectDestroy();
						break;
					}
				}
				break;
			case OBJECT_TYPE_VEHICLE:
				for (GameVehicle *vehicle : m_vehicles) {
					if (vehicle->GetGameObject() == object) {
						vehicle->OnObjectDestroy();
						break;
					}
				}
				break;
			default:
				printf("Unhandled object removal %u.\n", objectType);
				break;
		}
	}

	void Pulse(void)
	{
		// SetWindowText(Memory::Hooks::Read<HWND>(Memory::Offsets::Engine::WindowHandle), "SR3MP");

		Memory::Hooks::Write<float>(0x0130CAC0, 0.0f); // vehicles
		Memory::Hooks::Write<float>(0x0130CAC4, 0.0f); // peds
		Memory::Hooks::Write<float>(0x0130CB00, 0.0f); // peds override

		// sub_9065A0(1);
		// sub_904FB0(1);
		// sub_90EA20(0, 1);

		if (m_client) {
			m_client->Pulse();
		}
	}
};

Game *g_game = nullptr;

void OnMainLoopPulse(void)
{
	if (g_game)
		g_game->Pulse();
}

void OnObjectDestroy(ctg_object *const object)
{
	if (g_game)
		g_game->OnObjectDestroy(object);
}

DynamicHeapAllocator<Game> m_gameAllocator;

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
