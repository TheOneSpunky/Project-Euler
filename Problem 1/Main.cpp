/**
 * Project Euler Problem 1: Multiples of 3 or 5
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>

auto main() -> int {
  constexpr auto limit { 1000 };
  constexpr auto a     { 3 };
  constexpr auto b     { 5 };
  constexpr auto c     { a * b };

  const auto sumMultiples {
    [&limit](const int& factor) -> int {
      const auto n{ (limit - 1) / factor };
      return (factor * n * (n + 1) / 2);
    }
  };

  const auto sum{ sumMultiples(a) + sumMultiples(b) - sumMultiples(c) };

  std::cout << sum << std::endl;

  return 0;
}