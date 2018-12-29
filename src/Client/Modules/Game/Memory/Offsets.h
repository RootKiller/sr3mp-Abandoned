//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#pragma once

#include "STypes.h"

namespace Memory {

#define DefOffset(Name)  Name

class Offsets
{
public:
	struct Engine {
		static address WindowHandle;
	};

	struct Hooks {
		static address MainLoop;
		static address MainLoopRetn;
	};

	struct player {
		static address unknown_fn_1;
	};

	struct concrete_instantiator__player {
		static address instance;
	};

	struct concrete_instantiator__vehicle {
		static address instance;
	};

	static void Initialize(void);
};

} /* namespace Memory */

/* EOF */

