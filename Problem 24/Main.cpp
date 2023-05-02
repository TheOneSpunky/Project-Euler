/**
 * Project Euler Problem 24: Lexicographic permutations
 * 
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <string>
#include <vector>

auto precomputeFactorials(const int& n) -> std::vector<int> {
  auto factorials{ std::vector<int>(n + 1) };

  factorials[0] = 1;

  for (auto i{ 1 }; i <= n; i++)
    factorials[i] = factorials[i - 1] * i;

  return factorials;
}

auto main() -> int {
  constexpr auto target     { 1000000 };
  const auto     factorials { precomputeFactorials(9) };

  auto digits    { std::string{ "0123456789" } };
  auto result    { std::string{} };
  auto remaining { target - 1 };

  for (auto i{ static_cast<int>(digits.size()) - 1 }; i > 0; i--) {
    const auto index{ remaining / factorials[i] };

    remaining %= factorials[i];
    result    += digits[index];

    digits.erase(digits.begin() + index);

    if (remaining == 0)
      break;
  }

  result += digits;

  std::cout << result << std::endl;

  return 0;
}