#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    srand(time(NULL));
    int rowLoc = rand() % 3 + 1;//generates random row
    int colLoc = rand() % 3 + 1;//generates random column
    int rowGuess;
    int colGuess;

    vector<string> matrix(9, " ");
    bool hit = false;
    int index = 0;
    int numGuesses = 0;//keeps track of number of guesses
    bool invalidNum = false;//variable for guesses outside 1-3 range


    while (hit == false) {//while loop for guessing
        //user enters guess location
        cout << "Guess column:";
        cin >> colGuess;
        cout << "Guess row:";
        cin >> rowGuess;

        //next two if statements for invalid guesses
        if (rowGuess != 1 && rowGuess != 2 && rowGuess != 3) {
            cout << "ERROR. Row and column must be between 1 and 3.";
            invalidNum = true;
            break;
        }

        if (colGuess != 1 && colGuess != 2 && colGuess != 3) {
            cout << "ERROR. Row and column must be between 1 and 3.";
            invalidNum = true;
            break;
        }

        //next 3 if statements for location of XO
        if (rowGuess == 1) {
            if (colGuess == 1) {
                index = 0;
            } else if (colGuess == 2) {
                index = 1;
            } else {
                index = 2;
            }
        } else if (rowGuess == 2) {
            if (colGuess == 1) {
                index = 3;
            } else if (colGuess == 2) {
                index = 4;
            } else {
                index = 5;
            }
        } else {
            if (colGuess == 1) {
                index = 6;
            } else if (colGuess == 2) {
                index = 7;
            } else {
                index = 8;
            }
        }


        //hit or miss
        if (rowGuess == rowLoc && colGuess == colLoc) {
            matrix.at(index) = "X";
            hit = true;
        } else {
            matrix.at(index) = "O";
        }

        //prints matrix
        cout << matrix.at(0) << "!" << matrix.at(1) << "!" << matrix.at(2) << endl;
        cout << "~~~~~" << endl;
        cout << matrix.at(3) << "!" << matrix.at(4) << "!" << matrix.at(5) << endl;
        cout << "~~~~~" << endl;
        cout << matrix.at(6) << "!" << matrix.at(7) << "!" << matrix.at(8) << endl;
        numGuesses++;
    }
    //correct guess
    if (invalidNum == false) {
        cout << "Hit!" << endl;
        cout << "Num Guesses: " << numGuesses;
    }
    return 0;
}