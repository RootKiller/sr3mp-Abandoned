//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

template <typename ELEMENT_TYPE>
class DynamicHeapAllocator : public BaseAllocator<ELEMENT_TYPE>
{
private:
	ElementType			*m_data;

	unsigned			m_dataSize;

public:
						DynamicHeapAllocator(void)
		: m_data(nullptr)
		, m_dataSize(0)
	{

	}

						~DynamicHeapAllocator(void)
	{
		Free();
	}

	ElementType*		Alloc(const unsigned count = 1) override
	{
		ASSERT(! m_data);

		m_dataSize = count * sizeof(ElementType);
		m_data = new ElementType[count];
		return m_data;
	}

	ElementType*		Realloc(const unsigned count = 1) override
	{
		Free();
		return Alloc(count);
	}

	void				Free(void) override
	{
		if (m_data) {
			delete[]m_data;
			m_data = nullptr;
		}
	}

	unsigned GetSize(void) const override
	{
		return m_dataSize;
	}

	unsigned GetBytesSize(void) const override
	{
		return m_dataSize;
	}

	bool IsDynamic(void) const override
	{
		return true;
	}
};

/* EOF */
