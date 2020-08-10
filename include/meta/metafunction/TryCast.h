/* HEADER *********************************************************************************/
/*!
\file	Meta/MetaFunction/TryCast.h
\brief
    Simulates the syntax of C++ casts.
    Returns a boolean representing the result of:
    is static_cast if attempted, is valid.

	Copyright (c) 2020 SenseOnline
*/
/* HEADER END *****************************************************************************/
#ifndef _META_FN_TRYCAST_H_
#define _META_FN_TRYCAST_H_

#include "../types/Type.h"
#include "../types/Constant.h"

#include "utils/function/Function.h"


namespace MP
{
    namespace Lib
    {
        template <typename To>
        struct TryCast : public Ut::Function_t
        {
        public:

            template <typename From>
            constexpr auto operator () (From&) const noexcept
            {
                return Aux<Type_t<From&>, To> {}();
            }
            template <typename From>
            constexpr auto operator () (From&&) const noexcept
            {
                return Aux<Type_t<From&&>, To> {}();
            }


        private:

            template <typename, typename = To>
            struct Aux
            {
                constexpr auto operator () (void) const noexcept { return ::MP:: False; }
            };

            template <typename From>
            struct Aux<From, decltype(static_cast<To>(MP::declval<From>()))>
            {
                constexpr auto operator () (void) const noexcept { return ::MP:: True; }
            };
        };
    }

    template <typename To>
    inline constexpr Lib::TryCast<To> TryCast = {};
}




#endif

