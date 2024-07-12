/**
 * Project Euler: Problem 015
 * Lattice Paths
 * Solution written by Kyle Swecker
 * 
 * Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 * 
 * How many such routes are there through a 20x20 grid?
 */

#include <iostream>
#include <vector>
#include <cstdint>

static constexpr auto findGridRoutes(std::uint64_t gridSize) -> std::uint64_t {
  auto n  { gridSize * 2 };
  auto dp { std::vector<std::uint64_t>(n + 1, 1) };

  for (auto i { 1 }; i <= gridSize; i++)
    dp[i] = dp[i - 1] * (n - i + 1) / i;

  return dp[gridSize];
}

auto main() -> int {
  constexpr auto gridSize { 20 };
  constexpr auto routes   { findGridRoutes(gridSize) };

  std::cout << "Answer: " << routes << std::endl;

  return 0;
}
