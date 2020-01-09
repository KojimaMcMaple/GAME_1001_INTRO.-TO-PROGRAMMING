//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#define EMPLOYEE_SIZE 6

string PrettifyToString(double in_dou) {
	stringstream stream;
	stream << fixed << setprecision(2) << in_dou;
	return stream.str();
}

class Employee {
private:
	int emp_number;
	string name;
	double hours, pay_rate;
public:
	string GetName() {
		return name;
	}
	double GetWage() {
		return pay_rate * hours;
	}
	string GetEmployeeData() {
		return (to_string(emp_number) + "\t" + name 
			+ "\tHours:" + PrettifyToString(hours) 
			+ "\tRate:" + PrettifyToString(pay_rate) 
			+ "\tWage:" + PrettifyToString(GetWage()));
	}
	string GetNameNWage() {
		return (name + "\t" + PrettifyToString(GetWage()));
	}
	Employee() {
		emp_number = 0;
		name = "Name";
		hours = 0;
		pay_rate = 0;
	}

	Employee(int emp_number, string name, double hours, double pay_rate) {
		this->emp_number = emp_number;
		this->name = name;
		this->hours = hours;
		this->pay_rate = pay_rate;
	}
};

Employee FindHigh(Employee* em_ptr) {
	int result_index = 0;
	double result = em_ptr[result_index].GetWage();
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetWage() > result) {
			result = em_ptr[i].GetWage();
			result_index = i;
		}
	}
	return em_ptr[result_index];
}
Employee FindLow(Employee* em_ptr) {
	int result_index = 0;
	double result = em_ptr[result_index].GetWage();
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetWage() < result) {
			result = em_ptr[i].GetWage();
			result_index = i;
		}
	}
	return em_ptr[result_index];
}
double AvgWage(Employee* em_ptr) {
	double result = 0;
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		result += em_ptr[i].GetWage();
	}
	return result / EMPLOYEE_SIZE;
}
int AboveAvg(Employee* em_ptr) {
	int result = 0;
	double avg = AvgWage(em_ptr);
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetWage() > avg) {
			result++;
		}
	}
	return result;
}
int BelowAvg(Employee* em_ptr) {
	int result = 0;
	double avg = AvgWage(em_ptr);
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetWage() < avg) {
			result++;
		}
	}
	return result;
}

int main() {
	// INIT
	Employee employee_list[EMPLOYEE_SIZE];
	employee_list[0] = Employee(57117, "Kyle Hunter", 20.0, 14.0);
	employee_list[1] = Employee(39108, "Maxime Bordes", 30.0, 48.2);
	employee_list[2] = Employee(24537, "Heidi Klinck", 50.0, 35.9);
	employee_list[3] = Employee(44590, "Liuba Cuzacov", 52.2, 29.6);
	employee_list[4] = Employee(10001, "Sam Bridges", 70.1, 60.4);
	employee_list[5] = Employee(10000, "Hideo Kojima", 90.9, 100.1);
	Employee* em_ptr = employee_list;

	// OUTPUT
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		cout << em_ptr[i].GetEmployeeData() << endl;
	}

	cout << ">>> Highest wage: " << FindHigh(em_ptr).GetNameNWage()<< endl;
	cout << ">>> Lowest wage: " << FindLow(em_ptr).GetNameNWage()<< endl;
	cout << ">>> Average wage: " << to_string(AvgWage(em_ptr))<< endl;
	cout << ">>> Number of employees above average wage: " << to_string(AboveAvg(em_ptr))<< endl;
	cout << ">>> Number of employees below average wage: " << to_string(BelowAvg(em_ptr))<< endl;
	
	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***