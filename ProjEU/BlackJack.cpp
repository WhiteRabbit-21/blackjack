#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

void exit_func() {
    bool ask;
    cout << "Do you want to continue? 1/0";
    cin >> ask;
    if (ask != 1) {
        exit(0);
    }
   

}



void dealerWin() {

}

void playerWin() {

}

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


        if (countValues(face[tmp], sum) > 21) {
            cout << "Player sum is: " << sum << endl;
            cout << "Dealer win" << endl; // rewrite funcrion for role  
            exit_func();
            return 0;
        }
        // add aditional variable to check whos turn, and refresh everytime whem function will called
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

        if (countValues(face[tmp], sum) > 21) 
        {
            cout << "Player win" << endl; // rewrite funcrion for role  
            exit_func();
            return sum;
        }
        // add aditional variable to check whos turn, and refresh everytime whem function will called
        if (i >= AmountCardOnTable)
        {
            cout << "Sum is: " << sum << endl;
            
            if (sum == 21) 
            {
                return sum;
            }
            else
            {
                cout << "Do you need more?" << endl;
                bool ans;
                cin >> ans;
                if (ans == 1)
                {
                    AmountCardOnTable++;
                }
            }
        }
    }
    return sum;
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
    else if (playerScore == dealerScore)
    {
        cout << "Dealer win" << endl;
        return "Dealer";

    }
    else if (playerScore < dealerScore && dealerScore <= 21) {
        cout << "Dealer win" << endl;
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
 

        if (playerSum != 0) {

            cout << "Player Sum is: " << playerSum << endl;
            cout << endl;

            dealerSum = GeneratingCardOnTable(dealerSum, face, suit);

            values_compareFunction(playerSum, dealerSum);

            
            cout << "Dealers Sum is: " << dealerSum << endl;
            cout << endl;

            exit_func();
        }

    }
    // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;
    // cout << face[rand() % face.size()] << " " << suit[rand() % suit.size()] << endl;

    /* while (true) {

     }*/
}