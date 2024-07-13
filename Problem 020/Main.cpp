/**
 * Project Euler: Problem 020
 * Factorial Digit Sum
 * Solution written by Kyle Swecker
 * 
 * n! means n x (n - 1) x ... x 3 x 2 x 1
 * 
 * For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

static auto multiply(const std::vector<int>& number, const int multiplier) -> std::vector<int> {
  auto result { std::vector<int>{} };
  auto carry  { 0 };

  for (const auto digit : number) {
    const auto product { digit * multiplier + carry };

    result.push_back(product % 10);
    carry = product / 10;
  }

  while (carry) {
    result.push_back(carry % 10);
    carry /= 10;
  }

  return result;
}

static auto calculateFactorial(const int n) -> std::vector<int> {
  auto factorial { std::vector<int>{1} };

  for (auto i { 2 }; i <= n; i++)
    factorial = multiply(factorial, i);
  std::reverse(factorial.begin(), factorial.end());

  return factorial;
}

static auto sumDigits(const std::vector<int>& number) -> int {
  return std::accumulate(number.begin(), number.end(), 0);
}

auto main() -> int {
  const auto factorial { calculateFactorial(100) };
  const auto sum       { sumDigits(factorial) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
