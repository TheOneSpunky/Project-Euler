/**
 * Project Euler Problem 26: Reciprocal cycles
 * 
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2  = 0.5
 * 1/3  = 0.(3)
 * 1/4  = 0.25
 * 1/5  = 0.2
 * 1/6  = 0.1(6)
 * 1/7  = 0.(142857)
 * 1/8  = 0.125
 * 1/9  = 0.(1)
 * 1/10 = 0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <vector>

auto generatePrimes(const int& limit) -> std::vector<int> {
  auto isPrime { std::vector<bool>(limit + 1, true) };
  auto primes  { std::vector<int>{} };

  for (auto i{ 2 }; i <= limit; i++)
    if (isPrime[i]) {
      primes.push_back(i);

      for (auto j{ i * i }; j <= limit; j += i)
        isPrime[j] = false;
    }

  return primes;
}

auto cycleLength(const int& d) -> int {
  if (d % 2 == 0 || d % 5 == 0)
    return 0;

  auto k   { 1 };
  auto mod { 10 % d };

  while (mod != 1) {
    mod = (mod * 10) % d;
    k++;
  }

  return k;
}

auto main() -> int {
  auto primes         { generatePrimes(1000) };
  auto maxd           { 0 };
  auto maxCycleLength { 0 };

  for (auto it{ primes.rbegin() }; it != primes.rend(); it++) {
    const auto d{ *it };

    if (d <= 5)
      break;

    auto currentLength{ cycleLength(d) };

    if (currentLength > maxCycleLength) {
      maxCycleLength = currentLength;
      maxd           = d;
    }

    if (maxCycleLength == d - 1)
      break;
  }

  std::cout << maxd << std::endl;

  return 0;
}
