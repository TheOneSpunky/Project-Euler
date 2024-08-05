/**
 * Project Euler: Problem 038
 * Pandigital Multiples
 * Solution written by Kyle Swecker
 * 
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 * 
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * 
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
 * 
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 * 
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

static auto isPandigital(const std::string& number) -> bool {
  if (number.size() != 9)
    return false;

  const auto digits { std::set<char>{number.begin(), number.end()} };

  return (digits.size() == 9 && digits.find('0') == digits.end());
}

static auto concatenatedProduct(const int base, const int n) -> std::string {
  auto result { std::string{} };

  for (auto i { 1 }; i <= n; i++)
    result += std::to_string(base * i);

  return result;
}

static auto findLargestPandigital() -> int {
  constexpr auto limit             { 10000 };
  auto           largestPandigital { 0 };

  for (auto base { 1 }; base < limit; base++) {
    auto concatenated { std::string{} };

    for (auto i { 2 }; i < 10; i++) {
      concatenated = concatenatedProduct(base, i);

      if (concatenated.size() == 9 && isPandigital(concatenated))
        largestPandigital = std::max(largestPandigital, std::stoi(concatenated));
      else if (concatenated.size() > 9)
        break;
    }
  }

  return largestPandigital;
}

auto main() -> int {
  const auto largestPandigital { findLargestPandigital() };

  std::cout << "Answer: " << largestPandigital << std::endl;

  return 0;
}
