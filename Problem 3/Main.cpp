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
  if (n <= 1)
    return false;
  else if (n == 2 || n == 3)
    return true;
  else if (n % 2 == 0)
    return false;

  const auto limit{ static_cast<long long>(std::sqrt(n)) + 1 };

  for (auto i{ long long{3} }; i < limit; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  constexpr auto number{ long long{600851475143} };

  auto largestFactor{ long long{1} };

  for (auto i{ long long{2} }; i <= sqrt(number); i++)
    if (number % i == 0) {
      auto otherFactor{ long long{number / i} };

      if (isPrime(i))
        largestFactor = i;
      else if (isPrime(otherFactor))
        largestFactor = otherFactor;
    }

  std::cout << largestFactor << std::endl;

  return 0;
}