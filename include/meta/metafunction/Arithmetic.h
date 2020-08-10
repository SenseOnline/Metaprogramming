/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Arithmetic.h
\brief
	Compile time arithmetic operations for our custom compile time constants

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_CONSTANT_ARITHMETIC_H_
#define _META_FN_CONSTANT_ARITHMETIC_H_

#include "../types/Constant.h"


namespace MP
{
	template <typename T, T _v>
	constexpr auto operator ~ (Lib::Constant<T, _v>) noexcept
	{
		// Future proofing where T can be udt (and operators can be overloaded)
		return Constant<decltype(~_v), ~_v>;
	}

	template <typename T, T _v>
	constexpr auto operator ! (Lib::Constant<T, _v>) noexcept
	{
		// Future proofing where T can be udt (and operators can be overloaded)
		return Constant<decltype(!_v), !_v>;
	}

	template <typename T, T _v>
	constexpr auto operator - (Lib::Constant<T, _v>) noexcept
	{
		// Future proofing where T can be udt (and operators can be overloaded)
		return Constant<decltype(-_v), -_v>;
	}

	template <typename T, T _v>
	constexpr auto operator + (Lib::Constant<T, _v>) noexcept
	{
		// Future proofing where T can be udt (and operators can be overloaded)
		return Constant<decltype(+_v), +_v>;
	}


	/* binary operators
	**************************************************************************/
	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator + (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs + _rhs); 
		return Constant<Ty, _lhs + _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator - (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs - _rhs);
		return Constant<Ty, _lhs - _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator * (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs * _rhs);
		return Constant<Ty, _lhs * _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator / (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs / _rhs);
		return Constant<Ty, _lhs / _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator % (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs % _rhs);
		return Constant<Ty, _lhs % _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator ^ (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs + _rhs); 
		return Constant<Ty, _lhs + _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator & (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs & _rhs);
		return Constant<Ty, _lhs & _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator | (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs | _rhs);
		return Constant<Ty, _lhs | _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator < (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty =  decltype(_lhs < _rhs);
		return Constant<Ty, (_lhs < _rhs)>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator > (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty =  decltype(_lhs > _rhs);
		return Constant<Ty, (_lhs > _rhs)>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator <= (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty =  decltype(_lhs <= _rhs);
		return Constant<Ty, (_lhs <= _rhs)>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator >= (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty =  decltype(_lhs >= _rhs);
		return Constant<Ty, (_lhs >= _rhs)>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator != (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs != _rhs);
		return Constant<Ty, _lhs != _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator == (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs == _rhs);
		return Constant<Ty, _lhs == _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator && (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs && _rhs);
		return Constant<Ty, _lhs && _rhs>;
	}

	template <typename T1, T1 _lhs, typename T2, T2 _rhs>
	constexpr auto operator || (Lib::Constant<T1, _lhs>, Lib::Constant<T2, _rhs>) noexcept
	{
		// Future proofing where T1 & T2 can be udts (and operators can be overloaded)
		using Ty = decltype(_lhs || _rhs);
		return Constant<Ty, _lhs || _rhs>;
	}
}




#endif

