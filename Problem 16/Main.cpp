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

auto multiplyByTwo(const std::string& num) -> std::string {
  const auto numLength{ static_cast<int>(num.size()) };

  auto result  { std::string{} };
  auto carry   { 0 };
  auto product { 0 };

  for (auto i{ numLength - 1 }; i >= 0; i--) {
    product  = (num[i] - '0') * 2 + carry;
    carry    = product / 10;
    product %= 10;

    result.insert(result.begin(), static_cast<char>(product) + '0');
  }

  if (carry > 0)
    result.insert(result.begin(), static_cast<char>(carry) + '0');

  return result;
}

auto main() -> int {
  constexpr auto exponent{ 1000 };

  auto sum { 0 };
  auto num { std::string{"1"} };

  for (auto i{ 0 }; i < exponent; i++)
    num = multiplyByTwo(num);

  for (const auto& c : num)
    sum += c - '0';

  std::cout << sum << std::endl;

  return 0;
}