/**
 * Project Euler Problem 22: Names scores
 * 
 * Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>

auto nameValue(std::string_view name) -> int {
  auto value{ 0 };

  for (const char& c : name)
    value += c - 'A' + 1;

  return value;
}

auto main() -> int {
  auto file  { std::ifstream{"names.txt"} };
  auto name  { std::string{} };
  auto names { std::vector<std::string>{} };

  while (std::getline(file, name, ','))
    names.push_back(name.substr(1, name.size() - 2)); // Remove quotes

  std::sort(names.begin(), names.end());

  auto score{ 0ULL };

  for (auto i{ 0ULL }; i < names.size(); i++)
    score += (i + 1) * nameValue(names[i]);

  std::cout << score << std::endl;

  return 0;
}