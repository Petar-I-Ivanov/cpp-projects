/* Координатите на точките са дробни числа с двойна прецизност. Програмата да поддържа следната функционалност:
Въвеждане на нова двумерна точка в двумерното ортогонално пространство в масива;
Намиране и извеждане на разстояние от зададена от потребителя точка до всички в масива;
Намиране на точката с минимално разстояние от нулевата точка в масива (освен нея самата). */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Point {

    double X;
    double Y;

    Point() {
        X = 0; Y = 0;
    }

    Point(double _X, double _Y) {
        X = _X; Y = _Y;
    }

    bool input() {

        cout << "Input X: " << endl;
        cin >> X;
        if (cin.fail()) {
            return false;
        }

        cout << "Input Y: " << endl;
        cin >> Y;
        if (cin.fail()) {
            return false;
        }
        return true;
    }

    double output(Point& b) {
        return b.X, b.Y;
    }

    double distance(Point& b) {
        return sqrt(pow(X - b.X, 2) + pow(Y - b.Y, 2));
    }
};

int main() {

    vector<Point> A;

    int numberOfPoints;
    cout << "How much points you will input: ";
    cin >> numberOfPoints;
    if (cin.fail() || numberOfPoints < 1) {
        cout << "Invalid input for number of points." << endl;
        return 1;
    }

    for (int i = 0; i < numberOfPoints; i++) {

        Point pI;

        if (!pI.input()) {
            cout << "Invalid input for the point." << endl;
            return 2;
        }

        A.push_back(pI);
    }

    Point p;
    cout << "Input the point from which to display distance to others." << endl;

    if (!p.input()) {
        cout << "Invalid input for the point." << endl;
        return 3;
    }

    for (Point pI : A)
        cout << "Distance: " << (p.distance(pI)) << endl;

    Point o, o1;
    o.X = 0.0, o.Y = 0.0;
    o1.X = 100.0, o1.Y = 100.0;

    for (Point pI : A)
        if (o.distance(pI) < o1.distance(pI)) o1 = pI;

    Point pI;
    cout << "Distance closest to 0 is with point " << o1.output(o1) << ": " << o1.distance(pI) << endl;
}