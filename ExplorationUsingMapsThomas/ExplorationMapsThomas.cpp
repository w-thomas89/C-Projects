//William Thomas, wdthomas2@dmacc.edu, 10/30/2021
//This program will take input from user about which planet to search in our solar system
//and will return the distance from that planet to the Sun

#include <iostream>
#include <map>

using namespace std;

int main() {
    //const for converting KM to Miles
    const float KM_MI = 0.621371;
    //variable to hold input from user
    string input;
    //boolean to handle continued searches
    bool exit = false;
    //boolean to handle unfound input
    bool found = false;
    //declare map
    map<string, long long int>ss;
    //initialize map
    //long long int values are km from the sun. using long long int
    ss["Mercury"] = 57900000;
    ss["Venus"] = 108200000;
    ss["Earth"] = 149600000;
    ss["Mars"] = 227900000;
    ss["Jupiter"] = 778600000;
    ss["Saturn"] = 1433500000;
    ss["Uranus"] = 2872500000;
    ss["Neptune"] = 4495100000;

    //repeat loop uses bool exit
    while (!exit) {
        cout << "Enter a planet (case sensitive)" << endl;
        cin >> input;
        //setprecision to 0 to remove decimal places after converting to Miles
        cout.precision(0);
        //create iterator for map
        map<string, long long int>::iterator it;
        //iterate through map to find a match and output
        for (it = ss.begin(); it!=ss.end(); it++) {
            //standard string comparison - case sensitive
            if (input == it->first) {
                found = true;
                cout << fixed << it->first << " is " << it->second << " km or " << it->second*KM_MI << " miles away." << endl;
            }
        }
        //output if input search is not matched
        if (!found) {
            cout << "That planet does not exist or was not spelled correctly.\n"
                 << "Please double check spelling and capitalization.\n"
                 << "Input value: " << input << endl;
        }
        //output to run program again - assigns bool exit
        cout << "Search again? (n for no)" << endl;
        char cont;
        cin >> cont;
        if (tolower(cont) == 'n') {
            exit = true;
        }
    }
}

//tested with Uranus as input. Output returned correct planet and distance with correct conversion to miles and formatting
//tested with Earth as input. Output returned correct planet and distance with formatting
//tested with earth as input and returned correct invalid input segment. properly displaying input value as incorrect
