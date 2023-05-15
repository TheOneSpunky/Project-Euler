/**
 * Project Euler Problem 59: XOR decryption
 * 
 * Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt, a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <cctype>

auto containsCommonWords(const std::string& text) -> bool {
  const auto commonWords     { std::unordered_set<std::string>{"the", "and", "that", "have", "for", "not", "with", "you", "this", "but", "they"} };
  auto       iss             { std::istringstream(text) };
  auto       word            { std::string{} };
  auto       commonWordCount { 0 };

  while (iss >> word)
    if (commonWords.count(word) > 0)
      if (++commonWordCount >= 5)
        return true;

  return false;
}

auto decrypt(const std::vector<int>& cipher, const std::string& key) -> std::string {
  auto decrypted { std::string{} };
  auto keyLength { key.size() };

  for (auto i{ 0ULL }; i < cipher.size(); i++) {
    const auto ch{ static_cast<char>(cipher[i] ^ key[i % keyLength]) };

    // Ensure the decrypted character is a printable ASCII character
    if (ch < ' ' || ch > '~')
      return "";

    decrypted.push_back(ch);
  }

  return decrypted;
}

auto main() -> int {
  auto file   { std::ifstream("cipher.txt") };
  auto cipher { std::vector<int>{} };
  auto value  { 0 };

  while (file >> value) {
    if (file.peek() == ',')
      file.ignore();
    cipher.push_back(value);
  }

  auto decryptedText{ std::string{} };

  for (auto a{ 'a' }; a <= 'z'; a++) {
    for (auto b{ 'a' }; b <= 'z'; b++) {
      for (auto c{ 'a' }; c <= 'z'; c++) {
        const auto key{ std::string{a, b, c} };
        const auto tmp{ decrypt(cipher, key) };

        if (containsCommonWords(tmp)) {
          decryptedText = std::move(tmp);
          break;
        }
      }
      if (!decryptedText.empty())
        break;
    }
    if (!decryptedText.empty())
      break;
  }

  auto sum{ 0 };

  for (const char& ch : decryptedText)
    sum += ch;

  std::cout << decryptedText << '\n' << std::endl;
  std::cout << sum << std::endl;

  return 0;
}