/**
 * Project Euler Problem 39: Integer right triangles
 * 
 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 */

#include <iostream>

auto isRightTriangle(const int& a, const int& b, const int& c) -> bool {
  return (a * a + b * b == c * c);
}

auto main() -> int {
  constexpr auto limit{ 1000 };

  auto maxSolutions { 0 };
  auto maxP         { 0 };

  for (auto p{ 1 }; p <= limit; p++) {
    auto solutions{ 0 };

    for (auto a{ 1 }; a < p / 2; a++)
      for (auto b{ a }; b < p / 2; b++) {
        const auto c{ p - a - b };

        if (isRightTriangle(a, b, c))
          solutions++;
      }

    if (solutions > maxSolutions) {
      maxSolutions = solutions;
      maxP         = p;
    }
  }

  std::cout << maxP << std::endl;

  return 0;
}