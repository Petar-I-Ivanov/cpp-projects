/* В прогрмата се въвеждат година, месец, ден и пресмята следващата дата*/

#include<iostream>
using namespace std;

int main() {

    int year;
    int month;
    int monthLength = 31;
    int day;
    bool isLeapYear = false;

    cout << "Input year: ";
    cin >> year;
    if (cin.fail()) {
        cout << "Invalid input for the year." << endl;
        return 1;
    }
    
    if (year % 4 == 0) isLeapYear = true;

    cout << "Input month [1-12]: ";
    cin >> month;
    if (cin.fail() || month < 0 || month > 12) {
        cout << "Invalid input for the month." << endl;
        return 2;
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
        monthLength = 30;

    if (month == 2) {
        monthLength = (isLeapYear)
            ? 29
            : 28;
    }

    cout << "Input day [1-" << monthLength << "]: ";
    cin >> day;
    if (cin.fail() || day < 1 || day > monthLength) {
        cout << "Invalid input for the day." << endl;
        return 3;
    }
    
    if (day < monthLength) ++day;
    else {

        day = 1;

        if (month == 12) {
            month = 1;
            ++year;
        }
        else ++month;
        }

    cout << "Next date is [dd,mm,yyyy] " << day << "," << month << "," << year << endl;
}