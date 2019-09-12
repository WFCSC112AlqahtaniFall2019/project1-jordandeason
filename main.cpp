#include <iostream>
using namespace std;

//FUNCTION WHEN GUESSED LOCATION IS SAME AS SHIP LOCATION
void hitShip(int row, int column, string &row1, string &row3, string &row5) {
    if (column == 1) {
        if (row == 1) {
            row1.at(1) = 'X';
        } else if (row == 2) {
            row3.at(1) = 'X';
        } else {
            row5.at(1) = 'X';
        }
    } else if (column == 2) {
        if (row == 1) {
            row1.at(5) = 'X';
        } else if (row == 2) {
            row3.at(5) = 'X';
        } else {
            row5.at(5) = 'X';
        }
    } else {
        if (row == 1) {
            row1.at(9) = 'X';
        } else if (row == 2) {
            row3.at(9) = 'X';
        } else {
            row5.at(9) = 'X';
        }
    }
    cout << "Hit!" << endl;
}

//FUNCTION WHEN GUESSED LOCATION IS NOT SAME AS SHIP LOCATION
void missShip(int row, int column, string &row1, string &row3, string &row5) {
    if (column == 1) {
        if (row == 1) {
            row1.at(1) = 'O';
        } else if (row == 2) {
            row3.at(1) = 'O';
        } else {
            row5.at(1) = 'O';
        }
    } else if (column == 2) {
        if (row == 1) {
            row1.at(5) = 'O';
        } else if (row == 2) {
            row3.at(5) = 'O';
        } else {
            row5.at(5) = 'O';
        }
    } else {
        if (row == 1) {
            row1.at(9) = 'O';
        } else if (row == 2) {
            row3.at(9) = 'O';
        } else {
            row5.at(9) = 'O';
        }
    }
    cout << "Miss!" << endl;
}

//MAIN FUNCTION
int main() {

//CREATING OF VARIABLES
    bool done;
    done == false;
    int colLoc;
    int rowLoc;
    int colGuess;
    int rowGuess;
    int numGuesses = 0;

//GENERATING TWO RANDOM VARIABLES FOR SHIP LOCATION
    srand(time(NULL));
    colLoc = rand() % 2 + 1;
    rowLoc = rand() % 2 + 1;

//CREATING STRINGS FOR EACH ROW OF THE 3X3 MATRIX
    string rowOne = "   !   !   ";
    string rowTwo = "~~~~~~~~~~~~";
    string rowThree = "   !   !   ";
    string rowFour = "~~~~~~~~~~~~";
    string rowFive = "   !   !   ";

//WHILE LOOP THAT CONTINUES TO RUN UNTIL THE SHIP IS HIT
    while (done == false) {
        cout << "Guess column:";
        cin >> colGuess;
        cout << "Guess row:";
        cin >> rowGuess;
        numGuesses = numGuesses + 1;

//IF STATEMENT FOR WHEN THE SHIP IS HIT
        if (colGuess == colLoc && rowGuess == rowLoc) {
            hitShip(rowGuess, colGuess, rowOne, rowThree, rowFive);
            cout << "Guess number: " << numGuesses << endl;
            cout << rowOne << endl;
            cout << rowTwo << endl;
            cout << rowThree << endl;
            cout << rowFour << endl;
            cout << rowFive << endl;
            done = true;
//IF STATEMENT FOR WHEN ROW OR COLUMN VALUE ARE OUR OF 1-3 RANGE
        } else if ((rowGuess < 1 || rowGuess > 3) || (colGuess < 1 || colGuess > 3)) {
            cout << "ERROR. Row and column must be between 1 and 3." << endl;
        }
//IF STATEMENT FOR WHEN THE SHIP IS MISSED
        else {
            missShip(rowGuess, colGuess, rowOne, rowThree, rowFive);
            cout << "Guess number: " << numGuesses << endl;
            cout << rowOne << endl;
            cout << rowTwo << endl;
            cout << rowThree << endl;
            cout << rowFour << endl;
            cout << rowFive << endl;
        }
    }
}