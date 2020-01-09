#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void task16() {
	string file_name = "meow.txt";
	ofstream file;

	file.open(file_name);

	file << "ONE LINE";

	file.close();

	string fname = "meow.txt";
	ifstream in_file;

	in_file.open(fname);
	string fline;
	getline(in_file, fline);
	cout << fline;
	cout << endl;
	in_file.close();
}

void task17() {
	vector<int> num_v;
	int in_num;
	
	for (int i = 0; i < 6; i++) {
		cout << "Enter num #" << i + 1 << ": ";
		cin >> in_num;
		num_v.push_back(in_num);
	}

	string odd_fname = "odd.txt";
	string even_fname = "even.txt";

	ofstream odd_file;
	ofstream even_file;

	odd_file.open(odd_fname);
	even_file.open(even_fname);

	for (int i = 0; i < num_v.size(); i++) {
		if (num_v[i] % 2 == 0) {
			even_file << num_v[i] << endl;
		}
		else {
			odd_file << num_v[i] << endl;
		}
	}

	odd_file.close();
	even_file.close();
}

void task18() {
	vector<int> odd_v;
	vector<int> even_v;

	int odd_sum = 0;
	int even_sum = 0;

	double odd_avg;
	double even_avg;

	string odd_fname = "odd.txt";
	string even_fname = "even.txt";

	ifstream odd_file;
	ifstream even_file;

	odd_file.open(odd_fname);
	even_file.open(even_fname);

	string fline;

	while (getline(odd_file, fline)) {
		odd_v.push_back(stoi(fline));
	}
	while (getline(even_file, fline)) {
		even_v.push_back(stoi(fline));
	}

	odd_file.close();
	even_file.close();

	for (int i = 0; i < odd_v.size(); i++) {
		odd_sum += odd_v[i];
	}
	for (int i = 0; i < even_v.size(); i++) {
		even_sum += even_v[i];
	}

	odd_avg = double(odd_sum) / double(odd_v.size());
	even_avg = double(even_sum) / double(even_v.size());

	cout << "ODD: " << endl;
	for (int i = 0; i < odd_v.size(); i++) {
		cout << odd_v[i] << endl;
	}
	cout << "sum = " << odd_sum << endl;
	cout << "avg = " << odd_avg << endl;

	cout << endl;

	cout << "EVEN: " << endl;
	for (int i = 0; i < even_v.size(); i++) {
		cout << even_v[i] << endl;
	}
	cout << "sum = " << even_sum << endl;
	cout << "avg = " << even_avg << endl;
}

int main() {
	//task17();
	task18();

	system("pause");
	return 0;
}