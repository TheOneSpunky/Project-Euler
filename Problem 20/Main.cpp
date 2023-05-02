/**
 * Project Euler Problem 20: Factorial digit sum
 * 
 * n! means n * (n - 1) * ... * 3 * 2 * 1
 *
 * For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <string>

auto multiply(const std::vector<int>& num1, const std::vector<int>& num2) -> std::vector<int> {
  auto result{ std::vector<int>(num1.size() + num2.size(), 0) };

  for (auto i{ 0ULL }; i < num1.size(); i++)
    for (auto j{ 0ULL }; j < num2.size(); j++) {
      const auto index{ i + j };

      result[index]     += num1[i] * num2[j];
      result[index + 1] += result[i + j] / 10;
      result[index]     %= 10;
    }

  while (result.back() == 0 && result.size() > 1)
    result.pop_back();

  return result;
}

auto factorial(const int& n) -> std::vector<int> {
  auto result{ std::vector<int>{1} };

  for (auto i{ 2 }; i <= n; i++) {
    auto temp{ std::vector<int>{} };

    for (auto t{ i }; t > 0; t /= 10)
      temp.push_back(t % 10);

    result = multiply(result, temp);
  }

  return result;
}

auto main() -> int {
  constexpr auto n    { 100 };
  const auto     fact { factorial(n) };
  const auto     sum  { std::accumulate(fact.begin(), fact.end(), 0) };

  std::cout << "The sum of the digits in the number 100! is: " << sum << std::endl;

  return 0;
}