/**
 * Project Euler: Problem 005
 * Smallest Multiple
 * Solution written by Kyle Swecker
 * 
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * 
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>

static constexpr auto gcd(int a, int b) -> int {
  while (b != 0) {
    auto c { b };

    b = a % b;
    a = c;
  }

  return a;
}

static constexpr auto lcm(int a, int b) -> int {
  return ((a / gcd(a, b)) * b);
}

static constexpr auto lcmRange(int n) -> int {
  auto result { 1 };

  for (auto i { 2 }; i <= n; i++)
    result = lcm(result, i);

  return result;
}

auto main() -> int {
  constexpr auto n      { 20 };
  constexpr auto result { lcmRange(n) };

  std::cout << "Answer: " << result << std::endl;

  return 0;
}
