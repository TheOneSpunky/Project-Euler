/**
 * Project Euler: Problem 050
 * Consecutive Prime Sum
 * Solution written by Kyle Swecker
 * 
 * The prime 41, can be written as the sum of six consecutive primes:
 * 
 * 41 = 2 + 3 + 5 + 7 + 11 + 13.
 * 
 * This is the longest sum of consecutive primes that adds to a prime below 100.
 * 
 * The longest sum of consecutive primes below one-thousand that adds to a prime,
 * contains 21 terms, and is equal to 953.
 * 
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>

static auto generatePrimes(int limit) -> std::vector<int> {
  auto sieve  { std::vector<bool>(limit, true) };
  auto primes { std::vector<int>{} };

  sieve[0] = sieve[1] = false;

  for (auto i { 2 }; i * i < limit; i++)
    if (sieve[i])
      for (auto j { i * i }; j < limit; j += i)
        sieve[j] = false;

  for (auto i { 2 }; i < limit; i++)
    if (sieve[i])
      primes.push_back(i);

  return primes;
}

static auto findLongestConsecutivePrimeSum(int limit) -> int {
  auto primes              { generatePrimes(limit) };
  auto primeSet            { std::unordered_set<int>(primes.begin(), primes.end()) };
  auto maxConsecutiveCount { std::size_t{21} };
  auto resultPrime         { 0 };
  auto prefixSums          { std::vector<long long>{0} };

  for (const auto& prime : primes)
    prefixSums.push_back(prefixSums.back() + prime);

  for (auto startIdx { std::size_t{0} }; startIdx < primes.size(); startIdx++) {
    if (primes.size() - startIdx <= maxConsecutiveCount)
      break;

    for (auto endIdx { std::size_t{startIdx + maxConsecutiveCount} }; endIdx < primes.size(); endIdx++) {
      const auto sum { prefixSums[endIdx + 1] - prefixSums[startIdx] };

      if (sum >= limit)
        break;

      const auto sumAsInt { static_cast<int>(sum) };

      if (primeSet.find(sumAsInt) != primeSet.end()) {
        const auto consecutiveCount { endIdx - startIdx + 1 };

        if (consecutiveCount > maxConsecutiveCount) {
          maxConsecutiveCount = consecutiveCount;
          resultPrime         = sumAsInt;
        }
      }
    }
  }

  return resultPrime;
}

auto main() -> int {
  constexpr auto limit  { 1'000'000 };
  const auto     result { findLongestConsecutivePrimeSum(limit) };

  std::cout << "Answer: " << result << std::endl;

  return 0;
}
