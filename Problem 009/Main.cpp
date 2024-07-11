/**
 * Project Euler: Problem 009
 * Special Pythagorean Triplet
 * Solution written by Kyle Swecker
 * 
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * 
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>

static constexpr auto findProductABC(const int n) -> int {
  for (auto a { 1 }; a < n; a++) {
    const auto b { n * (n - 2 * a) / (2 * (n - a)) };
    const auto c { n - a - b };

    if (a * a + b * b == c * c)
      return a * b * c;
  }

  return -1;
}


auto main() -> int {
  constexpr auto target  { 1000 };
  constexpr auto product { findProductABC(target) };

  std::cout << "Answer: " << product << std::endl;

  return 0;
}
