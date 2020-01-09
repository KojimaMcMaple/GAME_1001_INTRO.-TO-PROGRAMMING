//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// INIT
	int number;
	int sum = 0;

	// INPUT
	cout << "Enter an integer: ";
	cin >> number;

	// PROCESS
	if (number < 0) {
		number = abs(number);
	}
	for (int i = 1; i <= number; i++) {
		sum += i;
	}

	// OUTPUT
	cout << "The sum of all from 1 to " << number << " is: " << sum << endl;

	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***