/* Въвежда се факултетен номер и ако на хилядите стои
1 - студентът е редовна форма, ако е 2 - задочна */

#include<iostream>
#include<cmath>
using namespace std;

int main() {

    const int NUMBER_POSITION = 4;
    string facultyNumber;

    cout << "Input faculty number." << endl;
    cin >> facultyNumber;

    if (cin.fail() || facultyNumber.length() < 4) {
        cout << "Invalid input." << endl;
        return 1;
    }

    for (int i = facultyNumber.length() - 1; i >= 0; i--) {

        if (facultyNumber[i] < '0' || facultyNumber[i] > '9') {
            cout << "Invalid faculty number." << endl;
            return 2;
        }
    }

    int length = facultyNumber.length();

    if (facultyNumber[length - NUMBER_POSITION] == '1') {
        cout << "The student is a regular form." << endl;
        return 0;
    }

    if (facultyNumber[length - NUMBER_POSITION] == '2') {
        cout << "The student is part-time form." << endl;
        return 0;
    }

    cout << "Invalid faculty number." << endl;
    return 3;
}