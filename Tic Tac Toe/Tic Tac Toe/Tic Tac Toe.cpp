#include <iostream>

using namespace std;

const int SIZE = 9;
char square[SIZE] = { '1', '2', '3',
                      '4', '5', '6',
                      '7', '8', '9' };

void print();
int checkWin();

int main()
{
    int player = 1, choice;
    char mark;

    do
    {
        print();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        if (cin.fail() || choice <= 0 || choice > SIZE) {
            cout << "Invalid move" << endl;
            system("pause");
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';

        if (square[choice - 1] == (char)(choice + '0')) {
            square[choice - 1] = mark;
        }

        else {
            cout << "Invalid move" << endl;
            system("pause");
            continue;
        }

        player++;

    } while (checkWin() == -1);

    print();

    if (checkWin() == 1) {
        cout << "\tPlayer " << --player << " win" << endl;
    }

    else {
        cout << "\tGame draw" << endl;
    }

    system("pause");
    return 0;
}

void print() {

    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

    cout << "     |     |     " << endl << endl;
}

bool isHorizontalWin() {

    return ((square[0] == square[1] && square[1] == square[2]) ||
        (square[3] == square[4] && square[4] == square[5]) ||
        (square[6] == square[7] && square[7] == square[8]));
}

bool isVerticalWin() {

    return ((square[0] == square[3] && square[3] == square[6]) ||
        (square[1] == square[4] && square[4] == square[7]) ||
        (square[2] == square[5] && square[5] == square[8]));
}

bool isDiagonalWin() {

    return ((square[0] == square[4] && square[4] == square[8]) ||
        (square[2] == square[4] && square[4] == square[6]));
}

bool isWin() {
    
    return isHorizontalWin() || isVerticalWin() || isDiagonalWin();
}

bool isDraw() {

    for (int i = 0; i < SIZE; i++) {
        if (square[i] == (char)((i + 1) + '0')) {
            return false;
        }
    }

    return true;
}

int checkWin() {

    return isWin() ? 1
         : isDraw() ? 0
         : -1;
}