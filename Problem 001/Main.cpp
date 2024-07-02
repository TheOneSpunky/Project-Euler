/**
 * Project Euler: Problem 001
 * Multiples of 3 or 5
 * Solution written by Kyle Swecker
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>

static constexpr auto sumOfMultiples(const int n, const int target) -> int {
  const auto p { (target - 1) / n };

  return (n * p * (p + 1) / 2);
}

auto main() -> int {
  constexpr auto first  { 3 };
  constexpr auto second { 5 };
  constexpr auto third  { first * second };
  constexpr auto target { 1000 };
  constexpr auto sum    { sumOfMultiples(first, target) + sumOfMultiples(second, target) - sumOfMultiples(third, target) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
