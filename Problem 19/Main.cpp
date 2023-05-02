/**
 * Project Euler Problem 19: Counting Sundays
 * 
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1. 1 Jan 1900 was a Monday.
 * 2. Thirty days has September, April, June and November. All the rest have thirty-one, saving February alone, which has twenty-eight, rain or shine. And on leap years, twenty-nine.
 * 3. A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * 
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>
#include <array>

constexpr auto zeller(int year, int month) -> int {
  if (month < 3) {
    month += 12;
    year--;
  }

  const auto k { year % 100 };
  const auto j { year / 100 };

  return (13 * (month + 1) + k + k / 4 + 5 * j + j / 4) % 7;
}

auto main() -> int {
  auto sundays{ 0 };

  for (auto year{ 1901 }; year <= 2000; year++)
    for (auto month{ 1 }; month <= 12; month++)
      if (zeller(year, month) == 0)
        sundays++;

  std::cout << sundays << std::endl;

  return 0;
}