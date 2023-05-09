/**
 * Project Euler Problem 40: Champernowne's constant
 * 
 * An irrational decimal fraction is created by concatenating the positive integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If d_n represents the nth digit of the fractional part, find the value of the following expression:
 * 
 * d_1 x d_10 x d_100 x d_1000 x d_10000 x d_100000 x d_1000000
 */

#include <iostream>
#include <string>
#include <cmath>

auto getDigitAtPos(const int& pos) {
  auto currentPos { 0 };
  auto digitCount { 0 };
  auto number     { 1 };

  while (currentPos < pos) {
    auto temp{ number };

    while (temp) {
      temp /= 10;
      digitCount++;
    }

    currentPos += digitCount;
    digitCount  = 0;
    number++;
  }
  number--;

  const auto indexFromRight{ currentPos - pos };

  return (number / static_cast<int>(std::pow(10, indexFromRight))) % 10;
}

auto main() -> int {
  const auto product {
    getDigitAtPos(1)    * getDigitAtPos(10)    * getDigitAtPos(100)    *
    getDigitAtPos(1000) * getDigitAtPos(10000) * getDigitAtPos(100000) *
    getDigitAtPos(1000000)
  };

  std::cout << product << std::endl;

  return 0;
}