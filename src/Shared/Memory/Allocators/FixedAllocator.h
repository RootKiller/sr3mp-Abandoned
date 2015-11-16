//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

template <typename ELEMENT_TYPE, unsigned SIZE>
class FixedAllocator : public BaseAllocator<ELEMENT_TYPE>
{
private:
	ElementType			m_data[SIZE];

public:
	FixedAllocator(void)
	{

	}

	~FixedAllocator(void)
	{
	}

	ElementType*		Alloc(const unsigned count = 1) override
	{
		ASSERT(count <= SIZE);
		return m_data;
	}

	ElementType*		Realloc(const unsigned count = 1) override
	{
		ASSERT(count <= SIZE);
		return m_data;
	}

	void				Free(void) override
	{
	}

	unsigned GetSize(void) const override
	{
		return SIZE;
	}

	unsigned GetBytesSize(void) const override
	{
		return SIZE * sizeof(ElementType);
	}

	bool IsDynamic(void) const override
	{
		return false;
	}
};

/* EOF */
