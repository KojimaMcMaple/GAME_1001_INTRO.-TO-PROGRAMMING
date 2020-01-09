#include <iostream>
#include <string>
using namespace std;

int main() {
	int fixed_salary_arr[10] = { 200,  500,  300,  250,  300,  200,  250,  800, 1000,  300 };
	int sales_arr[10] =       { 2000, 1500, 2200, 3800, 2500, 6500, 5000, 2900, 1800, 3500 };
	int total_salary_arr[10] = {};

	int range_200_299 = 0;
	int range_300_399 = 0;
	int range_400_499 = 0;
	int range_500_599 = 0;
	int range_600_699 = 0;
	int range_700_799 = 0;
	int range_800_899 = 0;
	int range_900_999 = 0;
	int range_1000 = 0;

	for (int i = 0; i < 10; i++) {
		total_salary_arr[i] = fixed_salary_arr[i] + sales_arr[i] * 6/100;
		if (total_salary_arr[i] >= 200 && total_salary_arr[i] <= 299) {
			range_200_299++;
		}
		else if (total_salary_arr[i] >= 300 && total_salary_arr[i] <= 399) {
			range_300_399++;
		}
		else if (total_salary_arr[i] >= 400 && total_salary_arr[i] <= 499) {
			range_400_499++;
		}
		else if (total_salary_arr[i] >= 500 && total_salary_arr[i] <= 599) {
			range_500_599++;
		}
		else if (total_salary_arr[i] >= 600 && total_salary_arr[i] <= 699) {
			range_600_699++;
		}
		else if (total_salary_arr[i] >= 700 && total_salary_arr[i] <= 799) {
			range_700_799++;
		}
		else if (total_salary_arr[i] >= 800 && total_salary_arr[i] <= 899) {
			range_800_899++;
		}
		else if (total_salary_arr[i] >= 900 && total_salary_arr[i] <= 999) {
			range_900_999++;
		}
		else if (total_salary_arr[i] >= 1000) {
			range_1000++;
		}
	}

	cout << "Total salary for each employee: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << "[" << total_salary_arr[i] << "] ";
	}
	cout << endl;
	cout << endl;

	cout << ">>> Report based on the total salary <<<" << endl;
	cout << "- " << range_200_299 << " people earned between $200-299" << endl;
	cout << "- " << range_300_399 << " people earned between $300-399" << endl;
	cout << "- " << range_400_499 << " people earned between $400-499" << endl;
	cout << "- " << range_500_599 << " people earned between $500-599" << endl;
	cout << "- " << range_600_699 << " people earned between $600-699" << endl;
	cout << "- " << range_700_799 << " people earned between $700-799" << endl;
	cout << "- " << range_800_899 << " people earned between $800-899" << endl;
	cout << "- " << range_900_999 << " people earned between $900-999" << endl;
	cout << "- " << range_1000 << " people earned between $1000 and over" << endl;

	system("pause");
	return 1;
}