#include <iostream>
#include <string>

#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

void task9() {
	string item_name;
	double price_value;
	double tax_rate_value;
	double tax_from_price;
	double price_after_tax;
	double typecast_test;

	cout << "Enter item name: ";
	getline(cin, item_name); //cin will input first word
	if (item_name.size() < 5) {
		item_name = "DEFAULT";
		cout << "INVALID INPUT! Defaulting to " << item_name << ".";
	}
	//name = name.size() < 5 ? "DEFAULT" : item_name;

	cout << endl;

	cout << "Enter price: ";
	cin >> price_value;
	if (price_value < 1) {
		price_value = 1;
		cout << "INVALID INPUT! Defaulting to " << price_value << ".";
	}
	cout << "\nEnter tax rate (%): ";
	cin >> tax_rate_value;
	if (tax_rate_value < 5) {
		tax_rate_value = 5;
		cout << "INVALID INPUT! Defaulting to " << tax_rate_value << ".";
	}
	

	tax_from_price = price_value * tax_rate_value / 100;
	price_after_tax = price_value + tax_from_price;

	cout << endl;

	cout << "Using our magical algorithm: " << endl;
	cout << left << setw(20) << "Item Name";
	cout << right << setw(10) << "Price";
	cout << right << setw(10) << "Tax Rate";
	cout << right << setw(10) << "Tax";
	cout << right << setw(10) << "Total";
	cout << endl;

	cout << left << setw(20) << item_name;
	cout << right << setw(10) << fixed << showpoint << setprecision(2) << price_value;
	cout << right << setw(10) << fixed << showpoint << setprecision(2) << tax_rate_value;
	cout << right << setw(10) << fixed << showpoint << setprecision(2) << tax_from_price;
	cout << right << setw(10) << fixed << showpoint << setprecision(2) << price_after_tax;
	cout << endl;
	/*
	typecast_test = int(price_after_tax);
	cout << "- Typecast is " << typecast_test << endl;
	*/
}

void task10() {
	cout << "BEGIN" << endl;
	for (int i = 0; i < 101; i += 5) {
		cout << i << endl;
	}
	cout << "END" << endl;
}

void task11() {
	cout << "BEGIN" << endl;
	for (int i = 100; i > -1; i -= 4) {
		cout << i << endl;
	}
	cout << "END" << endl;
}

void task12() {
	cout << "BEGIN" << endl;
	for (int i = 2; i < 257; i *= 2) {
		cout << i << endl;
	}
	cout << "END" << endl;
}

void task13() {
	string in_str;
	
	cout << "Enter a string to know its ASCII: ";
	getline(cin, in_str);

	cout << left << setw(10) << "Chars";
	cout << right << setw(10) << "ASCII";
	cout << endl;

	for (int i = 0; i < in_str.size(); i++) {
		cout << left << setw(10) << in_str[i];
		cout << right << setw(10) << int(in_str[i]);
		cout << endl;
	}
}

void task14() {
	int first_num;
	int second_num;
	int third_num;

	cout << "Enter 1st number: ";
	cin >> first_num;
	
	cout << "Enter 2nd number: ";
	cin >> second_num;

	cout << "Enter 3rd number as incremental: ";
	cin >> third_num;

	cout << endl;
	cout << "BEGIN" << endl;
	if (second_num > first_num) {
		for (int i = first_num; i <= second_num; i += third_num) {
			cout << i << endl;
		}
	}
	else {
		for (int i = first_num; i > second_num; i -= third_num) {
			cout << i << endl;
		}
	}
	cout << "END" << endl;
}

int main111() {
	//cout << "highest = " << numeric_limits<double>::max() << endl;
	//cout << "lowest = " << numeric_limits<double>::min() << endl;

	//task4();
	//cout << '\n'; // '': character output

	//task5();
	//cout << '\n'; // '': character output

	//task6();
	//cout << '\n'; // '': character output

	//task7();
	//cout << '\n'; // '': character output

	//task9();
	//cout << '\n'; // '': character output
	/*
	task10();
	cout << endl;

	task11();
	cout << endl;

	task12();
	cout << endl;

	task13();
	cout << endl;
	*/
	task14();
	cout << endl;

	system("pause");
	return 1;
}
