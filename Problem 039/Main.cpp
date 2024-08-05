/**
 * Project Euler: Problem 039
 * Integer Right Triangles
 * Solution written by Kyle Swecker
 * 
 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120:
 * 
 * {20,48,52}, {24,45,51}, {30,40,50}
 * 
 * For which value of p <= 1000, is the number of solutions maximised?
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <cmath>

static auto isRightTriangle(const int a, const int b, const int c) -> bool {
  return (a * a + b * b == c * c);
}

static auto findTrianglesWithPerimeter(const int p) -> std::vector<std::tuple<int, int, int>> {
  auto triangles { std::vector<std::tuple<int, int, int>>{} };

  for (auto a { 1 }; a < p / 2; a++)
    for (auto b { a }; b < (p - a) / 2; b++) {
      const auto c { p - a - b };

      if (c > 0 && isRightTriangle(a, b, c))
        triangles.push_back(std::make_tuple(a, b, c));
    }

  return triangles;
}

static auto findMaxSolutions(const int maxPerimeter) -> int {
  auto maxSolutions     { 0 };
  auto highestPerimeter { 0 };
  auto perimeterCount   { std::unordered_map<int, int>{} };

  for (auto p { 1 }; p <= maxPerimeter; p++) {
    auto       triangles { findTrianglesWithPerimeter(p) };
    const auto count     { triangles.size() };

    if (count > maxSolutions) {
      maxSolutions    = count;
      highestPerimeter = p;
    }

    perimeterCount[p] = count;
  }

  return highestPerimeter;
}

auto main() -> int {
  constexpr auto maxPerimeter { 1000 };
  const auto     maxSolutions { findMaxSolutions(maxPerimeter) };

  std::cout << "Answer: " << maxSolutions << std::endl;

  return 0;
}
