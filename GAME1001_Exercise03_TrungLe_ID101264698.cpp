//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	// INIT
	int selection;
	double ticketPrice = 20;
	double childTicketPrice = ticketPrice / 2;
	double seniorTicketPrice = ticketPrice * 0.8;

	// TICKET MENU
	cout << "TICKET MENU" << endl;
	cout << left << setw(20) << "(1) Adult (15-64):" 
		<< right << setw(5) <<" $" << ticketPrice << endl;
	cout << left << setw(20) << "(2) Child (0-14):"
		<< right << setw(5) <<" $" << childTicketPrice << endl;
	cout << left << setw(20) << "(3) Senior (65+):"
		<< right << setw(5) <<" $" << seniorTicketPrice << endl;
	cout << left << setw(20) << "(4) Cancel ticket purchase & exit" << endl;
	cout << endl;

	// INPUT
	cout << "Please enter your selection: ";
	cin >> selection;

	// OUTPUT
	switch (selection) {
	case 1:
		cout << "You have selected (1). Total is $" << ticketPrice << "." << endl;
		break;
	case 2:
		cout << "You have selected (2). Total is $" << childTicketPrice << "." << endl;
		break;
	case 3:
		cout << "You have selected (3). Total is $" << seniorTicketPrice << "." << endl;
		break;
	default:
		cout << "No ticket selected. Exiting program..." << endl;
		break;
	}

	cout << endl;
	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***