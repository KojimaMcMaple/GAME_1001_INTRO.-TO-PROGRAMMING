#include <iostream>
#include <ctime>
#include <string>
using namespace std;

void task15() {
	int arr_num[5];
	int sum_val = 0;
	int prod_val = 1;

	cout << "Enter 1st number: ";
	cin >> arr_num[0];
	cout << "Enter 2nd number: ";
	cin >> arr_num[1];
	cout << "Enter 3rd number: ";
	cin >> arr_num[2];
	cout << "Enter 4th number: ";
	cin >> arr_num[3];
	cout << "Enter 5th number: ";
	cin >> arr_num[4];

	for (int i = 0; i < 5; i++) {
		sum_val += arr_num[i];
		prod_val *= arr_num[i];
	}

	cout << "Sum of 5 numbers is: " << sum_val << endl;
	cout << "Prod of 5 numbers is: " << prod_val << endl;
}

void task16() {
	int ran_num;
	int player_num;
	bool is_endgame = false;

	srand(time(NULL));
	ran_num = 1 + rand() % 100;

	do {
		cout << "Enter your guess[1-100]: ";
		cin >> player_num;

		if (player_num > ran_num) {
			cout << "Guess is too high!" << endl;
		}
		else if (player_num < ran_num) {
			cout << "Guess is too low!" << endl;
		}
		else {
			is_endgame = true;
			cout << "GUESS IS CORRECT!" << endl;
		}
	} while (!is_endgame);
}

// PRIME NUMBER CALCULATOR
void task17() {
	int user_num;
	bool exit_program;
	bool is_prime;
	float remainder_val;
	string user_answer;

	do {
		exit_program = false;
		is_prime = true;
		cout << "Enter a number to determine if it's prime: ";
		cin >> user_num;

		for (int i = 2; i < user_num; i++) {
			remainder_val = user_num % i;
			if (remainder_val == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			cout << user_num << " IS A PRIME NUMBER!" << endl;
		}
		else {
			cout << user_num << " is not a prime number." << endl;
		}

		cout << "Do you want to continue? (y/n): ";
		cin >> user_answer;

		if (user_answer.compare("n") == 0) {
			exit_program = true;
		}
	} while (!exit_program);

}

int main() {
	task17();

	system("pause");
	return 1;
}