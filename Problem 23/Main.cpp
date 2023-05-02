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

// A: 4179871

#include <iostream>
#include <vector>
#include <unordered_set>

auto properDivisors(const int& n) -> std::vector<int> {
  auto divisors{ std::vector<int>{} };

  for (auto i{ 1 }; i <= n / 2; i++)
    if (n % i == 0)
      divisors.push_back(i);

  return divisors;
}

auto isAbundant(const int& n) -> bool {
  auto divisors { properDivisors(n) };
  auto sum      { 0 };

  for (const int& divisor : divisors)
    sum += divisor;

  return sum > n;
}

auto main() -> int {
  constexpr auto limit{ 28123 };

  auto abundantNumbers { std::vector<int>{} };
  auto abundantSums    { std::unordered_set<int>{} };

  for (auto i{ 1 }; i <= limit; i++)
    if (isAbundant(i))
      abundantNumbers.push_back(i);

  for (auto i{ 0ULL }; i < abundantNumbers.size(); i++)
    for (auto j{ i }; j < abundantNumbers.size(); j++) {
      const auto abundantSum{ abundantNumbers[i] + abundantNumbers[j] };

      if (abundantSum <= limit)
        abundantSums.insert(abundantSum);
    }

  auto sum{ 0 };

  for (auto i{ 1 }; i <= limit; i++)
    if (abundantSums.find(i) == abundantSums.end())
      sum += i;

  std::cout << "Sum of all positive integers which cannot be written as the sum of two abundant numbers: " << sum << std::endl;

  return 0;
}