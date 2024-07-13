/**
 * Project Euler: Problem 019
 * Counting Sundays
 * Solution written by Kyle Swecker
 * 
 * You are given the following information, but you may prefer to do some research for yourself.
 * 
 *   - 1 Jan 1900 was a Monday.
 *   - Thirty days has September,
 *     April, June and November.
 *     All the rest have thirty-one,
 *     Saving February alone,
 *     Which has twenty-eight, rain or shine.
 *     And on leap years, twenty-nine.
 *   - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * 
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>
#include <array>

static inline constexpr auto isLeapYear(const int year) -> bool {
  return (!(year % 4) && (year % 100 || !(year % 400)));
}

static constexpr auto countSundays(int startYear, int endYear) -> int {
  constexpr auto daysInMonthRegular { std::array<int, 12>{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
  constexpr auto daysInMonthLeap    { std::array<int, 12>{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
  auto           dayOfWeek          { 1 };

  for (auto year { 1900 }; year < startYear; year++)
    dayOfWeek = (dayOfWeek + (isLeapYear(year) ? 366 : 365)) % 7;

  auto sundayCount { 0 };

  for (auto year { startYear }; year <= endYear; year++) {
    const auto* daysInMonth { isLeapYear(year) ? daysInMonthLeap.data() : daysInMonthRegular.data() };

    for (auto month { 0 }; month < 12; month++) {
      if (!dayOfWeek)
        sundayCount++;

      dayOfWeek = (dayOfWeek + daysInMonth[month]) % 7;
    }
  }

  return sundayCount;
}

auto main() -> int {
  constexpr auto sundays { countSundays(1901, 2000) };

  std::cout << "Answer:" << sundays << std::endl;

  return 0;
}
