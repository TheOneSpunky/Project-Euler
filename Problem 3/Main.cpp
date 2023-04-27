/**
 * Project Euler Problem 3: Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <cmath>

auto isPrime(long long n) -> bool {
  if (n < 2)
    return false;

  for (auto i{ long long{2} }; i <= std::sqrt(n); i++)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  constexpr auto number{ long long{600851475143} };
  
  auto largestFactor{ long long{1} };

  for (auto i{ long long{2} }; i <= sqrt(number); i++)
    if (number % i == 0) {
      if (isPrime(i))
        largestFactor = std::max(largestFactor, i);

      auto otherFactor{ long long{number / i} };

      if (isPrime(otherFactor))
        largestFactor = std::max(largestFactor, otherFactor);
    }

  std::cout << largestFactor << std::endl;

  return 0;
}