/* В програмата се въвеждат боря на стените, след това кв. им метри и
извежда колко кофи с боя са ти нужни, ако 1 кофа стига за 3кв. м.*/

#include <iostream>
using namespace std;

int main() {

    const int BOX = 3;
    int numberOfWalls;

    cout << "Input number of walls: ";
    cin >> numberOfWalls;
    if (cin.fail() || numberOfWalls < 3) {
        cout << "Invalid input for number of walls." << endl;
        return 1;
    }

    double total = 0;

    for (int i = 0; i < numberOfWalls; i++) {

        double eachWall;
        cout << "How much sq. m. is wall " << i + 1 << ": ";
        cin >> eachWall;

        if (cin.fail() || eachWall < 0) {
            cout << "Invalid input for sq. m. for wall " << i + 1 << "." << endl;
            return 2;
        }

        total += eachWall;
    }

    cout << "At " << total << "sq. m. in total you need " << ceil(total / BOX) << " paint boxes." << endl;
}