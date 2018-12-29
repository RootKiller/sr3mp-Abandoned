//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "Memory/Hooks.h"

#include "math/conversion_helpers.h"

#include "GameLocalCharacter.h"

GameLocalCharacter::GameLocalCharacter(void)
	: m_player(nullptr)
{
	m_player = Memory::Hooks::Read<player *>(0x05A3637C);
}

GameLocalCharacter::~GameLocalCharacter(void)
{

}

void GameLocalCharacter::GetTransform(Math::Vector3& vector, Math::Matrix33 &matrix)
{
	if (m_player) {
		vector = to_vector3(m_player->position);
		matrix = to_matrix33(m_player->orientation);
	}
}

void GameLocalCharacter::SetTransform(const Math::Vector3& vector, const Math::Matrix33 &matrix)
{
	if (m_player)
		m_player->set_transform(to_vector3(vector), to_matrix33(matrix), 1);
}

Math::Vector3 GameLocalCharacter::GetPosition(void)
{
	if (m_player)
		return to_vector3(m_player->position);

	return Math::Vector3();
}

void GameLocalCharacter::SetPosition(const Math::Vector3& vector)
{
	if (m_player)
		m_player->set_position(to_vector3(vector), 1);
}

Math::Matrix33 GameLocalCharacter::GetOrientation(void)
{
	if (m_player)
		return to_matrix33(m_player->orientation);

	return Math::matrix33_identity;
}

void GameLocalCharacter::SetOrientation(const Math::Matrix33& matrix)
{
	if (m_player)
		m_player->set_orientation(to_matrix33(matrix), 1);
}

/**
 * Get game object used by this wrapper.
 */
ctg_object* GameLocalCharacter::GetGameObject(void)
{
	return m_player;
}

/**
 * Callback executed when engine destroys game object used by this wrapper.
 */
void GameLocalCharacter::OnObjectDestroy(void)
{
	// For this variant of object we do not have any specific code to
	// call in case object get destroyed.
	// ASSERT(false);
	printf("Local character removed.\n");
}

/**
 * Destroy object.
 */
void GameLocalCharacter::Destroy(void)
{
	ASSERT_MSG(false, "It is not possible to destroy local character.");
}
/* EOF */
