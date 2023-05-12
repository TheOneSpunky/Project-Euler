/**
 * Project Euler Problem 50: Consecutive prime sum
 * 
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

#include <iostream>
#include <vector>
#include <algorithm>

auto isPrime(const int& n) -> bool {
  if (n < 2)
    return false;

  for (auto i{ 2 }; i * i <= n; i++)
    if (n % i == 0)
      return false;

  return true;
}

auto main() -> int {
  constexpr auto limit  { 1'000'000 };
  auto           primes { std::vector<int>{} };

  for (auto i{ 2 }; i < limit; i++)
    if (isPrime(i))
      primes.push_back(i);

  auto maxLength { 0 };
  auto maxPrime  { 0 };

  for (auto i{ 0 }; i < primes.size(); i++) {
    auto sum{ 0 };

    for (auto j{ i }; j < primes.size(); j++) {
      sum += primes[j];

      if (sum >= limit)
        break;

      if (isPrime(sum) && (j - i + 1) > maxLength) {
        maxLength = j - i + 1;
        maxPrime = sum;
      }
    }
  }

  std::cout << maxPrime << std::endl;

  return 0;
}