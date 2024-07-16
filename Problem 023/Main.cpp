/**
 * Project Euler: Problem 023
 * Non-Abundant Sums
 * Solution written by Kyle Swecker
 * 
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28
 * is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant
 * if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as
 * the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater
 * than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced
 * any further by analysis even though it is known that the greatest number that cannot be expressed as the
 * sum of two abundant numbers is less than this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <iostream>
#include <vector>

static auto sumProperDivisors(int n) -> int {
  auto sum { 1 };

  for (auto i { 2 }; i * i <= n; i++)
    if (!(n % i)) {
      sum += i;

      if (const auto s { n / i }; i != s)
        sum += s;
    }

  return sum;
}

static inline auto isAbundant(int n) -> bool {
  return (sumProperDivisors(n) > n);
}

static auto generateAbundantNumbers(int limit) -> std::vector<int> {
  auto abundantNumbers { std::vector<int>{} };

  for (auto i { 12 }; i <= limit; i++)
    if (isAbundant(i))
      abundantNumbers.push_back(i);

  return abundantNumbers;
}

static auto sumNonAbundantSums(int target) -> int {
  const auto abundantNumbers { generateAbundantNumbers(target) };
  auto       eligibleNumbers { std::vector<bool>(target + 1, false) };

  for (auto i { std::size_t{} }; i < abundantNumbers.size(); i++)
    for (auto j { i }; j < abundantNumbers.size(); j++) {
      const auto sum { abundantNumbers[i] + abundantNumbers[j] };

      if (sum <= target)
        eligibleNumbers[sum] = true;
      else
        break;
    }

  auto totalSum { 0 };

  for (auto i { 1 }; i <= target; i++)
    if (!eligibleNumbers[i])
      totalSum += i;

  return totalSum;
}

auto main() -> int {
  constexpr auto target { 28123 };
  const auto     sum    { sumNonAbundantSums(target) };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
