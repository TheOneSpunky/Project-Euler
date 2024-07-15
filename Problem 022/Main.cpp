/**
 * Project Euler: Problem 022
 * Names Scores
 * Solution written by Kyle Swecker
 * 
 * Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name, multiply this value by its
 * alphabetical position in the list to obtain a name score.
 * 
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
 * is the 938th name in the list. So, COLIN would obtain a score of 938 * 53 = 49714.
 * 
 * What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <stdexcept>

static auto readSortNames(const std::string& fileName) -> std::vector<std::string> {
  auto names      { std::vector<std::string>{} };
  auto fileStream { std::ifstream{fileName} };

  if (!fileStream.is_open())
    throw std::runtime_error("Error: Unable to open file.");

  auto fileContent { std::string{} };

  fileStream.seekg(0, std::ios::end);
  fileContent.resize(fileStream.tellg());
  fileStream.seekg(0, std::ios::beg);
  fileStream.read(&fileContent[0], fileContent.size());
  fileStream.close();

  auto stringStream { std::stringstream{fileContent} };
  auto name         { std::string{} };

  while (std::getline(stringStream, name, ',')) {
    name.erase(std::remove(name.begin(), name.end(), '\"'), name.end());
    names.push_back(name);
  }

  std::sort(names.begin(), names.end());

  return names;
}

static auto calculateAlphabeticalValue(const std::string& name) -> int {
  auto value { 0 };

  for (const auto ch : name)
    value += ch - 'A' + 1;

  return value;
}

static auto calculateTotalScore(const std::vector<std::string>& names) -> int {
  auto totalScore { 0 };

  for (auto i { std::size_t{} }; i < names.size(); i++)
    totalScore += calculateAlphabeticalValue(names[i]) * (i + 1);

  return totalScore;
}

auto main() -> int {
  constexpr auto fileName { std::string_view{"names.txt"} };

  try {
    auto       names      { readSortNames(fileName.data()) };
    const auto totalScore { calculateTotalScore(names) };

    std::cout << "Answer: " << totalScore << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
