/* HEADER *********************************************************************************/
/*!
\file	Meta/Types/MetaConstants.h
\brief
	Defines compile time constants as a type. A la std::integral_constant

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_TYPES_CONSTANT_H_
#define _META_TYPES_CONSTANT_H_


namespace MP
{
	namespace Lib
	{
		// @TODO : Consider using std::integral_constant ? -- operator() only available in C++14 but we're stuck with 14 minumum anyway
		template <typename T, T _v>
		struct Constant
		{
			using type       = Constant;
			using value_type = T;
			inline static constexpr T value = _v;

			inline constexpr T operator () (void) const noexcept(noexcept(T(_v))) { return     value; }
			inline constexpr   operator T  (void) const noexcept(noexcept(T(_v))) { return (*this)(); }
		};
	}


	// Defines for common types

	template <typename T, T      _v> inline constexpr auto Constant  = Lib::Constant<T,                  _v> { };
	template <bool               _v> inline constexpr auto Bool      = Lib::Constant<bool,               _v> { };
	template <int                _v> inline constexpr auto Int       = Lib::Constant<int,                _v> { };
	template <short              _v> inline constexpr auto Short     = Lib::Constant<short,              _v> { };
	template <char               _v> inline constexpr auto Char      = Lib::Constant<char,               _v> { };
	template <wchar_t            _v> inline constexpr auto wChar     = Lib::Constant<wchar_t,            _v> { };
	template <long               _v> inline constexpr auto Long      = Lib::Constant<long,               _v> { };
	template <long long          _v> inline constexpr auto LongLong  = Lib::Constant<long long,          _v> { };
	template <unsigned int       _v> inline constexpr auto Unsigned  = Lib::Constant<unsigned,           _v> { };
	template <unsigned short     _v> inline constexpr auto uShort    = Lib::Constant<unsigned short,     _v> { };
	template <unsigned long      _v> inline constexpr auto uLong     = Lib::Constant<unsigned long,      _v> { };
	template <unsigned long long _v> inline constexpr auto uLongLong = Lib::Constant<unsigned long long, _v> { };

	inline constexpr auto True  = Bool <true >;
	inline constexpr auto False = Bool <false>;
	template <unsigned int       _v> inline constexpr auto uInt = Unsigned <_v>;
	template <unsigned long long _v> inline constexpr auto uLL  = uLongLong<_v>;
}



#endif		// INCLUDE GUARD

