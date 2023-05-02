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
#include <vector>
#include <cmath>

auto properDivisorSums(const int& limit) -> std::vector<int> {
  const auto sqrtLimit { std::sqrt(limit) };
  auto       sums      { std::vector<int>(limit, 1) };

  sums[0] = 0;

  for (auto i{ 2 }; i <= sqrtLimit; i++)
    for (int j = i * i; j < limit; j += i) {
      sums[j] += i;

      if (i != j / i)
        sums[j] += j / i;
    }

  return sums;
}

auto main() -> int {
  constexpr auto limit{ 10000 };

  auto sums { properDivisorSums(limit) };
  auto sum  { 0 };

  for (auto a{ 2 }; a < limit; a++) {
    const auto b{ sums[a] };

    if (b < limit && a != b && a == sums[b])
      sum += a;
  }

  std::cout << sum << std::endl;

  return 0;
}