/* Дели числата в масивите А и B и извежда
произведението им и остатъка им */

#include <iostream>
#include <list>
#include <vector>
using namespace std;

void easyArray() {

    int A[8] = { 7, -7, 7, -7, 3, -3, 3, -3 };
    int B[8] = { 3, 3, -3, -3, 7, 7, -7, -7 };

    for (int i = 0; i < 8; i++) {

        int wholeNumber = A[i] / B[i];
        int remainderNumber = A[i] % B[i];

        cout << "The whole[" << i + 1 << "] = " << wholeNumber << endl;
        cout << "The remainder[" << i + 1 << "] = " << remainderNumber << endl;
    }
}

void advancedArray() {

    list<vector<int>> A = { {7,3}, {-7,3}, {7,-3}, {-7,-3}, {3,7}, {-3, 7}, {3, -7}, {-3, -7} };
    int B[8][2] = { {7,3}, {-7,3}, {7,-3}, {-7,-3}, {3,7}, {-3, 7}, {3, -7}, {-3, -7} };

    A.push_back({ 7, 7 });

    int i = 0;
    for (vector<int> pairNumbers : A) {

        int wholeNumber = pairNumbers[0] / pairNumbers[1];
        int remainderNumber = pairNumbers[0] % pairNumbers[1];

        cout << "The whole[" << i + 1 << "] = " << wholeNumber << endl;
        cout << "The remainder[" << i + 1 << "] = " << remainderNumber << endl;
        i++;
    }
}

int main() {

    cout << "Easy array:" << endl;
    easyArray();

    cout << endl;

    cout << "Advanced array:" << endl;
    advancedArray();
}