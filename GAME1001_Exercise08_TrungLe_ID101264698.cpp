//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	int emp_number;
	string name;
	double hours, pay_rate;
public:
	string GetEmployeeData() {
		return (to_string(emp_number) + "\t" + name + "\t" + to_string(hours) + "\t" + to_string(pay_rate));
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

int main() {
	// INIT
	const int employee_list_size = 4;
	Employee employee_list[employee_list_size];
	employee_list[0] = Employee(57117, "Kyle Hunter", 20.0, 14.0);
	employee_list[1] = Employee(39108, "Maxime Bordes", 30.0, 48.2);
	employee_list[2] = Employee(24537, "Heidi Klinck", 50.0, 35.9);
	employee_list[3] = Employee(10000, "Hideo Kojima", 90.0, 100.1);

	// OUTPUT
	for (int i = 0; i < employee_list_size; i++) {
		cout << employee_list[i].GetEmployeeData() << endl;
	}
	
	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***