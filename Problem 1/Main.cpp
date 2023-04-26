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

  auto sum{ 0 };

  for (auto i{ 1 }; i < limit; i++)
    if (i % a == 0 || i % b == 0)
      sum += i;

  std::cout << sum << std::endl;

  return 0;
}