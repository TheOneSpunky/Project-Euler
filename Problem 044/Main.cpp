/**
 * Project Euler: Problem 044
 * Pentagon Numbers
 * Solution written by Kyle Swecker
 * 
 * Pentagonal numbers are represented by the formula,
 * P(n) = n(3n - 1) / 2. The first few pentagonal numbers are:
 * 
 *    1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
 * 
 * It can be seen that P(4) + P(7) = 22 + 70 = 92 = P(8).
 * However, their difference, 70 - 22 = 48, is not pentagonal.
 * 
 * Find the pair of pentagonal numbers, P(j) and P(k), for which
 * their sum and difference are pentagonal and D = |P(k) - P(j)|
 * is minimised; what is the value of D?
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <limits>
#include <algorithm>
#include <utility>

static auto pentagonal(std::uint64_t n) -> std::uint64_t {
  return (n * (3 * n - 1) / 2);
}

static auto isPentagonalFormula(std::uint64_t p) -> bool {
  const auto discriminant     { 1.0 + 24.0 * static_cast<double>(p) };
  const auto sqrtDiscriminant { std::sqrt(discriminant) };
  const auto n                { (sqrtDiscriminant + 1.0) / 6.0 };
  const auto epsilon          { 1e-10 };

  return (std::abs(n - std::round(n)) < epsilon);
}

static auto isPentagonal(std::uint64_t p, const std::unordered_set<std::uint64_t>& pentagonalSet, std::uint64_t maxPentagonal) -> bool {
  if (pentagonalSet.find(p) != pentagonalSet.end())
    return true;
  else if (p > maxPentagonal)
    return isPentagonalFormula(p);

  return false;
}

static auto initializePentagonals(std::uint64_t limit, std::vector<std::uint64_t>& pentagonals, std::unordered_set<std::uint64_t>& pentagonalSet) -> void {
  pentagonals.reserve(limit);

  for (auto i { std::uint64_t{1} }; i <= limit; i++)
    pentagonals.push_back(pentagonal(i));

  pentagonalSet = std::unordered_set<std::uint64_t>(pentagonals.begin(), pentagonals.end());
}

static auto findMinimumDifference(const std::vector<std::uint64_t>& pentagonals, const std::unordered_set<std::uint64_t>& pentagonalSet) -> std::pair<std::uint64_t, std::pair<std::uint64_t, std::uint64_t>> {
  auto minDifference { std::uint64_t{std::numeric_limits<std::uint64_t>::max()} };
  auto resultJ       { std::uint64_t{0} };
  auto resultK       { std::uint64_t{0} };

  for (auto j { std::size_t{0} }; j < pentagonals.size(); j++) {
    const auto pj { std::uint64_t{pentagonals[j]} };

    for (auto k { std::size_t{j + 1} }; k < pentagonals.size(); k++) {
      const auto pk   { std::uint64_t{pentagonals[k]} };
      const auto diff { std::uint64_t{pk - pj} };

      if (diff >= minDifference)
        break;

      if (isPentagonal(diff, pentagonalSet, pentagonals.back())) {
        const auto sum { std::uint64_t{pj + pk} };

        if (isPentagonal(sum, pentagonalSet, pentagonals.back())) {
          minDifference = diff;
          resultJ       = j + 1;
          resultK       = k + 1;
        }
      }
    }
  }

  return { minDifference, {resultJ, resultK} };
}

auto main() -> int {
  constexpr auto limit { std::uint64_t{10000} };

  auto pentagonals   { std::vector<std::uint64_t>{} };
  auto pentagonalSet { std::unordered_set<std::uint64_t>{} };

  initializePentagonals(limit, pentagonals, pentagonalSet);

  const auto [minDifference, indices] = findMinimumDifference(pentagonals, pentagonalSet);
  const auto [j, k]                   = indices;

  if (minDifference != std::numeric_limits<std::uint64_t>::max()) {
    auto pj  { pentagonal(j) };
    auto pk  { pentagonal(k) };
    auto sum { std::uint64_t{pj + pk} };

    std::cout << "Answer: " << minDifference << std::endl;
  }
  else
    std::cout << "No solution found within the given range." << std::endl;

  return 0;
}