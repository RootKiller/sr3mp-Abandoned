//
//    Saints Row The Third Multiplayer
// Copyright (C) 2015 All rights reserved
//

#include "STypes.h"

#include "Debug.h"

#include "Offsets.h"
#include "Hooks.h"

namespace Memory {

address Offsets::Engine::WindowHandle = 0;

address Offsets::Hooks::MainLoop = 0;
address Offsets::Hooks::MainLoopRetn = 0;

//! Player offsets
//@{
address Offsets::player::unknown_fn_1 = 0;
//@}

//! Player concrete instanatiator offsets
//@{
address Offsets::concrete_instantiator__player::instance = 0;
//@}

//! Vehicle concrete instanatiator offsets
//@{
address Offsets::concrete_instantiator__vehicle::instance = 0;
//@}

void Offsets::Initialize(void)
{
	const address baseAddress									= Memory::Hooks::GetBaseAddress();

	Engine::WindowHandle										= baseAddress + 0x05F0FF60;


	Hooks::MainLoop												= baseAddress + 0x005CFF51;
	Hooks::MainLoopRetn											= baseAddress + 0x005CFF56;

//! Player offsets
//@{
	player::unknown_fn_1										= baseAddress + 0x009E7D10;
//@}

//! Player concrete instanatiator offsets
//@{
	concrete_instantiator__player::instance						= baseAddress + 0x05A42478;
//@}

//! Vehicle concrete instanatiator offsets
//@{
	concrete_instantiator__vehicle::instance					= baseAddress + 0x05B21E80;
//@}
}

}  /* namespace Memory */

/* EOF */
