#include <iostream>
#include<string>
#include<ctime>
using namespace std;

struct TS {
    string str = "";
    double d = 0.0;
};

void EnterTS(TS& ts) {

    cout << "Enter string: ";
    cin.get();
    getline(cin, ts.str);
    do {
        cout << "Enter double: ";
        cin >> ts.d;
    } while (ts.d <= 0);
}

void EnterAllTS(TS ts[], const int size) {

    srand(time(NULL));
    int sum1 = 0, sum2 = 0;
    string str1 = "!@#$%^&*()", str2 = "agabklighntop", a;

    for (int i = 0; i < size; i++) {
        a = "";
        cout << "Enter information for TS " << i + 1 << endl;
        EnterTS(ts[i]);
        a += str1[rand() % str1.length()];
        a += str1[rand() % str1.length()];
        a += str2[rand() % str2.length()];
        a += ts[i].str;
        cout << "Noviqt niz: ";
        cout << a << endl;
        sum2 += a.length();
        a = ts[i].str;
        sum1 += a.length();
    }

    cout << "Suma na dyljunata na starite nizove: " << sum1 << endl;
    cout << "Suma na dyljinata na novite nizove: " << sum2 << endl;
}

int main() {

    const int x = 50;
    TS ts[x];
    int n;

    cout << "Kolko TS shte vavejdate (maksimum 50): ";
    cin >> n;
    if (n <= 0 || cin.fail()) {
        cout << "Greshen input." << endl;
        return 1;
    }

    EnterAllTS(ts, n);
}