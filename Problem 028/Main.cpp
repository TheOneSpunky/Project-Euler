/**
 * Project Euler: Problem 028
 * Number Spiral Diagonals
 * Solution written by Kyle Swecker
 * 
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 * 
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 * 
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * 
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>

static constexpr auto diagonalSum(const int n) -> int {
  auto sum { 1 };

  for (auto i { 3 }; i <= n; i += 2)
    sum += (4 * (i * i) - 6 * (i - 1));

  return sum;
}

auto main() -> int {
  constexpr auto n   { 1001 };
  constexpr auto sum { diagonalSum(n) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
