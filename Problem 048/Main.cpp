/**
 * Project Euler: Problem 048
 * Self Powers
 * Solution written by Kyle Swecker
 * 
 * The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 * 
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <iostream>
#include <cstdint>

static auto mulMod(std::uint64_t a, std::uint64_t b, std::uint64_t mod) -> std::uint64_t {
  auto result { std::uint64_t{} };

  a %= mod;
  b %= mod;

  while (b > 0) {
    if (b & 1)
      result = (result + a) % mod;

    a   = (a + a) % mod;
    b >>= 1;
  }

  return result;
}

static auto modPow(std::uint64_t base, std::uint64_t exp, std::uint64_t mod) -> std::uint64_t {
  auto result { std::uint64_t{1} };

  base %= mod;

  while (exp > 0) {
    if (exp & 1)
      result = mulMod(result, base, mod);

    base  = mulMod(base, base, mod);
    exp >>= 1;
  }

  return result;
}

auto main() -> int {
  constexpr auto mod { std::uint64_t{10000000000ULL} };
  auto           sum { std::uint64_t{} };

  for (auto i { std::uint64_t{1} }; i <= 1000; i++)
    sum = (sum + modPow(i, i, mod)) % mod;

  std::cout << "Answer: " << sum << std::endl;

  return 0;
}
