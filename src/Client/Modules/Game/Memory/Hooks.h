//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include <Windows.h>
#include <stdio.h>

#include "STypes.h"
#include "Debug.h"

// X86 version of Hooks.

namespace Memory {
namespace Hooks {

//! Get base address.
address GetBaseAddress(void);

//! Initialize hooks subsystem.
void Initialize(void);

//! Set noop.
void Noop(const address hookAddress, const unsigned size);

//! Read memory.
template <typename TYPE>
TYPE Read(const address address)
{
	return *reinterpret_cast<TYPE *>(address);
}

//! Write memory.
template <typename TYPE>
void Write(const address address, const TYPE newValue)
{
	*reinterpret_cast<TYPE *>(address) = newValue;
}

//! JumpHook class.
class JumpHook
{
private:
	byte			*m_bytes;

	byte			*m_hookPtr;
public:
	JumpHook(void) : m_bytes(nullptr), m_hookPtr(nullptr) {}

	~JumpHook(void)
	{
		ASSERT_MSG(!m_bytes, "Hook has to be uninstalled explicitly!");
	}

	void Setup(const address hookAddress)
	{
		m_hookPtr = reinterpret_cast<byte *>(GetBaseAddress() + hookAddress);
	}

	template <typename CALLBACK_TYPE>
	void Install(CALLBACK_TYPE *const fn)
	{
		ASSERT(!m_bytes);

		m_bytes = new byte[5];
		memcpy(m_bytes, m_hookPtr, 5);

		const address hookAddress = reinterpret_cast<address>(m_hookPtr);
		const address funcAddress = reinterpret_cast<address>(fn) - hookAddress - 5;

		*m_hookPtr									= 0xE9;
		*reinterpret_cast<address *>(m_hookPtr + 1)	= funcAddress;
	}

	void Uninstall(void)
	{
		ASSERT(m_bytes);
		ASSERT(m_hookPtr);

		memcpy(m_hookPtr, m_bytes, 5);

		if (m_bytes) {
			delete []m_bytes;
			m_bytes = nullptr;
		}

		m_hookPtr = nullptr;
	}
};

} /* namespace Hooks */
} /* namespace Memory */

/* EOF */
