/**
 * Project Euler Problem 46: Goldbach's other conjecture
 * 
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2x12
 * 15 = 7 + 2x22
 * 21 = 3 + 2x32
 * 25 = 7 + 2x32
 * 27 = 19 + 2x22
 * 33 = 31 + 2x12
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include<iostream>
#include<vector>
#include<cmath>

auto primeSieve(const int& n) -> std::vector<bool> {
  auto prime{ std::vector<bool>(n + 1, true) };

  prime[0] = prime[1] = false;

  for (auto p{ 2 }; p * p <= n; p++)
    if (prime[p] == true)
      for (auto i{ p * p }; i <= n; i += p)
        prime[i] = false;

  return prime;
}

auto isComposite(const int& n) -> bool {
  if (n <= 1)
    return false;
  else if (n <= 3)
    return false;
  else if (n % 2 == 0 || n % 3 == 0)
    return true;

  for (auto i{ 5 }; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return true;

  return false;
}

auto main() -> int {
  constexpr auto n     { 10000 };
  auto           prime { primeSieve(n) };

  for (auto i{ 9 }; i <= n; i += 2)
    if (isComposite(i)) {
      auto found{ false };

      for (auto j{ 2 }; j < i && !found; j++)
        if (prime[j])
          for (auto k{ 0 }; k * k <= (i - j) / 2 && !found; k++)
            if (j + 2 * k * k == i)
              found = true;

      if (!found) {
        std::cout << i << std::endl;
        break;
      }
    }

  return 0;
}