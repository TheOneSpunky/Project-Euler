/**
 * Project Euler Problem 3: Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <random>
#include <numeric>

auto gcd(long long a, long long b) -> long long {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

auto pollardsRho(long long n) -> long long {
  if (n % 2 == 0)
    return 2;

  std::random_device rd;

  auto range        { std::mt19937_64{rd()} };
  auto distribution { std::uniform_int_distribution<long long>(2, n - 2) };
  auto x            { distribution(range) };
  auto y            { x };
  auto c            { distribution(range) };
  auto d            { long long{1} };

  while (d == 1) {
    x = (x * x + c) % n;
    y = (y * y + c) % n;
    y = (y * y + c) % n;
    d = gcd(std::abs(x - y), n);
  }

  return d;
}

auto largestPrimeFactor(long long n) -> long long {
  for (auto i{ long long{2} }; i <= std::sqrt(n); i++)
    if (n % i == 0)
      return std::max(i, largestPrimeFactor(n / i));

  auto factor{ pollardsRho(n) };

  if (factor == n)
    return factor;

  return std::max(largestPrimeFactor(factor), largestPrimeFactor(n / factor));
}

auto main() -> int {
  constexpr auto number        { 600851475143 };
  const auto     largestFactor { largestPrimeFactor(number) };

  std::cout << largestFactor << std::endl;

  return 0;
}
