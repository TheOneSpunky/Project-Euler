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
#include <bitset>

auto reverseString(const std::string& s) -> std::string {
  return std::string(s.rbegin(), s.rend());
}

auto isBinaryPalindrome(const int& num) -> bool {
  auto       binary { std::bitset<20>(num).to_string() };
  const auto pos    { binary.find_first_not_of('0') };

  binary = binary.substr(pos);

  return (binary == reverseString(binary));
}

auto main() -> int {
  constexpr auto limit { 1000000 };
  auto           sum   { 0 };

  for (auto i{ 1 }; i < 1000; i++) {
    auto left  { std::to_string(i) };
    auto right { reverseString(left) };

    const auto oddPalindrome{ std::stoi(left + right) };

    if (oddPalindrome < limit && isBinaryPalindrome(oddPalindrome))
      sum += oddPalindrome;

    for (auto j{ 0 }; j < 10; j++) {
      const auto evenPalindrome{ std::stoi(left + std::to_string(j) + right) };

      if (evenPalindrome < limit && isBinaryPalindrome(evenPalindrome))
        sum += evenPalindrome;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}