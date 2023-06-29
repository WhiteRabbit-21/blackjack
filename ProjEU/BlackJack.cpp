#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

int countValues(string Card, int &sum) {
    
    if (Card == "Deuce") {
        sum += 2;
    }
    if (Card == "Three") {
        sum += 3;
    }
    if (Card == "Four") {
        sum += 4;
    }
    if (Card == "Five") {
        sum += 5;
    }
    if (Card == "Six") {
        sum += 6;
    }
    if (Card == "Seven") {
        sum += 7;
    }
    if (Card == "Eight") {
        sum += 8;
    }
    if (Card == "Nine") {
        sum += 9;
    }
    if (Card == "Ten") {
        sum += 10;
    }
    if (Card == "Jack") {
        sum += 10;
    }
    if (Card == "Queen") {
        sum += 10;
    }
    if (Card == "King") {
        sum += 10;
    }
    if (Card == "Ace") {
        sum += 11; // or 1 (add function to check, if it is a first card)
    }

    return sum;
}

int main(){

    srand(time(0));
    // Intializing cards
    vector <string> face = 
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };

    vector <string> suit = { "Hearts", "Diamonds", "Clubs", "Spades" };

    // Generating card on the table for the player

    int i = 0, AmountCardOnTable = 2, sum = 0;
    while (i < AmountCardOnTable) 
    {
        int tmp = rand() % face.size();
        cout << face[tmp] << " " << suit[rand() % suit.size()] << endl;
        i++;
        countValues(face[tmp], sum);

        if (i >= AmountCardOnTable) 
        {
            cout << "Do you need more?" << endl;
            bool ans;
            cin >> ans;
            if (ans == 1) {
                AmountCardOnTable++;
            }
            
        }
    }

    cout << endl;
    cout << "Sum is: " << sum;
    cout << endl;
   // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;
   // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;

   /* while (true) {

    }*/
}