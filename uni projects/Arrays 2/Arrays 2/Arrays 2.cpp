/* Създава масив, заделен в динамичната памет с размер n, въведен от клавиатурата; Масивът е от дробни числа;
Намира максималното въведено число и изкарва индексите в масива, където се среща;
Намира средноаритметичното  число от всички, въведени в масива;
Намира средноаритметичното число от всички, въведени в масива, които са по-малки от число t, въведено от потребителя. */

#include <iostream>
#include <vector>
using namespace std;

bool inputValues(double arr[], int size) {

    for (int i = 0; i < size; i++) {

        cout << "Input value for A[" << i + 1 << "]: ";
        cin >> arr[i];

        if (cin.fail()) return false;

    }
}

void findMax(double arr[], int size) {

    double max = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }

    cout << "Max number " << max << " is found at indices: ";

    for (int i = 0; i < size; i++) {
        if (arr[i] == max) cout << i << " ";
    }

    cout << endl;
}

double findAverage(double arr[], int size) {

    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];
         
    return sum / size;
}

double findAverageLesserThan(double arr[], int size, double lesserThan) {

    double sum = 0;
    int counter = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < lesserThan) {
            sum += arr[i];
            counter++;
        }
    }

    return sum / counter;
}

int main() {

    double* arr = 0;
    int size;

    cout << "Input size of the array: ";
    cin >> size;
    if (cin.fail() || size <= 1) {
        cout << "Invalid input for the size of the array." << endl;
        return 1;
    }

    arr = new double[size];
    if (!inputValues(arr, size)) {
        cout << "Invalid value." << endl;
        return 2;
    }

    double lesserThan;
    cout << "Input average of the numbers less than which number you want: ";
    cin >> lesserThan;
    if (cin.fail()) {
        cout << "Invalid input.";
        return 3;
    }

    findMax(arr, size);
    cout << "Average of all is " << findAverage(arr, size) << endl;
    cout << "Average of numbers under " << lesserThan << " is " << findAverageLesserThan(arr, size, lesserThan) << endl;
}