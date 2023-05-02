/**
 * Project Euler Problem 23: Non-abundant sums
 * 
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <iostream>
#include <vector>

auto sumProperDivisors(const int& n) -> int {
  auto sum{ 1 };

  for (auto i{ 2 }; i * i <= n; i++)
    if (n % i == 0) {
      sum += i;

      if (i != n / i)
        sum += n / i;
    }

  return sum;
}

auto isAbundant(const int& n) -> bool {
  return sumProperDivisors(n) > n;
}

auto main() -> int {
  constexpr auto limit{ 28123 };

  auto abundantNumbers { std::vector<int>{} };
  auto abundantSums    { std::vector<bool>(limit + 1, false) };

  for (auto i{ 1 }; i <= limit; i++)
    if (isAbundant(i)) {
      abundantNumbers.push_back(i);

      for (const auto& abundantNumber : abundantNumbers) {
        const auto abundantSum{ abundantNumber + i };

        if (abundantSum <= limit)
          abundantSums[abundantSum] = true;
      }
    }

  auto sumOfNonAbundantSums{ 0 };

  for (auto i{ 1 }; i <= limit; i++)
    if (!abundantSums[i])
      sumOfNonAbundantSums += i;

  std::cout << sumOfNonAbundantSums << std::endl;

  return 0;
}