//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "Modules/API/Entities/IGameCharacter.h"

#include "objects/player.h"

#include "GameEntity.h"

class GameLocalCharacter : public IGameCharacter, public GameEntity
{
private:
	player *				m_player;
public:
							GameLocalCharacter(void);
							~GameLocalCharacter(void);

	// IGameEntity
	void					GetTransform			(Math::Vector3& vector, Math::Matrix33 &matrix) override;
	void					SetTransform			(const Math::Vector3& vector, const Math::Matrix33 &matrix) override;

	Math::Vector3			GetPosition				(void) override;
	void					SetPosition				(const Math::Vector3& vector) override;

	Math::Matrix33			GetOrientation			(void) override;
	void					SetOrientation			(const Math::Matrix33& matrix) override;

	// GameEntity
	ctg_object *			GetGameObject			(void) override;
	void					OnObjectDestroy			(void) override;
	void					Destroy					(void) override;
};

/* EOF */
