/**
 * Project Euler Problem 35: Circular primes
 * 
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

auto sieveOfEratosthenes(const int& n) -> std::vector<bool> {
  auto prime{ std::vector<bool>(n + 1, true) };

  prime[0] = false;
  prime[1] = false;

  for (auto p{ 2 }; p * p <= n; p++)
    if (prime[p])
      for (auto i{ p * p }; i <= n; i += p)
        prime[i] = false;

  return prime;
}

auto generateRotations(const int& n) -> std::vector<int> {
  auto rotations { std::vector<int>{} };
  auto numStr    { std::to_string(n) };

  const auto numDigits{ static_cast<int>(numStr.size()) };

  for (auto i{ 0 }; i < numDigits; i++) {
    std::rotate(numStr.begin(), numStr.begin() + 1, numStr.end());
    rotations.push_back(std::stoi(numStr));
  }

  return rotations;
}

auto isCircularPrime(const int& n, const std::vector<bool>& prime) -> bool {
  if (!prime[n])
    return false;

  auto rotations{ generateRotations(n) };

  for (const auto& rotation : rotations)
    if (!prime[rotation])
      return false;

  return true;
}

auto hasInvalidDigit(const int& n) -> bool {
  auto numStr{ std::to_string(n) };

  for (const char& c : numStr) {
    const auto digit{ c - '0' };

    if (digit % 2 == 0 || digit % 5 == 0)
      return true;
  }

  return false;
}

auto main() -> int {
  constexpr auto n     { 1000000 };
  auto           prime { sieveOfEratosthenes(n) };

  auto count{ 0 };

  for (auto i{ 2 }; i < n; i++)
    if (i > 5 && hasInvalidDigit(i))
      continue;
    else if (isCircularPrime(i, prime))
      count++;

  std::cout << count << std::endl;

  return 0;
}