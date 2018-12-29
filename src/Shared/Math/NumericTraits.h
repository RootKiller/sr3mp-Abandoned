//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "STypes.h"

namespace Math {

/**
 * Numeric traits.
 *
 * The single trait contains
 * > IS_NUMBER		- Is number?
 * > IS_FLOAT		- Is float-point?
 * > IS_INTEGER		- Is integer?
 * > IS_SIGNED		- Is signed?
 * > One			- One value
 * > Zero			- Zero value
 * > SizeOf			- Size of the numeric type in bytes.
 * > Min			- Minimum value
 * > Max			- Maximum value
 */
template <typename TYPE>
struct NumericTraits
{
	static const bool	IS_NUMBER		= false;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= false;
	static const bool	IS_SIGNED		= false;

	static void			One				(void);
	static void			Zero			(void);

	static void			SizeOf			(void);

	static void			Min				(void);
	static void			Max				(void);

	static void			Epsilon			(void);
};

template <>
struct NumericTraits<float>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= true;
	static const bool	IS_INTEGER		= false;
	static const bool	IS_SIGNED		= true;

	static float		One				(void)	{	return 1.0f;						}
	static float		Zero			(void)	{	return 0.0f;						}

	static size_t		SizeOf			(void)	{	return 4;							}

	static float		Min				(void)	{	return 1.175494351e-38F;			}
	static float		Max				(void)	{	return 3.402823466e+38F;			}

	static float		Epsilon			(void)	{	return 0.0001f;						}
};

template <>
struct NumericTraits<double>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= true;
	static const bool	IS_INTEGER		= false;
	static const bool	IS_SIGNED		= true;

	static double		One				(void)	{	return 1.0;							}
	static double		Zero			(void)	{	return 0.0;							}

	static size_t		SizeOf			(void)	{	return 8;							}

	static double		Min				(void)	{	return 2.2250738585072014e-308;		}
	static double		Max				(void)	{	return 1.7976931348623158e+308;		}

	static double		Epsilon			(void)	{	return 0.0001;						}
};

template <>
struct NumericTraits<uint8>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= false;

	static uint8		One				(void)	{	return 1;							}
	static uint8		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 1;							}

	static uint8		Min				(void)	{	return 0;							}
	static uint8		Max				(void)	{	return 0xFFu;						}

	static uint8		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<uint16>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= false;

	static uint16		One				(void)	{	return 1;							}
	static uint16		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 2;							}

	static uint16		Min				(void)	{	return 0;							}
	static uint16		Max				(void)	{	return 0xFFFFu;						}

	static uint16		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<uint32>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= false;

	static uint32		One				(void)	{	return 1;							}
	static uint32		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 4;							}

	static uint32		Min				(void)	{	return 0;							}
	static uint32		Max				(void)	{	return 0xFFFFFFFFu;					}

	static uint32		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<uint64>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= false;

	static uint64		One				(void)	{	return 1;							}
	static uint64		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 8;							}

	static uint64		Min				(void)	{	return 0;							}
	static uint64		Max				(void)	{	return 0xffffFFFFffffFFFFllu;		}

	static uint64		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<sint8>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= true;

	static sint8		One				(void)	{	return 1;							}
	static sint8		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 1;							}

	static sint8		Min				(void)	{ return -128;							}
	static sint8		Max				(void)	{ return 127;							}

	static sint8		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<sint16>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= true;

	static sint16		One				(void)	{	return 1;							}
	static sint16		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 2;							}

	static sint16		Min				(void)	{ return -32768;						}
	static sint16		Max				(void)	{ return 32737;							}

	static sint16		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<sint32>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= true;

	static sint32		One				(void)	{	return 1;							}
	static sint32		Zero			(void)	{	return 0;							}

	static size_t		SizeOf			(void)	{	return 4;							}

	static sint32		Min				(void)	{ return (-2147483647 - 1);				}
	static sint32		Max				(void)	{ return 2147483647;					}

	static sint32		Epsilon			(void)	{	return 0;							}
};

template <>
struct NumericTraits<sint64>
{
	static const bool	IS_NUMBER		= true;
	static const bool	IS_FLOAT		= false;
	static const bool	IS_INTEGER		= true;
	static const bool	IS_SIGNED		= true;

	static sint64		One				(void)	{	return 1;							}
	static sint64		Zero			(void)	{	return 0;							}

	static sint64		SizeOf			(void)	{	return 8;							}

	static sint64		Min				(void)	{ return (-9223372036854775807i64 - 1); }
	static sint64		Max				(void)	{ return 9223372036854775807i64;		}

	static sint64		Epsilon			(void)	{	return 0;							}
};

} /* namespace Math */

/* EOF */
