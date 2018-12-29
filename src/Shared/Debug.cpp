//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "Debug.h"

#include <stdio.h>

#ifdef OS_WINDOWS
#	include <Windows.h>
#endif

namespace Debug {

/**
 * Custom assert handler pointer.
 */
CustomAssertHandler* g_customAssertHandler = NULL;

void SetCustomAssertHandler(CustomAssertHandler *const customAssertHandler)
{
	g_customAssertHandler = customAssertHandler;
}

static bool consoleLock = false;

void SpawnSystemConsole(void)
{
	ASSERT(!consoleLock);
#ifdef DEBUG_BUILD
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
#endif
	consoleLock = true;
}

void KillSystemConsole(void)
{
	ASSERT(consoleLock);
#ifdef DEBUG_BUILD
	FreeConsole();
#endif
	consoleLock = false;
}

namespace Detail {
/**
 * Internal assert handler
 *
 * @param[in] expression The stringized expression.
 * @param[in] message The user defined message.
 * @param[in] fn The function name.
 * @param[in] file The file name.
 * @param[in] line The line number.
 */
void AssertHandler(const char *const expression, const char *const message, const char *const fn, const char *const file, const size_t line)
{
	if (g_customAssertHandler && (*g_customAssertHandler)(expression, message, fn, file, line)) {
		return;
	}

	char assertionMessage[512] = { 0 };

	if (message) {
		// Message variant

		sprintf(
			assertionMessage,
			"An assertion error has been occured.\n\n"
			"Expression:\n\t%s\n" /* expression */
			"Function:\n\t%s\n" /* fn */
			"File:\n\t%s\n" /* file */
			"Line:\n\t%u\n" /* line */
			"Message:\n\t%s\n" /* message */
			"", expression, fn, file, line, message
		);
	}
	else {
		// No message variant

		sprintf(
			assertionMessage,
			"An assertion error has been occured.\n\n"
			"Expression:\n\t%s\n" /* expression */
			"Function:\n\t%s\n" /* fn */
			"File:\n\t%s\n" /* file */
			"Line:\n\t%u\n" /* line */
			"", expression, fn, file, line
		);
	}

#ifdef OS_WINDOWS
	OutputDebugStringA(assertionMessage);

	MessageBoxA(NULL, assertionMessage, "Assertion error", MB_ICONERROR);
	RaiseException(EXCEPTION_BREAKPOINT, EXCEPTION_NONCONTINUABLE, 0, nullptr);
#else
#	error Define variant for your operating system.
#endif
	}
}
}

/* EOF */
