#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void task19() {
	fstream file;
	string file_name = "meow.txt";
	file.open(file_name, ios::app | ios::in);
	file << "Doing second line" << endl;
	file.close();
}

void task20() {
	fstream file;
	string file_name = "meow.txt";
	file.open(file_name, ios::in);

	string line;

	while (getline(file, line)) {
		cout << line << endl;
		file.seekg(0);
	}

	file.close();
}

bool StrLenIsEven(string line) {
	return (line.size() % 2 == 0);
}

void task21() {
	vector<string> word_arr_odd;
	vector<string> word_arr_even;
	for (int i=1; i < 6; i++) {
		string word;
		cout << "Please enter word #" << i << ": ";
		getline(cin, word);
		if (StrLenIsEven(word)) {
			word_arr_even.push_back(word);
		}
		else {
			word_arr_odd.push_back(word);
		}
	}

	if (!word_arr_even.empty()) {
		fstream file;
		string fname = "even_chars.txt";
		file.open(fname, ios::app | ios::in);
		for (int i = 0; i < word_arr_even.size(); i++) {
			file << word_arr_even[i] << endl;
		}
		file.close();
	}
	
	if (!word_arr_odd.empty()) {
		fstream file;
		string fname = "odd_chars.txt";
		file.open(fname, ios::app | ios::in);
		for (int i = 0; i < word_arr_odd.size(); i++) {
			file << word_arr_odd[i] << endl;
		}
		file.close();
	}
}

class Human {
private:
	double str = 10.0;
	double def = 10.0;
	double sta = 10.0;
public:
	string play_name = "meow";
	string username = "no_username";
	double age = 18.0;

	Human() {};
	Human(string n, double a) {
		play_name = n;
		age = a;
	}
};

class Car {
private:
	string model_code = "AAA";
	bool is_manual = true;
	double top_speed = 500.0;
public:
	string brand = "NULL_BRAND";
	string make = "NULL_MAKE";
	int year = 1111;

	Car() {};
	Car(string b, string m) {
		brand = b;
		make = m;
	}
	Car(string b, string m, int y) {
		brand = b;
		make = m;
		year = y;
	}
};

int main() {
	Human player1 = Human();
	Human player2 = Human("Death", 100);

	system("pause");
	return 1;
}