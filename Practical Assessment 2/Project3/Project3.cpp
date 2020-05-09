#include <iostream>
#include "Shape.h"

using namespace std;

int main(){
	Shape* base_ptr;
	int choice;
	bool valid;
	do {
		valid = true;
		cout << "Choose a shape to calculate : " << endl;
		cout << "1. Rectangle" << endl;
		cout << "2. Circle" << endl;
		cout << "3. Right Angle Triangle" << endl;
		cout << "Enter choice:";
		cin >> choice;
		switch (choice){
		case 1:
			base_ptr = new Rectangle();
			break;
		case 2:
			base_ptr = new Circle();
			break;
		case 3:
			base_ptr = new Rt_Triangle();
			break;
		default:
			valid = false;
			break;
		}
	} while (!valid);
	
	base_ptr->read_shape_data();
	base_ptr->compute_area();
	base_ptr->compute_perimeter();
	base_ptr->print_result();

	return 0;
}

