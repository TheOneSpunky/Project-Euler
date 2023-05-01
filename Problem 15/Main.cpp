/**
 * Project Euler Problem 15: Lattice paths
 * 
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <iostream>
#include <vector>

auto calculateRoutes(const int& n) -> long long {
  auto grid{ std::vector<std::vector<long long>>(n + 1, std::vector<long long>(n + 1, 0)) };

  for (auto i{ 0 }; i <= n; i++) {
    grid[i][0] = 1;
    grid[0][i] = 1;
  }

  for (auto i{ 1 }; i <= n; i++)
    for (int j{ 1 }; j <= n; j++)
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];

  return grid[n][n];
}

auto main() -> int {
  constexpr auto n      { 20 };
  const auto     routes { calculateRoutes(n) };

  std::cout << routes << std::endl;

  return 0;
}