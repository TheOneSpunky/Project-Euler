/**
 * Project Euler: Problem 030
 * Digit fifth Powers
 * Solution written by Kyle Swecker
 * 
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 * 
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * 
 * As 1 = 1^4 is not a sum it is not included.
 * 
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * 
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <iostream>
#include <vector>
#include <cmath>

static auto isSumOfFifthPowers(const int n) -> bool {
  auto sum  { 0 };
  auto temp { n };

  while (temp > 0) {
    sum  += std::pow(temp % 10, 5);
    temp /= 10;
  }

  return sum == n;
}

static auto digitFifthPowers() -> int {
  constexpr auto limit { 354294 };
  auto           sum   { 0 };

  for (auto i { 10 }; i < limit; i++)
    if (isSumOfFifthPowers(i))
      sum += i;

  return sum;
}

auto main() -> int {
  const auto sum { digitFifthPowers() };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
