//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "objects/base_object.h"

class object_instantiator
{
public:
	virtual base_object *create_object	(void) = 0;
	virtual int			delete_object	(base_object *object) = 0;

	virtual signed		get_slots_count	(void) = 0;
	virtual int			get_used_slots	(void) = 0;
	virtual signed		get_memory_size	(void) = 0;
	virtual bool		is_dynamic		(void) = 0; // maybe
	virtual int			unk_fn_005		(int a1) = 0;
	virtual void		nullsub			(void) = 0;

	virtual ~object_instantiator		(void) = 0;
};

/* EOF */
