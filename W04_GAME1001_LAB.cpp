#include <iostream>
#include <string>

#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

void task8() {
	string item_name;
	double price_value;
	double tax_rate_value;
	double tax_from_price;
	double price_after_tax;
	double typecast_test;

	cout << "Enter item name: ";
	getline(cin, item_name); //cin will input first word
	cout << endl;

	cout << "Enter price: ";
	cin >> price_value;
	cout << "\nEnter tax rate (%): ";
	cin >> tax_rate_value;

	tax_from_price = price_value * tax_rate_value / 100;
	price_after_tax = price_value + tax_from_price;

	cout << endl;

	cout << "Using our magical algorithm: " << endl;
	cout << "- Item name is \"" << item_name << "\"" << endl;
	cout << "- Price is $" << price_value << endl;
	cout << "- Tax rate is " << tax_rate_value << "%" << endl;
	cout << "- Total is $" << price_after_tax << endl;
	cout << "- Tax is $" << tax_from_price << endl;
	
	typecast_test = int(price_after_tax);
	cout << "- Typecast is " << typecast_test << endl;
}

int main() {
	cout << "highest = " << numeric_limits<double>::max() << endl;
	cout << "lowest = " << numeric_limits<double>::min() << endl;
	
	//task4();
	cout << '\n'; // '': character output

	//task5();
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
