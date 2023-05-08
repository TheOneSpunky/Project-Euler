/**
 * Project Euler Problem 37: Truncatable primes
 * 
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include <cmath>
#include <vector>

auto generatePrimesUpTo(const int& limit) -> std::vector<int> {
  auto isPrime{ std::vector<bool>(limit + 1, true) };

  isPrime[0] = false;
  isPrime[1] = false;

  for (auto i{ 2 }; i * i <= limit; ++i)
    if (isPrime[i])
      for (auto j{ i * i }; j <= limit; j += i)
        isPrime[j] = false;

  auto primes{ std::vector<int>{} };

  for (auto i{ 2 }; i <= limit; i++)
    if (isPrime[i])
      primes.push_back(i);

  return primes;
}

auto isPrime(const int& n, const std::vector<int>& primes) -> bool {
  if (n < 2)
    return false;

  for (const int& prime : primes)
    if (prime * prime > n)
      break;
    else if (n % prime == 0)
      return false;

  return true;
}

auto isTruncatablePrime(int n, const std::vector<int>& primes) -> bool {
  auto temp       { n };
  auto multiplier { 1 };

  while (temp > 0) {
    if (!isPrime(temp, primes))
      return false;

    temp       /= 10;
    multiplier *= 10;
  }

  while (n > 0) {
    if (!isPrime(n, primes))
      return false;

    multiplier /= 10;
    n          %= multiplier;
  }

  return true;
}

auto main() -> int {
  const auto primes{ generatePrimesUpTo(1'000) };

  auto count  { 0 };
  auto sum    { 0 };
  auto number { 23 };

  while (count < 11) {
    if (isTruncatablePrime(number, primes)) {
      sum += number;
      count++;
    }
    number += 2;
  }

  std::cout << sum << std::endl;

  return 0;
}