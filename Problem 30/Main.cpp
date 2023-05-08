/**
 * Project Euler Problem 30: Digit fifth powers
 * 
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <iostream>
#include <vector>

auto isSumOfFifthPower(int number, const std::vector<int>& powers) -> bool {
  const auto original { number };
  auto       sum      { 0 };

  while (number > 0) {
    const auto digit{ number % 10 };

    sum    += powers[digit];
    number /= 10;
  }

  return sum == original;
}

auto main() -> int {
  const auto upper   { 6 * static_cast<int>(std::pow(9, 5)) };
  auto       powers  { std::vector<int>(10) };

  for (auto i{ 0 }; i <= 9; i++)
    powers[i] = static_cast<int>(std::pow(i, 5));

  auto sum{ 0 };

  for (auto i{ 10 }; i <= upper; i++)
    if (isSumOfFifthPower(i, powers))
      sum += i;

  std::cout << sum << std::endl;

  return 0;
}