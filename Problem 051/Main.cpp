/**
 * Project Euler: Problem 051
 * Prime Digit Replacements
 * Solution written by Kyle Swecker
 * 
 * By replacing the 1st digit of the 2-digit number *3, it turns out
 * that six of the nine possible values: 13, 23, 43, 53, 73, and 83,
 * are all prime.
 * 
 * By replacing the 3rd and 4th digits of 56**3 with the same digit,
 * this 5-digit number is the first example having seven primes among
 * the ten generated numbers, yielding the family: 56003, 56113,
 * 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being
 * the first member of this family, is the smallest prime with this
 * property.
 * 
 * Find the smallest prime which, by replacing part of the number
 * (not necessarily adjacent digits) with the same digit, is part of an
 * eight prime value family.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

auto isPrime(int n) -> bool {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

std::vector<int> generatePrimes(int limit) {
  std::vector<bool> isPrime(limit + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p <= limit; p++) {
    if (isPrime[p]) {
      for (int i = p * p; i <= limit; i += p) {
        isPrime[i] = false;
      }
    }
  }

  std::vector<int> primes;
  for (int p = 2; p <= limit; p++) {
    if (isPrime[p]) {
      primes.push_back(p);
    }
  }
  return primes;
}

// Find all positions where a specific digit appears
std::vector<int> findDigitPositions(const std::string& numStr, char digit) {
  std::vector<int> positions;
  for (int i = 0; i < numStr.length(); i++) {
    if (numStr[i] == digit) {
      positions.push_back(i);
    }
  }
  return positions;
}

// Generate all possible combinations of digit positions
std::vector<std::vector<int>> generateCombinations(const std::vector<int>& positions) {
  std::vector<std::vector<int>> result;
  int n = positions.size();

  // Generate all non-empty subsets (2^n - 1 possibilities)
  for (int i = 1; i < (1 << n); i++) {
    std::vector<int> combination;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        combination.push_back(positions[j]);
      }
    }
    result.push_back(combination);
  }

  return result;
}

// Check how many primes we get by replacing the digits at given positions
std::pair<int, std::vector<int>> countPrimeFamily(int num, const std::vector<int>& positions) {
  std::string numStr = std::to_string(num);
  int count = 0;
  std::vector<int> primeFamily;

  // Try replacing with each digit (0-9)
  for (int d = 0; d <= 9; d++) {
    // Skip if first position is 0 (would make it non-prime)
    if (d == 0 && std::find(positions.begin(), positions.end(), 0) != positions.end()) {
      continue;
    }

    std::string replacedStr = numStr;
    for (int pos : positions) {
      replacedStr[pos] = '0' + d;
    }

    int replacedNum = std::stoi(replacedStr);
    if (isPrime(replacedNum)) {
      count++;
      primeFamily.push_back(replacedNum);
    }
  }

  return { count, primeFamily };
}

int main() {
  // We'll search for primes up to this limit
  const int LIMIT = 1000000;

  // Generate primes up to the limit
  std::vector<int> primes = generatePrimes(LIMIT);

  // For each prime, try replacing digits and check if we get 8 primes
  for (int prime : primes) {
    std::string primeStr = std::to_string(prime);

    // Count occurrences of each digit
    std::unordered_set<char> uniqueDigits;
    for (char digit : primeStr) {
      uniqueDigits.insert(digit);
    }

    // For each digit that appears, try replacing all its occurrences
    for (char digit : uniqueDigits) {
      // Find all positions where this digit appears
      std::vector<int> positions = findDigitPositions(primeStr, digit);
      if (positions.empty()) continue;

      // Generate all possible combinations of positions
      std::vector<std::vector<int>> combinations = generateCombinations(positions);

      // Check each combination
      for (const auto& combo : combinations) {
        auto [count, family] = countPrimeFamily(prime, combo);

        if (count >= 8) {
          std::cout << "Smallest prime with eight prime family: " << *std::min_element(family.begin(), family.end()) << std::endl;
          std::cout << "The eight prime family: ";
          for (int i = 0; i < std::min(8, (int)family.size()); i++) {
            std::cout << family[i] << " ";
          }
          std::cout << std::endl;
          return 0;
        }
      }
    }
  }

  std::cout << "No solution found within the given limit." << std::endl;
  return 0;
}