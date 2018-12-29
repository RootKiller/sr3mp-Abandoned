//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include <stdio.h>

#include "GameVehicle.h"

#include "objects/object_factory.h"

#include "math/conversion_helpers.h"

#include "vehicle_model_data.h"

#include "sr3_world.h"

GameVehicle::GameVehicle(const AString& model, const Math::Vector3& position, const Math::Matrix33 &orientation)
	: m_gameObject(nullptr)
	, m_resourceId(0)
{
	printf("Creating vehicle (%s, {%f, %f, %f})\n", model.CStr(), position.X, position.Y, position.Z);

	m_resourceId = vehicle_name_to_id(model);
	if (!m_resourceId) {
		printf("Unable to get human preset from npc name.\n");
		return;
	}

	if (Spawn(position, orientation)) {
		printf("Vehicle has been created.\n");
	}
	else {
		printf("Unable to create vehicle.\n");
	}
}

GameVehicle::~GameVehicle(void)
{
	// TODO: Destroy vehicle
}

/**
 * Spawn vehicle.
 *
 * @return @c true in case vehicle was spawned @c false otherwise.
 */
bool GameVehicle::Spawn(const Math::Vector3& position, const Math::Matrix33& orientation)
{
	ASSERT(!m_gameObject);
	const vehicle_model_data *const modelData = get_vehicle_model_data_from_resource_id(m_resourceId);
	if (!modelData) {
		printf("Unable to find model data by resource id\n");
		return false;
	}

	// Is this possible it's loading the model? Hmm
	const bool unknownBool = sub_BC01B0(modelData->unknown_bool, 1, 0);
	if (!unknownBool) {
		printf("Unable to load model.\n");
		return false;
	}

	vehicle_spawn_data spawn_data;
	status_flags status_flags_;
	spawn_data.set_info(m_resourceId, to_vector3(position), to_matrix33(orientation), 7, status_flags_);
	spawn_data.set_removal_permission(2);

	m_gameObject = object_factory::create_vehicle(&spawn_data);
	return m_gameObject != NULL;
}

void GameVehicle::GetTransform(Math::Vector3& vector, Math::Matrix33 &matrix)
{
	if (m_gameObject) {
		vector = to_vector3(m_gameObject->position);
		matrix = to_matrix33(m_gameObject->orientation);
	}
}

void GameVehicle::SetTransform(const Math::Vector3& vector, const Math::Matrix33 &matrix)
{
	if (m_gameObject)
		m_gameObject->set_transform(to_vector3(vector), to_matrix33(matrix), 1);
}

Math::Vector3 GameVehicle::GetPosition(void)
{
	if (m_gameObject)
		return to_vector3(m_gameObject->position);

	return Math::Vector3();
}

void GameVehicle::SetPosition(const Math::Vector3& vector)
{
	if (m_gameObject)
		m_gameObject->set_position(to_vector3(vector), 1);
}

Math::Matrix33 GameVehicle::GetOrientation(void)
{
	if (m_gameObject)
		return to_matrix33(m_gameObject->orientation);

	return Math::matrix33_identity;
}

void GameVehicle::SetOrientation(const Math::Matrix33& matrix)
{
	if (m_gameObject)
		m_gameObject->set_orientation(to_matrix33(matrix), 1);
}

/**
 * Get game object used by this wrapper.
 */
ctg_object* GameVehicle::GetGameObject(void)
{
	return m_gameObject;
}

/**
 * Callback executed when engine destroys game object used by this wrapper.
 */
void GameVehicle::OnObjectDestroy(void)
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
void GameVehicle::Destroy(void)
{
	if (m_gameObject) {
		get_world()->destroy_object(m_gameObject, 0, 0);
		m_gameObject = NULL;
	}
}

/* EOF */
