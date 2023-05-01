/**
 * Project Euler Problem 14: Longest Collatz sequence
 * 
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * 
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>
#include <unordered_map>

auto collatzLength(const long long& n, std::unordered_map<long long, long long>& memo) -> long long {
  if (n == 1)
    return 1;

  if (memo.find(n) != memo.end())
    return memo[n];

  auto length{ 1LL };

  if (n % 2 == 0)
    length += collatzLength(n / 2, memo);
  else
    length += collatzLength(3 * n + 1, memo);

  memo[n] = length;

  return length;
}

auto main() -> int {
  constexpr auto limit{ 1000000 };

  auto longestChain   { 0LL };
  auto startingNumber { 0LL };
  auto memo           { std::unordered_map<long long, long long>{} };

  for (auto i{ 1 }; i < limit; i++) {
    const auto length{ collatzLength(i, memo) };

    if (length > longestChain) {
      longestChain   = length;
      startingNumber = i;
    }
  }

  std::cout << startingNumber << std::endl;

  return 0;
}