/**
 * Project Euler Problem 41: Pandigital prime
 * 
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  const auto sqrtn{ static_cast<int>(std::sqrt(n)) };

  for (auto i{ 3 }; i <= sqrtn; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

auto isPandigital(int n) -> bool {
  auto digits{ std::vector<int>{} };

  while (n > 0) {
    const auto digit{ n % 10 };

    if (digit == 0)
      return false;

    digits.push_back(digit);

    n /= 10;
  }

  std::sort(digits.begin(), digits.end());

  for (auto i{ 0ULL }; i < digits.size(); i++)
    if (digits[i] != i + 1)
      return false;

  return true;
}

auto main() -> int {
  constexpr auto maxn                   { 7 };
  auto           largestPandigitalPrime { 0 };

  for (auto n{ 1 }; n <= maxn; n++) {
    auto digits{ std::vector<int>(n) };

    for (auto i{ 1 }; i <= n; i++)
      digits[i - 1] = i;

    do {
      auto num{ 0 };

      for (const int& digit : digits)
        num = num * 10 + digit;

      if (isPrime(num) && isPandigital(num))
        largestPandigitalPrime = std::max(largestPandigitalPrime, num);
    } while (std::next_permutation(digits.begin(), digits.end()));
  }

  std::cout << largestPandigitalPrime << std::endl;

  return 0;
}