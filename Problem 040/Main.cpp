/**
 * Project Euler: Problem 040
 * Champernowne's Constant
 * Solution written by Kyle Swecker
 * 
 * An irrational decimal fraction is created by concatenating the positive integers:
 * 
 * 0.123456789101112131415161718192021...
 * 
 * It can be seen that the 12th digit of the fractional part is 1.
 * 
 * If d_n represents the nth digit of the fractional part, find the value of the following expression:
 * 
 * d_1 * d_10 * d_100 * d_1000 * d_10000 * d_100000 * d_1000000
 */

#include <iostream>
#include <string>
#include <array>

static auto getNthDigit(const std::size_t n) -> char {
  auto sequence { std::string{} };

  for (auto i { std::size_t{1} }; sequence.size() < n; i++)
    sequence += std::to_string(i);

  return sequence[n - 1];
}

static auto findDigitProduct() -> int {
  constexpr auto positions { std::array<std::size_t, 7>{1, 10, 100, 1000, 10000, 100000, 1000000} };
  auto           product   { 1 };

  for (const auto& position : positions)
    product *= getNthDigit(position) - '0';

  return product;
}

auto main() -> int {
  const auto digitProduct { findDigitProduct() };

  std::cout << "Answer: " << digitProduct << std::endl;

  return 0;
}
