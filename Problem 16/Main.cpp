/**
 * Project Euler Problem 16: Power digit sum
 * 
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include <vector>

auto multiply(const std::vector<int>& a, const std::vector<int>& b) -> std::vector<int> {
  auto result{ std::vector<int>(a.size() + b.size(), 0) };

  for (auto i{ 0ULL }; i < a.size(); i++)
    for (auto j{ 0ULL }; j < b.size(); j++)
      result[i + j + 1] += a[i] * b[j];

  for (auto i{ result.size() - 1 }; i > 0; i--) {
    result[i - 1] += result[i] / 10;
    result[i]     %= 10;
  }

  return result;
}

auto powerOfTwo(int exponent) -> std::vector<int> {
  const auto maxDigits{ 1 + static_cast<int>(1000 * std::log10(2)) };

  auto num  { std::vector<int>(maxDigits, 0) };
  auto base { std::vector<int>{2} };

  num.back() = 1;

  while (exponent > 0) {
    if (exponent % 2 == 1)
      num = multiply(num, base);

    base      = multiply(base, base);
    exponent /= 2;
  }

  return num;
}

auto main() -> int {
  constexpr auto exponent { 1000 };
  const auto     num      { powerOfTwo(exponent) };

  auto sum{ 0 };

  for (const auto& digit : num)
    sum += digit;

  std::cout << sum << std::endl;

  return 0;
}
