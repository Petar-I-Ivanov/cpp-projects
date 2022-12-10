/* Въвеждат се годините и програмата пресмята
колко свещи ще са нужни за всяка цифра */

#include<iostream>
#include<string>
using namespace std;

int main() {

    string years;

    cout << "Input years of the birthday: ";
    cin >> years;

    int length = years.length();

    for (int i = 0; i < length; i++) {

        if (years[i] < '0' || years[i] > '9') {
            cout << "Invalid value." << endl;
            return 1;
        }
    }

    cout << "For " << years << " years you will need " << length << " candles." << endl;
}