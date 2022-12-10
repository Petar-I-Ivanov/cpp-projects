/* Въвежда се число и програмата изкарва всички прости числа
до въведеното число (по метода на Ератостен) */

#include<iostream>
using namespace std;

int main() {

    int primeNumbers[1000];
    int toNumber;

    cout << "Input to which number to be shown prime numbers: ";
    cin >> toNumber;

    if (cin.fail() || toNumber <= 2) {
        cout << "Invalid value." << endl;
        return 1;
    }

    int i = 2;
    int counter = 0;

    while (i < toNumber) {

        bool isPrime = true;
        int j = 0;

        while (j < counter && primeNumbers[j] * primeNumbers[j] <= i) {
            if (i % primeNumbers[j] == 0) isPrime = false;
            j++;
        }

        if (isPrime) {
            primeNumbers[counter] = i;
            counter++;
        }

        i++;
    }

    for (int i = 0; i < counter; i++)
        cout << primeNumbers[i] << " ";
}