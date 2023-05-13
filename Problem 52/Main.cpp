/**
 * Project Euler Problem 52: Permuted multiples
 * 
 * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 *
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

#include <algorithm>
#include <iostream>
#include <string>

auto hasSameDigits(const int& a, const int& b) -> bool {
  auto aStr { std::to_string(a) };
  auto bStr { std::to_string(b) };

  std::sort(aStr.begin(), aStr.end());
  std::sort(bStr.begin(), bStr.end());

  return (aStr == bStr);
}

auto main() -> int {
  for (auto x{ 1 };; x++) {
    if (hasSameDigits(x, 2 * x) &&
        hasSameDigits(x, 3 * x) &&
        hasSameDigits(x, 4 * x) &&
        hasSameDigits(x, 5 * x) &&
        hasSameDigits(x, 6 * x)) {
      std::cout << x << std::endl;
      break;
    }
  }

  return 0;
}