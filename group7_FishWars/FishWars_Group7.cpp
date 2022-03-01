//Fish Wars Group 7
//William Thomas, Gage Decker, Ryan Juelsgaard, Eric Stalcup
//This program is a "war" style card game that will play through 13 rounds per game.
//This game will prompt you for input at a regular basis, and uses character and integer input values.


#include <iostream>
#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time
#include <vector>
#include <limits>
using namespace std;
//rules and regulations display. will only display one time per run.
//Gage provided formatting. William implemented to display.
void rulesRegs() {
    const string RULES_REGS = "____________________RULES AND REGULATIONS____________________\n\n"
                              "Card Wars is a game in which two players have 13 cards, 10 cards labeled 1-10, 2 peace cards and 1 shark card.\n"
                              "The card with the higher value wins or if cards that equal each other are played they end in a draw."
                              "The game is played in 13 rounds until all cards are used. \n\nWhen a player wins a round they get a battle bonus"
                              "point which is added onto their card value. Example: playing a 7 with a battle bonus of 2 leaves their value at 9.\n\nA"
                              "Shark card beats any number value card. A peace card when played against a shark or normal number reduces the opponents battle"
                              "bonus to 0 and ends in a draw for the round. If two sharks are played it ends in a draw. If two peace cards are played neither"
                              "players battle bonus is reduced.\n\nScore is kept track through the rounds and whoever wins more rounds will be declared the winner."
                              "\n\nExamples of Play:\n----------------------------------------------------------"
                              "\n\nPlayer card: 5\nDealer card: 8\n\nDealer Wins\nPlayer Score: 0  (BB: 0)  Dealer Score: 1  (BB: 1)"
                              "\n\n----------------------------------------------------------\n\nPlayer card: 6\nDealer card: Peace\n\nDraw"
                              "\nPlayer Bonus Reduced\nPlayer Score: 0  (BB: 0)  Dealer Score: 1  (BB: 1)\n\n----------------------------------------------------------"
                              "\n\n----------------------------------------------------------\n\nPlayer Card: Peace\nDealer card: Shark\n\nDraw"
                              "\nDealer Bonus Reduced\nPlayer Score: 0  (BB: 0)  Dealer Score: 1  (BB: 0)\n\n----------------------------------------------------------";
    cout << RULES_REGS << endl;

}

int main()
{
    const int MOVES = 13;
    //const string cards[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Peace", "Peace", "Shark"}; //used vector instead for dynamic resizing
    //used vectors for cards
    vector<string> playerCards = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Peace", "Peace", "Shark"};
    vector<string> dealerCards = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Peace", "Peace", "Shark"};
    //vectors for hands for easy integer comparison
    vector<int> playerHand;
    vector<int> dealerHand;
    unsigned int playerChoice, dealerChoice;
    //int to hold a numeric value of card played for comparison of winner
    int playerValue, dealerValue;
    //variables for repeating the game
    char playerInputString;
    bool exit = false;
    //seed random generator
    srand(time(NULL));
    //display rules and regulations one time before play
    rulesRegs();
    //new game loop
    while (!exit) {
        int playerScore = 0;
        int dealerScore = 0;
        int playerBonus = 0;
        int dealerBonus = 0;
        //fill the vector of the players/dealers hand
        for (int i = 0; i < MOVES; ++i) {
                playerHand.push_back(i + 1);
                dealerHand.push_back(i + 1);
        }
//        for (unsigned int i = 0; i < playerHand.size(); ++i) { //tester to make sure vectors are properly filled
//            cout << playerHand.at(i) << endl;
//            cout << dealerHand.at(i) << endl;
//        }
        for (int i = 0; i < MOVES; ++i) {

            //prompt to see cards remaining in dealer's hand after first round
            if (i > 0) {
                cout << "\nWould you like to see the dealer's leftover cards? (y for yes)" << endl;
                char view;
                cin >> view;
                view = tolower(view);
                if (view == 'y') {
                    cout << "\nDealer's Hand: ";
                    for (unsigned int j = 0; j < dealerHand.size(); j++) {
                        cout << dealerCards.at(j);
                        if (j < (dealerHand.size() - 1)) { //if statement to control commas
                            cout << ", ";
                        }
                        else cout << endl; //else to endline if last item in vector
                    }
                    cout << endl << endl; //formatting
                }
            }
            cout << "Which card would you like to play?" << endl;
            //Show the player their hand
            for (unsigned int k = 0; k < playerHand.size(); k++) {
                cout << k + 1 << " to play - " << playerCards.at(k) << endl;
            }

            cin >> playerChoice;
            //loop when non-numeric input is found
            while(cin.fail()) { //input validation
                cout << "Invalid choice, please enter a number" << endl;
                //clearing the input stream buffer up to delimiter
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores entire stream to maximum size of input buffer and sets delimiter.
                cin >> playerChoice;
            }

            while((playerChoice < 1) || (playerChoice > playerHand.size())) { //Input Validation
                cin.ignore();
                cout << "Invalid choice, Choose again" << endl;
                cin >> playerChoice;
            }
            if (dealerHand.size() > 1) {
                dealerChoice = rand() % dealerHand.size(); //randomize dealer's choice
            }
            else dealerChoice = 0;

            //assigning numeric values to Peace and Shark card selections
            if (playerCards.at(playerChoice - 1) == "Peace") {
                playerValue = 11;
            }
            else if (dealerCards.at(dealerChoice) == "Peace") { //Ryan altered .at to remove the -1 as dealer choice is randomized to correct index locations
                dealerValue = 11;
            }
            else if (playerCards.at(playerChoice - 1) == "Shark") {
                playerValue = 13;
            }
            else if (dealerCards.at(dealerChoice) == "Shark") { //Ryan
                dealerValue = 13;
            }
            else {
                playerValue = playerHand.at(playerChoice - 1); //assign value from vector to choice
                dealerValue = dealerHand.at(dealerChoice); //asign value from vector to choice
            }
            //display cards played to player
            cout << "Player's card: " << playerCards.at(playerChoice - 1) << endl;
            cout << "Dealer's card: " << dealerCards.at(dealerChoice) << endl;

            //checks for standard value card comparison
            if (playerValue <= 10 && dealerValue <= 10) {
                if ((playerValue + playerBonus) > (dealerValue + dealerBonus)) {
                    cout << "\nPlayer Wins" << endl; //Extra endl for readability
                    playerScore += 1;
                    playerBonus += 1;
                }
                else {
                    cout << endl << "Dealer Wins" << endl;
                    dealerScore += 1;
                    dealerBonus += 1;
                }
            }
            //if player used shark card and dealer did not use peace or shark
            else if (playerValue == 13 && dealerValue < 11) {
                cout << endl << "Player wins" << endl;
                playerScore += 1;
                playerBonus += 1;
            }
            //if dealer used shark card and player did not use peace or shark
            else if (dealerValue == 13 && playerValue < 11) {
                cout << endl << "Dealer Wins" << endl;
                dealerScore += 1;
                dealerBonus += 1;
            }
            //player used peace card against shark or value
            else if ((playerValue > 10 && playerValue < 13) && (dealerValue < 11 || dealerValue > 12)) {
                cout << endl << "Draw" << endl;
                cout << "Dealer Bonus Reduced" << endl;
                dealerBonus = 0;
            }
            //player used shark or value against peace card
            else if ((dealerValue > 10 && dealerValue < 13) && (playerValue < 11 || playerValue > 12)) {
                cout << endl << "Draw" << endl;
                cout << "Player Bonus Reduced" << endl;
                playerBonus = 0;
            }
            cout << "Player Score: " << playerScore << "  (BB: " << playerBonus << ")  Dealer Score: " << dealerScore << "  (BB: " << dealerBonus << ")" << endl << endl;
            //remove cards and hand from vectors after play comparison
            playerHand.erase(playerHand.begin() + (playerChoice - 1));
            playerCards.erase(playerCards.begin() + (playerChoice - 1));
            dealerHand.erase(dealerHand.begin() + (dealerChoice ));
            dealerCards.erase(dealerCards.begin() + (dealerChoice));
        }
        if (playerScore > dealerScore)
            cout << "PLAYER IS THE GRAND WINNER" << endl;
        else
            cout << "DEALER IS THE GRAND WINNER" << endl;
        cout << "\nPlay again?" << endl;
        cout << "'n' for No" << endl;
        cin >> playerInputString;
        //convert input to lowercase
        playerInputString = tolower(playerInputString);
        if (playerInputString == 'n')
            exit = true;
    }
    return 0;
}
