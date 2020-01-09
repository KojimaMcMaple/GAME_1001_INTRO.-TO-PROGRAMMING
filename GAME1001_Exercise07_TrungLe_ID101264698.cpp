//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	// INIT
	const int kArrSize = 5;
	int marks[kArrSize];
	int sum = 0;
	int max;
	int min;
	double avg;
	bool is_valid_input = false;

	// INPUT
	for (int i = 0; i < kArrSize; i++) {
		do {
			is_valid_input = false;
			cout << "Enter mark for assignment #" << i + 1 << ": ";
			cin >> marks[i];
			cin.ignore(INT_MAX, '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input! Please try again!" << endl;
			}
			else {
				is_valid_input = true;
			}
		} while (!is_valid_input);
	}

	// MIN MAXING
	max = marks[0];
	min = marks[0];
	for (int i = 1; i < kArrSize; i++) {
		if (marks[i] > max) {
			max = marks[i];
		}
		if (marks[i] < min) {
			min = marks[i];
		}
	}

	// SUM
	for (int i = 0; i < kArrSize; i++) {
		sum += marks[i];
	}

	// AVG
	avg = (double)sum / (double)kArrSize;

	// OUTPUT
	cout << fixed << setprecision(2) << "The average mark is: " << avg << endl;
	cout << "The minimum mark is: " << min << endl;
	cout << "The maximum mark is: " << max << endl;

	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***