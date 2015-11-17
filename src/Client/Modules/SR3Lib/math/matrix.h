//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#pragma pack(push, 1)
class matrix33
{
public:
	//! Matrix data.
	float m[3][3];

	//! Default matrix constructor creating identity matrix.
	matrix33(void)
	{
		m[0][0] = m[1][1] = m[2][2] = 1.0f;
		m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1] = 0.0f;
	}

	//! Construct matrix from float pointer.
	matrix33(const float *const data)
	{
		m[0][0] = data[0];
		m[0][1] = data[1];
		m[0][2] = data[2];

		m[1][0] = data[3];
		m[1][1] = data[4];
		m[1][2] = data[5];

		m[2][0] = data[6];
		m[2][1] = data[7];
		m[2][2] = data[8];
	}

	//! Copy constructor.
	matrix33(const matrix33 &matrix)
	{
		*this = matrix;
	}

	//! Move constructor.
	matrix33(matrix33 &&matrix)
	{
		*this = matrix;
	}

	//! Copy assignment operator.
	matrix33& operator=(const matrix33 &matrix)
	{
		for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y) {
			m[x][y] = matrix.m[x][y];
		}
		return *this;
	}

	//! Move assignment operator.
	matrix33& operator=(matrix33 &&matrix)
	{
		for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y) {
			m[x][y] = matrix.m[x][y];
		}
		return *this;
	}
};

static const matrix33 matrix33_identity;
#pragma pack(pop)

/* EOF */
