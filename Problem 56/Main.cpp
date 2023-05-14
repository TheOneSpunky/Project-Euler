/**
 * Project Euler Problem 56: Powerful digit sum
 * 
 * A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
 *
 * Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
 */

#include <iostream>
#include <vector>
#include <algorithm>

auto power(const int& a, const int& b) -> std::vector<int> {
  auto result{ std::vector<int>(1, 1) };

  // For each power
  for (auto i{ 0 }; i < b; i++) {
    auto carry{ 0 };

    // For each digit
    for (auto& r : result) {
      const auto prod{ r * a + carry };

      r     = prod % 10;
      carry = prod / 10;
    }

    // While there is still a carry
    while (carry) {
      result.push_back(carry % 10);

      carry /= 10;
    }
  }

  return result;
}

auto digitSum(const std::vector<int>& digits) -> int {
  auto sum{ 0 };

  for (const int& digit : digits)
    sum += digit;

  return sum;
}

auto main() -> int {
  auto maxSum{ 0 };

  for (auto a{ 1 }; a < 100; a++)
    for (auto b{ 1 }; b < 100; b++) {
      const auto digits{ power(a, b) };

      maxSum = std::max(maxSum, digitSum(digits));
    }

  std::cout << maxSum << std::endl;

  return 0;
}