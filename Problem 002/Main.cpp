/**
 * Project Euler: Problem 002
 * Even Fibonacci Numbers
 * Solution written by Kyle Swecker
 * 
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 * 
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */

#include <iostream>

auto main() -> int {
  constexpr auto target { 4000000 };

  auto sum { 0 };
  auto a   { 1 };
  auto b   { 1 };
  auto c   { 2 }; // a + b

  while (c < target) {
    sum += c;

    a = b + c;
    b = c + a;
    c = a + b;
  }

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
