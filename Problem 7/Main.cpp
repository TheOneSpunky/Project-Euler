/**
 * Project Euler Problem 7: 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <iostream>
#include <cmath>

auto isPrime(const unsigned long long& n) -> unsigned long long {
  if (n <= 1)
    return false;
  else if (n <= 3)
    return true;
  else if (n % 2 == 0)
    return false;

  const auto limit{ static_cast<unsigned long long>(std::sqrt(n)) };

  for (auto i{ unsigned long long{3} }; i <= limit; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  constexpr auto targetPrime { 10001 };
  auto           primeCount  { 0 };
  auto           number      { 1 };

  while (primeCount < targetPrime) {
    number++;
    if (isPrime(number))
      primeCount++;
  }

  std::cout << number << std::endl;

  return 0;
}