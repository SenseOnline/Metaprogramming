/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Manipulate.h
\brief
	Type manipulators

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_MANIPULATE_H_
#define _META_FN_MANIPULATE_H_

#include "impl/ManipulateImpl.h"
#include "../types/MetaFunction.h"


namespace MP
{
	inline constexpr auto Decay            = Lib::MetaFunction<Lib:: Decay             >{};

	inline constexpr auto RemoveConst      = Lib::MetaFunction<Lib:: RemoveConst       >{};
	inline constexpr auto RemoveVolatile   = Lib::MetaFunction<Lib:: RemoveVolatile    >{};
	inline constexpr auto RemoveReference  = Lib::MetaFunction<Lib:: RemoveReference   >{};
	inline constexpr auto RemoveCV         = Lib::MetaFunction<Lib:: RemoveCV          >{};
	inline constexpr auto RemoveCVR        = Lib::MetaFunction<Lib:: RemoveCVRef       >{};
	inline constexpr auto RemovePointer    = Lib::MetaFunction<Lib:: RemovePointer     >{};
	inline constexpr auto RemoveExtent     = Lib::MetaFunction<Lib:: RemoveExtent      >{};
	inline constexpr auto RemoveAllExtents = Lib::MetaFunction<Lib:: RemoveAllExtents  >{};

	inline constexpr auto AddConst         = Lib::MetaFunction<Lib:: AddConst          >{};
	inline constexpr auto AddVolatile      = Lib::MetaFunction<Lib:: AddVolatile       >{};
	inline constexpr auto AddCV            = Lib::MetaFunction<Lib:: AddCV             >{};
	inline constexpr auto AddLRef          = Lib::MetaFunction<Lib:: AddLRef           >{};
	inline constexpr auto AddRRef          = Lib::MetaFunction<Lib:: AddRRef           >{};
	inline constexpr auto AddPointer       = Lib::MetaFunction<Lib:: AddPointer        >{};

	inline constexpr auto MakeSigned       = Lib::MetaFunction<Lib:: MakeSigned        >{};
	inline constexpr auto MakeUnsigned     = Lib::MetaFunction<Lib:: MakeUnsigned      >{};

	inline constexpr auto CommonType       = Lib::MetaFunction<Lib:: CommonType        >{};
	inline constexpr auto ElementType      = Lib::MetaFunction<Lib:: ElementType       >{};
	

	// Aliases

	inline constexpr auto AddPtr                       = AddPointer;
	inline constexpr auto RemovePtr                    = RemovePointer;
	inline constexpr auto RemoveRef                    = RemoveReference;
	inline constexpr auto AddConstVolatile             = AddCV;
	inline constexpr auto RemoveConstVolatile          = RemoveCV;
	inline constexpr auto RemoveCVRef                  = RemoveCVR;
	inline constexpr auto RemoveConstVolatileReference = RemoveCVR;
}




#endif

