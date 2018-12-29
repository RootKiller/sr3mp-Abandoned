//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "Defines.h"

namespace Debug {

typedef bool(*CustomAssertHandler)(const char *const expression, const char *const message, const char *const fn, const char *const file, const size_t line);

/**
 * Set custom assert handler.
 *
 * @param[in] customAssertHandler The custom assert handler method pointer, \c NULL means unset.
 */
void SetCustomAssertHandler(CustomAssertHandler *const customAssertHandler);

/**
 * Spawn debug system console.
 */
void SpawnSystemConsole(void);

/**
 * Kill debug system console.
 */
void KillSystemConsole(void);

namespace Detail {
	void AssertHandler(const char *const expression, const char *const message, const char *const fn, const char *const file, const size_t line);
} /* namespace Detail */
} /* namespace Debug */

#ifdef DEBUG_BUILD
#	define ASSERT(expr)				((!!(expr)) ? static_cast<void>(0) : Debug::Detail::AssertHandler(STRINGIZE(expr), NULL, FUNCTION_NAME, __FILE__, __LINE__))
#	define ASSERT_MSG(expr, message) ((!!(expr)) ? static_cast<void>(0) : Debug::Detail::AssertHandler(STRINGIZE(expr), message, FUNCTION_NAME, __FILE__, __LINE__))
#else
#	define ASSERT(expr)
#	define ASSERT_MSG(expr, message)
#endif

/* EOF */
