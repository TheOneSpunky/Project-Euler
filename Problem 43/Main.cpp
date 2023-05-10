/**
 * Project Euler Problem 43: Sub-string divisibility
 * 
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 *
 * Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on. In this way, we note the following:
 *
 * d_2d_3d_4=406 is divisible by 2
 * d_3d_4d_5=063 is divisible by 3
 * d_4d_5d_6=635 is divisible by 5
 * d_5d_6d_7=357 is divisible by 7
 * d_6d_7d_8=572 is divisible by 11
 * d_7d_8d_9=728 is divisible by 13
 * d_8d_9d_10=289 is divisible by 17
 * 
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

auto hasSubstringDivisibility(const std::vector<int>& digits) -> bool {
  constexpr auto divisors{ std::array<int, 7>{2, 3, 5, 7, 11, 13, 17} };

  for (auto i{ 1ULL }; i < digits.size() - 2; i++) {
    const auto num{ digits[i] * 100 + digits[i + 1] * 10 + digits[i + 2] };

    if (num % divisors[i - 1] != 0)
      return false;
  }

  return true;
}

auto vectorToNumber(const std::vector<int>& digits) -> long long {
  auto num{ 0LL };

  for (const int& digit : digits)
    num = num * 10 + digit;

  return num;
}

auto generatePandigitalNumbers(std::vector<int>& digits, const int& depth, long long& sum) -> void {
  if (depth == digits.size()) {
    if (hasSubstringDivisibility(digits))
      sum += vectorToNumber(digits);

    return;
  }

  for (auto i{ depth }; i < digits.size(); i++) {
    std::swap(digits[i], digits[depth]);
    generatePandigitalNumbers(digits, depth + 1, sum);
    std::swap(digits[i], digits[depth]);
  }
}

auto main() -> int {
  auto digits { std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
  auto sum    { 0LL };

  generatePandigitalNumbers(digits, 0, sum);

  std::cout << sum << std::endl;

  return 0;
}