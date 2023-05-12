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
#include <cmath>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  const auto limit{ static_cast<int>(std::sqrt(n)) };

  for (auto i{ 3 }; i <= limit; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  auto groups{ std::map<std::string, std::vector<int>>{} };

  for (auto i{ 1000 }; i < 10000; ++i)
    if (isPrime(i)) {
      auto digits{ std::to_string(i) };

      std::sort(digits.begin(), digits.end());
      groups[digits].push_back(i);
    }

  for (auto& [digits, group] : groups) {
    std::sort(group.begin(), group.end());

    const auto size{ group.size() };

    for (auto i{ 0 }; i < size; i++)
      for (auto j{ i + 1 }; j < size; j++) {
        const auto k{ 2 * group[j] - group[i] };

        if (std::binary_search(group.begin(), group.end(), k))
          if (group[i] != 1487 || group[j] != 4817) {
            std::cout << group[i] << group[j] << k << std::endl;

            return 0;
          }
      }
  }

  return 0;
}