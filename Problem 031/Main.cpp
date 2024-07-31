/**
 * Project Euler: Problem 031
 * Coin Sums
 * Solution written by Kyle Swecker
 * 
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * 
 * It is possible to make £2 in the following way:
 * 
 * 1x£1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
 * 
 * How many different ways can £2 be made using any number of coins?
 */

#include <iostream>
#include <vector>

static auto findChangeCombinations(const int amount) -> int {
  auto coins        { std::vector<int>{1, 2, 5, 10, 20, 50, 100, 200} };
  auto combinations { std::vector<int>(amount + 1, 0) };

  combinations[0] = 1;

  for (const auto& coin : coins)
    for (auto i { coin }; i <= amount; i++)
      combinations[i] += combinations[static_cast<std::size_t>(i) - coin];

  return combinations[amount];
}

auto main() -> int {
  constexpr auto amount       { 200 };
  auto           combinations { findChangeCombinations(amount) };

  std::cout << "Answer: " << combinations << std::endl;

  return 0;
}
