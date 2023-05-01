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
#include <algorithm>
#include <execution>

auto collatzLength(long long n) -> long long {
  auto length{ 0LL };

  while (n != 1) {
    if ((n & 1) == 0)
      n >>= 1;
    else
      n = 3 * n + 1;

    length++;
  }

  return length;
}

auto main() -> int {
  constexpr auto limit   { 1000000 };
  auto           lengths { std::vector<long long>(limit) };

  std::for_each(std::execution::par_unseq, lengths.begin() + 1, lengths.end(),
    [&lengths](long long& length) {
      length = collatzLength(&length - &lengths[0]);
    });

  const auto maxIter        { std::max_element(lengths.begin() + 1, lengths.end()) };
  const auto startingNumber { std::distance(lengths.begin(), maxIter) };

  std::cout << startingNumber << std::endl;

  return 0;
}