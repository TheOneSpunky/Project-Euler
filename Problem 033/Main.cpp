/**
 * Project Euler: Problem 033
 * Digit Cancelling Fractions
 * Solution written by Kyle Swecker
 * 
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 * 
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * 
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 * 
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

static auto findNonTrivialFractions() -> std::vector<std::pair<int, int>> {
  auto fractions { std::vector<std::pair<int, int>>{} };

  for (auto numerator { 10 }; numerator < 100; numerator++) {
    for (auto denominator { numerator + 1 }; denominator < 100; denominator++) {
      const auto num1 { numerator / 10 };
      const auto num2 { numerator % 10 };
      const auto den1 { denominator / 10 };
      const auto den2 { denominator % 10 };

      if (!num2 && !den2) 
        continue;

      if (num1 == den1 && num2 * denominator == numerator * den2)
        fractions.emplace_back(numerator, denominator);
      else if (num1 == den2 && num2 * denominator == numerator * den1)
        fractions.emplace_back(numerator, denominator);
      else if (num2 == den1 && num1 * denominator == numerator * den2)
        fractions.emplace_back(numerator, denominator);
      else if (num2 == den2 && num1 * denominator == numerator * den1)
        fractions.emplace_back(numerator, denominator);
    }
  }

  return fractions;
}

static auto multiplyFractions(const std::vector<std::pair<int, int>>& fractions) -> std::pair<int, int> {
  auto product { std::pair<int, int>{1, 1} };

  for (const auto& fraction : fractions) {
    product.first  *= fraction.first;
    product.second *= fraction.second;
  }

  return product;
}

static auto reduceFraction(const std::pair<int, int>& fraction) -> std::pair<int, int> {
  const auto gcd { std::gcd(fraction.first, fraction.second) };

  return { fraction.first / gcd, fraction.second / gcd };
}

auto main() -> int {
  const auto fractions { findNonTrivialFractions() };
  const auto product   { multiplyFractions(fractions) };
  const auto reduced   { reduceFraction(product) };

  std::cout << "Answer: " << reduced.second << std::endl;

  return 0;
}
