/**
 * Project Euler: Problem 016
 * Power Digit Sum
 * Solution written by Kyle Swecker
 * 
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * 
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <algorithm>

static auto bigMultiply(const std::vector<std::uint64_t>& num, std::uint64_t multiplier) -> std::vector<std::uint64_t> {
  auto result { std::vector<std::uint64_t>{} };
  auto carry  { std::uint64_t{} };

  for (auto digit : num) {
    const auto product { digit * multiplier + carry };

    result.push_back(product % 10);
    carry = product / 10;
  }

  while (carry > 0) {
    result.push_back(carry % 10);
    carry /= 10;
  }

  return result;
}

static auto bigPower(std::uint64_t base, std::uint64_t exponent) -> std::vector<std::uint64_t> {
  auto result { std::vector<std::uint64_t>{1} };

  for (auto i { std::uint64_t{} }; i < exponent; i++)
    result = bigMultiply(result, base);
  std::reverse(result.begin(), result.end());

  return result;
}

static inline auto bigSum(const std::vector<std::uint64_t>& n) -> std::uint64_t {
  return std::accumulate(n.begin(), n.end(), static_cast<std::uint64_t>(0));
}

auto main() -> int {
  const auto result   { bigPower(2, 1000) };
  const auto digitSum { bigSum(bigPower(2, 1000)) };

  std::cout << "Answer: " << digitSum << std::endl;

  return 0;
}
