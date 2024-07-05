/**
 * Project Euler: Problem 004
 * Largest Palindrome Product
 * Solution written by Kyle Swecker
 * 
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>

static constexpr auto isPalindrome(unsigned n) -> bool {
  const auto original { n };
  auto       reversed { unsigned{} };

  while (n) {
    reversed = reversed * 10 + n % 10;
    n       /= 10;
  }

  return (original == reversed);
}

static constexpr auto largestPalindromeProduct() -> unsigned {
  auto largest { unsigned{} };

  for (auto i { unsigned{999} }; i >= 100; i--) {
    for (auto j { unsigned{999} }; j >= i; j--) {
      const auto product { i * j };

      if (product <= largest)
        break;
      else if (isPalindrome(product))
        largest = product;
    }
  }

  return largest;
}

auto main() -> int {
  constexpr auto largestPalindrome { largestPalindromeProduct() };

  std::cout << "Answer: " << largestPalindrome << std::endl;

  return 0;
}
