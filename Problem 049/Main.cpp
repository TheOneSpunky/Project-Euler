/**
 * Project Euler: Problem 049
 * Prime Permutations
 * Solution written by Kyle Swecker
 * 
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330,
 * is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the
 * 4-digit numbers are permutations of one another.
 * 
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting
 * this property, but there is one other 4-digit increasing sequence.
 * 
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

static auto isPrime(int n) -> bool {
  if (n <= 1)
    return false;
  else if (n == 2 || n == 3)
    return true;
  else if (!(n % 2) || !(n % 3))
    return false;

  for (auto i { 5 }; i * i <= n; i += 6)
    if (!(n % i) || !(n % (i + 2)))
      return false;

  return true;
}

static auto getSortedDigits(int n) -> std::string {
  auto str { std::to_string(n) };

  std::sort(str.begin(), str.end());

  return str;
}

auto main() -> int {
  auto primes          { std::vector<int>{} };
  auto permutationSets { std::unordered_map<std::string, std::vector<int>>{} };

  for (auto i { 1000 }; i < 10000; i++)
    if (isPrime(i))
      primes.push_back(i);

  for (const auto& prime : primes) {
    const auto sortedDigits { getSortedDigits(prime) };

    permutationSets[sortedDigits].push_back(prime);
  }

  for (const auto& [sortedDigits, permSet] : permutationSets) {
    if (permSet.size() < 3)
      continue;

    auto sortedPermSet { std::vector<int>{permSet} };

    std::sort(sortedPermSet.begin(), sortedPermSet.end());

    for (auto i { std::size_t{0} }; i < sortedPermSet.size(); i++)
      for (auto j { std::size_t{i + 1} }; j < sortedPermSet.size(); j++) {
        const auto a    { sortedPermSet[i] };
        const auto b    { sortedPermSet[j] };
        const auto diff { b - a };
        const auto c    { b + diff };

        if (c >= 1000 && c < 10000 && std::binary_search(sortedPermSet.begin(), sortedPermSet.end(), c)) {
          if (a != 1487) {
            auto result { std::to_string(a) + std::to_string(b) + std::to_string(c) };

            std::cout << "Answer: " << result << std::endl;

            return 0;
          }
        }
      }
  }

  std::cout << "No other sequence found." << std::endl;

  return 0;
}
