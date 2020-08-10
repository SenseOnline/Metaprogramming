/* HEADER *********************************************************************************/
/*!
\file	Meta/Types/MetaFunction.h
\brief
	For porting plain old metafunctions to function objects.

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_TYPES_METAFUNCTION_H_
#define _META_TYPES_METAFUNCTION_H_

#include "Type.h"
#include "Constant.h"

#include "utils/function/Function.h"


namespace MP
{
	namespace Lib
	{
		/*!
			Used to adapt metafunctions that produces a type
		*/
		template <template <typename ...> class F>
		struct MetaFunction : public Ut::Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty const& ...) const noexcept
			{
				// @TODO : if ::type doesn't exist
				if constexpr (test<Type_t<Ty> ...>(int{}))
					return ::MP::Type<typename F<Type_t<Ty> ...>::type>;
				else
					return ::MP::Type<NULL_TYPE>;
			}

		private:
			template <typename ... Ty, typename = typename F<Ty...>::type>
			static constexpr bool test(int) { return true;  }
			template <typename ...>
			static constexpr bool test(...) { return false; }
		};

		/*! 
			Used to adapt metafunctions that produces a value
		*/
		template <template <typename ...> class F>
		struct MetaFunctionV : public Ut::Function_t
		{
			template <typename ... Ty>
			constexpr auto operator () (Ty const& ...) const noexcept
			{
				using result = F<Type_t<Ty> ...>;

				// We follow STL naming convention here as this is supposed to adapt the STL
				return MP::Constant<typename result::value_type, result::value>;
			}
		};
	}
}




#endif

