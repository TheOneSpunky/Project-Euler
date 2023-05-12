/**
 * Project Euler Problem 47: Distinct primes factors
 * 
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 x 7
 * 15 = 3 x 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2^2 x 7 x 23
 * 645 = 3 x 5 x 43
 * 646 = 2 x 17 x 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */

#include <iostream>
#include <vector>

auto numPrimeFactors(int num) -> int {
  auto factors{ 0 };

  for (auto i{ 2 }; i * i <= num; i++) {
    if (num % i)
      continue;

    while (num % i == 0)
      num /= i;

    factors++;
  }

  if (num > 1)
    factors++;

  return factors;
}

auto main() -> int {
  for (auto i{ 2 };;) {
    if (numPrimeFactors(i) != 4) {
      i++;
      continue;
    }
    else if (numPrimeFactors(i + 1) != 4) {
      i += 2;
      continue;
    }
    else if (numPrimeFactors(i + 2) != 4) {
      i += 3;
      continue;
    }
    else if (numPrimeFactors(i + 3) != 4) {
      i += 4;
      continue;
    }

    std::cout << i << std::endl;

    break;
  }

  return 0;
}