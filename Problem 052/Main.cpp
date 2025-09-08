/**
 * Project Euler: Problem 052
 * Permutated Multiples
 * Solution written by Kyle Swecker
 * 
 * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 * 
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

#include <iostream>
#include <array>

using Sig = std::array<int, 10>;

static inline auto signature(long long v) -> Sig {
  auto count { Sig{} };

  do {
    count[v % 10]++;
    v /= 10;
  } while (v > 0);

  return count;
}

static inline auto pow10i(int n) -> long long {
  auto p { long long{1} };

  while (n--)
    p *= 10;

  return p;
}

auto main() -> int {
  for (auto digits { 1 }; ; digits++) {
    const auto lo    { pow10i(digits - 1) };
    const auto hi    { (pow10i(digits) - 1) / 6 };
    const auto start { (lo % 9 == 0) ? lo : lo + (9 - lo % 9) };

    for (auto x { start }; x <= hi; x += 9) {
      auto s  { signature(x) };
      auto ok { true };

      for (auto k{ 2 }; k <= 6; k++)
        if (signature(k * x) != s) {
          ok = false;
          break;
        }

      if (ok) {
        std::cout << "Answer: " << x;
        return 0;
      }
    }
  }
}