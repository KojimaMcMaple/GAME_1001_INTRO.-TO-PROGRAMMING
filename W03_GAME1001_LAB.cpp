#include <iostream>
#include <string>
using namespace std;

void task4() {
	string very_friendly_message;

	very_friendly_message = "This is a very friendly message !!!"; // "": string output
	cout << very_friendly_message << endl;
}

void task5() {
	string feel_message1;
	string feel_message2;

	feel_message1 = "I feel despair."; // "": string output
	feel_message2 = "Because the class takes too long to be interesting."; // "": string output
	cout << feel_message1 << endl << feel_message2 << endl;
}

void task6() {
	float height_value;
	float weight_value;
	int age_value;

	cout << "Enter your height: ";
	cin >> height_value;
	cout << "\nEnter your weight: ";
	cin >> weight_value;
	cout << "\nEnter your age: ";
	cin >> age_value;

	cout << endl;

	cout << "Using our magical algorithm: " << endl;
	cout << "- Your age is " << age_value << endl;
	cout << "- Your weight is " << weight_value << endl;
	cout << "- Your height is " << height_value << endl;
}

void signed_unsigned() {
	char letter1, letter2, letter3; //default: UNSIGNED
	letter1 = 'a';
	letter2 = 69;
	letter3 = 'agz';

	cout << letter1 << endl;
	cout << letter2 << endl;
	cout << letter3 << endl;
	cout << UCHAR_MAX << endl;
	cout << SCHAR_MAX << endl;
	cout << SCHAR_MIN << endl;
}

void task7() {
	unsigned short number1;
	double number2; //default: SIGNED

	cout << "Enter first number: ";
	cin >> number1;
	cout << "\nEnter second number: ";
	cin >> number2;

	cout << endl;

	cout << "Using our magical algorithm: " << endl;
	cout << "- First number is " << number1 << endl;
	cout << "- Second number is " << number2 << endl;
	cout << "- Sum is " << number1 + number2 << endl;
	cout << "- Dif is " << number1 - number2 << endl;
}

void task8() {
	float price_value;
	float tax_rate_value;
	float tax_from_price;
	float price_after_tax;

	cout << "Enter price: ";
	cin >> price_value;
	cout << "\nEnter tax rate (%): ";
	cin >> tax_rate_value;

	tax_from_price = price_value * tax_rate_value / 100;
	price_after_tax = price_value + tax_from_price;

	cout << endl;

	cout << "Using our magical algorithm: " << endl;
	cout << "- Price is $" << price_value << endl;
	cout << "- Tax rate is " << tax_rate_value << "%" << endl;
	cout << "- Total is $" << price_after_tax << endl;
	cout << "- Tax is $" << tax_from_price << endl;
}

int main() {
	task4();
	cout << '\n'; // '': character output

	task5();
	cout << '\n'; // '': character output

	//task6();
	cout << '\n'; // '': character output

	//task7();
	cout << '\n'; // '': character output

	task8();
	cout << '\n'; // '': character output

	system("pause");
	return 1;
}
