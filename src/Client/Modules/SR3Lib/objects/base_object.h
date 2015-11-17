//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "math/vector.h"
#include "math/matrix.h"

#include "ctg_object.h"

enum base_object_flags_t
{
	BASE_OBJECT_FLAGS_unknown				= 1,
	BASE_OBJECT_FLAGS_unknown2				= 2,
	BASE_OBJECT_FLAGS_unknown3				= 4,
	BASE_OBJECT_FLAGS_is_cutscene_object	= 8,
	BASE_OBJECT_FLAGS_unknown4				= 4096
};

#pragma pack(push, 1)
class base_object : public ctg_object
{
public:
	uint8				pad[5];								// 0035-003A
	uint16				unknown_03A;						// 003A-003C (flags [base_object_flags_t])
	uint32				unknown_03C;						// 003C-0040
	vector				position;							// 0040-004C
	matrix33			orientation;						// 004C-0070
	uint16				unknown_070;						// 0070-0072
	uint16				unknown_072;						// 0072-0074
	uint16				unknown_074;						// 0074-0076

	virtual				~base_object			(void) = 0;
	virtual	bool		deserialize				(int a2) = 0;
	virtual bool		serialize				(int a2) = 0;

	/**
	 * In base_object this method calls deserialize without parameter..
	 * at least thats what pseudocode says.
	 */
	virtual bool		return_true_002			(void) = 0;

	virtual bool		return_true_003			(void)	= 0;
	virtual bool		return_true_004			(void)	= 0;
	virtual bool		pure_call_001			(void)	= 0;
	virtual bool		pure_call_002			(void)	= 0;

	virtual bool		pure_call_003			(bool a2, int16 a3)	= 0; //< Some set. (touches the same fields as the next method)
	virtual bool		pure_call_004			(bool a2) = 0; // < Some get (touches the same fields as the previous method)

	virtual void		nullsub_001				(void)	= 0;
	virtual	bool		unknown_method_001		(int a2) = 0;
	virtual	bool		unknown_method_002		(int a2) = 0;
	virtual bool		unknown_method_003		(void) = 0;

	virtual bool		unknown_method_004		(bool a2, int a3) = 0;
	virtual void		nullsub_002				(void)	= 0;

	virtual	unsigned	set_transform			(const vector &position, const matrix33 &orientation, int unknown)  = 0;
	virtual	unsigned	set_position			(const vector &position, int unknown) = 0;
	virtual unsigned	set_orientation			(const matrix33 &orientation, int unknown) = 0;
	virtual vector		get_position			(vector &position) = 0;

	virtual bool		some_flag_check			(void) = 0;
};

static_assert(sizeof(base_object) == 0x0076, "base_object size is not valid");
#pragma pack(pop)

/* EOF */
