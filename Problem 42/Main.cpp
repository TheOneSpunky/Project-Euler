/**
 * Project Euler Problem 42: Coded triangle numbers
 * 
 * The nth term of the sequence of triangle numbers is given by, tn = (1/2)n(n+1); so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

auto isTriangleNumber(const int& num) -> bool {
  const auto n{ static_cast<int>((-1 + std::sqrt(1 + 8 * num)) / 2) };

  return num == n * (n + 1) / 2;
}

auto wordValue(const std::string& word) -> int {
  auto sum{ 0 };

  for (const char& c : word)
    sum += c - 'A' + 1;

  return sum;
}

auto readWords(const std::string& filename) -> std::vector<std::string> {
  auto words { std::vector<std::string>{} };
  auto file  { std::ifstream{filename} };
  auto line  { std::string{} };

  while (std::getline(file, line)) {
    auto iss  { std::istringstream(line) };
    auto word { std::string{} };

    while (std::getline(iss, word, ',')) {
      word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
      words.push_back(word);
    }
  }

  return words;
}

auto main() -> int {
  const auto words { readWords("words.txt") };
  auto       count { 0 };

  for (const std::string& word : words)
    if (isTriangleNumber(wordValue(word)))
      count++;

  std::cout << count << std::endl;

  return 0;
}