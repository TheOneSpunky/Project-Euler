/**
 * Project Euler Problem 16: Power digit sum
 * 
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

auto multiply(const std::string& a, const std::string& b) -> std::string {
  const auto aLength { static_cast<int>(a.size()) };
  const auto bLength { static_cast<int>(b.size()) };

  auto result{ std::vector<int>(aLength + bLength, 0) };

  for (auto i{ aLength - 1 }; i >= 0; i--)
    for (auto j{ bLength - 1 }; j >= 0; j--) {
      const auto product { (a[i] - '0') * (b[j] - '0') };
      const auto tempSum { result[i + j + 1] + product };

      result[i + j + 1]  = tempSum % 10;
      result[i + j]     += tempSum / 10;
    }

  auto resultStr{ std::string{} };

  for (auto i{ 0 }; i < result.size(); i++) {
    if (i == 0 && result[i] == 0)
      continue;

    resultStr += std::to_string(result[i]);
  }

  return resultStr;
}

auto powerOfTwo(int exponent) -> std::string {
  auto num  { std::string{"1"} };
  auto base { std::string{"2"} };

  while (exponent > 0) {
    if (exponent % 2 == 1)
      num = multiply(num, base);

    base      = multiply(base, base);
    exponent /= 2;
  }

  return num;
}

auto main() -> int {
  constexpr auto exponent{ 1000 };

  auto sum { 0 };
  auto num { powerOfTwo(exponent) };

  for (const char& c : num)
    sum += c - '0';

  std::cout << sum << std::endl;

  return 0;
}