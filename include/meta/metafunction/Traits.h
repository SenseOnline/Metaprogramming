/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Traits.h
\brief
	Type traits metafunctions

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_TRAITS_H_
#define _META_FN_TRAITS_H_

#include "impl/TraitsImpl.h"

#include "Concept.h"
#include "../types/MetaFunction.h"
#include "utils/function/FnOps.h"
#include "utils/function/Flip.h"


namespace MP
{
	inline constexpr auto IsIntegral                      = Lib::MetaFunctionV<Lib:: IsIntegral >{};
	inline constexpr auto IsSigned                        = Lib::MetaFunctionV<Lib:: IsSigned   >{};
	inline constexpr auto IsUnsigned                      = Lib::MetaFunctionV<Lib:: IsUnsigned >{};
	inline constexpr auto IsFloat                         = Lib::MetaFunctionV<Lib:: IsFloat    >{};
	inline constexpr auto IsObject                        = Lib::MetaFunctionV<Lib:: IsObject   >{};

	inline constexpr auto IsVoid                          = Lib::MetaFunctionV<Lib:: IsVoid     >{};
	inline constexpr auto IsNullptr                       = Lib::MetaFunctionV<Lib:: IsNullptr  >{};
	inline constexpr auto IsFunction                      = Lib::MetaFunctionV<Lib:: IsFunction >{};
	inline constexpr auto IsArray                         = Lib::MetaFunctionV<Lib:: IsArray    >{};

	inline constexpr auto IsEnum                          = Lib::MetaFunctionV<Lib:: IsEnum        >{};
	inline constexpr auto IsUnion                         = Lib::MetaFunctionV<Lib:: IsUnion       >{};
	inline constexpr auto IsClass                         = Lib::MetaFunctionV<Lib:: IsClass       >{};
	inline constexpr auto IsEmptyClass                    = Lib::MetaFunctionV<Lib:: IsEmptyClass  >{};
	inline constexpr auto IsAbstract                      = Lib::MetaFunctionV<Lib:: IsAbstract    >{};
	inline constexpr auto IsPolymorphic                   = Lib::MetaFunctionV<Lib:: IsPolymorphic >{};
	inline constexpr auto IsFinal                         = Lib::MetaFunctionV<Lib:: IsFinal       >{};

	inline constexpr auto Rank                            = Lib::MetaFunctionV<Lib:: Rank           >{};
	inline constexpr auto Extent                          = Lib::MetaFunctionV<Lib:: Extent         >{};
	inline constexpr auto UnderlyingType                  = Lib::MetaFunction <Lib:: UnderlyingType >{};

	inline constexpr auto IsPointer                       = Lib::MetaFunctionV<Lib:: IsPointer   >{};
	inline constexpr auto IsReference                     = Lib::MetaFunctionV<Lib:: IsReference >{};
	inline constexpr auto IsLRef                          = Lib::MetaFunctionV<Lib:: IsLRef      >{};
	inline constexpr auto IsRRef                          = Lib::MetaFunctionV<Lib:: IsRRef      >{};
	inline constexpr auto IsPtr                           = IsPointer;                                          // shorthand
	inline constexpr auto IsRef                           = IsReference;                                        // shorthand

	inline constexpr auto IsMemberPtr                     = Lib::MetaFunctionV<Lib:: IsMemberPtr         >{};
	inline constexpr auto IsDataMemberPtr                 = Lib::MetaFunctionV<Lib:: IsDataMemberPtr     >{};
	inline constexpr auto IsFunctionMemberPtr             = Lib::MetaFunctionV<Lib:: IsFunctionMemberPtr >{};

	inline constexpr auto IsSame                          = Lib::MetaFunctionV<Lib:: IsSame                >{};
	inline constexpr auto IsInvokable                     = Lib::MetaFunctionV<Lib:: IsInvokable           >{};
	inline constexpr auto IsPartiallyApplicable           = Lib::MetaFunctionV<Lib:: IsPartiallyApplicable >{};
	inline constexpr auto IsConvertable                   = Lib::MetaFunctionV<Lib:: IsConvertable         >{};
	inline constexpr auto IsBaseOf                        = Lib::MetaFunctionV<Lib:: IsBaseOf              >{};
	inline constexpr auto IsDerivedFrom                   = ::Ut::Flip(IsBaseOf) && IsConvertable;

	inline constexpr auto IsConstructable                 = Lib::MetaFunctionV<Lib:: IsConstructable                 >{};
	inline constexpr auto IsCopyConstructable             = Lib::MetaFunctionV<Lib:: IsCopyConstructable             >{};
	inline constexpr auto IsMoveConstructable             = Lib::MetaFunctionV<Lib:: IsMoveConstructable             >{};
	inline constexpr auto IsDefaultConstructable          = Lib::MetaFunctionV<Lib:: IsDefaultConstructable          >{};
	inline constexpr auto IsTriviallyConstructable        = Lib::MetaFunctionV<Lib:: IsTriviallyConstructable        >{};
	inline constexpr auto IsTriviallyCopyConstructable    = Lib::MetaFunctionV<Lib:: IsTriviallyCopyConstructable    >{};
	inline constexpr auto IsTriviallyMoveConstructable    = Lib::MetaFunctionV<Lib:: IsTriviallyMoveConstructable    >{};
	inline constexpr auto IsTriviallyDefaultConstructable = Lib::MetaFunctionV<Lib:: IsTriviallyDefaultConstructable >{};
	inline constexpr auto IsNothrowConstructable          = Lib::MetaFunctionV<Lib:: IsNothrowConstructable          >{};
	inline constexpr auto IsNothrowCopyConstructable      = Lib::MetaFunctionV<Lib:: IsNothrowCopyConstructable      >{};
	inline constexpr auto IsNothrowMoveConstructable      = Lib::MetaFunctionV<Lib:: IsNothrowMoveConstructable      >{};
	inline constexpr auto IsNothrowDefaultConstructable   = Lib::MetaFunctionV<Lib:: IsNothrowDefaultConstructable   >{};

	inline constexpr auto IsConstructible                 = Lib::MetaFunctionV<Lib:: IsConstructible                 >{};
	inline constexpr auto IsCopyConstructible             = Lib::MetaFunctionV<Lib:: IsCopyConstructible             >{};
	inline constexpr auto IsMoveConstructible             = Lib::MetaFunctionV<Lib:: IsMoveConstructible             >{};
	inline constexpr auto IsDefaultConstructible          = Lib::MetaFunctionV<Lib:: IsDefaultConstructible          >{};
	inline constexpr auto IsTriviallyConstructible        = Lib::MetaFunctionV<Lib:: IsTriviallyConstructible        >{};
	inline constexpr auto IsTriviallyCopyConstructible    = Lib::MetaFunctionV<Lib:: IsTriviallyCopyConstructible    >{};
	inline constexpr auto IsTriviallyMoveConstructible    = Lib::MetaFunctionV<Lib:: IsTriviallyMoveConstructible    >{};
	inline constexpr auto IsTriviallyDefaultConstructible = Lib::MetaFunctionV<Lib:: IsTriviallyDefaultConstructible >{};
	inline constexpr auto IsNothrowConstructible          = Lib::MetaFunctionV<Lib:: IsNothrowConstructible          >{};
	inline constexpr auto IsNothrowCopyConstructible      = Lib::MetaFunctionV<Lib:: IsNothrowCopyConstructible      >{};
	inline constexpr auto IsNothrowMoveConstructible      = Lib::MetaFunctionV<Lib:: IsNothrowMoveConstructible      >{};
	inline constexpr auto IsNothrowDefaultConstructible   = Lib::MetaFunctionV<Lib:: IsNothrowDefaultConstructible   >{};

	inline constexpr auto IsDestructable                  = Lib::MetaFunctionV<Lib:: IsDestructable                  >{};
	inline constexpr auto IsDestructible                  = Lib::MetaFunctionV<Lib:: IsDestructible                  >{};
	inline constexpr auto IsDefaultInitializable		  = IsDestructable && IsDefaultConstructible &&
															Concept([](auto obj) -> decltype(decltype(obj) {}) {}) &&
															Concept([](auto obj) -> decltype(::new (static_cast<void*>(nullptr)) decltype(obj)) {});

	inline constexpr auto IsAssignable                    = Lib::MetaFunctionV<Lib:: IsAssignable              >{};
	inline constexpr auto IsCopyAssignable                = Lib::MetaFunctionV<Lib:: IsCopyAssignable          >{};
	inline constexpr auto IsMoveAssignable                = Lib::MetaFunctionV<Lib:: IsMoveAssignable          >{};
	inline constexpr auto IsTriviallyAssignable           = Lib::MetaFunctionV<Lib:: IsTriviallyAssignable     >{};
	inline constexpr auto IsTriviallyCopyAssignable       = Lib::MetaFunctionV<Lib:: IsTriviallyCopyAssignable >{};
	inline constexpr auto IsTriviallyMoveAssignable       = Lib::MetaFunctionV<Lib:: IsTriviallyMoveAssignable >{};
	inline constexpr auto IsNothrowAssignable             = Lib::MetaFunctionV<Lib:: IsNothrowAssignable       >{};
	inline constexpr auto IsNothrowCopyAssignable         = Lib::MetaFunctionV<Lib:: IsNothrowCopyAssignable   >{};
	inline constexpr auto IsNothrowMoveAssignable         = Lib::MetaFunctionV<Lib:: IsNothrowMoveAssignable   >{};

	inline constexpr auto IsTrivial                       = Lib::MetaFunctionV<Lib:: IsTrivial                 >{};
	inline constexpr auto IsTriviallyCopyable             = Lib::MetaFunctionV<Lib:: IsTriviallyCopyable       >{};
	inline constexpr auto IsMovable                       = IsObject  && IsMoveAssignable && IsMoveConstructible;
	inline constexpr auto IsCopyable                      = IsMovable && IsCopyAssignable && IsCopyConstructable;

	inline constexpr auto IsEqualityComparableWith        = Concept([](auto&& lhs, auto&& rhs) -> decltype(static_cast<void> (lhs == rhs))     {});
	inline constexpr auto IsEqualityComparable            = Concept([](auto&& obj)             -> decltype(IsEqualityComparableWith(obj, obj)) {});

	inline constexpr auto IsSemiRegular                   = IsDefaultInitializable && IsCopyable;
	inline constexpr auto IsRegular                       = IsSemiRegular && IsEqualityComparable;
	
	inline constexpr auto IsPostIncrementable             = Concept([](auto&& obj) -> decltype(obj++) {});
	inline constexpr auto IsPostDecrementable             = Concept([](auto&& obj) -> decltype(obj--) {});
	inline constexpr auto IsPreIncrementable              = Concept([](auto&& obj) -> decltype(++obj) {});
	inline constexpr auto IsPreDecrementable              = Concept([](auto&& obj) -> decltype(--obj) {});

	inline constexpr auto IsWeaklyIncrementable           = IsDefaultInitializable && IsMovable && IsPostIncrementable &&
															Concept([](auto obj) -> decltype(IsSame(::MP::Type<decltype(obj)&>, ::MP::Type<decltype(++obj)>)) {});
	inline constexpr auto IsWeaklyDecrementable           = IsDefaultInitializable && IsMovable && IsPostDecrementable &&
															Concept([](auto obj) -> decltype(IsSame(::MP::Type<decltype(obj)&>, ::MP::Type<decltype(--obj)>)) {});

	inline constexpr auto IsIncrementable                 = IsRegular && IsWeaklyIncrementable &&
															Concept([](auto obj) -> decltype(IsSame(::MP::Type<decltype(obj)>, ::MP::Type<decltype(obj++)>)) {});
	inline constexpr auto IsDecrementable                 = IsRegular && IsWeaklyDecrementable &&
															Concept([](auto obj) -> decltype(IsSame(::MP::Type<decltype(obj)>, ::MP::Type<decltype(obj--)>)) {});

	inline constexpr auto HasEnd                          = Concept([](auto&& obj) -> decltype(::std::end   (obj)) {});
	inline constexpr auto HasBegin                        = Concept([](auto&& obj) -> decltype(::std::begin (obj)) {});
	inline constexpr auto IsContiguous					  = Concept([](auto&& obj) -> decltype(  obj .data  (   )) {}) || IsArray;
	inline constexpr auto IsRange                         = HasBegin && HasEnd;
	inline constexpr auto IsSpan                          = IsRange  && IsContiguous;
}




#endif

