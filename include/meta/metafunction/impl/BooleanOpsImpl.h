/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Impl/BooleanOpsImpl.h
\author Tan Jie Wei Jacky (100%)
\par    email: t.jieweijacky\@digipen.edu
\brief
	Not, Or, And, XOR ...

*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_BOOLEAN_OPERATIONS_IMPL_H_
#define _META_FN_BOOLEAN_OPERATIONS_IMPL_H_

#include "TraitsImpl.h"

#include "../../types/Constant.h"
#include "utils/function/Function.h"


namespace MP
{
	namespace Lib
	{
		struct Not : public Ut::Function_t
		{
			template <typename Ty>
			constexpr auto operator () (Ty&& value) const noexcept
			{
				return !value;
			}
		};

		struct And : public Ut::Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty&& ... argv) const noexcept
			{
				return (argv && ...);
			}
		};

		struct Or : public Ut::Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty&& ... argv) const noexcept
			{
				return (argv || ...);
			}
		};
	}
}

namespace MPL = ::MP::Lib;




#endif

