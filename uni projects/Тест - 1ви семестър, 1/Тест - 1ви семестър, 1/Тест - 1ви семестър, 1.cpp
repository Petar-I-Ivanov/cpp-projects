#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int x;
    int choice;
    double y;

    cout << "Input x: ";
    cin >> x;
    if (cin.fail()) {
        cout << "Invalid input for x.";
        return 1;
    }

    cout << "Choose equalution." << endl
        << "1. y = x - 5" << endl
        << "2. y = sin(x)-x" << endl
        << "3. y = cos(x)" << endl
        << "4. y = exp(x)" << endl;

    cin >> choice;
    switch (choice) {
    case 1:
        y = double(x) - 5;
        cout << "y = " << y << endl;
        break;
    case 2:
        y = sin(double(x)) - double(x);
        cout << "y = " << y << endl;
        break;
    case 3:
        y = cos(double(x));
        cout << "y = " << y << endl;
        break;
    case 4:
        y = exp(double(x));
        cout << "y = " << y << endl;
        break;
    default:
        cout << "Invalid value.";
        break;
    }

    return 0;
}