/**
 * Project Euler Problem 9: Special Pythagorean triplet
 * 
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * 
 * a^2 + b^2 = c^2
 * 
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 */

#include <iostream>

auto main() -> int {
  constexpr auto targetDivisor{ 500 };

  for (auto m{ 2 }; m < targetDivisor; m++)
    if (targetDivisor % m == 0) {
      const auto mn { targetDivisor / m };
      const auto n  { mn - m };

      if (m > n && n > 0) {
        const auto a       { m * m - n * n };
        const auto b       { 2 * m * n };
        const auto c       { m * m + n * n };
        const auto product { a * b * c };

        std::cout << "The Pythagorean triplet is: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "The product abc is:         " << product << std::endl;

        return 0;
      }
    }

  return 1;
}