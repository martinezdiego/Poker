#include <random>
#include <vector>

#include <card.h>

// genera los 3-subconjuntos de un n-conjunto de cartas 
void search(int i, const vector<Card> & cards, vector<Card> & current, vector<vector<Card>> & subsets) {
  if (i == cards.size()) {
    if (current.size() == 3)
      subsets.push_back(current);
  }
  else {
    search(i + 1, cards, current, subsets);
    current.push_back(cards[i]);
    search(i + 1, cards, current, subsets);
    current.pop_back();
  }
}

// remueve una carta al azar de una baraja de póker
Card remove(vector<Card> & deck) {
  random_device rd;
	mt19937 gen(rd());
  int n = deck.size();
	uniform_int_distribution<int> dis(0,n-1);
  int pos = dis(gen);

  Card ref = deck[pos];
  deck.erase(deck.begin() + pos);
  
  return ref;
}
