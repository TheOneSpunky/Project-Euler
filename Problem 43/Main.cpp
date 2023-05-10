/**
 * Project Euler Problem 43: Sub-string divisibility
 * 
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 *
 * Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on. In this way, we note the following:
 *
 * d_2d_3d_4=406 is divisible by 2
 * d_3d_4d_5=063 is divisible by 3
 * d_4d_5d_6=635 is divisible by 5
 * d_5d_6d_7=357 is divisible by 7
 * d_6d_7d_8=572 is divisible by 11
 * d_7d_8d_9=728 is divisible by 13
 * d_8d_9d_10=289 is divisible by 17
 * 
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <vector>
#include <array>

auto canPrune(const std::vector<int>& digits, const int& depth) -> bool {
  constexpr auto divisors{ std::array<int, 7>{2, 3, 5, 7, 11, 13, 17} };

  if (depth < 3)
    return false;

  const auto num{ digits[depth - 2] * 100 + digits[depth - 1] * 10 + digits[depth] };

  return (num % divisors[depth - 3] != 0);
}

auto vectorToNumber(const std::vector<int>& digits) -> long long {
  auto num{ 0LL };

  for (const int& digit : digits)
    num = num * 10 + digit;
  
  return num;
}

auto dfs(std::vector<int>& digits, std::vector<bool>& used, int depth, long long& sum) -> void {
  if (depth == 10) {
    sum += vectorToNumber(digits);

    return;
  }

  for (auto i{ static_cast<int>(depth == 0) }; i <= 9; i++)
    if (!used[i]) {
      digits[depth] = i;
      used[i]       = true;

      if (!canPrune(digits, depth))
        dfs(digits, used, depth + 1, sum);

      used[i] = false;
    }
}

auto main() -> int {
  auto digits { std::vector<int>(10) };
  auto used   { std::vector<bool>(10, false) };
  auto sum    { 0LL };

  dfs(digits, used, 0, sum);

  std::cout << sum << std::endl;

  return 0;
}