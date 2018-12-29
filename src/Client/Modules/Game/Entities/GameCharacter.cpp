//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <stdio.h>

#include "GameCharacter.h"

#include "objects/ai/human_ai_data.h"
#include "objects/object_factory.h"

#include "math/conversion_helpers.h"

#include "sr3_world.h"

GameCharacter::GameCharacter(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation)
	: m_gameObject(nullptr)
	, m_humanPreset(0)
{
	printf("Creating character (%s, {%f, %f, %f})\n", model.CStr(), position.X, position.Y, position.Z);

	/**
	 * npc_cop - Police man
	 * npc_ped_genki
	 * npc_ped_mascot01
	 */
	m_humanPreset = npc_name_to_id(model);
	if (!m_humanPreset) {
		printf("Unable to get human preset from npc name.\n");
		return;
	}

	if (Spawn(position, orientation)) {
		printf("Character has been created.\n");
	}
	else {
		printf("Unable to create character.\n");
	}
}

GameCharacter::~GameCharacter(void)
{
	ASSERT(!m_gameObject);
}

/**
 * Spawn character.
 *
 * @return @c true in case vehicle was spawned @c false otherwise.
 */
bool GameCharacter::Spawn(const Math::Vector3& position, const Math::Matrix33 &orientation)
{
	ASSERT(!m_gameObject);

	npc_spawn_data spawn_data;
	spawn_data.set_info(m_humanPreset, to_vector3(position), to_matrix33(orientation), 8, 0);
	spawn_data.set_removal_permission(2);

	m_gameObject = object_factory::create_npc(&spawn_data);
	if (!m_gameObject) {
		printf("Unable to create npc object.\n");
		return false;
	}

	m_gameObject->set_invulnerable_to_gunfire	(false);
	m_gameObject->set_player_group_ignore		(true);
	m_gameObject->set_always_show_on_minimap	(true);
	m_gameObject->set_detection_events_enabled	(false);
	m_gameObject->set_dont_attack_me_on_sight	(true);
	m_gameObject->set_dont_affect_notoriety		(true);
	m_gameObject->set_dont_drop_weapon_on_death (true);
	m_gameObject->set_dont_drop_weapon_on_ragdoll(true);
	m_gameObject->set_dont_drop_cash			(true);
	m_gameObject->set_never_die					(true); // nneeeevah!
	m_gameObject->set_invulnerable				(true);

	const address __gameObject = reinterpret_cast<address>(m_gameObject);

	// TODO: NPC structure..
	human_ai_data *const ai_data = reinterpret_cast<human_ai_data *>(__gameObject + 688);

	ai_data->set_combat_enable					(false);
	ai_data->set_deaf							(true);
	ai_data->set_cant_attack					(true);
	return true;
}

void GameCharacter::GetTransform(Math::Vector3& vector, Math::Matrix33 &matrix)
{
	if (m_gameObject) {
		vector = to_vector3(m_gameObject->position);
		matrix = to_matrix33(m_gameObject->orientation);
	}
}

void GameCharacter::SetTransform(const Math::Vector3& vector, const Math::Matrix33 &matrix)
{
	if (m_gameObject)
		m_gameObject->set_transform(to_vector3(vector), to_matrix33(matrix), 1);
}

Math::Vector3 GameCharacter::GetPosition(void)
{
	if (m_gameObject)
		return to_vector3(m_gameObject->position);

	return Math::Vector3();
}

void GameCharacter::SetPosition(const Math::Vector3& vector)
{
	if (m_gameObject)
		m_gameObject->set_position(to_vector3(vector), 1);
}

Math::Matrix33 GameCharacter::GetOrientation(void)
{
	if (m_gameObject)
		return to_matrix33(m_gameObject->orientation);

	return Math::matrix33_identity;
}

void GameCharacter::SetOrientation(const Math::Matrix33& matrix)
{
	if (m_gameObject)
		m_gameObject->set_orientation(to_matrix33(matrix), 1);
}

/**
 * Get game object used by this wrapper.
 */
ctg_object* GameCharacter::GetGameObject(void)
{
	return m_gameObject;
}

/**
 * Callback executed when engine destroys game object used by this wrapper.
 */
void GameCharacter::OnObjectDestroy(void)
{
	ASSERT(m_gameObject);

	const Math::Matrix33& storedOrientation = to_matrix33(m_gameObject->orientation);
	const Math::Vector3& storedPosition = to_vector3(m_gameObject->position);

	m_gameObject = nullptr;
	Spawn(storedPosition, storedOrientation);
}

/**
 * Destroy object.
 */
void GameCharacter::Destroy(void)
{
	if (m_gameObject) {
		get_world()->destroy_object(m_gameObject, 0, 0);
		m_gameObject = NULL;
	}
}

/* EOF */
