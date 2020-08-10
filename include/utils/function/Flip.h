/* HEADER *********************************************************************************/
/*!
\file	Utils/Function/Flip.h
\brief
	Flips the first two arguments to a function

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _UTILITY_FN_FLIP_H_
#define _UTILITY_FN_FLIP_H_

#include "Function.h"
#include "../common/Common.h"

#include "meta/metafunction/impl/ManipulateImpl.h"


namespace Ut
{
	namespace Lib
	{
		struct Flip
		{
			template <typename T>
			struct FlipF : ::Ut::Function_t
			{
				template <typename A, typename B, typename ... Ts>
				constexpr auto operator () (A&& a, B&& b, Ts&& ... argv) const noexcept(noexcept(
					MP::declval<T>() (MP::declval<B>(), MP::declval<A>(), MP::declval<Ts>() ...)))
				{
					return func(::Ut::Fwd<B>(b), ::Ut::Fwd<A>(a), ::Ut::Fwd<Ts>(argv) ...);
				}

				T func;
			};

			template <typename T>
			constexpr FlipF<MPL::RemoveCVR_t<T>> operator () (T&& v) const noexcept
			{
				return { ::Ut::Fwd<T>(v) };
			}
		};
	}

	inline constexpr Lib::Flip Flip = {};
}




#endif

