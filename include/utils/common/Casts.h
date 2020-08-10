/* HEADER *********************************************************************************/
/*!
\file	Utils/Function/Casts.h
\brief
	Commonly used type casts.

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _UTILITY_FN_CASTS_H_
#define _UTILITY_FN_CASTS_H_

#include "meta/metafunction/TryCast.h"
#include "meta/metafunction/Traits.h"
#include "meta/metafunction/Manipulate.h"
#include "meta/metafunction/EnableIf.h"

#include <cstring>  // memcpy


namespace Ut
{
	using MP::TryCast;

	/*!
		because bit_cast doesn't exist till C++20
	*/
	template <typename To, typename Fr>
	inline auto BitCast(Fr&& _obj) noexcept -> MPL::Type_t<decltype(
		MP::EnableIf(MP::IsTriviallyCopyable(MP::Type<Fr>) && MP::IsTrivial(MP::Type<To>), MP::Type<To>)
	)> {
		static_assert(sizeof(Fr) == sizeof(To), "Invalid Cast. Cannot convert types of different sizes.");
		To ret;
		::std:: memcpy(&ret, &_obj, sizeof(To));
		return ret;
	}

	/*!
		More evil than bit_cast but undefined behaviour
	*/
	template <typename To, typename Fr>
	inline To PunCast(Fr&& _obj) noexcept(noexcept(To{ ::MP::declval<To&>() }))
	{
		static_assert(sizeof(Fr) <= sizeof(To), "Invalid Cast. Cannot convert to type of greater size.");
		union temp {
			int dummy;
			Fr object;
			To result;
		};

		temp x{ 0 }; // initialise as dummy...
		::std:: memcpy(&x.object, &_obj, sizeof(Fr));
		return x.result;
	}
}




#endif

