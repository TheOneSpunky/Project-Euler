/**
 * Project Euler Problem 5: Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <array>
#include <cmath>

auto main() -> int {
  constexpr auto numbersRange     { 20 };
  auto           smallestMultiple { long long{1} };
  constexpr auto primes           { std::array<int, 8>{2, 3, 5, 7, 11, 13, 17, 19} };

  for (const auto& prime : primes)
    smallestMultiple *= static_cast<long long>(std::pow(prime, static_cast<int>(std::floor(std::log(numbersRange) / std::log(prime)))));

  std::cout << smallestMultiple << std::endl;

  return 0;
}