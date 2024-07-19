/**
 * Project Euler: Problem 025
 * 1000-digit Fibonacci Number
 * Solution written by Kyle Swecker
 * 
 * The Fibonacci sequence is defined by the recurrence relation:
 * 
 * Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
 * 
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
 * 
 * The 12th term, F12, is the first term to contain three digits.
 * 
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

static auto findIndex(const int digits) -> int {
  auto previous { std::vector<int>(1, 1) };
  auto current  { std::vector<int>(1, 1) };
  auto index    { 2 };

  while (current.size() < digits) {
    auto next { std::vector<int>(current.size() + 1, 0) };

    for (auto i { std::size_t{} }; i < current.size(); i++) {
      next[i] += current[i];

      if (next[i] >= 10) {
        next[i + 1] += next[i] / 10;
        next[i]     %= 10;
      }
    }

    for (auto i { std::size_t{} }; i < previous.size(); i++) {
      next[i] += previous[i];

      if (next[i] >= 10) {
        next[i + 1] += next[i] / 10;
        next[i]     %= 10;
      }
    }

    if (!next.back())
      next.pop_back();

    previous = current;
    current  = next;
    index++;
  }

  return index;
}

auto main() -> int {
  constexpr auto digits { 1'000 };
  const auto     index  { findIndex(digits) };

  std::cout << "Answer: " << index << std::endl;

  return 0;
}
