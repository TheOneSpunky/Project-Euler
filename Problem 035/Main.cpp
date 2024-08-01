/**
 * Project Euler: Problem 035
 * Circular Primes
 * Solution written by Kyle Swecker
 * 
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * 
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * 
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

static auto isPrime(const int n) -> bool {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (!(n % 2))
    return false;

  const auto limit { std::sqrt(n) };

  for (auto i { 3 }; i <= limit; i += 2)
    if (!(n % i))
      return false;

  return true;
}

static auto generateRotations(const int n) -> std::vector<int> {
  auto rotations { std::vector<int>{} };
  auto nStr      { std::to_string(n) };

  for (auto i { std::size_t{0} }; i < nStr.size(); i++) {
    std::rotate(nStr.begin(), nStr.begin() + 1, nStr.end());
    rotations.push_back(std::stoi(nStr));
  }

  return rotations;
}

static auto isCircularPrime(const int n) -> bool {
  const auto rotations { generateRotations(n) };

  for (const auto& rotation : rotations)
    if (!isPrime(rotation))
      return false;

  return true;
}

static auto countCircularPrimes(const int limit) -> int {
  auto count { 0 };

  for (auto i { 2 }; i < limit; i++)
    if (isCircularPrime(i))
      count++;

  return count;
}

auto main() -> int {
  constexpr auto limit { 1'000'000 };
  const auto     count { countCircularPrimes(limit) };

  std::cout << "Answer: " << count << std::endl;

  return 0;
}
