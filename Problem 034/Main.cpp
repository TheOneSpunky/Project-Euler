/**
 * Project Euler: Problem 034
 * Digit Factorials
 * Solution written by Kyle Swecker
 * 
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * 
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * 
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream>
#include <vector>
#include <array>
#include <numeric>

static auto factorial(const std::size_t n) -> std::size_t {
  static const auto factorials {
    std::array<std::size_t, 10> {
      []() {
        auto facts { std::array <std::size_t, 10>{1} };

        for (auto i { std::size_t{1} }; i < 10; i++)
          facts[i] = facts[i - 1] * i;

        return facts;
      }()
    }
  };

  return factorials[n];
}

static auto sumDigitFactorials(std::size_t n) -> std::size_t {
  auto sum { std::size_t{0} };

  while (n > 0) {
    sum += factorial(n % 10);
    n   /= 10;
  }

  return sum;
}

static auto sumCuriousNumbers() -> std::size_t {
  auto curiousNumbers { std::vector<std::size_t>{} };

  for (auto i { std::size_t{10} }; i < 50000; i++)
    if (i == sumDigitFactorials(i))
      curiousNumbers.push_back(i);

  return std::accumulate(curiousNumbers.begin(), curiousNumbers.end(), std::size_t{0});
}

auto main() -> int {
  const auto sum { sumCuriousNumbers() };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
