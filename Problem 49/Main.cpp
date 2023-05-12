/**
 * Project Euler Problem 49: Prime permutations
 * 
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <thread>
#include <atomic>
#include <cmath>

auto g_found{ std::atomic<bool>(false) };

auto generatePrimes(const int& n) -> std::vector<int> {
  auto isPrime{ std::vector<bool>(n + 1, true) };

  isPrime[0] = isPrime[1] = false;

  for (auto i{ 2 }; i * i <= n; ++i)
    if (isPrime[i])
      for (auto j{ i * i }; j <= n; j += i)
        isPrime[j] = false;

  auto primes{ std::vector<int>{} };

  for (auto i{ 1000 }; i <= n; i++)
    if (isPrime[i])
      primes.push_back(i);

  return primes;
}

auto findSequences(const std::vector<int>& group) -> void {
  const auto size{ group.size() };

  for (auto i{ 0 }; i < size; i++)
    for (auto j{ i + 1 }; j < size; j++) {
      if (g_found)
        return;

      const auto k{ 2 * group[j] - group[i] };

      if (std::binary_search(group.begin(), group.end(), k))
        if (group[i] != 1487 || group[j] != 4817) {
          std::cout << group[i] << group[j] << k << std::endl;
          g_found = true;
          return;
        }
    }
}

auto main() -> int {
  auto groups { std::map<std::string, std::vector<int>>{} };
  auto primes { generatePrimes(9999) };

  for (const auto& prime : primes) {
    auto digits{ std::to_string(prime) };

    std::sort(digits.begin(), digits.end());
    groups[digits].push_back(prime);
  }

  auto threads{ std::vector<std::thread>{} };

  for (auto& [digits, group] : groups) {
    std::sort(group.begin(), group.end());

    if (group.size() < 3)
      continue;

    threads.push_back(std::thread(findSequences, group));
  }

  for (auto& thread : threads)
    thread.join();

  return 0;
}