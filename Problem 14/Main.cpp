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
#include <vector>

auto collatzLength(long long n, std::vector<long long>& lengths) -> long long {
  const auto original { n };
  auto       length   { 0LL };

  while (n != 1) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = 3 * n + 1;

    length++;

    if (n < original) {
      length += lengths[n];

      break;
    }
  }

  lengths[original] = length;

  return length;
}

auto main() -> int {
  constexpr auto limit   { 1000000 };
  auto           lengths { std::vector<long long>(limit, 0) };

  lengths[1] = 1;

  for (auto i{ 1 }; i < limit; i++)
    collatzLength(i, lengths);

  auto longestChain   { 0LL };
  auto startingNumber { 0LL };

  for (auto i{ 1 }; i < limit; i++)
    if (lengths[i] > longestChain) {
      longestChain   = lengths[i];
      startingNumber = i;
    }

  std::cout << startingNumber << std::endl;

  return 0;
}