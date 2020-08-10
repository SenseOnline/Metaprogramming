/* HEADER *********************************************************************************/
/*!
\file	Utils/Function/FnOps.h
\brief
	Operations on functions to allow for easy compositing of functions.

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _UTILITY_FN_FUNCTION_OPERATORS_H_
#define _UTILITY_FN_FUNCTION_OPERATORS_H_

#include "Function.h"

#include "meta/metafunction/EnableIf.h"
#include "meta/metafunction/impl/TraitsImpl.h"
#include "meta/metafunction/impl/ManipulateImpl.h"
#include "meta/metafunction/impl/BooleanOpsImpl.h"
#include "meta/metafunction/Arithmetic.h"


namespace Ut
{
	namespace Lib
	{
		template <typename L, typename R>
		struct CompositeFn : public Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty&& ... argv) const noexcept
			{
				return lhs( rhs(static_cast<Ty&&>(argv) ...) );
			}

			L lhs;
			R rhs;
		};

		template <typename L, typename R, typename Op>
		struct BinaryFn : public Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty&& ... argv) const noexcept
			{
				return op (lhs(static_cast<Ty&&>(argv) ...), rhs(static_cast<Ty&&>(argv) ...));
			}

			L lhs;
			R rhs;
			Op op;
		};
	}


	/* unary  operators
	**************************************************************************/
	template <typename T, typename = MPL::EnableIf_t<MPL::IsBaseOf<Function_t, T>::value>>
	constexpr auto operator ~ (T const& f) noexcept
	{ 
		auto tilda = [](auto&& v) { return ~v; };
		return Lib::CompositeFn<decltype(tilda), T>{ tilda, f };
	}

	template <typename T, typename = MPL::EnableIf_t<MPL::IsBaseOf<Function_t, T>::value>>
	constexpr auto operator ! (T const& f) noexcept
	{
		return Lib::CompositeFn<::MPL::Not, T>{ ::MPL::Not{}, f };
	}


	/* binary operators - composition
	**************************************************************************/
	template <typename L, typename R, typename = MPL::EnableIf_t<MPL::IsBaseOf<Function_t, L>::value && MPL::IsBaseOf<Function_t, R>::value>>
	constexpr auto operator << (L const& lhs, R const& rhs) noexcept
	{
		return Lib::CompositeFn<L, R> {lhs, rhs};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<MPL::IsBaseOf<Function_t, L>::value && MPL::IsBaseOf<Function_t, R>::value>>
	constexpr auto operator >> (L const& lhs, R const& rhs) noexcept
	{
		return Lib::CompositeFn<R, L> {rhs, lhs};
	}


	/* binary operators
	**************************************************************************/

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator + (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l + r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator - (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l - r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator * (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l * r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator / (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l / r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator < (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l < r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator > (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l > r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator == (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l == r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator != (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l != r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator <= (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l <= r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator >= (L&& lhs, R&& rhs) noexcept
	{
		auto fn = [](auto&& l, auto&& r) { return l >= r; };
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, decltype(fn)>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), fn
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value && 
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator && (L&& lhs, R&& rhs) noexcept
	{
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, ::MPL::And>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), ::MPL::And{}
		};
	}

	template <typename L, typename R, typename = MPL::EnableIf_t<
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<L>>::value &&
		MPL::IsBaseOf<Function_t, MPL::RemoveCVR_t<R>>::value >>
	constexpr auto operator || (L&& lhs, R&& rhs) noexcept
	{
		return Lib::BinaryFn<MPL::RemoveCVR_t<L>, MPL::RemoveCVR_t<R>, ::MPL::Or>{
			static_cast<L&&>(lhs), static_cast<R&&>(rhs), ::MPL::Or{}
		};
	}
}




#endif

