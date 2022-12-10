/* Въвежда се число и програмата и намира факториела му */

#include <iostream>
using namespace std;

int main() {

    int number;
    long long factoriel = 1;

    cout << "Input number: ";
    cin >> number;
    if (cin.fail()) {
        cout << "Invalid input." << endl;
        return 1;
    }

    for (int i = 1; i <= number; i++)
        factoriel *= i;

    cout << "Fac(" << number << ") = " << factoriel << endl;
}