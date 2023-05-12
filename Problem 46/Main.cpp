/**
 * Project Euler Problem 46: Goldbach's other conjecture
 * 
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2x12
 * 15 = 7 + 2x22
 * 21 = 3 + 2x32
 * 25 = 7 + 2x32
 * 27 = 19 + 2x22
 * 33 = 31 + 2x12
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <vector>
#include <cmath>

auto primeSieve(const int& n) -> std::vector<int> {
  auto isPrime{ std::vector<bool>(n + 1, true) };

  isPrime[0] = isPrime[1] = false;

  for (auto p{ 2 }; p * p <= n; p++)
    if (isPrime[p] == true)
      for (auto i{ p * p }; i <= n; i += p)
        isPrime[i] = false;

  auto primes{ std::vector<int>{} };

  for (auto i{ 2 }; i <= n; ++i)
    if (isPrime[i])
      primes.push_back(i);

  return primes;
}

auto isComposite(int n, const std::vector<int>& primes) -> bool {
  for (const auto& p : primes)
    if (p >= n)
      break;
    else if (n % p == 0)
      return true;

  return false;
}

auto main() -> int {
  constexpr auto n      { 10000 };
  auto           primes { primeSieve(n) };

  for (auto i{ 9 }; i <= n; i += 2) {
    if (isComposite(i, primes)) {
      auto found{ false };

      for (const auto& p : primes) {
        if (p >= i)
          break;

        const auto k{ std::sqrt((i - p) / 2.0) };

        if (k == static_cast<int>(k)) {
          found = true;
          break;
        }
      }
      if (!found) {
        std::cout << i << std::endl;
        break;
      }
    }
  }

  return 0;
}