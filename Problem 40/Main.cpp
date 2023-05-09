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

int main() {
  auto irrationalDecimalFraction { std::string{} };
  auto i                         { 1 };

  while (irrationalDecimalFraction.size() <= 1000000) {
    irrationalDecimalFraction += std::to_string(i);
    i++;
  }

  const auto d1       { irrationalDecimalFraction[0]      - '0' };
  const auto d10      { irrationalDecimalFraction[9]      - '0' };
  const auto d100     { irrationalDecimalFraction[99]     - '0' };
  const auto d1000    { irrationalDecimalFraction[999]    - '0' };
  const auto d10000   { irrationalDecimalFraction[9999]   - '0' };
  const auto d100000  { irrationalDecimalFraction[99999]  - '0' };
  const auto d1000000 { irrationalDecimalFraction[999999] - '0' };
  const auto result   { d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000 };

  std::cout << result << std::endl;

  return 0;
}