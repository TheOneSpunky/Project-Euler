/**
 * Project Euler Problem 5: Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <vector>
#include <cmath>

// Remove these
#include <numeric>
#include <algorithm>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;

  for (auto i{ 2 }; i <= std::sqrt(n); i++)
    if (n % i == 0)
      return false;

  return true;
}

auto highestPowerInRange(const int& prime, int range) -> int {
  auto power{ 0 };

  while (range >= prime) {
    power++;
    range /= prime;
  }

  return power;
}

auto main() -> int {
  constexpr auto numbersRange     { 20 };
  auto           smallestMultiple { long long{1} };

  for (auto i{ 2 }; i <= numbersRange; i++)
    if (isPrime(i))
      smallestMultiple *= std::pow(i, highestPowerInRange(i, numbersRange));

  std::cout << smallestMultiple << std::endl;

  return 0;
}