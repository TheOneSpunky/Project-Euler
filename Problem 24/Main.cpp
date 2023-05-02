/**
 * Project Euler Problem 24: Lexicographic permutations
 * 
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto main() -> int {
  constexpr auto target{ 1000000 };

  auto digits  { std::string{"0123456789"} };
  auto current { 1 };

  while (current < target) {
    std::next_permutation(digits.begin(), digits.end());
    current++;
  }

  std::cout << digits << std::endl;

  return 0;
}