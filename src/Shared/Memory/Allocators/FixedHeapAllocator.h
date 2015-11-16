//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

template <typename ELEMENT_TYPE, unsigned SIZE>
class FixedHeapAllocator : public BaseAllocator<ELEMENT_TYPE>
{
private:
	ElementType			*m_data;

public:
	FixedHeapAllocator(void)
	{
		m_data = new ElementType[SIZE];
	}

	~FixedHeapAllocator(void)
	{
		if (m_data) {
			delete[]m_data;
			m_data = nullptr;
		}
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
