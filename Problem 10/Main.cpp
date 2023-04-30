/**
 * Project Euler Problem 10: Summation of primes
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include <vector>

auto sieveOfEratosthenes(const int& limit) -> std::vector<bool> {
  auto primes{ std::vector<bool>(limit + 1, true) };

  primes[0] = primes[1] = false;

  for (auto i{ 2 }; i * i <= limit; i++)
    if (primes[i])
      for (auto j{ i * i }; j <= limit; j += i)
        primes[j] = false;

  return primes;
}

auto sumPrimes(const int& limit) -> long long {
  auto primes { sieveOfEratosthenes(limit) };
  auto sum    { long long{2} };

  for (auto i{ 3 }; i < limit; i += 2)
    if (primes[i])
      sum += i;

  return sum;
}

auto main() -> int {
  constexpr auto limit { 2000000 };
  const auto     sum   { sumPrimes(limit) };

  std::cout << sum << std::endl;

  return 0;
}