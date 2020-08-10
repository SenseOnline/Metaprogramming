/* HEADER *********************************************************************************/
/*!
\file	Meta/Types/Type.h
\brief
	Convert types to into objects that can be passed into functions as parameters

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_TYPES_TYPE_H_
#define _META_TYPES_TYPE_H_


namespace MP
{
	// Error type
	struct NULL_TYPE;

	// Delibrately undefined
	template <typename T> T declval(void) noexcept;

	namespace Lib
	{
		template <typename Ty>
		struct Type
		{
			using type = Ty;
		};

		template <typename Ty> struct Type<Type<Ty>         > : Type<Ty> { };
		template <typename Ty> struct Type<Type<Ty> &       > : Type<Ty> { };
		template <typename Ty> struct Type<Type<Ty> &&      > : Type<Ty> { };
		template <typename Ty> struct Type<Type<Ty> const & > : Type<Ty> { };
		template <typename Ty> struct Type<Type<Ty> const &&> : Type<Ty> { };

		template <>
		struct Type<NULL_TYPE>
		{
			// SFINAE Friendly?
		};

		template <typename Ty>
		using Type_t = typename Type<Ty>::type;
	}


	template <typename Ty>
	inline constexpr Lib::Type<Ty> Type = {};


	// Additional Helper (undefined) Functions
	template <typename Ty> Lib::Type<Ty>  GetType(Ty)            noexcept;
	template <typename Ty> Lib::Type<Ty>  GetType(Lib::Type<Ty>) noexcept;
}



#endif		// INCLUDE GUARD
