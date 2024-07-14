/**
 * Project Euler: Problem 021
 * Amicable Numbers
 * Solution written by Kyle Swecker
 * 
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called
 * amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, and 110; therefore d(220) = 284.
 * The proper divisors of 284 are 1, 2, 4, 71, and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <vector>
#include <numeric>

static auto sumProperDivisors(const int n) -> int {
  if (n < 2)
    return 0;

  const auto sqrtN { static_cast<int>(std::sqrt(n)) };
  auto       sum   { 1 };

  for (auto i { 2 }; i <= sqrtN; i++)
    if (!(n % i)) {
      sum += i;

      if (const auto j { n / i }; i != j)
        sum += j;
    }

  return sum;
}

static auto findAmicableNumbers(const int target) -> std::vector<int> {
  auto amicableNumbers { std::vector<int>{} };

  for (auto a { 2 }; a < target; a++) {
    const auto b { sumProperDivisors(a) };

    if (b > a && b < target && sumProperDivisors(b) == a) {
      amicableNumbers.push_back(a);
      amicableNumbers.push_back(b);
    }
  }

  return amicableNumbers;
}

static auto sumAmicableNumbers(const int target) -> int {
  const auto amicableNumbers { findAmicableNumbers(target) };

  return std::accumulate(amicableNumbers.begin(), amicableNumbers.end(), 0);
}

auto main() -> int {
  constexpr auto target { 10000 };
  const auto     sum    { sumAmicableNumbers(target) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
