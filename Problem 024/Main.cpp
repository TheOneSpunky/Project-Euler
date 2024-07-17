/**
 * Project Euler: Problem 024
 * Lexicographic Permutations
 * Solution written by Kyle Swecker
 * 
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the
 * digits 1, 2, 3, and 4. If all of the permutations are listed numerically or alphabetically, we call it
 * lexicographic order. The lexicographic permutations of 0, 1, and 2 are:
 * 
 * 012   021   102   120   201   210
 * 
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

static auto calculateFactorials(int n) -> std::vector<int> {
  auto factorials { std::vector<int>(n + 1, 1) };

  for (auto i { 1 }; i <= n; i++)
    factorials[i] = factorials[i - 1] * i;

  return factorials;
}

static auto nthPermutation(const std::vector<int>& digits, int target) -> std::string {
  auto availableDigits { digits };
  auto permutation     { std::string{} };
  auto n               { static_cast<int>(availableDigits.size()) };
  auto factorials      { calculateFactorials(n - 1) };

  target--;

  for (auto i { n - 1 }; i >= 0; i--) {
    const auto index { target / factorials[i] };

    target      %= factorials[i];
    permutation += std::to_string(availableDigits[index]);

    availableDigits.erase(availableDigits.begin() + index);
  }

  return permutation;
}

auto main() -> int {
  constexpr auto target      { 1'000'000 };
  const auto     digits      { std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
  const auto     permutation { nthPermutation(digits, target) };

  std::cout << "Answer: " << permutation << std::endl;

  return 0;
}
