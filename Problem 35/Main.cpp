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
#include <string>
#include <vector>
#include <cmath>

auto isPrime(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n <= 3)
    return true;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;

  const auto limit{ std::sqrt(n) };

  for (auto i{ 5 }; i <= limit; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
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

auto isCircularPrime(const int& n) -> bool {
  if (!isPrime(n))
    return false;

  auto rotations{ generateRotations(n) };

  for (auto rotation : rotations)
    if (!isPrime(rotation))
      return false;

  return true;
}

auto main() -> int {
  auto count{ 0 };

  for (auto i{ 2 }; i < 1000000; i++)
    if (isCircularPrime(i))
      count++;

  std::cout << count << std::endl;

  return 0;
}