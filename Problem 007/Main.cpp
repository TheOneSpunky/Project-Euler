/**
 * Project Euler: Problem 007
 * 10001st Prime
 * Solution written by Kyle Swecker
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * 
 * What is the 10,001st prime number?
 */

#include <iostream>

static auto isPrime(const int n) -> bool {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (!(n % 2) || !(n % 3))
    return false;
  for (auto i { 5 }; i * i <= n; i += 6)
    if (!(n % i) || !(n % (i + 2)))
      return false;
  return true;
}

static auto findNthPrime(const int n) -> int {
  auto count  { 0 };
  auto number { 1 };

  while (count < n)
    if (isPrime(number++))
      count++;

  return --number;
}

auto main() -> int {
  constexpr auto target { 10001 };
  const auto     prime  { findNthPrime(target) };

  std::cout << "Answer: " << prime << std::endl;

  return 0;
}
