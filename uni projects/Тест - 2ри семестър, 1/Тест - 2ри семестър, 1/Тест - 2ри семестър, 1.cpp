#include <iostream>
#include <ctime>
using namespace std;

int length = 10;

int findNumberSumLesserThan(int arr[], int lesserThan) {

    int counter = 0;

    for (int i = 0; i < length; i++) {
        if ((arr[i] * arr[i + 1]) < lesserThan) {
            counter++;
        }
    }

    return counter;
}

void addHundredToNumbersLesserThan(int arr[], int lesserThan) {

    for (int i = 0; i < length; i++) {
        if (arr[i] < lesserThan) {
            arr[i] += 100;
        }
    }

    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {

    srand(time(NULL));
    int* randomNumbers = new int[length];

    for (int i = 0; i < length; i++) {
        randomNumbers[i] = rand() % 10;
    }

    int lesserThan;
    cout << "Find pairs adjacent elements with product lesser than: ";
    cin >> lesserThan;
    if (cin.fail()) {
        cout << "Invalid value." << endl;
        return 1;
    }

    cout << "The number of pair adjacent elements with product lesser than " << lesserThan
        << " : " << findNumberSumLesserThan(randomNumbers, lesserThan) << endl;

    cout << "Array before the change." << endl;
    for (int i = 0; i < length; ++i) {
        cout << randomNumbers[i] << ' ';
    }
    cout << endl;

    cout << "Array after the change." << endl;
    addHundredToNumbersLesserThan(randomNumbers, lesserThan);
    return 0;
}