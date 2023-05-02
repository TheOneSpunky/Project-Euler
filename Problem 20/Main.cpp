/**
 * Project Euler Problem 20: Factorial digit sum
 * 
 * n! means n * (n - 1) * ... * 3 * 2 * 1
 *
 * For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <vector>
#include <numbers>
#include <numeric>
#include <complex>

auto fft(std::vector<std::complex<double>>& a, const bool invert) -> void {
  const auto n{ a.size() };

  if (n == 1)
    return;

  const auto limit { n / 2 };
  auto       a0    { std::vector<std::complex<double>>(limit) };
  auto       a1    { std::vector<std::complex<double>>(limit) };

  for (auto i{ 0 }; i < limit; i++) {
    a0[i] = a[i * 2];
    a1[i] = a[i * 2 + 1];
  }

  fft(a0, invert);
  fft(a1, invert);

  auto ang { 2 * std::numbers::pi_v<double> / n * (invert ? -1 : 1) };
  auto w   { std::complex<double>(1) };
  auto wn  { std::complex<double>(std::cos(ang), std::sin(ang)) };

  for (auto i{ 0 }; i < limit; i++) {
    a[i]         = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];

    if (invert) {
      a[i]         /= 2;
      a[i + n / 2] /= 2;
    }

    w *= wn;
  }
}

auto multiply(const std::vector<int>& num1, const std::vector<int>& num2) -> std::vector<int> {
  auto a { std::vector<std::complex<double>>(num1.begin(), num1.end()) };
  auto b { std::vector<std::complex<double>>(num2.begin(), num2.end()) };
  auto n { 1 };

  auto limit{ num1.size() + num2.size() };

  while (n < limit)
    n *= 2;

  a.resize(n);
  b.resize(n);

  fft(a, false);
  fft(b, false);

  for (auto i{ 0 }; i < n; ++i)
    a[i] *= b[i];

  fft(a, true);

  auto result{ std::vector<int>(n) };

  for (auto i{ 0 }; i < n; i++)
    result[i] = static_cast<int>(std::round(a[i].real()));

  limit = n - 1;

  for (auto i{ 0 }; i < limit; i++) {
    result[i + 1] += result[i] / 10;
    result[i]     %= 10;
  }

  while (result.back() == 0 && result.size() > 1)
    result.pop_back();

  return result;
}

auto factorial(const int& n) -> std::vector<int> {
  auto result{ std::vector<int>{1} };

  for (auto i{ 2 }; i <= n; i++) {
    auto temp{ std::vector<int>{} };

    for (auto t{ i }; t > 0; t /= 10)
      temp.push_back(t % 10);

    result = multiply(result, temp);
  }

  return result;
}

auto main() -> int {
  constexpr auto n    { 100 };
  const auto     fact { factorial(n) };
  const auto     sum  { std::accumulate(fact.begin(), fact.end(), 0) };

  std::cout << sum << std::endl;

  return 0;
}