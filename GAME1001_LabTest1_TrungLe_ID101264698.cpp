#include <iostream>
using namespace std;

int main() {
	double item1_price;
	double item2_price;
	double item3_price;
	double item4_price;
	double item5_price;

	double weekly_pay;
	double sale_rate;

	double item1_after_sale_rate;
	double item2_after_sale_rate;
	double item3_after_sale_rate;
	double item4_after_sale_rate;
	double item5_after_sale_rate;

	double total_pay;
	/*
	item1_price = 299.99;
	item2_price = 89.75;
	item3_price = 189.95;
	item4_price = 150.89;
	item5_price = 429.45;
	*/
	cout << "Enter Item 1 price: ";
	cin >> item1_price;
	cout << "Enter Item 2 price: ";
	cin >> item2_price;
	cout << "Enter Item 3 price: ";
	cin >> item3_price;
	cout << "Enter Item 4 price: ";
	cin >> item4_price;
	cout << "Enter Item 5 price: ";
	cin >> item5_price;

	weekly_pay = 200;
	sale_rate = 9;

	item1_after_sale_rate = item1_price * sale_rate / 100;
	item2_after_sale_rate = item2_price * sale_rate / 100;
	item3_after_sale_rate = item3_price * sale_rate / 100;
	item4_after_sale_rate = item4_price * sale_rate / 100;
	item5_after_sale_rate = item5_price * sale_rate / 100;

	total_pay = weekly_pay + item1_after_sale_rate +
		item2_after_sale_rate +
		item3_after_sale_rate +
		item4_after_sale_rate +
		item5_after_sale_rate;

	cout << endl;
	cout << "ITEM" << "\t\t" << "PRICE" << "\t\t" << "EARNINGS (9%)" << endl;
	cout << "1" << "\t\t" << item1_price << "\t\t" << item1_after_sale_rate << endl;
	cout << "2" << "\t\t" << item2_price << "\t\t" << item2_after_sale_rate << endl;
	cout << "3" << "\t\t" << item3_price << "\t\t" << item3_after_sale_rate << endl;
	cout << "4" << "\t\t" << item4_price << "\t\t" << item4_after_sale_rate << endl;
	cout << "5" << "\t\t" << item5_price << "\t\t" << item5_after_sale_rate << endl;

	cout << endl;
	cout << "Default weekly pay = $" << weekly_pay << endl;
	cout << "TOTAL weekly pay = $" << total_pay << endl;
	cout << endl;

	cout << endl;
	cout << "-Calculations done by Trung Le (Kyle)-" << endl;
	cout << endl;

	system("pause");
	return 1;
}