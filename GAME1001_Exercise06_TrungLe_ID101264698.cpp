#include <iostream>
using namespace std;

class Rectangle {
private:
	double length = 0;
	double width = 0;
public:
	void SetLength(double len) {
		if (len < 0) {
			len = 0;
		}
		length = len;
	}
	void SetWidth(double wid) {
		if (wid < 0) {
			wid = 0;
		}
		width = wid;
	}
	double GetLength() {
		return length;
	}
	double GetWidth() {
		return width;
	}
	double GetArea() {
		return length * width;
	}
	double GetPerimeter() {
		return 2 * (length + width);
	}

	Rectangle() {
		SetLength(1.0);
		SetWidth(1.0);
	}
	Rectangle(double len, double wid) {
		SetLength(len);
		SetWidth(wid);
	}
};

int main() {
	double temp_len;
	double temp_wid;
	bool is_valid_input = false;
	
	Rectangle rect1 = Rectangle();
	cout << "Length of 1st rectangle = " << rect1.GetLength() << endl;
	cout << "Width of 1st rectangle = " << rect1.GetWidth() << endl;
	cout << "Area of 1st rectangle = " << rect1.GetArea() << endl;
	cout << "Perimeter of 1st rectangle = " << rect1.GetPerimeter() << endl;

	cout << endl;

	Rectangle rect2 = Rectangle(20,10);
	cout << "Length of 2nd rectangle = " << rect2.GetLength() << endl;
	cout << "Width of 2nd rectangle = " << rect2.GetWidth() << endl;
	cout << "Area of 2nd rectangle = " << rect2.GetArea() << endl;
	cout << "Perimeter of 2nd rectangle = " << rect2.GetPerimeter() << endl;

	cout << endl;

	Rectangle rect3 = Rectangle();
	do {
		is_valid_input = false;
		cout << "Please enter length of 3rd rectangle: ";
		cin >> temp_len;
		cin.ignore(INT_MAX, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input! Please try again." << endl;
		}
		else {
			is_valid_input = true;
			rect3.SetLength(temp_len);
		}
	} while (!is_valid_input);

	do {
		is_valid_input = false;
		cout << "Please enter width of 3rd rectangle: ";
		cin >> temp_wid;
		cin.ignore(INT_MAX, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input! Please try again." << endl;
		}
		else {
			is_valid_input = true;
			rect3.SetWidth(temp_wid);
		}
	} while (!is_valid_input);
	
	cout << "Length of 3rd rectangle = " << rect3.GetLength() << endl;
	cout << "Width of 3rd rectangle = " << rect3.GetWidth() << endl;
	cout << "Area of 3rd rectangle = " << rect3.GetArea() << endl;
	cout << "Perimeter of 3rd rectangle = " << rect3.GetPerimeter() << endl;

	system("pause");
	return 1;
}