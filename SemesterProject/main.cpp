//William Thomas, wdthomas2@dmacc.edu, 4/3/2021
//This program is called Wanderlust Casino. This is a standard casino console based game where player can play 21, roulette, or slots.


#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

//function prototypes
char formatChange(char input);
void welcomeScreen();
double loanPayoff();
int wantLoan();
double loanShark();
char whichGame();
int Random();


//welcome screen function
void welcomeScreen(){
    cout << "Welcome to Wanderfund Casino!!" << endl;
    cout << endl;
    cout << "Here you will test your casino skill in the game of Blackjack, Roulette, and Slots!" << endl;
    cout << "You have the option to bring your own money," << endl;
    cout << "or you can ask the Loan Officer for some extra cash. But watch out..." << endl;
    cout << "They take their cut regardless if you win.." << endl;
}

//function to deduct percentage of loaned cash from player if player chose to take a loan
double loanPayoff(double loanCash){
    if (loanCash > 0){
        double loanPayment = loanCash * 0.05;   //declares variable to say how much is paid
        loanCash = (loanCash * 0.95);           //making the payment
        cout << "Hey You! The Shark wants his money. Time to pay up! \n";
        cout << endl;
        cout << "You payed the loan shark $" << loanPayment << endl;
        cout << endl;
    }
    return loanCash;
}

//function to ask player if they wish to take out a loan - nested in loanShark function and passes only to loanShark
int wantLoan(){
    char yesORno;
    int i = 0;
    cout << "Would you like to visit the loan office today? \n" << endl;
    cout << "y for yes, n for no" << endl;
    cin >> yesORno;
    yesORno = formatChange(yesORno);
    if (yesORno == 'y'){
        i = 1;
        return i;
    }
    else {
    return i;
    }
}

//loanShark welcome screen - returns amount taken out as loan to be added to player total purse
double loanShark(int wantsLoan){
    //statement to check if player wants the loan. Returns from intro or from main menu.
    if (wantsLoan == 1){
    double loanDollars = 0;
        cout << endl;
        cout << "Welcome to the Wanderfund Loan Office! \n" << endl;
        cout << endl;
        cout << "If you take out a loan." << endl;
        cout << "We will take a 5% payment before each new round" << endl;
        cout << "Until we are paid back. \n" << endl;
        cout << "How much would you like to borrow today?" << endl;
        cin >> loanDollars;
        return loanDollars;
    }
    return 0;
}


//function to request which game user would like to play.
char whichGame(){
    char choice;
    cout << "Which game would you like to play?" << endl;
    cout << "  B  -  BlackJack(21)" << endl;
    cout << "  S  -  Slots" << endl;
    cout << "  R  -  Roulette" << endl;
    cout << "  L  -  LoanShark" << endl;
    cout << "  E  -  EXIT" << endl;
    cin >> choice;
    choice = formatChange(choice);
    return choice;
}

//function to change any char input from user to lower case. used throughout program.
char formatChange(char input){
    if (isupper(input)){
        input = tolower(input);
    }
    return input;
}


// Random number generator. Generator is seeded in main.
int Random(int low, int high){
    int randomNum;
    randomNum = rand() % (high - low) + 1;
    return randomNum;
}


//21 card game
void blackJack(double &purse, double &loanCash){                //BLACKJACK - Functional
    //initialize variables
    double myFunds = purse;
    double loanFunds = loanCash;
    double cash;    //variable used to compare bet to total money
    int playerHand = 0;
    int dealerHand = 0;
    double betAmt;
    char wantHit;
    char playAgain;
    const int WIN = 3;

    //do-while loop to continue playing after each hand
    do{
        cash = myFunds + loanFunds;
        cout << "You have $" << cash << endl;
        cout << "How much would you like to bet?" << endl;
        cin >> betAmt;
        if (betAmt > cash){ //validation loop
            cout << "You don't have that much. Please enter a value less than or equal to: " << cash << endl;
            cin >> betAmt;
        }
        //generate initial hand for player and dealer
        playerHand = Random(3,20);
        dealerHand = Random(3,20);
        //output to player if they want to increase score
        cout << "Player has " << playerHand << "." << endl;
        cout << "Dealer has " << dealerHand << "." << endl;
        cout << "Would player like to hit?" << endl;
        cin >> wantHit;
        wantHit = formatChange(wantHit);

        //while loop that outputs player hand after each hit and asks if they want another, also displays bust if player goes over 21
        while ((wantHit == 'y') && (playerHand < 21)){
            playerHand += (Random(2,9));
            if (playerHand > 21){
                cout << "You BUST!!! Sorry..." << endl;
                if (myFunds > 0){
                    myFunds -= betAmt;
                    loanFunds = loanPayoff(loanFunds);
                }
                else {
                    loanFunds -= betAmt;
                    loanFunds = loanPayoff(loanFunds);
                }

            }
            else{
                cout << "Player has " << playerHand << "." << endl;
                cout << endl;
                cout << "Would player like to hit?" << endl;
                cin >> wantHit;
            }
        }
        //hit blackjack. instant win.
        if (playerHand == 21){
            cout << "BLACKJACK!!" << endl;
            cout << "You win " << betAmt * WIN << "." << endl;
            myFunds += (betAmt * WIN);
            loanFunds = loanPayoff(loanFunds);

        }
        //loop for dealer to hit if score is less than 17, less than player,and player did not bust
        while ((playerHand < 21) && (dealerHand <= 17)){
            dealerHand += (Random(2,9));
        }
        cout << "Player hand is: " << playerHand << endl;
        cout << "Dealer hand is: " << dealerHand << endl;
        cout << endl;

        //check for win
        if ((playerHand < 21) && (playerHand > dealerHand)){
            cout << "You Won!!" << endl;
            cout << "You win " << betAmt * WIN << "." << endl;
            myFunds += (betAmt * WIN);
            loanFunds = loanPayoff(loanFunds);
        }
        //check for a tie
        else if (playerHand == dealerHand){
            cout << "You tied." << endl;
            cout << "That is like kissing your sister." << endl;
            cout << "You didn't lose anything." << endl;
            loanFunds = loanPayoff(loanFunds);
        }
        else if (dealerHand > 21){
            cout << "You won!." << endl;
            cout << "You win " << betAmt * WIN << "." << endl;
            myFunds += (betAmt * WIN);
            loanFunds = loanPayoff(loanFunds);
        }
        //lose
        else if (dealerHand > playerHand){
            cout << "You Lost!" << endl;
            cout << "You lose " << betAmt << "." << endl;
            myFunds -= betAmt;
            loanFunds = loanPayoff(loanFunds);
        }
        //re-declare variable for final output after round and loan payoff
        cash = myFunds + loanFunds;
        cout << "You have $" << cash << "." << endl;
        cout << "Would you like to play again? (y/n)" << endl;
        cin >> playAgain;
        playAgain = formatChange(playAgain);
    }
    while (playAgain == 'y');
}

//Roulette game
void roulette(double &purse, double &loanCash){                 //ROULETTE - Functional
    //Variable declaration
    double cash;
    const int MIN = 1;
    const int MAX = 36;
    char playerGameChoice;
    double playerBetAmt;
    int numBets;
    vector<int> playedNumber;
    int vectorNum;
    int landedBall;
    int i;

    //Welcome output to player
    cout << "Welcome to the Roulette Table!" << endl;
    cout << "You can choose to play 1 of 4 different ways!" << endl;
    cout << endl;
    cout << "If you would like to bet on individual numbers. Please enter 'N'. This pays 35:1." << endl;
    cout << "You must bet the same amount for each number you choose." << endl;
    cout << endl;
    cout << "If you would like to bet on 1 of the 12 streets of the table. Please enter 'S'. This pays 12:1." << endl;
    cout << endl;
    cout << "Or would you like to bet on a 1 of the 3 board sections? Please enter 'B'. This pays 4:1." << endl;
    cout << endl;
    cout << "Or you can bet on the basic Black/Red. This pays 2:1. Not standard rules but more appealing." << endl;
    cout << "Please enter 'A'." << endl;
    cout << endl;
    cout << "Or you can enter 'E' to EXIT!" << endl;
    cout << endl;

    //loop to continue playing based on player input
    do{
        cout << "Please enter your playing choice." << endl;
        cout << "N for numbers. S for streets. B for sections. A for black/red. E to exit." << endl;
        cin >> playerGameChoice;
        formatChange(playerGameChoice);

        //loop if player wants to play individual numbers
        if (playerGameChoice == 'n'){
            cash = purse + loanCash;
            const int WIN = 35;
            char play;
            bool playAgain = true;
            bool didYouWin = false;
            while (playAgain != false){
                cout << "How many numbers are you wanting to bet on?" << endl;
                cin >> numBets;
                while (numBets > 36){   //input validation
                    cout << "You can't bet on more numbers than is on the table. Please enter a number between 1 - 36." << endl;
                    cin >> numBets;
                }
                cout << "How much are you wanting to bet on each number?" << endl;
                cin >> playerBetAmt;
                while ((playerBetAmt * numBets) > cash){    //input validation
                    cout << "You don't have that much. Please enter no more than: " << cash << endl;
                    cin >> playerBetAmt;
                }
                cout << endl;
                //loop to input each number you wish to bet on, and adds to vector
                for (i = 0; i < numBets; i++){
                    cout << "Enter the number you want to play." << endl;
                    cin >> vectorNum;
                    cout << endl;
                    playedNumber.push_back(vectorNum);
                }
                //generate winning number
                landedBall = Random(MAX, MIN);
                cout << "The ball landed on: " << landedBall << endl;
                cout << endl;

                //loop to check for a winning match
                for (i = 0; i < numBets; i++){
                    if (playedNumber.at(i) == landedBall){
                        cout << "Your bet on " << playedNumber.at(i) << " WON!" << endl;
                        cout << "You have won " << playerBetAmt * WIN << "!" << endl;
                        didYouWin = true;

                        //statement to show that money bet on numbers other than winning is still lost
                        if (numBets > 1){
                            cout << "With the win though, you lost $" << playerBetAmt * (numBets - 1) << " on the other numbers." << endl;
                            if (purse > 0){
                                purse -= (playerBetAmt * (numBets - 1));
                            }
                            else {
                                loanCash -= (playerBetAmt * (numBets - 1));
                            }
                        }
                        purse += (playerBetAmt * WIN);
                        loanCash = loanPayoff(loanCash);
                        cout << endl;
                        }
                    }

                //Output if no numbers matched
                if (didYouWin == false) {
                    cout << "You did not win. Sorry." << endl;
                    cout << "You lost " << playerBetAmt * numBets << endl;
                    if (purse > 0){
                        purse -= (playerBetAmt * numBets);
                    }
                    else {
                        loanCash -= (playerBetAmt * numBets);
                    }
                    loanCash = loanPayoff(loanCash);\
                    cash = purse + loanCash;
                    cout << "Your purse is now filled with $" << cash << endl;
                }
                //redeclare for final output of money
                cash = purse + loanCash;
                cout << "You have $" << cash << "." << endl;
                cout << "Want to play again. Y/N" << endl;
                cin >> play;
                play = formatChange(play);
                if (play == 'n'){
                    playAgain = false;
                }
            }
        }

        //loop if player wants to play Streets
        if (playerGameChoice == 's'){
            cash = purse + loanCash;
            const int WIN = 12;
            char play;
            bool playAgain = true;
            int playedSection;
            int winningStreet;
            int streetNums[12][3] = {   //declare 2d array
                {1,2,3},
                {4,5,6},
                {7,8,9},
                {10,11,12},
                {13,14,15},
                {16,17,18},
                {19,20,21},
                {22,23,24},
                {25,26,27},
                {28,29,30},
                {31,32,100} };

            landedBall = Random(MAX, MIN);  //randomize winning number

            //informative output to player
            cout << "You have chosen to bet on the streets. There are 12 streets." << endl;
            cout << "Street 1 = 1,2,3" << endl;
            cout << "Street 2 = 4,5,6" << endl;
            cout << "Street 3 = 7,8,9" << endl;
            cout << "Street 4 = 10,11,12" << endl;
            cout << "Street 5 = 13,14,15" << endl;
            cout << "Street 6 = 16,17,18" << endl;
            cout << "Street 7 = 19,20,21" << endl;
            cout << "Street 8 = 22,23,24" << endl;
            cout << "Street 9 = 25,26,27" << endl;
            cout << "Street 10 = 28,29,30" << endl;
            cout << "Street 11 = 31,32,33" << endl;
            cout << "Street 12 = 34,35,36" << endl;
            cout << endl;

            //while loop to continue playing
            while (playAgain != false){
                cout << "Please enter the number of the street you would like to bet on." << endl;
                cin >> playedSection;
                while ((playedSection < 1) || (playedSection > 12)){
                    cout << "Please enter a valid street number 1-12." << endl;
                    cin >> playedSection;
                }
                cout << "Please enter the amount you would like to bet." << endl;
                cin >> playerBetAmt;
                while (playerBetAmt > cash){
                    cout << "You don't have that much. Please enter less than $" << cash << "." << endl;
                    cin >> playerBetAmt;
                }

                //loop to find winning street
                for (int i = 0; i < 12; ++i){
                    for (int j = 0; j < 3; ++j){
                        if (landedBall == streetNums[i][j]){
                            winningStreet = (i + 1);
                        }
                    }

                }
                //WIN
                if (playedSection == winningStreet){
                    cout << "You Won! The winning street was: " << winningStreet << endl;
                    cout << "You win $" << playerBetAmt * WIN << "." << endl;
                    purse += (playerBetAmt * WIN);
                    loanCash = loanPayoff(loanCash);
                }
                //LOSS
                else{
                    cout << "You lost..." << endl;
                    cout << "The winning street was " << winningStreet << "." << endl;
                    cout << "You lose $" << playerBetAmt << endl;
                    if (purse > 0){
                    purse -= playerBetAmt;
                    }
                    else {
                        loanCash -= playerBetAmt;
                    }
                    loanCash = loanPayoff(loanCash);
                }
                cash = purse + loanCash;
                //Prompt to play again
                cout << "You have $" << cash << "." << endl;
                cout << "Want to play again. Y/N" << endl;
                cin >> play;
                play = formatChange(play);
                if (play == 'n'){
                    playAgain = false;
                }
            }


        }

        //loop if player wants to play board sections
        if (playerGameChoice == 'b'){
            cash = purse + loanCash;
            const int WIN = 4;
            char play;
            bool playAgain = true;
            int winningSection;
            int playerSection;
            double playerBetAmt;
            int sectionNums[3][12] = {      //declare 2d array
                {1,4,7,10,13,16,19,22,25,28,31,34},
                {2,5,8,11,14,17,20,23,26,29,32,35},
                {3,6,9,12,15,18,21,24,27,30,33,36}  };

            //loop to continue playing
            while (playAgain != false){
                //generate winning ball
                landedBall = Random(MAX, MIN);
                //output information to player
                cout << "You chose to play board sections. Each section is as follows:" << endl;
                cout << "Section 1: 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34." << endl;
                cout << "Section 2: 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35." << endl;
                cout << "Section 3: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36." << endl;
                cout << endl;
                cout << "Please enter the number of the section you want to play." << endl;
                cin >> playerSection;
                cout << "Please enter how much you want to bet." << endl;
                cin >> playerBetAmt;
                while (playerBetAmt > cash){    //validation
                    cout << "You don't have that much. Please enter less than $" << cash << "." << endl;
                    cin >> playerBetAmt;
                }

                //loop to find winning section
                for (int i = 0; i < 3; ++i){
                    for (int j = 0; j < 12; ++j){
                        if (landedBall == sectionNums[i][j]){
                            winningSection = (i + 1);
                        }
                    }
                }

                //WIN
                if (playerSection == winningSection){
                    cout << "You Won! The winning section was: " << winningSection << endl;
                    cout << "You win $" << playerBetAmt * WIN << "." << endl;
                    purse += (playerBetAmt * WIN);
                    loanCash = loanPayoff(loanCash);
                }
                //LOSS
                else{
                    cout << "You lost..." << endl;
                    cout << "The winning section was " << winningSection << "." << endl;
                    cout << "You lose $" << playerBetAmt << endl;
                    if (purse > 0){
                        purse -= playerBetAmt;
                    }
                    else {
                        loanCash -= playerBetAmt;
                    }
                    loanCash = loanPayoff(loanCash);
                }
                cash = purse + loanCash;
                //Prompt to play again
                cout << "You have $" << cash << "." << endl;
                cout << "Want to play again. Y/N" << endl;
                cin >> play;
                play = formatChange(play);
                if (play == 'n'){
                    playAgain = false;
                }
            }
        }

        //loop if player wants to play red/black
        if (playerGameChoice == 'a'){
            cash = purse + loanCash;
            const int WIN = 2;
            char play;
            bool playAgain = true;
            int playerChoice;
            double playerBetAmt;
            bool didYouWin = false;

            do{
                //information output
                cout << "You have $" << purse << "." << endl;
                cout << "You have chose to bet on Red/Black. Which is the same as betting on ODD/EVEN." << endl;
                cout << "Please enter 1 (ONE) to bet on the ODD section (BLACK)." << endl;
                cout << "Please enter 2 (TWO) to bet on the EVEN section (RED)." << endl;
                cin >> playerChoice;
                cout << endl;
                cout << "Please enter how much you want to bet." << endl;
                cin >> playerBetAmt;
                while (playerBetAmt > cash){    //validation
                    cout << "You don't have that much. Please enter a number less than " << cash << endl;
                    cin >> playerBetAmt;
                }
                landedBall = Random(MAX, MIN);

                //checking to see if wining number is even (RED)
                if (landedBall % 2 == 0){
                    didYouWin = true;
                }
                //WIN
                if (didYouWin == true){
                    cout << "Great Job! You Won!" << endl;
                    cout << "You won $" << playerBetAmt * WIN << "." << endl;
                    purse += (playerBetAmt * WIN);
                    loanCash = loanPayoff(loanCash);
                }
                //LOSS
                else {
                    cout << "Sorry you lost..." << endl;
                    cout << "You lost $" << playerBetAmt << "." << endl;
                    if (purse > 0){
                        purse -= playerBetAmt;
                    }
                    else {
                        loanCash -= playerBetAmt;
                    }
                    loanCash = loanPayoff(loanCash);
                }
                cash = purse + loanCash;
                cout << "You have $" << purse << "." << endl;
                cout << "Want to play again. Y/N" << endl;
                cin >> play;
                play = formatChange(play);
                if (play == 'n'){
                    playAgain = false;
                }
            }
            while (playAgain != false);
        }



    }
    while (playerGameChoice != 'e');
}

//Slots game
void slots(double &purse, double &loanCash){                    //SLOTS - Functional
    //variable declaration
    const int NUM_WHEELS = 3;
    const int WIN_2 = 5;
    const int WIN_3 = 25;
    double cash = purse + loanCash;
    char play;
    bool playAgain = true;
    const int MAX = 6;
    const int MIN = 1;
    int slotWheel[NUM_WHEELS];
    int a;
    double playerBetAmt;

    //output information to player
    cout << "Welcome to the Slot Machines!!" << endl;
    cout << endl;
    cout << "Three drums will be assigned at random. If none of the drums match, you lose your bet." << endl;
    cout << "If two of the drums match, you win 5 times your bet." << endl;
    cout << "If all three drums match. You will win 25 times your bet." << endl;

    //loop to continue playing
    while (playAgain != false){
        cout << "Please place your bet." << endl;
        cin >> playerBetAmt;
        while (playerBetAmt > cash){    //validation
            cout << "You don't have that much. Try again. You have$" << cash << "." << endl;
            cin >> playerBetAmt;
        }
        //iteration loop to assign random case to array
        for (int i = 0; i < NUM_WHEELS; ++i){
            //generate random
            a = Random(MIN, MAX);

            switch(a){

            case(0):
                cout << "BAR" << endl;
                slotWheel[i] = 1;
                break;
            case(1):
                cout << "CHERRY" << endl;
                slotWheel[i] = 2;
                break;
            case(2):
                cout << "BELLS" << endl;
                slotWheel[i] = 3;
                break;
            case(3):
                cout << "SEVEN" << endl;
                slotWheel[i] = 4;
                break;
            case(4):
                cout << "GRAPE" << endl;
                slotWheel[i] = 5;
                break;
            case(5):
                cout << "DIAMOND" << endl;
                slotWheel[i] = 6;
                break;
            }
        }
        //comparing array position integers to check for all 3 matches
        if ((slotWheel[0] == slotWheel[1]) && (slotWheel[1] == slotWheel[2])){
             cout << "You matched all three!" << endl;
             cout << "You won $" << playerBetAmt * WIN_3 << "." << endl;
             purse += (playerBetAmt * WIN_3);
             loanCash = loanPayoff(loanCash);

        }
        //else if (needed to prevent redundancy when 3 match) statement to check for 2 matches.
        else if ((slotWheel[0] == slotWheel[1]) || (slotWheel[0] == slotWheel[2]) || (slotWheel[1] == slotWheel[2])){
            cout << "You matched two words." << endl;
            cout << "You won $" << playerBetAmt * WIN_2 << "." << endl;
            purse += (playerBetAmt * WIN_2);
            loanCash = loanPayoff(loanCash);
        }
        //else statement to output when nothing matches
        else {  //((slotWheel[0] != slotWheel[1]) && (slotWheel[1] != slotWheel[2]) && (slotWheel[0] != slotWheel[2])){
            cout << "You lost. Nothing matched." << endl;
            cout << "You lose $" << playerBetAmt << endl;
            if (purse > 0){
                purse -= playerBetAmt;
                loanCash = loanPayoff(loanCash);
            }
            else {
                loanCash -= playerBetAmt;
                loanCash = loanPayoff(loanCash);
            }
        }

        cash = purse + loanCash;
        cout << "You have $" << cash << "." << endl;
        cout << "Want to play again. Y/N" << endl;
        cin >> play;
        play = formatChange(play);
        if (play == 'n'){
            playAgain = false;
        }

    }
}


//Main Program body
int main (){
    //declare variables
    double purse ;
    double loanCash;
    bool repeat = true;
    const char BLACKJACK = 'b';
    const char ROULETTE = 'r';
    const char SLOTS = 's';
    const char LOANSHARK = 'l';
    const char EXIT = 'e';

    //seeding random number generator
    srand(time(0));

    //Introduction to player
    welcomeScreen();

    //output and request input for player money brought. this can be entered high to preven loan sharks.
    cout << "How much money did you bring with you today? \n";
    cin >> purse;

    //nested function. first function asks user if they want a loan, second function returns how much they want if they say yes.
    loanCash = loanShark(wantLoan());

    //loop to continue playing. can back out of any game and return back to this menu.
    //"MAIN-MENU"
    do{
        char choice;
        //function to ask which game they want to play. returns char to compare below
        choice = whichGame();
        if (choice == BLACKJACK){
            blackJack(purse, loanCash);
        }
        if (choice == ROULETTE){
            roulette(purse, loanCash);
        }
        if (choice == SLOTS){
            slots(purse, loanCash);
        }
        if (choice == LOANSHARK){
            loanCash = loanShark(1);
        }
        if (choice == EXIT){
        repeat = false;
        }

    }
    while (repeat != false);

}

//TESTING DATA
//Tested no money coming in. No money from loan shark. Expect no games to allow a bet. Worked as expected.
//Tested using 10000 coming in. No money from loan shark. Expect games to properly calculate from bets. Worked as expected.
//Tested using 0 coming in. 10000 from loan shark.  Expect games to recognize loanCash vs purse, and loanShark to prompt after every hand. Worked as expected.
//Tested blackjack for 25 hands. Expected all calculations to be accurate. Did experience bug where loanCash was not properly reduced with loanPayoff.
//Tested roulette for 25 rounds. Expected each round to properly check for win. Win verification did loop through array and output as expected.
//Tested slots for 25 rounds. Expect each win to be accurate. Worked as expected.

