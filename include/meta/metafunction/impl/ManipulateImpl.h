/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Impl/ManipulateImpl.h
\author Tan Jie Wei Jacky (100%)
\par    email: t.jieweijacky\@digipen.edu
\brief
	Type manipulators metafunctions ported from the STL.
	It is done this way for three main reasons:
	  1. We use a different naming convention from the STL
	  2. Allows easy substitution of the STL's version (missing due to STL version etc.)
	  3. Allows easy replacement of custom implementation with the STL's version

	Furthermore, it allows us to add metafunctions while keeping everything in one place.
*/
/* HEADER END *****************************************************************************/
#ifndef _META_IMPL_MANIPULATE_H_
#define _META_IMPL_MANIPULATE_H_

#include <type_traits>


namespace MP { namespace Lib
{
	template <typename Ty> using Decay            = ::std:: decay                <Ty>;

	template <typename Ty> using RemoveConst      = ::std:: remove_const         <Ty>;
	template <typename Ty> using RemoveVolatile   = ::std:: remove_volatile      <Ty>;
	template <typename Ty> using RemoveReference  = ::std:: remove_reference     <Ty>;
	template <typename Ty> using RemoveCV         = ::std:: remove_cv            <Ty>;
	template <typename Ty> using RemovePointer    = ::std:: remove_pointer       <Ty>;
	template <typename Ty> using RemoveExtent     = ::std:: remove_extent        <Ty>;
	template <typename Ty> using RemoveAllExtents = ::std:: remove_all_extents   <Ty>;

	template <typename Ty> using AddConst         = ::std:: add_const            <Ty>;
	template <typename Ty> using AddVolatile      = ::std:: add_volatile         <Ty>;
	template <typename Ty> using AddCV            = ::std:: add_cv               <Ty>;
	template <typename Ty> using AddLRef          = ::std:: add_lvalue_reference <Ty>;
	template <typename Ty> using AddRRef          = ::std:: add_rvalue_reference <Ty>;
	template <typename Ty> using AddPointer       = ::std:: add_pointer          <Ty>;

	template <typename Ty> using MakeSigned       = ::std:: make_signed          <Ty>;
	template <typename Ty> using MakeUnsigned     = ::std:: make_unsigned        <Ty>;

	template <typename ... Ty> using CommonType   = ::std:: common_type          <Ty ...>;

	template <typename Ty> using RemoveCVRef      = RemoveCV <typename RemoveReference<Ty>::type>;
	template <typename Ty> using RemoveCVR        = RemoveCVRef<Ty>;


	// STL doesn't have these ...

	template <typename T>           struct ElementType        { using type = T; };
	template <typename T>           struct ElementType <T*  > { using type = T; };
	template <typename T>           struct ElementType <T&  > { using type = T; };
	template <typename T>           struct ElementType <T&& > { using type = T; };
	template <typename T>           struct ElementType <T[ ]> { using type = T; };
	template <typename T, size_t N> struct ElementType <T[N]> { using type = T; };


	// Aliases

	template <typename Ty> using Decay_t            = typename Decay            <Ty>::type;
	template <typename Ty> using RemoveConst_t      = typename RemoveConst      <Ty>::type;
	template <typename Ty> using RemoveVolatile_t   = typename RemoveVolatile   <Ty>::type;
	template <typename Ty> using RemoveReference_t  = typename RemoveReference  <Ty>::type;
	template <typename Ty> using RemoveCV_t         = typename RemoveCV         <Ty>::type;
	template <typename Ty> using RemovePointer_t    = typename RemovePointer    <Ty>::type;
	template <typename Ty> using RemoveExtent_t     = typename RemoveExtent     <Ty>::type;
	template <typename Ty> using RemoveAllExtents_t = typename RemoveAllExtents <Ty>::type;

	template <typename Ty> using AddConst_t         = typename AddConst         <Ty>::type;
	template <typename Ty> using AddVolatile_t      = typename AddVolatile      <Ty>::type;
	template <typename Ty> using AddCV_t            = typename AddCV            <Ty>::type;
	template <typename Ty> using AddLRef_t          = typename AddLRef          <Ty>::type;
	template <typename Ty> using AddRRef_t          = typename AddRRef          <Ty>::type;
	template <typename Ty> using AddPointer_t       = typename AddPointer       <Ty>::type;

	template <typename Ty> using MakeSigned_t       = typename MakeSigned       <Ty>::type;
	template <typename Ty> using MakeUnsigned_t     = typename MakeUnsigned     <Ty>::type;

	template <typename ... Ty> using CommonType_t   = typename CommonType       <Ty ...>::type;

	template <typename Ty> using RemoveCVRef_t      = RemoveCV_t<RemoveReference_t<Ty>>;
	template <typename Ty> using RemoveCVR_t        = RemoveCVRef_t<Ty>;
}}

namespace MPL = ::MP::Lib;



#endif

