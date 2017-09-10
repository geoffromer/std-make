// Copyright (C) 2017 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Based on https://github.com/akrzemi1/explicit/blob/master/test/test_explicit.cpp

// <experimental/numerics/v1/numbers/double_wide_types.hpp>
#include <iostream>
#include <experimental/numerics/v1/numbers/double_wide_types.hpp>
#include <string>

#include <boost/detail/lightweight_test.hpp>

namespace stdex = std::experimental;
namespace nmx = std::experimental::numerics;

static_assert(std::is_same<decltype(nmx::to_signed(1)), int>::value, "error");
static_assert(std::is_same<decltype(nmx::to_signed(1u)), int>::value, "error");
static_assert(std::is_same<decltype(nmx::to_unsigned(1)), unsigned int>::value, "error");
static_assert(std::is_same<decltype(nmx::to_unsigned(1u)), unsigned int>::value, "error");

static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::int8_t>(1))), std::int16_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::uint8_t>(1))), std::uint16_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::int16_t>(1))), std::int32_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::uint16_t>(1))), std::uint32_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::int32_t>(1))), std::int64_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_double(static_cast<std::uint32_t>(1))), std::uint64_t>::value, "error");

static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::int16_t>(1))), std::int8_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::uint16_t>(1))), std::uint8_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::int32_t>(1))), std::int16_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::uint32_t>(1))), std::uint16_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::int64_t>(1))), std::int32_t>::value, "error");
static_assert(std::is_same<decltype(nmx::to_half(static_cast<std::uint64_t>(1))), std::uint32_t>::value, "error");

int main()
{

  BOOST_TEST_EQ(nmx::to_signed(1), 1);
  BOOST_TEST_EQ(nmx::to_signed(1u), 1);

  BOOST_TEST_EQ(nmx::to_unsigned(1), 1u);
  BOOST_TEST_EQ(nmx::to_unsigned(1u), 1u);

  BOOST_TEST_EQ(nmx::to_double(static_cast<std::int32_t>(1)), static_cast<std::int64_t>(1));
  BOOST_TEST_EQ(nmx::to_double(static_cast<std::uint32_t>(1u)), static_cast<std::uint64_t>(1u));

  BOOST_TEST_EQ(nmx::to_half(static_cast<std::int32_t>(1)), static_cast<std::int16_t>(1));
  BOOST_TEST_EQ(nmx::to_half(static_cast<std::uint32_t>(1u)), static_cast<std::uint16_t>(1u));

  BOOST_TEST_EQ(nmx::split_upper(0x00010002), static_cast<unsigned short>(0x0001));
  BOOST_TEST_EQ(nmx::split_lower(0x00010002), static_cast<unsigned short>(0x0002));

  BOOST_TEST_EQ(nmx::split_upper(-1), static_cast<unsigned short>(0xffff));
  BOOST_TEST_EQ(nmx::split_lower(-1), static_cast<unsigned short>(0xffff));

  BOOST_TEST_EQ(nmx::wide_signed(static_cast<unsigned short>(0xffff), static_cast<unsigned short>(0xffff)), -1);
  BOOST_TEST_EQ(nmx::wide_unsigned(static_cast<unsigned short>(0xffff), static_cast<unsigned short>(0xffff)), static_cast<unsigned>(-1));

  return ::boost::report_errors();
}

