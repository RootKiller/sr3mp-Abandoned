//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

// No header guards needed as this file contains only macro definitions.

/**
 * Stringize macro.
 *
 * Example:
 * @code
 * const int MAJOR_VERSION = 2;
 * const int MINOR_VERSION = 1;
 *
 * printf("Engine version: " STRINGIZE(MAJOR_VERSION) "." STRINGIZE(MINOR_VERSION));
 * @codeend
 */
#ifndef STRINGIZE
#	define _STRINGIZE_HELPER(a) #a
#	define STRINGIZE(a) _STRINGIZE_HELPER(a)
#endif

//! Code location macro
#ifndef CODE_LOCATION
#	define CODE_LOCATION (__FILE__ ":" STRINGIZE(__LINE__))
#endif

//! OS independed function name macro.
#ifndef FUNCTION_NAME
#	ifdef OS_WINDOWS
#		define FUNCTION_NAME __FUNCTION__
#	else
#		error "TODO : Implement FUNCTION_NAME macro in " CODE_LOCATION "
#	endif
#endif

/* EOF */
