/*
Ben Haney
EECS 348 EC Lab
Lab Section: Thursday 9am
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double ERROR = -999999.99;

//extractNumeric takes input string and returns formatted double
double extractNumeric(const string& str) {
    //Used to check for plus or minus sign at beginning of string
    bool plusminus = false;
    //Used to ensure only one decimal point
    bool decimal = false;
    //Used to index input string
    //size_t used to match type of str.length()
    size_t i = 0;

    //Checks if first character is a sign
    if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
        //Input has a sign
        plusminus = true;
        //Next character
        i++;
    }

    //Ensure that the input has more than one character
    if (i == str.length()) {
        //If input is only a sign, return error
        return ERROR;
    }

    //Iterate through rest of string after leading sign
    for (int i = 1; i < str.length(); i++) {
        //Ensure that the character is a digit between 0 and 9
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        }
        //Check if the character is a decimal
        else if (str[i] == '.' && !decimal) {
            //Input has a decimal
            decimal = true;
        }
        else {
            //If character is not a digit or decimal, return error
            return ERROR;
        }
    }

    //Try to convert string to double and return it
    try {
        return stod(str);
    }
    //If any exception, return error
    catch (...) {
        return ERROR;
    }

}

//Main takes input from user, runs extractNumeric, and prints output
//Borrowed from Professor Saiedian's lab writeup
int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}