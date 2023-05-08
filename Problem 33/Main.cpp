/**
 * Project Euler Problem 33: Digit cancelling fractions
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
#include <numeric>
#include <vector>

auto isCuriousFraction(int num, int den) -> bool {
  if (num % 10 == 0 && den % 10 == 0)
    return false; // Trivial example

  auto commonDigit{ -1 };

  for (auto i{ 1 }; i <= 9; i++)
    if ((num / 10 == i || num % 10 == i) && (den / 10 == i || den % 10 == i)) {
      commonDigit = i;
      break;
    }

  if (commonDigit == -1)
    return false;

  const auto simplifiedNum{ num / 10 == commonDigit ? num % 10 : num / 10 };
  const auto simplifiedDen{ den / 10 == commonDigit ? den % 10 : den / 10 };

  return (num * simplifiedDen == den * simplifiedNum);
}

auto main() -> int {
  auto curiousFractions{ std::vector<std::pair<int, int>>{} };

  for (auto num{ 10 }; num < 100; num++)
    for (auto den{ num + 1 }; den < 100; den++)
      if (isCuriousFraction(num, den))
        curiousFractions.push_back({ num, den });

  auto productNum { 1 };
  auto productDen { 1 };

  for (const auto& fraction : curiousFractions) {
    productNum *= fraction.first;
    productDen *= fraction.second;
  }

  const auto gcd{ std::gcd(productNum, productDen) };

  productNum /= gcd;
  productDen /= gcd;

  std::cout << productDen << std::endl;

  return 0;
}