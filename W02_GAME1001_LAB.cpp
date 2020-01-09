#include<iostream>
using namespace std;

int main() {
	/*
	// FIRST
	cout << "Meow!\n" << "More meows!" << endl;
	//std::cout
	system("pause");
	return 1;
	*/
	// SECOND
	int num1, num11;
	float num2;
	double num3; 
	short num4;
	cout << "Enter ONE int: ";
	cin >> num1;

	cout << "\nEnter ONE float: ";
	cin >> num2;

	cout << "\nEnter ONE double: ";
	cin >> num3;

	cout << "\nEnter ONE short: ";
	cin >> num4;

	cout << "You have entered int number: " << num1 << " , size: "<< sizeof(num1) << " bytes" << endl;
	cout << "\nYou have entered float number: " << num2 << " !?!" << endl;
	cout << "\nYou have entered double number: " << num3 << " !?!" << endl;
	cout << "\nYou have entered short number: " << num4 << " !?!" << endl;
	system("pause");
	return 0;
}
