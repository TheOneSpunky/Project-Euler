/**
 * Project Euler Problem 53: Combinatoric selections
 * 
 * There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, $\displaystyle \binom 5 3 = 10$.
 *
 * In general, $\displaystyle \binom n r = \dfrac{n!}{r!(n-r)!}$, where $r \le n$, $n! = n \times (n-1) \times ... \times 3 \times 2 \times 1, and 0! = 1$.
 *
 * It is not until $n = 23$, that a value exceeds one-million: $\displaystyle \binom {23} {10} = 1144066$
 *
 * How many, not necessarily distinct, values of $\displaystyle \binom n r$ for $1 \le n \le 100$, are greater than one-million?
 */

#include <iostream>
#include <vector>

constexpr auto g_N     { 101 };
constexpr auto g_M     { static_cast<std::int64_t>(1e6) };
auto           g_binom { std::vector<std::vector<int64_t>>(g_N, std::vector<int64_t>(g_N)) };

auto calcBinom() -> void {
  for (auto i{ 0 }; i < g_N; i++) {
    g_binom[i][0] = g_binom[i][i] = 1;

    for (auto j{ 1 }; j < i; j++) {
      g_binom[i][j] = g_binom[i - 1][j - 1] + g_binom[i - 1][j];

      if (g_binom[i][j] > g_M)
        g_binom[i][j] = g_M + 1;
    }
  }
}

auto main() -> int {
  calcBinom();

  auto count{ 0 };

  for (auto n{ 1 }; n < g_N; n++)
    for (auto r{ 0 }; r <= n / 2; r++)
      if (g_binom[n][r] > g_M) {
        count += n - 2 * r + 1;
        break;
      }

  std::cout << count << std::endl;

  return 0;
}