/**
 * Project Euler: Problem 017
 * Number Letter Counts
 * Solution written by Kyle Swecker
 * 
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are
 * 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * 
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many
 * letters would be used?
 * 
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains
 * 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing
 * out numbers is in compliance with British usage.
 */

#include <iostream>
#include <string>
#include <cstdint>
#include <map>
#include <algorithm>

static auto convert(std::uint64_t n) -> std::string {
  static const auto units {
    std::map<std::uint64_t, std::string> {
      {1, "one"},
      {2, "two"},
      {3, "three"},
      {4, "four"},
      {5, "five"},
      {6, "six"},
      {7, "seven"},
      {8, "eight"},
      {9, "nine"}
    }
  };
  static const auto teens {
    std::map<std::uint64_t, std::string> {
      {10, "ten"},
      {11, "eleven"},
      {12, "twelve"},
      {13, "thirteen"},
      {14, "fourteen"},
      {15, "fifteen"},
      {16, "sixteen"},
      {17, "seventeen"},
      {18, "eighteen"},
      {19, "nineteen"}
    }
  };
  static const auto tens {
    std::map<std::uint64_t, std::string> {
      {20, "twenty"},
      {30, "thirty"},
      {40, "forty"},
      {50, "fifty"},
      {60, "sixty"},
      {70, "seventy"},
      {80, "eighty"},
      {90, "ninety"}
    }
  };
  static const auto hundreds {
    std::map<std::uint64_t, std::string> {
      {100, "hundred"}
    }
  };
  static const auto thousand { std::string{" thousand"} };

  if (n == 1000)
    return (units.at(1) + thousand);

  auto words { std::string{} };

  if (n >= 100) {
    words += units.at(n / 100) + " " + hundreds.at(100);
    n     %= 100;

    if (n > 0)
      words += " and ";
  }

  if (n >= 20) {
    words += tens.at((n / 10) * 10);
    n     %= 10;

    if (n > 0)
      words += "-";
  }

  if (n >= 10) {
    words += teens.at(n);
    n      = 0;
  }

  if (n > 0)
    words += units.at(n);

  return words;
}

static auto numberToWords(std::uint64_t n) -> std::string {
  auto words { convert(n) };

  words.erase(std::remove(words.begin(), words.end(), ' '), words.end());
  words.erase(std::remove(words.begin(), words.end(), '-'), words.end());

  return words;
}

auto main() -> int {
  auto total { std::uint64_t{} };

  for (auto i { std::uint64_t{1} }; i <= 1000; i++)
    total += numberToWords(i).length();

  std::cout << "Answer: " << total << std::endl;

  return 0;
}
