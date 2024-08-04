/**
 * Project Euler: Problem 037
 * Truncatable Primes
 * Solution written by Kyle Swecker
 * 
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 * 
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 * 
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

static auto isPrime(const int n) -> bool {
  if (n < 2)
    return false;

  const auto limit { static_cast<int>(std::sqrt(n)) };

  for (auto i { 2 }; i <= limit; i++)
    if (!(n % i))
      return false;

  return true;
}

static auto isTrunctablePrime(const int n) -> bool {
  if (!isPrime(n))
    return false;

  const auto str { std::to_string(n) };

  for (auto i { 1 }; i < str.size(); i++)
    if (!isPrime(std::stoi(str.substr(i))) || !isPrime(std::stoi(str.substr(0, str.size() - i))))
      return false;

  return true;
}

static auto findTrunctablePrimes(const int count) -> std::vector<int> {
  auto primes { std::vector<int>{} };

  for (auto i { 10 }; primes.size() < count; i++)
    if (isTrunctablePrime(i))
      primes.push_back(i);

  return primes;
}

static inline auto sumTrunctablePrimes(const std::vector<int>& primes) -> int {
  return std::accumulate(primes.begin(), primes.end(), 0);
}

auto main() -> int {
  constexpr auto count  { 11 };
  const auto     primes { findTrunctablePrimes(count) };
  const auto     sum    { sumTrunctablePrimes(primes) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
