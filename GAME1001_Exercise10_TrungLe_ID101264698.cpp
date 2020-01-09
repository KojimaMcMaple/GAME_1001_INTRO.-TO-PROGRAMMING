//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
using namespace std;

int GetNumOfVowels(char* in_char_ptr, int in_char_size) {
	int result = 0;
	const int vowels_arr_size = 5;
	char vowels_arr[5] = { 'a','e','u','i','o' };

	for (int i = 0; i < in_char_size; i++) {
		for (int j = 0; j < vowels_arr_size; j++) {
			if (in_char_ptr[i] == vowels_arr[j]) {
				result++;
			}
		}
	}
	return result;
}

int main() {
	// INIT
	const int char_arr_size = 50;
	char char_arr[char_arr_size];
	char* char_arr_ptr = char_arr;
	int in_str_size = 0;

	// INPUT
	cout << "Please enter a string: ";
	cin.getline(char_arr, char_arr_size);
	in_str_size = strlen(char_arr);

	// OUTPUT
	cout << "Total number of characters is: " << in_str_size << endl;
	cout << "Total number of vowels is: " << GetNumOfVowels(char_arr_ptr, in_str_size) << endl;

	system("pause");
	return 0;
}
//***CODES BY TRUNG LE (KYLE)***