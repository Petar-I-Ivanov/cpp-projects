#include <iostream>
using namespace std;

int main() {

    double arr[5] = { 0 };

    cout << "Please input value for each element." << endl;
    for (int i = 0; i < 5; i++) {

        cout << i << ": ";
        cin >> arr[i];
        if (cin.fail()) {
            cout << "Invalid value for " << i << " element." << endl;
            return 1;
        }
    }

    int counter = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if ((arr[i] * 0.5) == arr[j] && arr[i] > 0) {
                counter++;
            }
        }
    }
    cout << counter << " elements of the array are with 1/2 higher value than value of other element." << endl;
}