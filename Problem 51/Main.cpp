/**
 * Project Euler Problem 51: Prime digit replacements
 */

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr auto g_limit { 1000000 };
auto           g_sieve { std::bitset<g_limit>{} };

std::vector<int> generate_primes() {
  g_sieve.set();
  g_sieve[0] = g_sieve[1] = 0;

  for (auto i{ 2 }; i * i < g_limit; i++)
    if (g_sieve[i])
      for (auto j{ i * i }; j < g_limit; j += i)
        g_sieve[j] = 0;

  auto primes{ std::vector<int>{} };

  for (auto i{ 0 }; i < g_limit; i++)
    if (g_sieve[i])
      primes.push_back(i);

  return primes;
}

auto findFamily(const std::vector<int>& primes) -> int {
  for (const auto& prime : primes) {
    auto primeStr{ std::to_string(prime) };

    for (auto digit{ '0' }; digit <= '9'; digit++) {
      auto count{ 0 };

      for (auto replace{ '0' }; replace <= '9'; replace++) {
        auto replaced  { primeStr };
        std::replace(replaced.begin(), replaced.end(), digit, replace);
        auto candidate { std::stoi(replaced) };

        if (replaced[0] != '0' && g_sieve[candidate])
          count++;
      }

      if (count == 8)
        return prime;
    }
  }

  return -1;
}

auto main() -> int {
  auto primes{ generate_primes() };

  std::cout << findFamily(primes) << std::endl;

  return 0;
}