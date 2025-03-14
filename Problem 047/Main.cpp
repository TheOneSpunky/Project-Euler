/**
 * Project Euler: Problem 047
 * Distinct Primes Factors
 * Solution written by Kyle Swecker
 * 
 * The first two consecutive numbers to have two distinct prime factors are:
 * 
 * 14 = 2 * 7
 * 15 = 3 * 5
 * 
 * The first three consecutive numbers to have three distinct prime factors are:
 * 
 * 644 = 2^2 * 7 * 23
 * 645 = 3 * 5 * 43
 * 646 = 2 * 17 * 19
 * 
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */

#include <iostream>
#include <unordered_set>
#include <cmath>
#include <array>
#include <map>

static auto countDistinctPrimeFactors(long long n) -> int {
  auto factors { std::unordered_set<long long>{} };

  while (!(n % 2)) {
    factors.insert(2);
    n /= 2;
  }

  for (auto i { long long{3} }; i <= std::sqrt(n); i += 2)
    while (!(n % i)) {
      factors.insert(i);
      n /= i;
    }

  if (n > 2)
    factors.insert(n);

  return factors.size();
}

static auto getPrimeFactorization(long long n) -> std::map<long long, int> {
  auto factorization{ std::map<long long, int>{} };

  while (!(n % 2)) {
    factorization[2]++;
    n /= 2;
  }

  for (auto i { long long{3} }; i <= std::sqrt(n); i += 2)
    while (!(n % i)) {
      factorization[i]++;
      n /= i;
    }

  if (n > 2)
    factorization[n]++;

  return factorization;
}

auto main() -> int {
  constexpr auto start        { long long{647} };
  auto           factorCounts { std::array<int, 4>{} };
  auto           found        { false };

  factorCounts[0] = countDistinctPrimeFactors(start);
  factorCounts[1] = countDistinctPrimeFactors(start + 1);
  factorCounts[2] = countDistinctPrimeFactors(start + 2);

  auto num { long long{start + 3} };

  while (!found) {
    factorCounts[3] = countDistinctPrimeFactors(num);

    found = (factorCounts[0] == 4 && factorCounts[1] == 4 && factorCounts[2] == 4 && factorCounts[3] == 4);

    if (!found) {
      factorCounts[0] = factorCounts[1];
      factorCounts[1] = factorCounts[2];
      factorCounts[2] = factorCounts[3];
      num++;
    }
  }

  const auto result{ long long{num - 3} };

  std::cout << "Answer: " << result << std::endl;

  return 0;
}
