/**
 * Project Euler: Problem 027
 * Quadratic Primes
 * Solution written by Kyle Swecker
 * 
 * Euler discovered the remarkable quadratic formula:
 * 
 * n^2 + n + 41
 * 
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39.
 * However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41,
 * and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 * 
 * The incredible formula n^2 - 79n + 1601 was discovered,
 * which produces 80 primes for the consecutive values 0 <= n <= 79.
 * The product of the coefficients, -79 and 1601, is -126479.
 * 
 * Considering quadratics of the form:
 * 
 * n^2 + an + b, where |a| < 1000 and |b| <= 1000
 * 
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |-4| = 4
 * 
 * Find the product of the coefficients, a and b,
 * for the quadratic expression that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 */

#include <iostream>
#include <vector>
#include <cmath>

static auto isPrime(const int n) -> bool {
  if (n <= 1)
    return false;
  else if (n == 2)
    return true;
  else if (!(n % 2))
    return false;

  for (auto i { 3 }, sqrtn { static_cast<int>(std::sqrt(n)) }; i <= sqrtn; i += 2)
    if (!(n % i))
      return false;

  return true;
}

static auto findProductWithMaxPrimes(const int aMax, const int bMax) -> int {
  auto maxPrimes { 0 };
  auto aBest     { 0 };
  auto bBest     { 0 };

  for (auto a { -aMax + 1 }; a < aMax; a++) {
    for (auto b { -bMax }; b <= bMax; b++) {
      auto n { 0 };

      while (isPrime(n * n + a * n + b))
        n++;

      if (n > maxPrimes) {
        maxPrimes = n;
        aBest     = a;
        bBest     = b;
      }
    }
  }

  return (aBest * bBest);
}

auto main() -> int {
  constexpr auto aMax   { 1000 };
  constexpr auto bMax   { 1000 };
  const auto     result { findProductWithMaxPrimes(aMax, bMax) };

  std::cout << "Answer: " << result << std::endl;

  return 0;
}
