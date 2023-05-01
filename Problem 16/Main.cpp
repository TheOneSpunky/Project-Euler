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

auto add(const std::string& a, const std::string& b) -> std::string {
  const auto aLength{ static_cast<int>(a.size()) };
  const auto bLength{ static_cast<int>(b.size()) };

  auto result { std::string{} };
  auto carry  { 0 };
  auto sum    { 0 };

  for (auto i{ 0 }; i < std::max(aLength, bLength); i++) {
    sum = carry;

    if (i < aLength)
      sum += a[aLength - 1 - i] - '0';
    if (i < bLength)
      sum += b[bLength - 1 - i] - '0';

    carry  = sum / 10;
    sum   %= 10;

    result.insert(result.begin(), static_cast<char>(sum) + '0');
  }

  if (carry > 0)
    result.insert(result.begin(), static_cast<char>(carry) + '0');

  return result;
}

auto powerOfTwo(int exponent) -> std::string {
  auto num  { std::string{"1"} };
  auto base { std::string{"2"} };

  while (exponent > 0) {
    if (exponent % 2 == 1)
      num = add(num, num);

    base      = add(base, base);
    exponent /= 2;
  }

  return num;
}

auto main() -> int {
  constexpr auto exponent{ 1000 };

  auto sum { 0 };
  auto num { std::string{"1"} };

  for (auto i{ 0 }; i < exponent; i++)
    num = add(num, num);

  for (const auto& c : num)
    sum += c - '0';

  std::cout << sum << std::endl;

  return 0;
}