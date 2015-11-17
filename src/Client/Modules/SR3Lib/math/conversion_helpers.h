//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "Math/Matrix33.h"
#include "Math/Vector3.h"

#include "vector.h"
#include "matrix.h"

static Math::Vector3 to_vector3(const vector &a)
{
	return Math::Vector3(a.x, a.y, a.z);
}

static vector to_vector3(const Math::Vector3 &a)
{
	return vector(a.X, a.Y, a.Z);
}

static Math::Matrix33 to_matrix33(const matrix33 &a)
{
	const float *const data = reinterpret_cast<const float *const>(&a.m);
	return Math::Matrix33(data);
}

static matrix33 to_matrix33(const Math::Matrix33 &a)
{
	const float *const data = reinterpret_cast<const float *const>(&a.m);
	return matrix33(data);
}
/* EOF */
