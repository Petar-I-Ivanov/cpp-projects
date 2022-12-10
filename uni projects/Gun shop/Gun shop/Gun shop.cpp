#include<iostream>
#include<string>
#include <vector>

using namespace std;

struct Weapons {

	int code;
	float price;
	string name;
	int cat;

	Weapons() {
		code = 0; price = 0; name = ""; cat = 0;
	}

	Weapons(int _code, float _price, string _name, int _cat) {
		code = _code; price = _price; name = _name; cat = _cat;
	}
};

struct Sells {

	int code;
	int quantity;
	int day;

	Sells() {
		code = 0; quantity = 0; day = 0;
	}

	Sells(int _code, int _num_sold, int _day) {
		code = _code; quantity = _num_sold; day = _day;
	}
};

struct Sells sells[100];
int sellCounter = 0;
struct Weapons weapons[100];
int weaponCounter = 0;
float dailyTurnovers[31];
float turnoversForArticle[100];

void inputWeapon() {

	Weapons& weapon = weapons[weaponCounter];

	cout << "Input code" << endl;
	cin >> weapon.code;
	cout << "Input name" << endl;
	cin >> weapon.name;
	cout << "Input price" << endl;
	cin >> weapon.price;
	cout << "Input category" << endl;
	cin >> weapon.cat;

	weaponCounter++;
}

void inputSell() {

	Sells& sell = sells[sellCounter];

	cout << "Input code" << endl;
	cin >> sell.code;
	cout << "Input quantity " << endl;
	cin >> sell.quantity;
	cout << "Input day of the sell" << endl;
	cin >> sell.day;

	float singlePrice = 0.0;

	for (int i = 0; i < weaponCounter; i++) {
		Weapons& w = weapons[i];

		if (w.code == sell.code) {
			singlePrice = w.price;
			break;
		}
	}

	dailyTurnovers[sell.day] += sell.quantity * singlePrice;
	turnoversForArticle[sell.code] += sell.quantity * singlePrice;

	sellCounter++;
}

void getMinDailySells() {

	float minTurnover = 3000000;
	int minDay = 0;

	for (int i = 0; i < 31; i++) {

		if (dailyTurnovers[i] != -1 && dailyTurnovers[i] < minTurnover) {
			minDay = i;
			minTurnover = dailyTurnovers[i];
		}
	}

	minTurnover++;
	cout << "Minimal turnover for day " << (minDay + 1) << ": " << minTurnover << endl;
}

void getMaxDailySells() {

	float maxTurnover = 0;
	int maxDay = 0;

	for (int i = 0; i < 31; i++) {

		if (dailyTurnovers[i] != -1 && dailyTurnovers[i] > maxTurnover) {
			maxDay = i;
			maxTurnover = dailyTurnovers[i];
		}
	}

	maxTurnover++;
	cout << "Maximum turnover for day " << (maxDay + 1) << ": " << maxTurnover << endl;
}

void getMaxSoldWeapon() {

	float maxTurnover = 0;
	int maxArt_code = -1;

	for (int i = 0; i < 100; i++) {

		if (turnoversForArticle[i] > maxTurnover) {
			maxTurnover = turnoversForArticle[i];
			maxArt_code = i;
		}
	}

	cout << "Most selling aritcle as a sum is " << maxArt_code << " with turnover: " << maxTurnover << endl;
}

int main() {

	int choice = 0;

	for (int i = 0; i < 31; i++) {
		dailyTurnovers[i] = -1;
	}
	for (int i = 0; i < 100; i++) {
		turnoversForArticle[i] = 0;
	}

	while (choice < 6) {

		cout << " 1. Enter article with code of article, single price, name and category." << endl;
		cout << " 2. Enter sell with code of article, quantity of the sell and day of the selling." << endl;
		cout << " 3. Prints report for the day with the minimum turnover." << endl;
		cout << " 4. Prints report for the day with the maximum turnover." << endl;
		cout << " 5. Prints report for the most selling article of the month with value of sold units." << endl;
		cout << " 6. Exit." << endl;

		cin >> choice;

		switch (choice) {

		case 1:
			inputWeapon();
			break;
		case 2:
			inputSell();
			break;
		case 3:
			getMinDailySells();
			break;
		case 4:
			getMaxDailySells();
			break;
		case 5:
			getMaxSoldWeapon();
			break;
		case 6:
			cout << "Bye." << endl;
			break;
		default:
			cout << "Wrong input." << endl;
		}
	}
}