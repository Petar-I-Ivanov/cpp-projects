#include <iostream>
#include <vector>
using namespace std;

struct Ticket {

	int day, broi;

	Ticket() {
		day = 0; broi = 0;
	}

	Ticket(int _day, int _broi) {
		day = _day; broi = _broi;
	}
};

struct Ticket tickets[100];
int numTicket = 0;

float inputTicket() {

	Ticket& a = tickets[numTicket];

	cout << "Vyvedete broq" << endl;
	cin >> a.broi;
	if (cin.fail()) {
		cout << "Nevalidna stoinost za broq." << endl << endl;
		return 1;
	}

	cout << "Vyvedete den" << endl;
	cin >> a.day;
	if (cin.fail() || a.day < 1 || a.day>15) {
		cout << "Nevalidna stoinost za denq." << endl << endl;
		return 2;
	}

	numTicket++;
}

void minBroi() {

	int min_broi = tickets[0].broi;

	for (int i = 0; i < numTicket; i++)
		if (min_broi > tickets[i].broi) min_broi = tickets[i].broi;

	cout << "Minimalniq broi prodadeni bileti e: " << min_broi << endl << endl;
}

void sumBroi() {

	int sum = 0;

	for (int i = 0; i < numTicket; i++) sum += tickets[i].broi;

	cout << "Obshtiq broi prodadeni bileti e: " << sum << endl << endl;
}

void aveBroi() {

	for (int i = 0; i < numTicket; i++)
		if (tickets[i].broi <= 25)
			cout << "Na " << tickets[i].day << " den sa prodadeni " << tickets[i].broi << " bileta" << endl << endl;
}

int main() {

	int choice = 0;

	while (choice < 5) {

		cout << "1. Vyvejdane na prodadeni bileti." << endl
			 << "2. Izvejdane na minimalniq broi prodadeni bileti" << endl
			 << "3. Obshtiq broi prodadeni bileti prez perioda." << endl
			 << "4. Izvejdane na dnite, prez koito sa prodadeni ne poveche ot 25 bileta" << endl
			 << "5. Izhod" << endl;

		cin >> choice;
		switch (choice) {

		case 1:
			inputTicket();
			break;
		case 2:
			minBroi();
			break;
		case 3:
			sumBroi();
			break;
		case 4:
			aveBroi();
			break;
		case 5:
			cout << "Izhod." << endl;
			break;
		default:
			cout << "Greshen izbor." << endl;
		}
	}

	return 0;
}