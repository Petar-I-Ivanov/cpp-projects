/* Въвежда се число в програмата и тя проверява дали е просто */

#include <iostream>
using namespace std;

int main() {

    int number;
    bool isPrime = true;

    cout << "Input positive number: ";
    cin >> number;

    if (cin.fail() || number < 1) {
        cout << "Invalid input." << endl;
        return 1;
    }

    for (int i = 0; i < number; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }

    cout << "The number " << number << " is " << (isPrime ? "prime." : "complex.") << endl;
}