/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Impl/TraitsImpl.h
\brief
	Type traits metafunctions ported from the STL.
	It is done this way for three main reasons:
	  1. We use a different naming convention from the STL
	  2. Allows easy substitution of the STL's version (missing due to STL version etc.)
	  3. Allows easy replacement of custom implementation with the STL's version

	Furthermore, it allows us to add metafunctions while keeping everything in one place.
*/
/* HEADER END *****************************************************************************/
#ifndef _META_IMPL_TRAITS_H_
#define _META_IMPL_TRAITS_H_

#include <type_traits>


namespace MP { namespace Lib
{
	template <typename Ty> using IsIntegral                                         = ::std:: is_integral                         <Ty>;
	template <typename Ty> using IsSigned                                           = ::std:: is_signed                           <Ty>;
	template <typename Ty> using IsUnsigned                                         = ::std:: is_unsigned                         <Ty>;
	template <typename Ty> using IsFloat                                            = ::std:: is_floating_point                   <Ty>;
	template <typename Ty> using IsObject                                           = ::std:: is_object                           <Ty>;

	template <typename Ty> using IsVoid                                             = ::std:: is_void                             <Ty>;
	template <typename Ty> using IsNullptr                                          = ::std:: is_null_pointer                     <Ty>;
	template <typename Ty> using IsFunction                                         = ::std:: is_function                         <Ty>;
	template <typename Ty> using IsArray                                            = ::std:: is_array                            <Ty>;

	template <typename Ty> using IsEnum                                             = ::std:: is_enum                             <Ty>;
	template <typename Ty> using IsUnion                                            = ::std:: is_union                            <Ty>;
	template <typename Ty> using IsClass                                            = ::std:: is_class                            <Ty>;
	template <typename Ty> using IsEmptyClass                                       = ::std:: is_empty                            <Ty>;
	template <typename Ty> using IsAbstract                                         = ::std:: is_abstract                         <Ty>;
	template <typename Ty> using IsPolymorphic                                      = ::std:: is_polymorphic                      <Ty>;
	template <typename Ty> using IsFinal                                            = ::std:: is_final                            <Ty>;
	template <typename Ty> using HasVirtualDestructor                               = ::std:: has_virtual_destructor              <Ty>;

	template <typename Ty> using IsPointer                                          = ::std:: is_pointer                          <Ty>;
	template <typename Ty> using IsReference                                        = ::std:: is_reference                        <Ty>;
	template <typename Ty> using IsLRef                                             = ::std:: is_lvalue_reference                 <Ty>;
	template <typename Ty> using IsRRef                                             = ::std:: is_rvalue_reference                 <Ty>;

	template <typename Ty> using IsMemberPtr                                        = ::std:: is_member_pointer                   <Ty>;
	template <typename Ty> using IsDataMemberPtr                                    = ::std:: is_member_object_pointer            <Ty>;
	template <typename Ty> using IsFunctionMemberPtr                                = ::std:: is_member_function_pointer          <Ty>;

	template <typename   T1, typename T2>     using IsSame				            = ::std:: is_same                             <T1, T2>;
	template <typename From, typename To>     using IsConvertable		            = ::std:: is_convertible                      <From, To>;
	template <typename Base, typename Ty>     using IsBaseOf			            = ::std:: is_base_of                          <Base, Ty>;

	template <typename F, typename ... Ts>    using IsInvokable                     = ::std:: is_invocable                        <F, Ts ...>;
	template <typename F, typename ... Ts>   struct IsPartiallyApplicable;

	template <typename Ty, typename ... Ps>   using IsConstructible                 = ::std:: is_constructible                    <Ty, Ps ...>;
	template <typename Ty, typename ... Ps>   using IsTriviallyConstructible        = ::std:: is_trivially_constructible          <Ty, Ps ...>;
	template <typename Ty, typename ... Ps>   using IsNothrowConstructible          = ::std:: is_nothrow_constructible            <Ty, Ps ...>;
	template <typename Ty>                    using IsCopyConstructible             = ::std:: is_copy_constructible               <Ty>;
	template <typename Ty>                    using IsMoveConstructible             = ::std:: is_move_constructible               <Ty>;
	template <typename Ty>                    using IsDefaultConstructible          = ::std:: is_default_constructible            <Ty>;
	template <typename Ty>                    using IsTriviallyCopyConstructible    = ::std:: is_trivially_copy_constructible     <Ty>;
	template <typename Ty>                    using IsTriviallyMoveConstructible    = ::std:: is_trivially_move_constructible     <Ty>;
	template <typename Ty>                    using IsTriviallyDefaultConstructible = ::std:: is_trivially_default_constructible  <Ty>;
	template <typename Ty>                    using IsNothrowCopyConstructible      = ::std:: is_nothrow_copy_constructible       <Ty>;
	template <typename Ty>                    using IsNothrowMoveConstructible      = ::std:: is_nothrow_move_constructible       <Ty>;
	template <typename Ty>                    using IsNothrowDefaultConstructible   = ::std:: is_nothrow_default_constructible    <Ty>;
	
	template <typename Ty, typename ... Ps>   using IsConstructable                 = IsConstructible                  <Ty, Ps ...>;
	template <typename Ty, typename ... Ps>   using IsTriviallyConstructable        = IsTriviallyConstructible         <Ty, Ps ...>;
	template <typename Ty, typename ... Ps>   using IsNothrowConstructable          = IsNothrowConstructible           <Ty, Ps ...>;
	template <typename Ty>                    using IsCopyConstructable             = IsCopyConstructible              <Ty>;
	template <typename Ty>                    using IsMoveConstructable             = IsMoveConstructible              <Ty>;
	template <typename Ty>                    using IsDefaultConstructable          = IsDefaultConstructible           <Ty>;
	template <typename Ty>                    using IsTriviallyCopyConstructable    = IsTriviallyCopyConstructible     <Ty>;
	template <typename Ty>                    using IsTriviallyMoveConstructable    = IsTriviallyMoveConstructible     <Ty>;
	template <typename Ty>                    using IsTriviallyDefaultConstructable = IsTriviallyDefaultConstructible  <Ty>;
	template <typename Ty>                    using IsNothrowCopyConstructable      = IsNothrowCopyConstructible       <Ty>;
	template <typename Ty>                    using IsNothrowMoveConstructable      = IsNothrowMoveConstructible       <Ty>;
	template <typename Ty>                    using IsNothrowDefaultConstructable   = IsNothrowDefaultConstructible    <Ty>;

	template <typename Ty>                    using IsDestructible                  = ::std:: is_destructible          <Ty>;
	template <typename Ty>                    using IsDestructable                  = IsDestructible                   <Ty>;

	template <typename To, typename From>     using IsAssignable                    = ::std:: is_assignable                       <To, From>;
	template <typename To, typename From>     using IsTriviallyAssignable           = ::std:: is_trivially_assignable             <To, From>;
	template <typename To, typename From>     using IsNothrowAssignable             = ::std:: is_nothrow_assignable               <To, From>;

	template <typename Ty>                    using IsCopyAssignable                = ::std:: is_copy_assignable                  <Ty>;
	template <typename Ty>                    using IsMoveAssignable                = ::std:: is_move_assignable                  <Ty>;
	template <typename Ty>                    using IsTriviallyCopyAssignable       = ::std:: is_trivially_copy_assignable        <Ty>;
	template <typename Ty>                    using IsTriviallyMoveAssignable       = ::std:: is_trivially_move_assignable        <Ty>;
	template <typename Ty>                    using IsNothrowCopyAssignable         = ::std:: is_nothrow_copy_assignable          <Ty>;
	template <typename Ty>                    using IsNothrowMoveAssignable         = ::std:: is_nothrow_move_assignable          <Ty>;
	
	template <typename Ty>                    using IsTrivial                       = ::std:: is_trivial                          <Ty>;
	template <typename Ty>                    using IsTriviallyCopyable             = ::std:: is_trivially_copyable               <Ty>;

	template <typename Ty>                    using Rank                             = ::std:: rank                               <Ty>;
	template <typename Ty>                    using UnderlyingType                   = ::std:: underlying_type                    <Ty>;
	template <typename Ty, unsigned _idx = 0> using Extent                           = ::std:: extent                             <Ty, _idx>;



/* Custom Implementations Below ============================================================================================================ */

	namespace detail {
		constexpr ::std::size_t PartiallyApplicableGuesses = 48;
		struct Anything;

		template <typename F, typename ... Ts>
		struct IsPartiallyApplicableAux;
	}

	template <typename F, typename ... Ts>
	struct IsPartiallyApplicable
	{
		static constexpr bool value = [] {
			if constexpr (IsFunction<F>::value || IsClass<F>::value)
				return detail::IsPartiallyApplicableAux<F, Ts...>::value;
			else
				return false;
		}();

		using value_type = decltype(value);
	};


	namespace detail {
		struct Anything
		{
			template <typename T> operator T &  (void) const noexcept;
			template <typename T> operator T && (void) const noexcept;
		};

		template <typename F, typename ... Ts>
		struct IsPartiallyApplicableAux
		{
			template <::std::size_t ... Vs>
			static constexpr bool Aux2 (::std::index_sequence<Vs ...>) noexcept {
				return IsInvokable<F, Ts..., decltype(void(Vs), ::std::declval<Anything>()) ...>::value;
			}

			template <::std::size_t ... Vs>
			static constexpr bool Aux1(::std::index_sequence<Vs ...>) noexcept {
				return (Aux2(::std::make_index_sequence<Vs> {}) || ...);
			}

			static constexpr bool value = [] {
				return Aux1(std::make_index_sequence< PartiallyApplicableGuesses >{});
			} ();
		};
	}
}}

namespace MPL = MP::Lib;




#endif

