/**
 * Project Euler: Problem 046
 * Goldbach's Other Conjecture
 * Solution written by Kyle Swecker
 * 
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 * 
 * 9 = 7 + 2*1^2
 * 15 = 7 + 2*2^2
 * 21 = 3 + 2*3^2
 * 25 = 7 + 2*3^2
 * 27 = 19 + 2*2^2
 * 33 = 31 + 2*1^2
 * 
 * It turns out that the conjecture was false.
 * 
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <vector>
#include <cmath>

static auto sievePrimes(int limit) -> std::vector<bool> {
  auto isPrime { std::vector<bool>(limit + 1, true) };
  isPrime[0] = isPrime[1] = false;

  for (auto i { 2 }; i * i <= limit; i++)
    if (isPrime[i])
      for (auto j { i * i }; j <= limit; j += i)
        isPrime[j] = false;

  return isPrime;
}

static auto isGoldbachSum(int num, const std::vector<bool>& isPrime) -> bool {
  for (auto s { 0 }; 2 * s * s <= num; s++) {
    const auto p { num - 2 * s * s };

    if (p > 0 && p < static_cast<int>(isPrime.size()) && isPrime[p])
      return true;
  }

  return false;
}

auto main() -> int {
  constexpr auto limit   { 10000000 };
  auto           isPrime { std::vector<bool>{sievePrimes(limit)} };
  auto           answer  { -1 };

  for (auto num { 9 }; num < limit - 2 * static_cast<int>(std::sqrt(limit)); num += 2)
    if (!isPrime[num] && !isGoldbachSum(num, isPrime)) {
      answer = num;
      break;
    }

  if (answer != -1)
    std::cout << "Answer: " << answer << std::endl;
  else
    std::cout << "No solution found within the given limit. Try increasing the limit." << std::endl;

  return 0;
}
