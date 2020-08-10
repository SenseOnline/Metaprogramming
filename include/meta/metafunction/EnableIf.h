/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/EnableIf.h
\brief
	Adapts std enable_if

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_ENABLEIF_H_
#define _META_FN_ENABLEIF_H_

#include "../types/Type.h"
#include "../types/Constant.h"

#include <type_traits>


namespace MP
{
	namespace Lib
	{
		template <bool _b, typename T = void>
		using EnableIf   = ::std:: enable_if<_b, T>;

		template <bool _b, typename T = void>
		using EnableIf_t = typename EnableIf<_b, T>::type;


		struct EnableIf_f
		{
			// If you enounter an error here, it means that you may have tried to
			// pass a raw value or a type the function cannot understand as an argument.
			// Please wrap the value using either MP::Constant, std::integral_constant or equivalent.

			template <template <typename B, B> class C, typename B, B _bool, typename U = Type<void>>
			auto operator () (C<B, _bool>, U = ::MP:: Type<void>) const noexcept -> EnableIf_t<!!_bool, Type_t<U>>;
		};
	}

	inline constexpr Lib::EnableIf_f EnableIf = {};
}

namespace MPL = ::MP::Lib;




#endif

