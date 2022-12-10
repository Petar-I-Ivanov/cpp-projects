/* Въвежда се текст и програмата изкарва всяка буква колко пъти се среща */

#include<iostream>
#include<string>
using namespace std;

int main() {

    string message;
    int letters[26] = { 0 };

    cout << "Input text: ";
    getline(cin, message);

    for (int i = 0; i < message.length(); i++) {

        if (message[i] >= 'a' && message[i] <= 'z')
            letters[message[i] - int('a')]++;

        if (message[i] >= 'A' && message[i] <= 'Z')
            letters[message[i] - int('A')]++;
    }

    for (int i = 0; i < 26; i++)
        if (letters[i] != 0)
            cout << "  " << static_cast<char>(i + 'a') << " : " << letters[i] << endl;
}