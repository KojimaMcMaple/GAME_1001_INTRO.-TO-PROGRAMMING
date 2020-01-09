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
	int GetId() {
		return emp_number;
	}
	string GetName() {
		return name;
	}
	double GetHours() {
		return hours;
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
int FindLowestHours(Employee* em_ptr) {
	int result_index = 0;
	double result = em_ptr[result_index].GetWage();
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetHours() < result) {
			result = em_ptr[i].GetHours();
			result_index = i;
		}
	}
	return result_index;
}
Employee* SortEmByHours(Employee in_list[]) {
	Employee temp;
	int lowest_index;
	for (int i = 0; i < EMPLOYEE_SIZE-1; i++) {
		lowest_index = i;
		for (int j = i + 1; j < EMPLOYEE_SIZE; j++) {
			if (in_list[j].GetHours() < in_list[lowest_index].GetHours()) {
				lowest_index = j;
			}
		}
		temp = in_list[i];
		in_list[i] = in_list[lowest_index];
		in_list[lowest_index] = temp;
	}

	return in_list;
}
int FindEmByName(Employee* em_ptr, string in_name) {
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		if (em_ptr[i].GetName() == in_name) {
			return em_ptr[i].GetId();
		}
	}
	return 0;
}
int main() {
	// INIT
	Employee employee_list[EMPLOYEE_SIZE];
	employee_list[0] = Employee(57117, "Kyle", 40.0, 14.0);
	employee_list[1] = Employee(39108, "Maxime", 30.0, 48.2);
	employee_list[2] = Employee(24537, "Heidi", 50.0, 35.9);
	employee_list[3] = Employee(44590, "Liuba", 15.0, 29.6);
	employee_list[4] = Employee(10001, "Sam", 100.0, 60.4);
	employee_list[5] = Employee(10000, "Hideo", 20.0, 100.1);
	Employee* em_ptr = employee_list;

	// OUTPUT
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		cout << em_ptr[i].GetEmployeeData() << endl;
	}

	/*cout << ">>> Highest wage: " << FindHigh(em_ptr).GetNameNWage()<< endl;
	cout << ">>> Lowest wage: " << FindLow(em_ptr).GetNameNWage()<< endl;
	cout << ">>> Average wage: " << to_string(AvgWage(em_ptr))<< endl;
	cout << ">>> Number of employees above average wage: " << to_string(AboveAvg(em_ptr))<< endl;
	cout << ">>> Number of employees below average wage: " << to_string(BelowAvg(em_ptr))<< endl;*/
	
	cout << endl;
	cout << ">>> LAB TEST: 1.Sort Employees by hours worked from low to high: " << endl;
	Employee* sorted_em_by_hrs_ptr = SortEmByHours(employee_list);
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		cout << sorted_em_by_hrs_ptr[i].GetEmployeeData() << endl;
	}

	cout << endl;
	cout << ">>> LAB TEST: 2.Perform a search for a specific employee and return the employee ID if found and 0 if not: " << endl;
	string search_string;
	cout << "Enter employee's name (case-sensitive): ";
	getline(cin, search_string);
	cout << "-> Employee ID is: " << FindEmByName(em_ptr, search_string) << endl;

	cout << endl;
	for (int i = 0; i < EMPLOYEE_SIZE; i++) {
		cout << em_ptr[i].GetEmployeeData() << endl;
	}

	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***