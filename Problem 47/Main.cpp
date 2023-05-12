/**
 * Project Euler Problem 47: Distinct primes factors
 * 
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 x 7
 * 15 = 3 x 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2^2 x 7 x 23
 * 645 = 3 x 5 x 43
 * 646 = 2 x 17 x 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */

#include <iostream>
#include <vector>

auto prime_factors(int num) -> std::vector<int> {
  auto factors{ std::vector<int>{} };

  for (auto i{ 2 }; i * i <= num; i++) {
    if (num % i)
      continue;

    while (num % i == 0)
      num /= i;

    factors.push_back(i);
  }

  if (num > 1)
    factors.push_back(num);

  return factors;
}

auto main() -> int {
  for (auto i{ 2 };; i++) {
    if (prime_factors(i).size() != 4)
      continue;
    else if (prime_factors(i + 1).size() != 4)
      continue;
    else if (prime_factors(i + 2).size() != 4)
      continue;
    else if (prime_factors(i + 3).size() != 4)
      continue;

    std::cout << i << std::endl;

    break;
  }

  return 0;
}