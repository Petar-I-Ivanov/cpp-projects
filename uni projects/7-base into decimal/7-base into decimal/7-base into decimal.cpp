/* Въвежда се число в 7чна бройна система и програмата го пресмята до 10чна */

#include <iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {

    string baseSeven;
    int decimal = 0;
    const int CHAR_INT_DIFFERENCE = 48;

    cout << "Input number in base-7 numeral system (0-6): ";
    cin >> baseSeven;

    int length = baseSeven.length();

    for (int i = 0; i < baseSeven.length(); i++) {

        if (baseSeven[i] < '0' || baseSeven[i] > '6') {
            cout << "Invalid input." << endl;
            return 1;
        }

        decimal += ( ((int)baseSeven[i]) - CHAR_INT_DIFFERENCE) * pow(7, (--length) );
    }

    cout << baseSeven << " into decimal numeral system is " << decimal << endl;
}