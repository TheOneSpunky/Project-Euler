/**
 * Project Euler Problem 1: Multiples of 3 or 5
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>
#include <future>
#include <mutex>

std::mutex g_mtx;

auto sumMultiplesPartial(int start, int end, const std::vector<int>& terms, int limit, int* sum) -> void {
  const auto numTerms{ static_cast<int>(terms.size()) };

  for (auto i{ start }; i < end; i++) {
    auto bits { std::bitset<32>{static_cast<unsigned __int64>(i)} };
    auto lcm  { 1 };
    auto sign { bits.count() % 2 == 0 ? -1 : 1 };

    for (auto j{ 0 }; j < numTerms; j++)
      if (bits[j])
        lcm = std::lcm(lcm, terms[j]);

    auto n          { (limit - 1) / lcm };
    auto partialSum { sign * lcm * n * (n + 1) / 2 };
    
    auto lock{ std::unique_lock<std::mutex>{g_mtx} };
    *sum += partialSum;
    lock.unlock();
  }
}

auto sumMultiples(const std::vector<int>& terms, int limit) -> int {
  auto       sum             { 0 };
  const auto numTerms        { static_cast<int>(terms.size()) };
  const auto numCombinations { 1 << numTerms };

  const auto numThreads { static_cast<int>(std::thread::hardware_concurrency()) };
  auto       futures    { std::vector<std::future<void>>{} };

  const auto range{ numCombinations / numThreads };

  for (auto i{ 0 }; i < numThreads; i++) {
    const auto start { i * range + 1 };
    const auto end   { (i == numThreads - 1) ? numCombinations : (i + 1) * range };

    futures.push_back(std::async(std::launch::async, sumMultiplesPartial, start, end, std::ref(terms), limit, &sum));
  }

  for (const auto& future : futures)
    future.wait();

  return sum;
}

auto main() -> int {
  constexpr auto limit { 1000 };
  const auto     terms { std::vector<int>{3, 5} };

  const auto sum{ sumMultiples(terms, limit) };

  std::cout << sum << std::endl;

  return 0;
}