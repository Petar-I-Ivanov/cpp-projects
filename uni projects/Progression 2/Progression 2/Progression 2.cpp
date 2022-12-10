/* Въвежда се |х|<1 и обхват (range) на уравнението и програмата пресмята до 3ти знак (0.000) по следната формула:
Sum = 1 - x / (2! * 3!) + x * x / (3!* 4!) - x * x * x / (4! * 5!) + ... */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func1(double x, int range) {

    double functionSum = 0;

    for (int i = 1; i <= range; i++) {

        if (i == 1) {
            functionSum = i - x / ((i + 1) * (i + 2));
        }
        else if (i % 2 == 0) {
            functionSum += (pow(x, i) / ((i + 1) * (i + 2)));
        }
        else if (i % 1 == 0) {
            functionSum -= (pow(x, i) / ((i + 1) * (i + 2)));
        }
    }
    return functionSum;
}

int main() {

    int range;
    double x;
    double sum;

    cout << "Input x: ";
    cin >> x;
    if (cin.fail() || fabs(x) >= 1) {
        cout << "Invalid value for x." << endl;
        return 1;
    }

    cout << "Input range of equation: ";
    cin >> range;
    if (cin.fail() || range <= 0) {
        cout << "Invalid value for range of equation." << endl;
        return 2;
    }

    sum = func1(x, range);
    cout << "Value of the equation is: " << setprecision(3) << sum << endl;
    return 0;
}