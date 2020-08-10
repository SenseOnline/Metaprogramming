/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/Concept.h
\brief
	Emulation of C++ concepts with a not too optimal syntax.
	Since we're trying to support C++14, we can't use actual concepts.
	
	We use static_cast instead of forward for the sake of avoiding an include

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_CONCEPT_H_
#define _META_FN_CONCEPT_H_

#include "../types/Type.h"
#include "../types/Constant.h"
#include "../metafunction/Conditional.h"

#include "utils/function/Function.h"


namespace MP
{
    namespace Lib
    {
        class Concept
        {
        public:

            template <typename Pred>
            constexpr auto operator () (Pred) const noexcept
            {
                return ConceptF<Pred> {};
            }


        private:

            template <typename Pred>
            class ConceptF : public Ut::Function_t
            {
            public:
                template <typename ... Ts>
                constexpr auto operator () (Ts&& ...) const noexcept
                {
                    return Aux<Ts ...>(int{});
                }
         
            private:

                template <bool BOOL>
                static Constant<bool, BOOL> ConditionalPassAux(Constant<bool, BOOL>) {};
                static Constant<bool, true> ConditionalPassAux(                 ...) {};

                template <typename ... Ts>
                static constexpr auto Aux(...) noexcept { return ::MP:: False; }

                template <typename ... Ts, class V = decltype(::MP:: 
                    declval<Pred>() (::MP:: declval<Type_t<Ts>>() ...))>
                static constexpr auto Aux(int) noexcept 
                { 
                    return decltype(  ConditionalPassAux(::MP::
                        declval<Conditional_t<IsSame<void, V>::value, int, V>>() 
                    )) {}; 
                }
            };

        };
    }
    
    inline constexpr Lib::Concept Concept = {};
}




#endif

