/**
 * Project Euler: Problem 032
 * Pandigital Products
 * Solution written by Kyle Swecker
 * 
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 * 
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 * 
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 * 
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

static auto isPandigital(const int a, const int b, const int c) -> bool {
  auto product { std::to_string(a) + std::to_string(b) + std::to_string(c) };

  if (product.size() != 9)
    return false;

  std::sort(product.begin(), product.end());

  return product == "123456789";
}

static auto sumPandigitalProducts() -> int {
  auto products { std::unordered_set<int>{} };

  for (auto a { 1 }; a < 100; a++)
    for (auto b { a }; b < 5000; b++) {
      const auto product { a * b };

      if (isPandigital(a, b, product))
        products.insert(product);
    }

  auto sum { 0 };

  for (const auto& product : products)
    sum += product;

  return sum;
}

auto main() -> int {
  const auto sum { sumPandigitalProducts() };

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
