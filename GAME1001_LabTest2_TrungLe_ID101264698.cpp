#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

int main() {
	int user_input;
	bool is_valid;

	for (int i = 0; i < 5; i++) {
		
		
		do {
			cout << "Enter number #" << i + 1 << " (1-30): ";
			cin >> user_input;
			is_valid = false;
			cin.ignore(INT_MAX, '\n');
			
			if (cin.fail()) {
				cin.clear(); // Clear the error state.
				cin.ignore(INT_MAX, '\n'); // Clear/flush out anything left in buffer.
				cout << "Invalid input! Try again." << endl;
			}
			else if (user_input < 1 || user_input > 30) {
				cout << "Number can only be between 1-30." << endl;
			}
			else {
				is_valid = true;
			}
		} while (!is_valid);

		for (int j = 0; j < user_input; j++) {
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
	return 1;
}