/**
 * Project Euler Problem 26: Reciprocal cycles
 * 
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2  = 0.5
 * 1/3  = 0.(3)
 * 1/4  = 0.25
 * 1/5  = 0.2
 * 1/6  = 0.1(6)
 * 1/7  = 0.(142857)
 * 1/8  = 0.125
 * 1/9  = 0.(1)
 * 1/10 = 0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <vector>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n <= 3)
    return true;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (auto i{ 5 }; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}

auto modularPow(int base, int exponent, int modulus) -> int {
  auto result{ 1 };

  base %= modulus;

  while (exponent > 0) {
    if (exponent % 2 == 1)
      result = (result * base) % modulus;

    exponent >>= 1;
    base       = (base * base) % modulus;
  }

  return result;
}

auto main() -> int {
  auto maxd      { 0 };
  auto maxLength { 0 };

  for (auto d{ 7 }; d < 1000; d += 2) {
    if (d % 5 == 0 || !isPrime(d))
      continue;

    auto order{ 1 };

    while (modularPow(10, order, d) != 1)
      order++;
    if (order > maxLength) {
      maxLength = order;
      maxd      = d;
    }
  }

  std::cout << maxd << std::endl;

  return 0;
}
