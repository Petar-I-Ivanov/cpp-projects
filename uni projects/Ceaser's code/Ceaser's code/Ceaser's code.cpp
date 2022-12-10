/* В програмата се въвежда текст и тя го превежда в
Кода на Цезар (буквата се заменя с тази с 2 след нея) */

#include<iostream>
#include<string>
using namespace std;

int main() {

    const int DISTANCE_BETWEEN_LETTERS = 2;
    string message;

    cout << "Input the message:" << endl;
    getline(cin, message);

    for (int i = 0; i < message.length(); ++i) {

        char letter = message[i];

        if (letter >= 'a' && letter <= 'z') {

            letter += DISTANCE_BETWEEN_LETTERS;
            if (letter > 'z') letter = letter - 'z' + 'a' - 1;
        }

        if (letter >= 'A' && letter <= 'Z') {

            letter += DISTANCE_BETWEEN_LETTERS;
            if (letter > 'Z') letter = letter - 'Z' + 'A' - 1;
        }

        message[i] = letter;
    }

    cout << "Message conversion:" << endl << message << endl;
}