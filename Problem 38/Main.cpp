/**
 * Project Euler Problem 38: Pandigital multiples
 * 
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 x 1 = 192
 * 192 x 2 = 384
 * 192 x 3 = 576
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

#include <iostream>
#include <string>
#include <algorithm>

constexpr auto g_maxOneDigit  { 9 };
constexpr auto g_maxNineDigit { 9876 };

auto isPandigital(const std::string& num) -> bool {
  if (num.size() != g_maxOneDigit)
    return false;

  auto sortedNum{ num };

  std::sort(sortedNum.begin(), sortedNum.end());

  return (sortedNum == "123456789");
}

auto concatenatedProduct(const int& num, const int& n) -> std::string {
  auto concatProduct{ std::string{} };

  for (auto i{ 1 }; i <= n; i++)
    concatProduct += std::to_string(num * i);

  return concatProduct;
}

auto main() -> int {
  auto largestPandigital{ 0 };

  for (auto i{ g_maxNineDigit }; i > 0; i--) {
    const auto max{ (i < 1000) ? g_maxOneDigit : 2 };

    for (auto n{ 2 }; n <= max; n++) {
      const auto concatProduct{ concatenatedProduct(i, n) };

      if (isPandigital(concatProduct)) {
        const auto pandigitalNum{ std::stoi(concatProduct) };

        if (pandigitalNum > largestPandigital) {
          largestPandigital = pandigitalNum;

          std::cout << largestPandigital << std::endl;

          return 0;
        }
      }
    }
  }

  return 1;
}