/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/BooleanOps.h
\brief
	Not, Or, And, XOR ...

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_BOOLEAN_OPERATIONS_H_
#define _META_FN_BOOLEAN_OPERATIONS_H_

#include "impl/BooleanOpsImpl.h"
#include "utils/function/FnOps.h"


namespace MP
{
	inline constexpr Lib::Not Not = {};
	inline constexpr Lib::And And = {};
	inline constexpr Lib::Or  Or  = {};
	inline constexpr auto     XOR = !Or || And;
}




#endif

