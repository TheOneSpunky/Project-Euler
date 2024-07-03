/**
 * Project Euler: Problem 003
 * Largest Prime Factor
 * Solution written by Kyle Swecker
 * 
 * The prime factors of 13195 are 5, 7, 13, and 29.
 * 
 * What is the largest prime factor of the number 600851475143?
 */

#include <iostream>

static constexpr auto isqrt(unsigned long long n) -> unsigned long long {
  auto x { n };
  auto y { (x + 1) / 2 };

  while (y < x) {
    x = y;
    y = (x + n / x) / 2;
  }

  return x;
}

static constexpr auto findLargestPrime(unsigned long long n) -> unsigned long long {
  auto largestPrime{ unsigned long long{} };

  // Handle 2 separately
  while (!(n % 2)) {
    largestPrime = 2;
    n           /= 2;
  }

  // Handle odd numbers from 3 to isqrt(n)
  for (auto i { unsigned long long{3} }, limit { isqrt(n) }; i <= limit; i += 2, limit = isqrt(n)) {
    if (!(n % i)) {
      largestPrime = i;

      while (!(n % i))
        n /= i;
    }
  }

  // Handle the case where n is a prime number greater than 2
  if (n > 2)
    largestPrime = n;

  return largestPrime;
}

auto main() -> int {
  constexpr auto target       { 600851475143 };
  constexpr auto largestPrime { findLargestPrime(target) };

  std::cout << "Answer: " << largestPrime << std::endl;

  return 0;
}
