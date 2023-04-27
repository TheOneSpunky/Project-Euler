/**
 * Project Euler Problem 3: Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <cmath>

auto largestPrimeFactor(long long number) -> long long {
  while (number % 2 == 0)
    number /= 2;
  while (number % 3 == 0)
    number /= 3;
  if (number == 1)
    return 3;

  for (auto i{ long long{5} }, w{ long long{2} }; i <= std::sqrt(number); i += w, w = 6 - w)
    while (number % i == 0)
      number /= i;

  return ((number > 1) ? number : 3);
}

auto main() -> int {
  constexpr auto number        { long long{600851475143} };
  auto           largestFactor { largestPrimeFactor(number) };

  std::cout << largestFactor << std::endl;

  return 0;
}