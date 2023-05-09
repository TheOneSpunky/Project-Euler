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
#include <vector>

auto gcd(int a, int b) -> int {
  while (b != 0) {
    const auto t{ b };

    b = a % b;
    a = t;
  }

  return a;
}

auto main() -> int {
  constexpr auto limit          { 1000 };
  auto           solutionCounts { std::vector<int>(limit + 1, 0) };

  for (auto m{ 2 }; m * m < limit; m++)
    for (auto n{ 1 }; n < m; n++)
      if (((m - n) % 2 == 1) && (gcd(m, n) == 1)) {
        const auto p{ 2 * m * (m + n) };

        for (auto k{ p }; k <= limit; k += p)
          solutionCounts[k]++;
      }

  auto maxSolutions { 0 };
  auto maxP         { 0 };

  for (auto p{ 1 }; p <= limit; p++)
    if (solutionCounts[p] > maxSolutions) {
      maxSolutions = solutionCounts[p];
      maxP         = p;
    }

  std::cout << maxP << std::endl;

  return 0;
}