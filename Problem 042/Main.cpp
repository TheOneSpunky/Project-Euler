/**
 * Project Euler Problem 042 - Coded Triangle Numbers
 * 
 * The nth term of the sequence of triangle numbers is given by
 * Tn = n(n + 1)/2; so the first ten triangle numbers are:
 * 
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * 
 * By converting each letter in a word to a number corresponding to its
 * alphabetical position and adding these values we form a word value.
 * For example, the word value for SKY is 19 + 11 + 25 = 55 = T10.
 * If the word value is a triangle number then we shall call the word
 * a triangle word.
 * 
 * Using words.txt, a 16K text file containing nearly two-thousand common
 * English words, how many are triangle words?
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

static auto isTriangleNumber(int n) -> bool {
  auto check     { long long{8LL * n + 1} };
  auto sqrtCheck { static_cast<long long>(std::sqrt(check)) };

  return (sqrtCheck * sqrtCheck == check);
}

static auto calculateWordValue(const std::string& word) -> int {
  auto value { 0 };

  for (auto c : word)
    if (std::isalpha(c))
      value += (std::toupper(c) - 'A' + 1);

  return value;
}

auto main() -> int {
  auto file { std::ifstream{"0042_words.txt"} };

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file `0042_words.txt`" << std::endl;
    return 1;
  }

  auto words  { std::vector<std::string>{} };
  auto word   { std::string{} };
  auto inWord { false };
  auto c      { char{} };

  while (file.get(c)) {
    if (c == '"') {
      inWord = !inWord;

      if (!inWord && !word.empty()) {
        words.push_back(word);
        word.clear();
      }
    }
    else if (inWord)
      word += c;
  }

  file.close();

  auto count { 0 };

  for (const auto& w : words) {
    auto value { calculateWordValue(w) };

    if (isTriangleNumber(value))
      count++;
  }

  std::cout << "Answer: " << count << std::endl;

  return 0;
}