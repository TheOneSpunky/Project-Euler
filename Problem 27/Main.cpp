/**
 * Project Euler Problem 27: Quadratic primes
 * 
 * Euler discovered the remarkable quadratic formula:
 * 
 * n^2 + n + 41
 * 
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 * 
 * The incredible formula n^2 - 79 * n + 1601 was discovered, which produces 80 primes for the consecutive values 0 <= n <= 79. The product of the coefficients, -79 and 1601, is -126479.
 * 
 * Considering quadratics of the form:
 * 
 * n^2 + a * n + b, where |a| < 1000 and |b| <= 1000
 * 
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |-4| = 4
 * 
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 */

#include <iostream>
#include <cmath>
#include <vector>

auto isPrime(const int& n) {
  if (n <= 1)
    return false;

  const auto limit{ std::sqrt(n) };

  for (auto i{ 2 }; i <= limit; i++)
    if (n % i == 0)
      return false;

  return true;
}

auto generatePrimes(const int& limit) -> std::vector<int> {
  auto primes{ std::vector<int>{} };

  for (auto i{ 2 }; i <= limit; i++)
    if (isPrime(i))
      primes.push_back(i);

  return primes;
}

auto main() -> int {
  const auto primes{ generatePrimes(1000) };

  auto maxPrimes { 0 };
  auto bestA     { 0 };
  auto bestB     { 0 };

  for (auto a{ -999 }; a < 1000; a += 2) {
    for (const auto& b : primes) {
      auto n{ 0 };

      while (isPrime(std::abs(n * n + a * n + b)))
        n++;

      if (n > maxPrimes) {
        maxPrimes = n;
        bestA = a;
        bestB = b;
      }
    }
  }

  const auto product{ bestA * bestB };

  std::cout << product << std::endl;

  return 0;
}