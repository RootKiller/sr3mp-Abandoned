//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "STypes.h"

#pragma pack(push, 1)
class ctg_object
{
public:
	// uint32				vtable;								// 0000-0004 - As we implement virtual methods the vtable is "generated"
	uint32				unknown_004_unset_in_ctor;			// 0004-0008
	uint32				unknown_008;						// 0008-000C
	uint32				unknown_00C;						// 000C-0010
	uint32				unknown_010;						// 0010-0014
	uint32				unknown_014;						// 0014-0018
	char*				object_name;						// 0018-001C
	uint32				unknown_01C;						// 001C-0020
	uint32				unknown_020;						// 0020-0024
	uint32				unknown_024;						// 0024-0028
	uint32				unknown_028;						// 0028-002C
	uint32				unknown_02C;						// 002C-0030
	uint16				unknown_030;						// 0030-0032
	uint16				unknown_032_flags;					// 0032-0034 (0x33 is set to 0x10 in ctor)
	uint8				type;								// 0034-0035 (id of the instantiator)

	virtual				~ctg_object				(void)	= 0;

	virtual	bool		deserialize				(int a2) = 0;
	virtual bool		serialize				(int a2) = 0;
	virtual bool		return_true_002			(void)	= 0;
	virtual bool		return_true_003			(void)	= 0;
	virtual bool		return_true_004			(void)	= 0;
	virtual bool		pure_call_001			(void)	= 0;
	virtual bool		pure_call_002			(void)	= 0;
	virtual bool		pure_call_003			(bool a2, int16 a3)	= 0;
	virtual bool		pure_call_004			(bool a2) = 0;
	virtual void		nullsub_001				(void)	= 0;
	virtual	bool		unknown_method_001		(int a2) = 0;
	virtual	bool		unknown_method_002		(int a2) = 0;
	virtual bool		unknown_method_003		(void) = 0;

	address*			_get_vtable				(void);
};

static_assert(sizeof(ctg_object) == 0x0035, "ctg_object size is not valid");
#pragma pack(pop)

/* EOF */
