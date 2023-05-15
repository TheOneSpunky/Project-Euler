/**
 * Project Euler Problem 62: Cubic permutations
 * 
 * The cube, 41063625 ({345}^3), can be permuted to produce two other cubes: 56623104 ({384}^3) and 66430125 ({405}^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

auto main() -> int {
  auto cubePermutations{ std::map<std::string, std::vector<long long>>{} };

  for (auto i{ 1LL };; i++) {
    const auto cube       { i * i * i };
    auto       cubeString { std::to_string(cube) };

    std::sort(cubeString.begin(), cubeString.end());
    cubePermutations[cubeString].push_back(cube);

    if (cubePermutations[cubeString].size() == 5) {
      std::cout << cubePermutations[cubeString][0] << std::endl;
      break;
    }
  }

  return 0;
}