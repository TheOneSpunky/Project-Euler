/**
 * Project Euler Problem 48: Self powers
 * 
 * The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <iostream>

constexpr auto g_mod{ 10'000'000'000LL }; // 10^10

auto power(long long base, long long exp) -> long long {
  auto result{ 1LL };

  for (auto i{ 0LL }; i < exp; i++)
    result = (result * base) % g_mod;

  return result;
}

int main() {
  auto sum{ 0LL };

  for (auto i{ 1LL }; i <= 1000; i++)
    sum = (sum + power(i, i)) % g_mod;

  std::cout << sum << std::endl;

  return 0;
}