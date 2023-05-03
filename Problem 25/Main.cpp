/**
 * Project Euler Problem 25: 1000-digit Fibonacci number
 */

#include <iostream>
#include <string>
#include <algorithm>

auto addStrings(const std::string& num1, const std::string& num2) -> std::string {
  auto result { std::string{} };
  auto carry  { 0 };
  auto p1     { static_cast<int>(num1.size()) - 1 };
  auto p2     { static_cast<int>(num2.size()) - 1 };

  while (p1 >= 0 || p2 >= 0) {
    auto x1      { p1 >= 0 ? num1[p1] - '0' : 0 };
    auto x2      { p2 >= 0 ? num2[p2] - '0' : 0 };
    auto tempSum { x1 + x2 + carry };

    carry = tempSum / 10;

    result.push_back(tempSum % 10 + '0');

    p1--;
    p2--;
  }

  if (carry)
    result.push_back(static_cast<char>(carry) + '0');

  std::reverse(result.begin(), result.end());

  return result;
}

auto main() -> int {
  auto prev1   { std::string{"1"} };
  auto prev2   { std::string{"1"} };
  auto current { std::string{} };
  auto index   { 2 };

  while (true) {
    current = addStrings(prev1, prev2);
    index++;

    if (current.length() >= 1000)
      break;

    prev2 = prev1;
    prev1 = current;
  }

  std::cout << index << std::endl;

  return 0;
}