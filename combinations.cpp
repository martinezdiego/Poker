#include <algorithm>

#include <utils.cpp>

// retorna la cantidad de manos de un par
int countOnePair(const vector<Card> & cards, const vector<Card> & hand)
{
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int same = 0, differents = 0;

    for (const auto & c : m) {
      if (c.second == 2 ) same ++;
      else if (c.second == 1) differents ++;
    }

    if (same == 1 and differents == 3)
      count++;
  }

  return count; 
}

// retorna la cantidad de manos de dos pares
int countTwoPair(const vector<Card> & cards, const vector<Card> & hand)
{
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int same = 0, differents = 0;

    for (const auto & c : m) {
      if (c.second == 2 ) same ++;
      else if (c.second == 1) differents ++;
    }

    if (same == 2 and differents == 1)
      count++;
  }

  return count;
}

// retora la cantidad de manos de un trio
int countThreeKind(const vector<Card> & cards, const vector<Card> & hand)
{
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int same = 0, differents = 0;

    for (const auto & c : m) {
      if (c.second == 3 ) same ++;
      else if (c.second == 1) differents ++;
    }

    if (same == 1 and differents == 2)
      count++;
  }

  return count;
}

// retorna la cantidad de manos de un cuarteto
int countFourKind(const vector<Card> & cards, const vector<Card> & hand)
{
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int same = 0, differents = 0;

    for (const auto & c : m) {
      if (c.second == 4 ) same ++;
      else if (c.second == 1) differents ++;
    }

    if (same == 1 and differents == 1)
      count++;
  }

  return count;
}

// retorna la cantidad de manos de escaleras
int countStraight(const vector<Card> & cards, const vector<Card> & hand)
{
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    sort(i.begin(), i.end(), [](const Card & a, const Card & b) { 
      return a.rank() < b.rank(); 
    });

    bool ok = true;

    for (int j = 1; j < 5; j++) {
      if (i[j].rank() - i[j-1].rank() != 1) {
        ok = false;
        break;
      }
    }

    if (not ok) {
      if (i[0].rank() == 1 and 
        i[4].rank() == 13 and 
        i[3].rank() == 12 and 
        i[2].rank() == 11 and 
        i[1].rank() == 10)
        count++;
    }
    else
      count++;
  }

  return count;
}

// retorna la cantidad de manos de color
int countFlush(const vector<Card> & cards, const vector<Card> & hand)
{
  
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    if (all_of(i.begin(),i.end(), [&](const Card & c) {
      return c.suit() == i[0].suit();
    }))
      count++;
  }
  return count;
}

// retorna la cantidad de manos de póquer
int countFullHouse(const vector<Card> & cards, const vector<Card> & hand)
{ 
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int a = 0, b = 0;

    for (const auto & c : m) {
      if (c.second == 3 ) a ++;
      else if (c.second == 2) b ++;
    }

    if (a and b)
      count++;
  }

  return count;
}

// retorna la cantidad de manos de carta alta
int countHighCard(const vector<Card> & cards, const vector<Card> & hand)
{
  
  vector<Card> current;
  vector<vector<Card>> subsets;

  search(0, cards, current, subsets);

  int count = 0;

  for (auto & i : subsets) {
    i.insert(i.end(), hand.begin(), hand.end());
    
    map<int, int> m;

    for (const auto & c : i)
      m[c.rank()]++;

    int differents = 0;

    for (const auto & c : m) {
      if (c.second == 1) differents ++;
    }

    if (differents == 5)
      count++;
  }

  return count - countStraight(cards, hand) - countFlush(cards, hand);
}

// imprime las combinaciones de manos de las cartas sobre la mesa con las iniciales
void printCombinations(const vector<Card> & cards, const vector<Card> & hand) 
{
  cout << "High Card: " << countHighCard(cards, hand) << '\n';
  cout << "One pair: " << countOnePair(cards, hand) << '\n';
  cout << "Two pair: " << countTwoPair(cards, hand) << '\n';
  cout << "Three of a kind: " << countThreeKind(cards, hand) << '\n';
  cout << "Straight: " << countStraight(cards, hand) << '\n';
  cout << "Flush: " << countFlush(cards, hand) << '\n';
  cout << "Full House: " << countFullHouse(cards, hand) << '\n';
  cout << "Four of a kind: " << countFourKind(cards, hand) << '\n';
}