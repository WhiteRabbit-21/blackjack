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
    if (Card == "Ace" && sum+11>21) {
        sum += 1;
    }
    else if (Card == "Ace" && sum + 11 <= 21)
    {
        sum += 11;
    }

    return sum;
}

int GeneratingCardOnTable(int& sum, vector <string> face, vector <string> suit) { //rewrire function with dealers decision and propabilyty theory

    int i = 0, AmountCardOnTable = 2;
    while (i < AmountCardOnTable)
    {
        int tmp = rand() % face.size();
        cout << face[tmp] << " " << suit[rand() % suit.size()] << endl;
        i++;

        tmp = countValues(face[tmp], sum);
        if (tmp > 21) {
            return sum;
        }
        if (i >= AmountCardOnTable)
        {
            cout << "Sum is: " << sum << endl;
            if (sum == 21) {
                return sum;
            }
            else {
                cout << "Do you need more?" << endl;
                bool ans;
                cin >> ans;
                if (ans == 1) {
                    AmountCardOnTable++;
                }
            }
            // add else operator for dealers turn or skip it

        }

    }
    return sum;
}

int GeneratingCardOnTableForDealer(int& sum, vector <string> face, vector <string> suit) {

    int i = 0, AmountCardOnTable = 2;
    while (i < AmountCardOnTable)
    {
        int tmp = rand() % face.size();
        cout << face[tmp] << " " << suit[rand() % suit.size()] << endl;
        i++;

        countValues(face[tmp], sum);
        
        if (i >= AmountCardOnTable)
        {
            cout << "Sum is: " << sum << endl;
            cout << "Do you need more?" << endl;
            bool ans;
            cin >> ans;
            if (ans == 1) {
                AmountCardOnTable++;
            }
            // add else operator for dealers turn or skip it
        }

    }
    return sum;
}


void exit_func() {
    bool ask;
    cout << "Do you want to continue? 1/0";
    cin >> ask;
    if (ask != 1) {
        exit(0);
    }

}

string values_compareFunction(int playerScore, int dealerScore)
{

    if (playerScore <= 21 && playerScore > dealerScore)
    {
        cout << "Player Win" << endl;
        return "Player";
    }
    else if (playerScore <= 21 && dealerScore > 21)
    {
        cout << "Player Win" << endl;
        return "Player";
    }
    else if (playerScore == 21 && dealerScore != 21) {
        cout << "Player Win" << endl;
        return "Player";
    }
    else if (playerScore > 21) { // implementd in code
        cout << "Dealer win" << endl;
        return "Dealer";
    }
    else if (playerScore == dealerScore)
    {
        cout << " Dealer win" << endl;
        return "Dealer";

    }
    else if (playerScore < dealerScore && dealerScore <= 21) {
        cout << " Dealer win" << endl;
        return "Dealer";

    }

}

int main() {

    // srand(time(0));

    // Intializing cards
    vector <string> face =
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };

    vector <string> suit = { "Hearts", "Diamonds", "Clubs", "Spades" };

    // Generating card on the table for the player

    while (true)
    {
        system("cls");

        int playerSum = 0;
        int dealerSum = 0;

        playerSum = GeneratingCardOnTable(playerSum, face, suit);

        cout << endl;
        cout << "Player Sum is: " << playerSum << endl;
        cout << endl;

        if (values_compareFunction(playerSum, dealerSum) == "Dealer") {
            cout << "Dealer win" << endl;
            exit_func();
        }
  
        dealerSum = GeneratingCardOnTable(dealerSum, face, suit);
        
        values_compareFunction(playerSum, dealerSum);

        
        cout << endl;
        cout << "Dealers Sum is: " << dealerSum << endl;
        cout << endl;

        values_compareFunction(playerSum, dealerSum);

        exit_func();

    }
    // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;
    // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;

    /* while (true) {

     }*/
}