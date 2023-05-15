/**
 * Project Euler Problem 60: Prime pair sets
 * 
 * The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
 *
 * Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr auto g_max         { 10000 };
auto           g_isComposite { std::bitset<g_max>{} };
auto           g_primes      { std::vector<int>{} };
auto           g_result      { std::vector<int>{} };

auto sieve() -> void {
  g_isComposite.set(0);
  g_isComposite.set(1);

  for (auto i{ 2 }; i < g_max; i++)
    if (!g_isComposite[i]) {
      g_primes.push_back(i);

      for (auto j{ i * i }; j < g_max; j += i)
        g_isComposite.set(j);
    }
}

auto isPrime(const int& n) -> bool {
  if (n < g_max)
    return !g_isComposite[n];

  for (const auto& prime : g_primes)
    if (prime * prime > n)
      break;
    else if (n % prime == 0)
      return false;

  return true;
}

auto checkConcatenation(int p1, const int& p2) -> bool {
  auto temp{ p2 };

  while (temp > 0) {
    p1   *= 10;
    temp /= 10;
  }

  return isPrime(p1 + p2);
}

auto dfs(std::vector<int>& current, const int& depth, const int& start) -> bool {
  if (depth == 5) {
    g_result = current;

    return true;
  }

  for (auto i{ start }; i < g_primes.size(); i++) {
    current[depth] = g_primes[i];

    auto flag{ true };

    for (auto j{ 0 }; j < depth; j++)
      if (!checkConcatenation(current[depth], current[j]) || !checkConcatenation(current[j], current[depth])) {
        flag = false;
        break;
      }

    if (flag && dfs(current, depth + 1, i + 1))
      return true;
  }

  return false;
}

auto main() -> int {
  auto current { std::vector<int>(5) };
  auto sum     { 0 };

  sieve();
  dfs(current, 0, 0);

  for (const int& prime : g_result)
    sum += prime;

  std::cout << sum << std::endl;

  return 0;
}