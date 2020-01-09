#include <iostream>
using namespace std;

double SumOf3(double num1, double num2, double num3) {
	double result;
	result = num1 + num2 + num3;
	return result;
}

double ProductOf3(double num1, double num2, double num3) {
	double result;
	result = num1 * num2 * num3;
	return result;
}

double AvgOf3(double num1, double num2, double num3) {
	double result;
	result = SumOf3(num1, num2, num3);
	result /= 3;
	return result;
}

int main() {
	// INITIALIZATION
	double number1;
	double number2;
	double number3;

	double sum_value;
	double product_value;
	double avg_value;

	// INPUT
	cout << "Enter number 1: ";
	cin >> number1;
	cout << "Enter number 2: ";
	cin >> number2; 
	cout << "Enter number 3: ";
	cin >> number3;

	// PROCESS
	sum_value = SumOf3(number1, number2, number3);
	product_value = ProductOf3(number1, number2, number3);
	avg_value = AvgOf3(number1, number2, number3);

	// OUTPUT
	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Calculation is complete. Below is the result:" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Sum of 3 numbers = " << sum_value << endl;
	cout << "Product of 3 numbers = " << product_value << endl;
	cout << "Average of 3 numbers = " << avg_value << endl;

	system("pause");
	return 1;
}