/* Въвеждат се a_1, d и колко пъти да се повтори прогресията и
прогрмата пресмята a_k за всеки член на прогресията (a_k = a_1 + (k - 1) * d) */

#include <iostream>
using namespace std;

int main() {

    int a_1, d;

    cout << "Input a1 and d" << endl;
    cin >> a_1 >> d;
    if (cin.fail()) {
        cout << "Invalid a1 or d." << endl;
        return 1;
    }

    int timesToRepeat;
    cout << "Input how many times to repeat the progression: ";
    cin >> timesToRepeat;
    if (cin.fail() || timesToRepeat <= 0) {
        cout << "Invalid value." << endl;
        return 2;
    }

    int a_k;
    int k = 1;
    while (k <= timesToRepeat) {
        a_k = a_1 + (k - 1) * d;
        cout << "For " << k + 1 << " memrber of the progression, value is " << a_k << endl;
        k++;
    }
}