/**
 * Project Euler Problem 31: Coin sums
 * 
 * In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * It is possible to make £2 in the following way:
 *
 * 1x£1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
 * How many different ways can £2 be made using any number of coins?
 */

#include <iostream>
#include <vector>

auto main() -> int {
  const auto coins { std::vector<int>{1, 2, 5, 10, 20, 50, 100, 200} };
  auto       ways  { std::vector<int>(201, 0) };

  ways[0] = 1;

  for (const auto& coin : coins)
    for (auto j{ coin }; j <= 200; j++)
      ways[j] += ways[j - coin];

  std::cout << ways[200] << std::endl;

  return 0;
}