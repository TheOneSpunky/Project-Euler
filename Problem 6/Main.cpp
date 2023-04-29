/**
 * Project Euler Problem 6: Sum square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 * 
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * 
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * 
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>
#include <numeric>
#include <array>

auto main() -> int {
  constexpr auto n{ 100 };

  const auto sum          { n * (n + 1) / 2 };
  const auto squareOfSum  { sum * sum };
  const auto sumOfSquares { n * (n + 1) * (2 * n + 1) / 6 };
  const auto difference   { squareOfSum - sumOfSquares };

  std::cout << difference << std::endl;

  return 0;
}