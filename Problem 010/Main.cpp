/**
 * Project Euler: Problem 010
 * Summation of Primes
 * Solution written by Kyle Swecker
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include <vector>

static auto sumPrimes(const std::size_t n) -> std::size_t {
  if (n < 2)
    return 0;

  const auto sieveSize { n + 1 / 2 };
  auto       isPrime   { std::vector<bool>(n, true) };

  isPrime[0] = isPrime[1] = false;

  for (auto i { std::size_t{2} }; i * i < n; i++)
    if (isPrime[i])
      for (auto j { i * i }; j < n; j += i)
        isPrime[j] = false;

  auto sum { std::size_t{} };

  for (auto i { std::size_t{2} }; i < n; i++)
    if (isPrime[i])
      sum += i;

  return sum;
}

auto main() -> int {
  constexpr auto target { std::size_t{2'000'000} };
  const auto     sum    { sumPrimes(target) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
