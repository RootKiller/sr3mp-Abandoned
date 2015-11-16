//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

template <typename TYPE>
struct NilValue { static const TYPE Value = static_cast<TYPE>(-1); };

struct Nil
{
	template <typename TYPE>
	operator TYPE(void) { return NilValue<TYPE>::Value; }
};

template <typename TYPE>
bool IsNil(const TYPE value)
{
	return (value == NilValue<TYPE>::Value);
}

template <typename TYPE>
bool NotNil(const TYPE value)
{
	return (value != NilValue<TYPE>::Value);
}

/* EOF */
