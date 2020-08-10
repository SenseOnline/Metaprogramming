/* HEADER *********************************************************************************/
/*!
\file	Utils/Function/Common.h
\brief
	Commonly used helper functions.
	They hopefully are identical to the ones provided in the STL.
	Reimplemented for naming convention differences.

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _UTILITY_FN_COMMON_H_
#define _UTILITY_FN_COMMON_H_

#include "meta/types/Type.h"
#include "meta/metafunction/impl/TraitsImpl.h"
#include "meta/metafunction/impl/ManipulateImpl.h"


namespace Ut
{
	using ::MP::declval;

	/*!
		std::forward
	*/
	template <typename Ty>
	constexpr decltype(auto) Forward(MP::Lib::RemoveReference_t<Ty>&& obj)
	{
		static_assert(!MPL::IsLRef<Ty>::value, "Invalid forwarding call.");
		return static_cast<Ty&&>(obj);
	}
	template <typename Ty>
	constexpr decltype(auto) Forward(MP::Lib::RemoveReference_t<Ty>& obj)
	{
		return static_cast<Ty&&>(obj);
	}

	/*!
		Shorthand for forward
		Cannot alias with a function pointer or reference as
		MSVC tends to create garbage instructions in our tests
	*/
	template <typename Ty>
	constexpr decltype(auto) Fwd(MPL::RemoveReference_t<Ty>&& obj)
	{
		static_assert(!MPL::IsLRef<Ty>::value, "Invalid forwarding call.");
		return static_cast<Ty&&>(obj);
	}
	template <typename Ty>
	constexpr decltype(auto) Fwd(MPL::RemoveReference_t<Ty>& obj)
	{
		return static_cast<Ty&&>(obj);
	}

	/*!
		std::move
	*/
	template <typename T>
	constexpr decltype(auto) Move(T&& _obj) noexcept
	{
		return static_cast<MPL::RemoveReference_t<T>&&>(_obj);
	}
}




#endif

