/**
 * Project Euler Problem 7: 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <iostream>
#include <vector>
#include <cmath>

auto sieveOfEratosthenes(unsigned long long limit) -> std::vector<bool> {
  const auto sqrtLimit { std::sqrt(limit) };
  auto       prime     { std::vector<bool>(limit + 1, true) };

  prime[0] = prime[1] = false;

  for (auto i{ unsigned long long{2} }; i <= sqrtLimit; i++)
    if (prime[i])
      for (auto j{ unsigned long long{i * i} }; j <= limit; j += i)
        prime[j] = false;

  return prime;
}

int main() {
  constexpr auto targetPrime { 10001 };
  constexpr auto limit       { 200000 };

  auto prime      { sieveOfEratosthenes(limit) };
  auto primeCount { 0 };
  auto number     { unsigned long long{} };

  for (number = 2; number <= limit; number++)
    if (prime[number]) {
      primeCount++;

      if (primeCount == targetPrime)
        break;
    }

  std::cout << number << std::endl;

  return 0;
}