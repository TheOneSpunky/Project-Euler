/**
 * Project Euler Problem 15: Lattice paths
 * 
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <iostream>

auto binomialCoefficient(const int& n) -> long long {
  auto result{ 1LL };

  for (auto i{ 1 }; i <= n; i++)
    result = result * (n + i) / i;

  return result;
}

int main() {
  constexpr auto n      { 20 };
  const auto     routes { binomialCoefficient(n) };

  std::cout << routes << std::endl;

  return 0;
}