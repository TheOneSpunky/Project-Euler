/**
 * Project Euler: Problem 043
 * Sub-string divisibility
 * Solution written by Kyle Swecker
 * 
 * The number, 1406357289, is a 0 to 9 pandigital number because
 * it is made up of each of the digits 0 to 9 in some order, but
 * it also has a rather interesting sub-string divisibility property.
 * 
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this
 * way, we note the following:
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
#include <array>
#include <numeric>
#include <chrono>
#include <cstdint>

constexpr auto g_divisors { std::array<int, 7>{2, 3, 5, 7, 11, 13, 17} };

static constexpr auto isDivisible(const std::array<int, 10>& digits, int start, int divisor) -> bool {
  const auto num { 100 * digits[start] + 10 * digits[static_cast<long long>(start) + 1] + digits[static_cast<long long>(start) + 2] };

  return (!(num % divisor));
}

static auto generatePandigitals(std::array<int, 10>& digits, std::array<bool, 10>& used, int index, std::int64_t& sum) -> void {
  if (index == 10) {
    const auto number { std::accumulate(digits.begin(), digits.end(), 0LL, [](std::int64_t acc, int digit) {
      return (acc * 10 + digit);
    })};

    sum += number;

    return;
  }

  for (auto digit { 0 }; digit <= 9; digit++) {
    if (!used[digit]) {
      if (!index && !digit)
        continue;

      digits[index] = digit;

      auto isValid { true };

      if (index >= 3) {
        const auto pos { index - 3 };

        if (pos < g_divisors.size() && !isDivisible(digits, index - 2, g_divisors[pos]))
          isValid = false;
      }

      if (isValid) {
        used[digit] = true;

        generatePandigitals(digits, used, index + 1, sum);

        used[digit] = false;
      }
    }
  }
}

static auto calculateSum() -> std::int64_t {
  auto digits { std::array<int, 10>{} };
  auto used   { std::array<bool, 10>{} };
  auto sum    { std::int64_t{} };

  generatePandigitals(digits, used, 0, sum);

  return sum;
}

auto main() -> int {
  const auto sum { calculateSum() };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
