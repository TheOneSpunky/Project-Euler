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

auto isPrime(const int& n) -> bool {
  if (n < 2)
    return false;

  const auto limit{ std::sqrt(n) };

  for (auto i{ 2 }; i <= limit; i++)
    if (n % i == 0)
      return false;

  return true;
}

auto isTruncatablePrime(int n) -> bool {
  auto temp       { n };
  auto multiplier { 1 };

  while (temp > 0) {
    if (!isPrime(temp))
      return false;

    temp       /= 10;
    multiplier *= 10;
  }

  while (n > 0) {
    if (!isPrime(n))
      return false;

    multiplier /= 10;
    n          %= multiplier;
  }

  return true;
}

auto main() -> int {
  auto count  { 0 };
  auto sum    { 0 };
  auto number { 23 };

  while (count < 11) {
    if (isTruncatablePrime(number)) {
      sum += number;
      count++;
    }
    number += 2;
  }

  std::cout << sum << std::endl;

  return 0;
}