//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include <math.h>

#include "NumericTraits.h"

namespace Math {

/**
 * Vector 3D class
 */
class Vector3
{
public:
	float X, Y, Z;

	//! Constructor
			Vector3			(void)
	{
		X = Y = Z = 0.f;
	}

	//! Copy constructor
			Vector3			(const Vector3 &vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
	}

	//! Move constructor
			Vector3			(Vector3 &&vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
	}

	/**
	 * Setting constructor - 2 component variant. The Z component is set to zero.
	 *
	 * @param[in] theX The X component.
	 * @param[in] theY The Y component.
	 */
	explicit Vector3		(const float theX, const float theY)
	{
		X = theX;
		Y = theY;
		Z = 0.0f;
	}

	/**
	 * Setting constructor - 3 component variant.
	 *
	 * @param[in] theX The X component.
	 * @param[in] theY The Y component.
	 * @param[in] theZ The Z component.
	 */
	explicit Vector3		(const float theX, const float theY, const float theZ)
	{
		X = theX;
		Y = theY;
		Z = theZ;
	}

	//! Destructor
			~Vector3		(void)
	{
	}

	//! Calculate cross product.
	Vector3 Cross			(const Vector3& b) const
	{
		Vector3 result;
		result.X = (Y * b.Z) - (b.Y * Z);
		result.Y = (X * b.Z) - (b.X * Z);
		result.Z = (X * b.Y) - (b.X * Y);
		return result;
	}

	//! Calculate dot product.
	float Dot				(const Vector3& b) const
	{
		return (X * b.X + Y * b.Y + Z * b.Z);
	}

	//! Calculate squared magnitude.
	float SQMagnitude		(void) const
	{
		return (X * X + Y * Y + Z * Z);
	}

	//! Calculate magnitude.
	float Magnitude			(void) const
	{
		return sqrtf(SQMagnitude());
	}

	//! Normalize vector.
	void Normalize			(void)
	{
		const float s = Magnitude();
		if (s <= NumericTraits<float>::Epsilon()) return;

		X /= s;
		Y /= s;
		Z /= s;
	}

	//! Produce normalized copy of vector.
	Vector3 Normalized		(void) const
	{
		Vector3 copy(*this);
		copy.Normalize();
		return copy;
	}

	//! Inverse vector.
	void Inverse			(void)
	{
		X = -X;
		Y = -Y;
		Z = -Z;
	}

	//! Produce inversed copy of vector.
	Vector3 Inversed		(void) const
	{
		Vector3 copy(*this);
		copy.Inverse();
		return copy;
	}

	//! Copy assignment operator.
	Vector3& operator=(const Vector3 &vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
		return *this;
	}

	//! Move assignment operator.
	Vector3& operator=(Vector3 &&vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
		return *this;
	}

	//! Multiplication by another Vector3 operator.
	Vector3 operator*		(const Vector3& vec)
	{
		X = X * vec.X;
		Y = Y * vec.Y;
		Z = Z * vec.Z;
		return *this;
	}

	//! Divide by another Vector3 operator.
	Vector3 operator/		(const Vector3& vec)
	{
		X = X / vec.X;
		Y = Y / vec.Y;
		Z = Z / vec.Z;
		return *this;
	}

	//! Add another Vector3 operator.
	Vector3 operator+		(const Vector3& vec)
	{
		X = X + vec.X;
		Y = Y + vec.Y;
		Z = Z + vec.Z;
		return *this;
	}

	//! Subtract another Vector3 operator.
	Vector3 operator-		(const Vector3& vec)
	{
		X = X - vec.X;
		Y = Y - vec.Y;
		Z = Z - vec.Z;
		return *this;
	}

	//! Multiplication by scalar operator.
	Vector3 operator*		(const float scalar)
	{
		X = X * scalar;
		Y = Y * scalar;
		Z = Z * scalar;
		return *this;
	}

	//! Divide by another Vector3 operator.
	Vector3 operator/		(const float scalar)
	{
		X = X / scalar;
		Y = Y / scalar;
		Z = Z / scalar;
		return *this;
	}

	//! Add another Vector3 operator.
	Vector3 operator+		(const float scalar)
	{
		X = X + scalar;
		Y = Y + scalar;
		Z = Z + scalar;
		return *this;
	}

	//! Subtract another Vector3 operator.
	Vector3 operator-		(const float scalar)
	{
		X = X - scalar;
		Y = Y - scalar;
		Z = Z - scalar;
		return *this;
	}
};

//! Vector by float multiplication operator.
static Vector3 operator*(const Vector3 &vec, const float scalar)
{
	Vector3 result(vec);
	return result.operator*(scalar);
}

//! float by Vector multiplication operator resulting Vector.
static Vector3 operator*(const float scalar, const Vector3 &vec)
{
	// We do not care about order as the multiplication
	// of vector and float is commutative. 
	Vector3 result(vec);
	return result.operator*(scalar);
}

} /* namespace Math */

/* EOF */
