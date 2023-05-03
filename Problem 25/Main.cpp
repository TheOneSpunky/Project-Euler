/**
 * Project Euler Problem 25: 1000-digit Fibonacci number
 * 
 * The Fibonacci sequence is defined by the recurrence relation:
 *
 * Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
 * Hence the first 12 terms will be:
 *
 * F1  = 1
 * F2  = 1
 * F3  = 2
 * F4  = 3
 * F5  = 5
 * F6  = 8
 * F7  = 13
 * F8  = 21
 * F9  = 34
 * F10 = 55
 * F11 = 89
 * F12 = 144
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <iostream>
#include <cmath>

int main() {
  const auto phi    { (1.0 + std::sqrt(5.0)) / 2.0 };
  const auto lphi   { std::log10(phi) };
  const auto lsqrt5 { std::log10(std::sqrt(5.0)) / 2.0 };
  const auto index  { std::ceil((1000.0 - 1.0 + lsqrt5) / lphi) };

  std::cout << index << std::endl;

  return 0;
}