//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "base_object.h"

#pragma pack(push, 1)
class resource_object : public base_object
{
public:
	uint32				unknown_076;					// 0076-007A
	uint16				unknown_07A;					// 007A-007C
	uint32				unknown_07C;					// 007C-0080
	uint16				unknown_080;					// 0080-0082
	uint8				unknown_082;					// 0082-0083
	uint8				unknown_083;					// 0083-0084

	virtual				~resource_object		(void) = 0;
	virtual	bool		deserialize				(int a2) = 0;
	virtual bool		serialize				(int a2) = 0;

	/**
	 * @see base_object::return_true_002
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

	virtual int			unknown_method_005		(void) = 0;

	virtual void		pure_call_005			(void) = 0;
	virtual void		pure_call_006			(void) = 0;
	virtual void		pure_call_007			(void) = 0;
	virtual void		pure_call_008			(void) = 0;
};

static_assert(sizeof(resource_object) == 0x0084, "resource_object size is not valid");
#pragma pack(pop)

/* EOF */
