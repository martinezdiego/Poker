/*
 *  Diego Martinez
 *  diegomartinez6c@gmail.com
 * 
 *  Oscar Albornoz
 *  oalbornoz08@gmail.com
 */
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <map>
#include <utility>

using namespace std;

const map<string, int> Suit = { 
  {"S", 1}, {"C", 2}, {"H", 3} ,{"D", 4} 
};
    
const map<string, int> Rank = { 
  {"A", 1}, {"2",2}, {"3",3}, {"4",4}, 
  {"5",5}, {"6",6}, {"7",7}, {"8",8}, 
  {"9",9}, {"10",10}, {"J",11}, {"Q",12}, {"K",13}
};

class Card 
{
  public:
    explicit Card(string c)
    {
      int n =  c.size();

      if (n < 2 or n > 3)
        throw invalid_argument("invalid card");
      
      string r, s;
      
      if (n == 2) 
        r = c.substr(0,1), s = c.substr(1);
      else 
        r = c.substr(0,2), s = c.substr(2);

      if (Rank.count(r) == 0 or Suit.count(s) == 0)
          throw invalid_argument("invalid card");
      
      card = {r, s};
    }
        
    Card(const Card & c) : card(c.card) 
    {
      // empty
    }
    
    Card(Card && c) : card(move(c.card)) { 
      // empty
     }
    
    Card & operator = (const Card & c) 
    { 
      card = c.card; 
      return *this; 
    }
    
    Card & operator = (Card && c) 
    { 
      swap(card, c.card); 
      return *this; 
    }

    bool operator == (const Card & c) const { return card == c.card; }

    // retorna el tipo   
    int suit() const { return Suit.at(card.second); }
    
    // retorna el valor
    int rank() const { return Rank.at(card.first); }
    
    // imprime la carta 
    void print() const { cout << card.first << card.second; }

  private:
    pair<string, string> card;
};
#endif