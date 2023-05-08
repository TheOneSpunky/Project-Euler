/**
 * Project Euler Problem 36: Double-base palindromes
 * 
 * The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <iostream>
#include <string>

auto reverseString(const std::string& s) -> std::string {
  return std::string(s.rbegin(), s.rend());
}

auto reverseBits(unsigned int num) -> unsigned int {
  auto reverseNum{ 0U };

  while (num > 0) {
    reverseNum <<= 1;
    reverseNum  |= (num & 1);
    num        >>= 1;
  }

  return reverseNum;
}

auto isBinaryPalindrome(const unsigned int& num) -> bool {
  return (num == reverseBits(num));
}

auto main() -> int {
  constexpr auto limit { 1000000 };
  auto           sum   { 0 };

  for (auto i{ 1 }; i < 1000; i++) {
    auto left  { std::to_string(i) };
    auto right { reverseString(left) };

    for (auto j{ -1 }; j < 10; j++) {
      const auto middle     { std::string{(j == -1) ? "" : std::to_string(j)} };
      const auto palindrome { std::stoi(left + middle + right) };

      if (palindrome < limit && isBinaryPalindrome(palindrome))
        sum += palindrome;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}