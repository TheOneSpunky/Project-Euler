/**
 * Project Euler Problem 17: Number letter counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <iostream>
#include <map>
#include <string>

auto numberToWords(int num, const std::map<int, std::string>& wordMap) {
  auto result{ std::string{} };

  if (num >= 1000) {
    result += wordMap.at(num / 1000) + " " + wordMap.at(1000);
    num    %= 1000;
  }

  if (num >= 100) {
    result += wordMap.at(num / 100) + " " + wordMap.at(100);
    num    %= 100;

    if (num > 0)
      result += " and ";
  }

  if (num >= 20) {
    result += wordMap.at(num - (num % 10));
    num    %= 10;

    if (num > 0)
      result += "-";
  }

  if (num > 0)
    result += wordMap.at(num);

  return result;
}

auto main() -> int {
  constexpr auto maxNum  { 1000 };
  const auto     wordMap {
    std::map<int, std::string> {
      {1, "one"},       {2, "two"},        {3, "three"},     {4, "four"},      {5, "five"},
      {6, "six"},       {7, "seven"},      {8, "eight"},     {9, "nine"},      {10, "ten"},
      {11, "eleven"},   {12, "twelve"},    {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"},
      {16, "sixteen"},  {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
      {20, "twenty"},   {30, "thirty"},    {40, "forty"},    {50, "fifty"},
      {60, "sixty"},    {70, "seventy"},   {80, "eighty"},   {90, "ninety"},
      {100, "hundred"}, {1000, "thousand"}
    }
  };

  auto letterCount{ 0 };

  for (auto i{ 1 }; i <= maxNum; i++) {
    auto words{ numberToWords(i, wordMap) };

    words.erase(std::remove(words.begin(), words.end(), ' '), words.end());
    words.erase(std::remove(words.begin(), words.end(), '-'), words.end());

    letterCount += static_cast<int>(words.length());
  }

  std::cout << letterCount << std::endl;

  return 0;
}