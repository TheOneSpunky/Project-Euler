/**
 * Project Euler: Problem 041
 * Pandigital Prime
 * Solution written by Kyle Swecker
 * 
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
 * 
 * What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

static auto isPrime(long long n) -> bool {
  if (n <= 1)
    return false;
  else if (n <= 3)
    return true;
  else if (!(n % 2) || !(n % 3))
    return false;

  for (auto i { long long{5} }; i * i <= n; i += 6)
    if (!(n % i) || !(n % (i + 2)))
      return false;

  return true;
}

static auto toNumber(const std::vector<int>& digits) -> long long {
  return std::accumulate(digits.begin(), digits.end(), 0LL, [](long long acc, int digit) {
    return (acc * 10 + digit);
  });
}

static auto largestPandigitalPrime() -> long long {
  auto digits { std::vector<int>(7) };

  std::iota(digits.begin(), digits.end(), 1);
  std::sort(digits.begin(), digits.end(), std::greater<int>());

  do {
    if (!(digits.back() % 2))
      continue;

    auto num { long long{toNumber(digits)} };

    if (isPrime(num))
      return num;
  } while (std::prev_permutation(digits.begin(), digits.end()));

  digits = { 4, 3, 2, 1 };

  do {
    if (!(digits.back() % 2))
      continue;

    auto num { long long{toNumber(digits)} };

    if (isPrime(num))
      return num;
  } while (std::prev_permutation(digits.begin(), digits.end()));

  return 3;
}

auto main() -> int {
  auto largest { largestPandigitalPrime() };

  std::cout << "Answer: " << largest << std::endl;

  return 0;
}