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
#include <cmath>

auto main() -> int {
  constexpr auto targetSum{ 1000 };

  for (auto a{ 1 }; a < targetSum; a++)
    for (auto b{ a + 1 }; b < targetSum - a; b++) {
      const auto c{ targetSum - a - b };

      if (a * a + b * b == c * c) {
        auto product{ a * b * c };

        std::cout << "The Pythagorean triplet is: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "The product abc is:         " << product << std::endl;

        return 0;
      }
    }

  return 1;
}
