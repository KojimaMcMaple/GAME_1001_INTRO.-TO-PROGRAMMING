//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <cmath>
using namespace std;

double SumOf3(double num_1, double num_2, double num_3) {
	return (num_1 + num_2 + num_3);
}

double ProdOf3(double num_1, double num_2, double num_3) {
	return (num_1 * num_2 * num_3);
}

double AvgOf3(double num_1, double num_2, double num_3) {
	return ((num_1 + num_2 + num_3)/3);
}

double PowerOverwhelming(double base_num, int pow_num) {
	double result;
	result = pow(base_num, pow_num);
	/*
	result = base_num;
	for (int i = 1; i < pow_num; i++) {
		result *= base_num;
	}
	*/
	return result;
}

int main() {
	// INIT
	double number_1;
	double number_2;
	double number_3;
	double base_number;
	int power_number;

	// INPUT
	cout << "Please enter the 1st number: ";
	cin >> number_1;
	cout << "Please enter the 2nd number: ";
	cin >> number_2;
	cout << "Please enter the 3rd number: ";
	cin >> number_3;
	cout << "Please enter the base  number: ";
	cin >> base_number;
	cout << "Please enter the power number: ";
	cin >> power_number;

	// OUTPUT
	cout << "\nUsing our algorithms, the results of your input are: " << endl;
	cout << "- SUMMARY = " << SumOf3(number_1, number_2, number_3) << endl;
	cout << "- PRODUCT = " << ProdOf3(number_1, number_2, number_3) << endl;
	cout << "- AVERAGE = " << AvgOf3(number_1, number_2, number_3) << endl;
	cout << "- POWER = " << PowerOverwhelming(base_number, power_number) << endl;

	system("pause");
	return 0;
}
//***CODES BY TRUNG LE (KYLE)***