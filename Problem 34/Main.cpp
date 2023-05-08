/**
 * Project Euler Problem 34: Digit factorials
 * 
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 * Note: As 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream>
#include <vector>

auto factorial(const int& n) -> int {
  if (n == 0 || n == 1)
    return 1;

  return (n * factorial(n - 1));
}

auto main() -> int {
  constexpr auto maxValue   { 1814400 };
  auto           factorials { std::vector<int>(10) };

  for (auto i{ 0 }; i < 10; i++)
    factorials[i] = factorial(i);

  auto sumCuriousNumbers{ 0 };

  for (auto number{ 10 }; number <= maxValue; number++) {
    auto temp               { number };
    auto sumDigitFactorials { 0 };

    while (temp > 0) {
      const auto digit{ temp % 10 };

      sumDigitFactorials += factorials[digit];
      temp               /= 10;
    }

    if (sumDigitFactorials == number)
      sumCuriousNumbers += number;
  }

  std::cout << sumCuriousNumbers << std::endl;

  return 0;
}