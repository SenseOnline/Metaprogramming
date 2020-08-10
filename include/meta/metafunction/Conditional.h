/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Conditional.h
\brief
	Adapts std conditional

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_CONDITIONAL_H_
#define _META_FN_CONDITIONAL_H_

#include "../types/Type.h"
#include "../types/Constant.h"

#include <type_traits>


namespace MP
{
	namespace Lib
	{
		template <bool _b, typename TRUE, typename FALSE>
		using Conditional = ::std::conditional<_b, TRUE, FALSE>;

		template <bool _b, typename TRUE, typename FALSE>
		using Conditional_t = typename Conditional<_b, TRUE, FALSE>::type;


		struct Conditional_f
		{
			template <template <typename B, B> class C, typename B, B _bool, typename TRUE, typename FALSE>
			auto operator () (C<B, _bool>, TRUE _true, FALSE _false) const noexcept
			{
				if constexpr (_bool) 
					return _true;
				else
					return _false;
			}
		};
	}

	inline constexpr Lib::Conditional_f Conditional = {};
}

namespace MPL = ::MP::Lib;




#endif

