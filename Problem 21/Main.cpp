/**
 * Project Euler Problem 21: Amicable numbers
 * 
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <cmath>

auto sumProperDivisors(const int& num) -> int {
  const auto sqrtNum { std::sqrt(num) };
  auto       sum     { 1 };

  for (auto i{ 2 }; i <= sqrtNum; i++)
    if (num % i == 0) {
      sum += i;

      if (i != num / i)
        sum += num / i;
    }

  return sum;
}

auto main() -> int {
  auto sum{ 0 };

  for (auto a{ 2 }; a < 10000; a++) {
    const auto b{ sumProperDivisors(a) };

    if (a != b && a == sumProperDivisors(b))
      sum += a;
  }

  std::cout << sum << std::endl;

  return 0;
}