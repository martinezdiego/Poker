#include <combinations.cpp>

int main()
{
  vector<Card> hand, deck, cards;
  
  for (auto s : Suit) {
    for (auto r : Rank) {
      deck.push_back(Card(r.first + s.first));
    }
  }
  
  cout << "Poker hand simulator\n\n";
  cout << "The suits are abbreviated for its initial letter\n";
  cout << "The face cards are abbreviated as J, Q, and K. The Ace is abbreviated as A\n";
  cout << "The cards are in format [Rank,Suit] (whitout brackets and ,) by example: 10H\n\n";
  
  cout << "Enter to start...";
  getchar();
  
  cout << "Do you want to choose the cards? (y/n): ";
  char c;
  cin >> c;
  cin.ignore();
  
  vector<pair<string, int>> turns { {"Flop", 3}, {"Turn", 1}, {"River", 1} };

  if (tolower(c) == 'y') {
    cout << "Insert " << 2 << " initials cards (separeted by a space): ";
    for (int i = 0; i < 2;) {
      string s;
      cin >> s;
      Card * c;
      
      try {
        c = new Card(s);
      } 
      catch (const invalid_argument & exec) {
        cout << exec.what() << '\n';
        continue;
      }
      
      if (find(hand.begin(), hand.end(), *c) != hand.end()) {
        cout << "card already exists" << '\n';
        continue;
      }

      hand.push_back(*c);
      i++;
    }
    cout << '\n';
    
    for (int i = 0; i < 3; i++) {
      cout << turns[i].first << '\n';
      cout << "----\n";
      cout << "Insert " << turns[i].second << " cards (separeted by a space): ";
      for (int j = 0; j < turns[i].second;) {
        string s;
        cin >> s;
        Card * c;
        
        try {
          c = new Card(s);
        } 
        catch (const invalid_argument & exec) {
          cout << exec.what() << '\n';
          continue;
        }
        
        if (find(cards.begin(), cards.end(), *c) != cards.end()) {
          cout << "card already exists" << '\n';
          continue;
        }

        cards.push_back(*c);
        j++;
      }
      cout << "Comunity cards: ";
      for (int j = 0; j < cards.size(); j++) {
        if (j) cout << ' ';
        cards[j].print();
      }
      cout << '\n';
      printCombinations(cards, hand);
      cout << '\n';  
    }
  }
  
  else if (tolower(c) == 'n') {
    cout << "Your initial cards: ";
    for (int i = 0; i < 2; i++) {
      Card c = remove(deck);
      hand.push_back(c);
      c.print();
      cout << ' ';
    }
    cout << '\n';
    cout << "Enter to continue..." << '\n';
    getchar();

    for (int i = 0; i < 3; i++) {
      cout << turns[i].first << '\n';
      cout << "----\n";
      for (int j = 0; j < turns[i].second; j++) {
        Card c = remove(deck);
        cards.push_back(c);
      }
      cout << "Comunity cards: ";
      for (int j = 0; j < cards.size(); j++) {
        if (j) cout << ' ';
        cards[j].print();
      }
      cout << '\n';
      printCombinations(cards, hand);
      cout << '\n';
      cout << "Enter to continue..." << '\n';
      getchar();  
    }
  }

  cout << "Done!" << '\n';
  return 0;
}