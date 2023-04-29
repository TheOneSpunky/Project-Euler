/**
 * Project Euler Problem 7: 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <iostream>
#include <vector>
#include <cmath>

auto sieveOfEratosthenes(const int& n) -> std::vector<int> {
  const auto limit      { static_cast<int>(n * (std::log(n) + std::log(std::log(n)))) };
  const auto sqrtLimit  { std::sqrt(limit) };
  auto       primeFlags { std::vector<bool>(limit + 1, true) };
  auto       primes     { std::vector<int>{} };

  primeFlags[0] = primeFlags[1] = false;

  for (auto i{ 2 }; i <= sqrtLimit; i++)
    if (primeFlags[i]) {
      primes.push_back(i);

      for (auto j{ i * i }; j <= limit; j += i)
        primeFlags[j] = false;
    }

  for (auto i{ primes.back() + 2 }; i <= limit; i += 2)
    if (primeFlags[i])
      primes.push_back(i);

  return primes;
}

auto main() -> int {
  constexpr auto targetPrime { 10001 };
  const auto     primes      { sieveOfEratosthenes(targetPrime) };

  std::cout << primes[targetPrime - 1] << std::endl;

  return 0;
}