/**
 * Project Euler: Problem 006
 * Sum Square Difference
 * Solution written by Kyle Swecker
 * 
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * 
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * 
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>

static constexpr auto sumOfSquares(int n) -> int {
  return (n * (n + 1) * (2 * n + 1) / 6);
}

static constexpr auto squareOfSum(int n) -> int {
  const auto sum { n * (n + 1) / 2 };

  return (sum * sum);
}

static constexpr auto difference(int n) -> int {
  return (squareOfSum(n) - sumOfSquares(n));
}

auto main() -> int {
  constexpr auto n { 100 };
  constexpr auto d { difference(n) };

  std::cout << "Answer: " << d << std::endl;

  return 0;
}
