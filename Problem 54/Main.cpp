/**
 * Project Euler Problem 54: Poker hands
 * 
 * In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *
 * High Card:       Highest value card.
 * One Pair:        Two cards of the same value.
 * Two Pairs:       Two different pairs.
 * Three of a Kind: Three cards of the same value.
 * Straight:        All cards are consecutive values.
 * Flush:           All cards of the same suit.
 * Full House:      Three of a kind and a pair.
 * Four of a Kind:  Four cards of the same value.
 * Straight Flush:  All cards are consecutive values of same suit.
 * Royal Flush:     Ten, Jack, Queen, King, Ace, in same suit.
 * 
 * The cards are valued in the order:
 * 
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 *
 * If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
 *
 * Consider the following five hands dealt to two players:
 *
 * Hand	 	  Player 1	 	       Player 2	 	     Winner
 * 1  	 5H 5C 6S 7S KD     2C 3S 8S 8D TD    Player 2
 *       Pair of Fives      Pair of Eights
 * 2	 	 5D 8C 9S JS AC     2C 5C 7D 8S QH    Player 1
 *      Highest card Ace  Highest card Queen
 * 3	 	 2D 9C AS AH AC     3D 6D 7D TD QD    Player 2
 *         Three Aces     Flush with Diamonds
 * 4	 	 4D 6S 9H QH QC     3D 6D 7H QD QS    Player 1
 *       Pair of Queens     Pair of Queens
 *      Highest card Nine Highest card Seven
 * 5	 	 2H 2D 4C 4D 4S     3C 3D 3S 9S 9D    Player 1
 *         Full House         Full House
 *      with Three Fours   with Three Threes
 * 
 * The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
 *
 * How many hands does Player 1 win?
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

enum class Rank : unsigned char {
  HighCard,
  Pair,
  TwoPairs,
  ThreeOfAKind,
  Straight,
  Flush,
  FullHouse,
  FourOfAKind,
  StraightFlush,
  RoyalFlush
};

struct Card {
  int  m_value;
  char m_suit;
};

using Hand = std::array<Card, 5>;

auto parseHand(const std::vector<std::string>& cards) -> Hand {
  static auto cardValues{ std::map<char, int> {
    {'2', 2}, {'3', 3}, {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
    {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14} }
  };

  auto hand{ Hand{} };

  for (auto i{ 0ULL }; i < cards.size(); i++) {
    hand[i].m_value = cardValues[cards[i][0]];
    hand[i].m_suit  = cards[i][1];
  }

  std::sort(hand.begin(), hand.end(), [](const Card& a, const Card& b) {
    return a.m_value < b.m_value;
  });

  return hand;
}

auto determineRank(const Hand& hand) -> Rank {
  auto sortedHand{ hand };

  std::sort(sortedHand.begin(), sortedHand.end(), [](const Card& a, const Card& b) {
    return a.m_value < b.m_value;
  });

  // Check for a flush (all the same suit)
  auto flush{ true };

  for (auto i{ 0 }; i < 4; i++)
    if (sortedHand[i].m_suit != sortedHand[i + 1].m_suit) {
      flush = false;
      break;
    }

  // Check for a straight (all consecutive values)
  auto straight{ true };

  for (auto i{ 0 }; i < 4; i++)
    if (sortedHand[i].m_value != sortedHand[i + 1].m_value - 1) {
      straight = false;
      break;
    }

  if (flush && straight) {
    // Check for a royal flush
    if (sortedHand[0].m_value == 10)
      return Rank::RoyalFlush;

    return Rank::StraightFlush;
  }

  // Check for four of a kind
  for (auto i{ 0 }; i < 2; i++)
    if (sortedHand[i].m_value     == sortedHand[i + 1].m_value &&
        sortedHand[i + 1].m_value == sortedHand[i + 2].m_value &&
        sortedHand[i + 2].m_value == sortedHand[i + 3].m_value)
      return Rank::FourOfAKind;

  // Check for a full house
  if ((sortedHand[0].m_value  == sortedHand[1].m_value  &&
       sortedHand[1].m_value  == sortedHand[2].m_value  &&
       sortedHand[3].m_value  == sortedHand[4].m_value) ||
      (sortedHand[0].m_value  == sortedHand[1].m_value  &&
       sortedHand[2].m_value  == sortedHand[3].m_value  &&
       sortedHand[3].m_value  == sortedHand[4].m_value))
    return Rank::FullHouse;

  if (flush)
    return Rank::Flush;
  else if (straight)
    return Rank::Straight;

  // Check for three of a kind
  for (auto i{ 0 }; i < 3; i++)
    if (sortedHand[i].m_value     == sortedHand[i + 1].m_value &&
        sortedHand[i + 1].m_value == sortedHand[i + 2].m_value)
      return Rank::ThreeOfAKind;

  // Check for two pairs
  if ((sortedHand[0].m_value == sortedHand[1].m_value  &&
       sortedHand[2].m_value == sortedHand[3].m_value) ||
      (sortedHand[0].m_value == sortedHand[1].m_value  &&
       sortedHand[3].m_value == sortedHand[4].m_value) ||
      (sortedHand[1].m_value == sortedHand[2].m_value  &&
       sortedHand[3].m_value == sortedHand[4].m_value))
    return Rank::TwoPairs;

  // Check for a pair
  for (auto i{ 0 }; i < 4; i++)
    if (sortedHand[i].m_value == sortedHand[i + 1].m_value)
      return Rank::Pair;

  return Rank::HighCard;
}

bool compareHands(const Hand& hand1, const Hand& hand2, Rank rank) {
  auto count1 { std::map<int, int>{} };
  auto count2 { std::map<int, int>{} };

  for (auto i{ 0 }; i < 5; i++) {
    count1[hand1[i].m_value]++;
    count2[hand2[i].m_value]++;
  }

  if (rank == Rank::Pair || rank == Rank::TwoPairs || rank == Rank::ThreeOfAKind || rank == Rank::FourOfAKind || rank == Rank::FullHouse) {
    for (auto count{ 4 }; count >= 1; count--)
      for (auto i{ 14 }; i >= 2; i--)
        if (count1[i] == count && count2[i] < count)
          return true;
        else if (count2[i] == count && count1[i] < count)
          return false;
  }
  else for (auto i{ 14 }; i >= 2; i--)
    if (count1[i] > count2[i])
      return true;
    else if (count1[i] < count2[i])
      return false;

  return false;
}


auto main() -> int {
  auto file { std::ifstream("poker.txt") };
  auto line { std::string{} };
  auto wins { 0 };

  while (std::getline(file, line)) {
    auto cards { std::vector<std::string>(10) };
    auto iss   { std::istringstream(line) };

    for (std::string& card : cards)
      iss >> card;

    const auto hand1 { parseHand(std::vector<std::string>(cards.begin(), cards.begin() + 5)) };
    const auto hand2 { parseHand(std::vector<std::string>(cards.begin() + 5, cards.end())) };
    const auto rank1 { determineRank(hand1) };
    const auto rank2 { determineRank(hand2) };

    if (rank1 > rank2 || (rank1 == rank2 && compareHands(hand1, hand2, rank1)))
      wins++;
  }

  std::cout << wins << std::endl;

  return 0;
}