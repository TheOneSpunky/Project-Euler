/**
 * Project Euler Problem 58: Spiral primes
 * 
 * Starting with 1 and spiraling anticlockwise in the following way, a square spiral with side length 7 is formed.
 *
 * 37 36 35 34 33 32 31
 * 38 17 16 15 14 13 30
 * 39 18  5  4  3 12 29
 * 40 19  6  1  2 11 28
 * 41 20  7  8  9 10 27
 * 42 21 22 23 24 25 26
 * 43 44 45 46 47 48 49
 *
 * It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 = 62%.
 *
 * If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
 */

#include <cmath>
#include <iostream>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  const auto limit{ std::sqrt(n) };

  for (auto i{ 3 }; i <= limit; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  auto total  { 1 };
  auto primes { 0 };

  for (auto n{ 3 };; n += 2) {
    for (auto i{ 0 }; i < 4; i++) {
      const auto diagonal{ n * n - i * (n - 1) };

      if (isPrime(diagonal))
        primes++;
    }

    total += 4;

    if (static_cast<double>(primes) / total < 0.1) {
      std::cout << n << std::endl;
      break;
    }
  }

  return 0;
}