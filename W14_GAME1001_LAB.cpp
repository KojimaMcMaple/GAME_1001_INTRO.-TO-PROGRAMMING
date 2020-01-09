#include <iostream>
#include <string>
using namespace std;

class Box {
private:
	double length, width, height;
	static int box_count;
public:
	void SetLength(const double length) {
		this->length = length;
	}
	void SetHeight(const double height) {
		this->height = height;
	}
	void SetWidth(const double width) {
		this->width = width;
	}
	double GetLength() {
		return length;
	}
	double GetHeight() {
		return height;
	}
	//Box b1 + Box b2 = Box b3
	//Box leftSide + Box rightSide 
	Box operator+(Box rightSide) {
		Box combined = Box();

		combined.length = this->length + rightSide.length;
		combined.width = this->width + rightSide.width;
		combined.height = this->height + rightSide.height;

		return combined;
	}

	Box operator*(Box rightSide) {
		Box combined = Box();

		combined.length = this->length * rightSide.length;
		combined.width = this->width * rightSide.width;
		combined.height = this->height * rightSide.height;

		return combined;
	}
	//int num = 10;
	//num--;
	Box operator--(int) {
		Box combined = Box();

		combined.length = this->length - 1;
		combined.width = this->width - 1;
		combined.height = this->height - 1;

		return combined;
	}
	//Summarize()
	string Summarize() {

		return "Length = " + to_string(length)
			+ "\nWidth = " + to_string(width)
			+ "\nHeight = " + to_string(height);
	}

	Box() {
		box_count++;
	}
	Box(double length, double width, double height) {
		this->length = length;
		this->width = width;
		this->height = height;
		box_count++;
	}
};

int Box::box_count = 0;

void task31() {

	Box b1 = Box();
	Box b2 = Box(12, 40, 100);

	//cout << Box::getNumBoxes();
}
Box FindLargestLength(Box list[], int size) {
	double highest = std::numeric_limits<double>::min();
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (list[i].GetLength() > highest) {
			highest = list[i].GetLength();
			index = i;
		}
	}
	return list[index];
}

Box FindSmallestLength(Box list[], int size) {
	double smallest = std::numeric_limits<double>::max();
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (list[i].GetLength() < smallest) {
			smallest = list[i].GetLength();
			index = i;
		}
	}
	return list[index];
}

Box* FindSmallestLen(Box* list_ptr, int size) {
	double smallest = list_ptr[0].GetLength();
	int index = -1;
	Box* result_ptr;
	for (int i = 0; i < size; i++) {
		if (list_ptr[i].GetLength() < smallest) {
			smallest = list_ptr[i].GetLength();
			index = i;
		}
	}
	result_ptr = &list_ptr[index];
	return result_ptr;
}

void Task32() {

	Box b1 = Box(2, 4, 6);
	Box b2 = Box(22, 44, 66);
	Box b3 = Box(23, 42, 61);
	Box b4 = Box(42, 54, 76);
	Box b5 = Box(20, 40, 60);

	const int kBoxSize = 5;

	Box boxes[kBoxSize] = { b1, b2, b3, b4, b5 };
	Box* boxes_ptr = boxes;

	Box maxLength = FindLargestLength(boxes, kBoxSize);
	//cout << maxLength.GetLength();

	Box* smallest_ptr = FindSmallestLen(boxes_ptr, kBoxSize);
	cout << smallest_ptr << endl;
	cout << smallest_ptr->GetHeight() << endl;
	cout << smallest_ptr->Summarize() << endl;
}

void task33() {
	Box b1 = Box(1, 2, 3);
	Box b2 = Box(4, 5, 6);
	Box b3 = b1 + b2; // 5, 7, 9 

	cout << "Box 1: " << b1.Summarize() << endl;
	cout << "Box 2: " << b2.Summarize() << endl;
	cout << "Box 3: " << b3.Summarize() << endl;
}

void task34() {
	Box b1 = Box(1, 2, 3);
	Box b2 = Box(4, 5, 6);
	Box b3 = b1 * b2; // 4, 10, 18 

	cout << "Box 1: " << b1.Summarize() << endl;
	cout << "Box 2: " << b2.Summarize() << endl;
	cout << "Box 3: " << b3.Summarize() << endl;
}
void task35() {
	Box b2 = Box(4, 5, 6);

	cout << "Box 2 before: " << b2.Summarize() << endl;
	Box b3 = b2--;
	cout << "Box 2 after: " << b3.Summarize() << endl;
}

void Task37() {
	string name = "Hideo Kojima";
	string* name_ptr;

	name_ptr = &name;

	cout << *name_ptr << endl;
}

int main111() {
	Task32();

	system("pause");
	return 1;
}