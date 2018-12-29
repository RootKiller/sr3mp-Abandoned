//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "math/NumericTraits.h"
#include "math/Vector3.h"
#include "math/Matrix33.h"

class IGameEntity
{
public:
	virtual void					GetTransform		(Math::Vector3& vector, Math::Matrix33 &matrix) = 0;
	virtual void					SetTransform		(const Math::Vector3& vector, const Math::Matrix33 &matrix) = 0;

	virtual Math::Vector3			GetPosition			(void) = 0;
	virtual void					SetPosition			(const Math::Vector3& vector) = 0;

	virtual Math::Matrix33			GetOrientation		(void) = 0;
	virtual void					SetOrientation		(const Math::Matrix33& matrix) = 0;
};

/* EOF */
