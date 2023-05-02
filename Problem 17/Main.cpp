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
#include <array>

constexpr auto lettersInNumber(int num) -> int {
  constexpr auto letterCount     { std::array<int, 20>{0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8} };
  constexpr auto letterCountTens { std::array<int, 10>{0, 0, 6, 6, 5, 5, 5, 7, 6, 6} };

  auto count{ 0 };

  if (num >= 1000) {
    count += letterCount[num / 1000] + 8; // 8 for "thousand"
    num %= 1000;
  }

  if (num >= 100) {
    count += letterCount[num / 100] + 7; // 7 for "hundred"
    num %= 100;

    if (num > 0)
      count += 3; // 3 for "and"
  }

  if (num >= 20) {
    count += letterCountTens[num / 10];
    num %= 10;
  }

  count += letterCount[num];

  return count;
}

auto main() -> int {
  constexpr auto max{ 1000 };

  auto totalCount{ 0 };

  for (auto i{ 1 }; i <= max; i++)
    totalCount += lettersInNumber(i);

  std::cout << totalCount << std::endl;

  return 0;
}
