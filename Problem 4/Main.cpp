/**
 * Project Euler Problem 4: Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <string>
#include <algorithm>

auto isPalindrome(int n) -> bool {
  auto number   { std::to_string(n) };
  auto reversed { number };

  std::reverse(reversed.begin(), reversed.end());

  return number == reversed;
}

auto main() -> int {
  constexpr auto min{ 100 };

  auto maxPalindrome{ 0 };

  for (auto i{ 999 }; i >= min; i--) {
    if (i * 999 <= maxPalindrome)
      break;

    for (auto j{ 999 }; j >= i; j--) {
      auto product{ i * j };

      if (product <= maxPalindrome)
        break;

      if (isPalindrome(product))
        maxPalindrome = product;
    }
  }

  std::cout << maxPalindrome << std::endl;

  return 0;
}