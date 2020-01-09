#include <iostream>
using namespace std;

int main() {
	// INIT
	double hoursWorked;
	double hourlyRate;

	double remainingHoursWorked;

	double regularPay;
	double overtimePay;
	double totalPay;

	// INPUT
	cout << "Enter the hours worked: ";
	cin >> hoursWorked;
	cout << "Enter the hourly rate: $";
	cin >> hourlyRate;

	// PROCESSING
	overtimePay = 0;
	if (hoursWorked <= 40) {
		regularPay = hourlyRate * hoursWorked;
	}
	else {
		regularPay = hourlyRate * 40;

		remainingHoursWorked = hoursWorked - 40;
		overtimePay = hourlyRate * remainingHoursWorked * 1.5;
	}
	totalPay = regularPay + overtimePay;

	// OUTPUT
	cout << endl;
	cout << "Regular pay is $" << regularPay << endl;
	cout << "Overtime pay is $" << overtimePay << endl;
	cout << "Total pay is $" << totalPay << endl;
	cout << endl;

	cout << endl;
	cout << "- Calculations done by Trung Le (Kyle) -";
	cout << endl;
}