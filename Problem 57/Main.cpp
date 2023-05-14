/**
 * Project Euler Problem 57: Square root convergents
 * 
 * It is possible to show that the square root of two can be expressed as an infinite continued fraction.
 *
 * \sqrt 2 =1+ \frac 1 {2+ \frac 1 {2 +\frac 1 {2+ \dots}}}
 *
 * By expanding this for the first four iterations, we get:
 *
 * 1 + \frac 1 2 = \frac  32 = 1.5
 * 1 + \frac 1 {2 + \frac 1 2} = \frac 7 5 = 1.4
 * 1 + \frac 1 {2 + \frac 1 {2+\frac 1 2}} = \frac {17}{12} = 1.41666 \dots
 * 1 + \frac 1 {2 + \frac 1 {2+\frac 1 {2+\frac 1 2}}} = \frac {41}{29} = 1.41379 \dots
 *
 * The next three expansions are \frac {99}{70}, \frac {239}{169}, and \frac {577}{408}, but the eighth expansion, \frac {1393}{985}, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
 *
 * In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
 */

#include <iostream>
#include <vector>

auto add(const std::vector<int>& a, const std::vector<int>& b) -> std::vector<int> {
  auto result { std::vector<int>(std::max(a.size(), b.size())) };
  auto carry  { 0 };

  for (auto i{ 0 }; i < result.size(); i++) {
    if (i < a.size())
      carry += a[i];
    if (i < b.size())
      carry += b[i];

    result[i]  = carry % 10;
    carry     /= 10;
  }
  if (carry)
    result.push_back(carry);

  return result;
}

auto multiply(const std::vector<int>& a, const int& b) -> std::vector<int> {
  auto result { std::vector<int>(a.size()) };
  auto carry  { 0 };

  for (auto i{ 0 }; i < a.size(); i++) {
    carry     += a[i] * b;
    result[i]  = carry % 10;
    carry     /= 10;
  }
  while (carry > 0) {
    result.push_back(carry % 10);
    carry /= 10;
  }

  return result;
}

auto main() -> int {
  auto numerator   { std::vector<int>{1} };
  auto denominator { std::vector<int>{1} };
  auto count       { 0 };

  for (auto i{ 0 }; i < 1000; i++) {
    const auto new_numerator   { add(multiply(denominator, 2), numerator) };
    const auto new_denominator { add(numerator, denominator) };

    if (new_numerator.size() > new_denominator.size())
      count++;

    numerator   = new_numerator;
    denominator = new_denominator;
  }

  std::cout << count << std::endl;

  return 0;
}