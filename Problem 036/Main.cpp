/**
 * Project Euler: Problem 036
 * Double-base Palindromes
 * Solution written by Kyle Swecker
 * 
 * The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 * 
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * 
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <stdexcept>

static auto isPalindrome(const int n, const int base) -> bool {
  auto str { std::string{} };

  if (base == 10)
    str = std::to_string(n);
  else if (base == 2) {
    str = std::bitset<32>(n).to_string();
    str.erase(0, str.find_first_not_of('0'));
  }
  else
    throw std::invalid_argument{"Invalid base"};

  auto reversed { str };

  std::reverse(reversed.begin(), reversed.end());

  return str == reversed;
}

static auto sumPalindromes(const int limit) -> int {
  auto sum { 0 };

  for (auto i { 1 }; i < limit; i++)
    if (isPalindrome(i, 10) && isPalindrome(i, 2))
      sum += i;

  return sum;
}

auto main() -> int {
  constexpr auto limit { 1'000'000 };
  const auto     sum   { sumPalindromes(limit) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
