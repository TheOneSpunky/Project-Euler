/**
 * Project Euler Problem 5: Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <numeric>
#include <algorithm>

auto gcd(long long a, long long b) -> long long {
  while (b != 0) {
    auto temp{ b };
    b = a % b;
    a = temp;
  }

  return a;
}

auto lcm(long long a, long long b) -> long long {
  return (a * b) / gcd(a, b);
}

auto main() -> int {
  auto smallestMultiple { long long{1} };

  for (auto i{ long long{2} }; i <= 20; i++)
    smallestMultiple = lcm(smallestMultiple, i);

  std::cout << smallestMultiple << std::endl;

  return 0;
}