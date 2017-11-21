// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Copyright (C) 2017 Vicente J. Botet Escriba

#ifndef JASEL_FUNDAMENTAL_V3_STRONG_MIXIN_ORDINAL_HPP
#define JASEL_FUNDAMENTAL_V3_STRONG_MIXIN_ORDINAL_HPP

#include <experimental/fundamental/v2/config.hpp>
#include <experimental/fundamental/v3/strong/strong_type.hpp>
#include <experimental/ordinal.hpp>
#include <experimental/wrapped.hpp>

namespace std
{
  namespace experimental
  {
    inline  namespace fundamental_v3
  {
    namespace mixin
    {
      struct strong_ordinal {};
      template <class Final>
      struct ordinal : strong_ordinal      {      };
    }
    namespace meta_mixin
    {
      template <class = void>
      struct ordinal
      {
        template <class Final>
        using type = mixin::ordinal<Final>;
      };
    }

    template <class W
    , class = enable_if_t<is_ordinal<wrapping::unwrapped_type_t<W>>{}>
    >
    struct wrapped_ordinal_traits
    {
      using T =  wrapping::unwrapped_type_t<W>;
      using size_type = typename ordinal::traits<T>::size_type;
      using size = typename ordinal::traits<T>::size;
      static W val(size_type p) { return W{ordinal::val<T>(p)}; }

      static size_type pos(W w)  { return ordinal::pos(underlying(w)); }
    };

    // An strong_id is an Ordinal type if its underlying type is an Ordinal type.
    namespace ordinal
    {
      template <class T>
      struct traits<T
            , experimental::meta::when<is_base_of<mixin::strong_ordinal,T>::value>
          > : wrapped_ordinal_traits<T> {};
    }
  }
}
}

#endif // header
