#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void initt(multimap<string, int>& card) {

    card.insert(std::pair<string, int>("Deuce", 2));
    card.insert(std::pair<string, int>("Three", 3));
    card.insert(std::pair<string, int>("Four", 4));
    card.insert(std::pair<string, int>("Five", 5));
    card.insert(std::pair<string, int>("Six", 6));
    card.insert(std::pair<string, int>("Seven", 7));
    card.insert(std::pair<string, int>("Eight", 8));
}

int main(){
    
    vector <string> face = 
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };

    //vector <string> suit = { "Hearts", "Diamonds", "Clubs", "Spades" };

    
    multimap<string, int> card; 
    initt(card);
    
    
    multimap <string, int>::iterator itr;

    for (itr = card.begin(); itr != card.end(); ++itr) {
        std::cout << itr->first << ", " << itr->second;
        std::cout << endl;
    }
    std::cout << endl;
 
    bool choice;

   /* while (true) {

    }*/
}