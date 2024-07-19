/**
 * Project Euler: Problem 026
 * Reciprocal Cycles
 * Solution written by Kyle Swecker
 * 
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 * 
 * 1/2  = 0.5
 * 1/3  = 0.(3)
 * 1/4  = 0.25
 * 1/5  = 0.2
 * 1/6  = 0.1(6)
 * 1/7  = 0.(142857)
 * 1/8  = 0.125
 * 1/9  = 0.(1)
 * 1/10 = 0.1
 * 
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <vector>

static auto getCycleLength(const int denominator) -> int {
  auto remainders { std::vector<int>(denominator, 0) };
  auto value      { 1 };
  auto position   { 0 };

  while (!remainders[value] && value) {
    remainders[value] = position;
    value            *= 10;
    value            %= denominator;
    position++;
  }

  if (!value)
    return 0;

  return (position - remainders[value]);
}

static auto findLongestCycle(const int target) -> int {
  auto maxLength { 0 };
  auto number    { 0 };

  for (auto d { 2 }; d < target; d++) {
    const auto length { getCycleLength(d) };

    if (length > maxLength) {
      maxLength = length;
      number    = d;
    }
  }

  return number;
}

auto main() -> int {
  const auto target { 1'000 };
  const auto result { findLongestCycle(target) };

  std::cout << "Answer: " << result << std::endl;

  return 0;
}
