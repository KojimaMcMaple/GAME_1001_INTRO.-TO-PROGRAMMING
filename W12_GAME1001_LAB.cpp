#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Human {
private:
	double str = 10.0;
	double def = 10.0;
	double sta = 10.0;
public:
	string play_name = "meow";
	string username = "no_username";
	double age = 18.0;

	double GetAge() {
		return age;
	}
	void SetAge(double age) {
		if (age > 0) {
			this->age = age;
		}
	}

	double GetStr() {
		return str;
	}
	void SetStr(double str) {
		if (str > 0 && str < 100) {
			this->str = str;
		}
	}

	double GetDef() {
		return def;
	}
	void SetDef(double def) {
		if (def > 0 && def < 100) {
			this->def = def;
		}
	}

	double GetSta() {
		return sta;
	}
	void SetSta(double sta) {
		if (sta > 0 && sta < 100) {
			this->sta = sta;
		}
	}

	string GetSummary() {
		return to_string(str) + '\n' + to_string(def) + '\n' + to_string(sta) + '\n' + play_name + '\n' + username + '\n' + to_string(age);
	}

	//Human() {};
	Human(string n, double a) {
		play_name = n;
		age = a;
	}
	Human(string play_name = "meow", string username = "no_username", double age = 18.0,
		double str = 10.0, double def = 10.0, double sta = 10.0) {
		this->play_name = play_name;
		this->username = username;
		this->age = age;
		this->str = str;
		this->def = def;
		this->sta = sta;
	}
	~Human() {
		cout << "No more Human." << endl;
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

class CustomFileClass {
private:
	int read_requests = 0;
	int write_requests = 0;
	fstream file_stream;
	string full_file_path;

	void _CloseFileStream() {
		file_stream.close();
	}
public:
	string read_line;
	string write_line;

	void SetFullFilePath(string full_file_path) {
		this->full_file_path = full_file_path;
	}
	bool IsFile() {
		bool result;
		file_stream.open(full_file_path, ios::in);
		result = file_stream.good();
		_CloseFileStream();
		return result;
	}
	int GetLineCount() {
		int result = 0;
		file_stream.open(full_file_path, ios::in);
		while (getline(file_stream, read_line)) {
			result++;
		}
		_CloseFileStream();
		return result;
	}
	string GetFileExtension() {
		string result;
		int found = full_file_path.find_last_of(".");
		if (found != -1) {
			result = full_file_path.substr(found, full_file_path.size() - found);
			_CloseFileStream();
			return result;
		}
		_CloseFileStream();
		return "NULL";
	}
	string GetFileName() {
		string result;
		int found_slash = full_file_path.find_last_of("\//");
		if (found_slash == -1) {
			found_slash = 0;
		}
		int found_dot = full_file_path.find_last_of(".");
		if (found_dot) {
			result = full_file_path.substr(found_slash, found_dot - found_slash);
			_CloseFileStream();
			return result;
		}
		_CloseFileStream();
		return "NULL";
	}
	string GetFullFileName() {
		return GetFileName() + GetFileExtension();
	}

	CustomFileClass() {}
	/*
	~CustomFileClass() {
		file_stream.close();
	}
	*/
};

int main() {
	/*
	Human player1 = Human();
	Human player2 = Human("Death", 100);

	cout << player1.GetSummary() << endl;
	cout << player2.GetSummary() << endl;
	*/
	CustomFileClass file1;
	file1.SetFullFilePath("meow.txt");

	cout << file1.GetFullFileName() << endl;

	system("pause");
	return 1;
}