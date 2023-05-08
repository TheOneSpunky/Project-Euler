/**
 * Project Euler Problem 32: Pandigital products
 * 
 * We shall say that an n - digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5 - digit number, 15234, is 1 through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39x186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

auto isPandigital(const int& num) -> bool {
  auto numStr{ std::to_string(num) };

  std::sort(numStr.begin(), numStr.end());

  return numStr == "123456789";
}

auto main() -> int {
  auto products{ std::unordered_set<int>{} };

  for (auto multiplicand{ 1 }; multiplicand <= 99; multiplicand++)
    for (auto multiplier{ 100 }; multiplier <= 9999 / multiplicand; multiplier++) {
      auto product      { multiplicand * multiplier };
      auto concatenated { std::stoi(std::to_string(multiplicand) + std::to_string(multiplier) + std::to_string(product)) };

      if (isPandigital(concatenated))
        products.insert(product);
    }

  auto sum{ 0 };

  for (const auto& product : products)
    sum += product;

  std::cout << sum << std::endl;

  return 0;
}