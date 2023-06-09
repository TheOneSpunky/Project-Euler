/**
 * Project Euler Problem 51: Prime digit replacements
 * 
 * By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 */

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr auto g_limit { 1'000'000 };
auto           g_sieve { std::bitset<g_limit>{} };

auto generatePrimes() -> std::vector<int> {
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

auto hasRepeatedDigits(const int& n, char& repeatedDigit) -> bool {
  auto num{ std::to_string(n) };

  std::sort(num.begin(), num.end());

  for (auto i{ 0U }; i < num.size() - 1; i++) {
    if (num[i] == num[i + 1] && num[i] <= '2') {
      repeatedDigit = num[i];

      return true;
    }
  }

  return false;
}

auto findFamily(const std::vector<int>& primes) -> int {
  for (const auto& prime : primes) {
    auto repeatedDigit{ char{} };

    if (!hasRepeatedDigits(prime, repeatedDigit))
      continue;

    auto primeStr{ std::to_string(prime) };

    for (auto digit{ '0' }; digit <= '2'; digit++) {
      auto count { 0 };
      auto fail  { 0 };

      for (auto replace{ '0' }; replace <= '9'; replace++) {
        auto replaced  { primeStr };
        std::replace(replaced.begin(), replaced.end(), digit, replace);
        auto candidate { std::stoi(replaced) };

        if (replaced[0] != '0' && g_sieve[candidate])
          count++;
        else
          fail++;

        if (fail > 2)
          break;
      }

      if (count == 8)
        return prime;
    }
  }

  return -1;
}

auto main() -> int {
  auto primes{ generatePrimes() };

  std::cout << findFamily(primes) << std::endl;

  return 0;
}