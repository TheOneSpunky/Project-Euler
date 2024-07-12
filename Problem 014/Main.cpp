/**
 * Project Euler: Problem 014
 * Largest Collatz Sequence
 * Solution written by Kyle Swecker
 * 
 * The following iterative sequence is defined for the set of positive integers:
 * 
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following sequence:
 * 
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * 
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 * 
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>
#include <unordered_map>
#include <cstdint>

auto g_cache { std::unordered_map<std::uint64_t, std::uint64_t>{{1, 1}} };

static auto chainLength(std::uint64_t n) -> std::uint64_t {
  if (g_cache.find(n) != g_cache.end())
    return g_cache[n];

  auto length { std::uint64_t{} };

  if (!(n % 2))
    length = 1 + chainLength(n / 2);
  else
    length = 2 + chainLength((3 * n + 1) / 2);

  g_cache[n] = length;

  return length;
}

static auto findLongestChain(std::uint64_t n) -> std::pair<std::uint64_t, std::uint64_t> {
  auto maxLength      { std::uint64_t{} };
  auto startingNumber { std::uint64_t{} };

  for (auto i { n / 2 }; i < n; i++) {
    const auto length { chainLength(i) };

    if (length > maxLength) {
      maxLength      = length;
      startingNumber = i;
    }
  }

  return {startingNumber, maxLength};
}

auto main() -> int {
  constexpr auto target                      { std::uint64_t{1'000'000} };
  const auto     [startingNumber, maxLength] { findLongestChain(target) };

  std::cout << "Answer: " << startingNumber << " (" << maxLength << " terms)" << std::endl;

  return 0;
}
