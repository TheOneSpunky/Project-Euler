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

auto isLeapYear(const int& year) -> bool {
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return true;

  return false;
}

auto main() -> int {
  constexpr auto days{ std::array<int, 12>{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

  auto day     { 1 }; // January 1, 1900 was a Monday (1).
  auto sundays { 0 };

  // Iterate from 1900 to 2000.
  for (auto year{ 1900 }; year <= 2000; year++)
    for (auto month{ 0 }; month < 12; month++) {
      if (year > 1900 && day % 7 == 0)
        sundays++;

      day += days[month];

      // Adjust for leap years in February.
      if (month == 1 && isLeapYear(year))
        day++;
    }

  std::cout << sundays << std::endl;

  return 0;
}