/**
 * Project Euler Problem 50: Consecutive prime sum
 * 
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

#include <iostream>
#include <vector>

constexpr auto g_limit{ 1'000'000 };

auto sieve() -> std::vector<int> {
  auto prime  { std::vector<bool>(g_limit, true) };
  auto primes { std::vector<int>{} };

  for (auto p{ 2 }; p * p < g_limit; p++)
    if (prime[p])
      for (auto i{ p * p }; i < g_limit; i += p)
        prime[i] = false;

  for (auto i{ 2 }; i < g_limit; i++)
    if (prime[i])
      primes.push_back(i);

  return primes;
}

auto main() -> int {
  const auto primes { sieve() };
  auto       prime  { std::vector<bool>(g_limit, false) };
  const auto n      { static_cast<int>(primes.size()) };
  auto       prefix { std::vector<int>(n + 1, 0) };

  for (const auto& p : primes)
    prime[p] = true;

  for (auto i{ 0 }; i < n; i++)
    prefix[i + 1] = prefix[i] + primes[i];

  auto maxLength { 0 };
  auto maxPrime  { 0 };

  for (auto i{ maxLength }; i < n; i++)
    for (auto j{ i - (maxLength + 1) }; j >= 0; j--) {
      const auto sum{ prefix[i] - prefix[j] };

      if (sum >= g_limit)
        break;

      if (prime[sum] && i - j > maxLength) {
        maxLength = i - j;
        maxPrime  = sum;
      }
    }

  std::cout << maxPrime << std::endl;

  return 0;
}