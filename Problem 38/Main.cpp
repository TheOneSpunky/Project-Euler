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

auto isPandigital(const std::string& num) -> bool {
  if (num.size() != 9)
    return false;

  auto sortedNum{ num };

  std::sort(sortedNum.begin(), sortedNum.end());

  return (sortedNum == "123456789");
}

auto concatenatedProduct(int num, int n) -> std::string {
  auto concatProduct{ std::string{} };

  for (auto i{ 1 }; i <= n; i++)
    concatProduct += std::to_string(num * i);

  return concatProduct;
}

auto main() -> int {
  constexpr auto upper { 9876 };
  constexpr auto lower { 9 };

  auto largestPandigital{ 0 };

  for (auto i{ 1 }; i <= upper; i++)
    for (auto n{ 2 }; n <= lower; n++) {
      auto concatProduct{ concatenatedProduct(i, n) };

      if (isPandigital(concatProduct)) {
        auto pandigitalNum{ std::stoi(concatProduct) };

        if (pandigitalNum > largestPandigital)
          largestPandigital = pandigitalNum;
      }
    }

  std::cout << largestPandigital << std::endl;

  return 0;
}