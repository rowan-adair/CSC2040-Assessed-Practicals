#include <iostream>
#include "RandArray.h"


using namespace std;

int main() {

	RandArray x(100, 26);
	x.print_data();

	RandArray* p = new RandArray(50, 11);
	p->print_data();
	delete p;

	RandArray *array1[5];
	RandArray *array2 = new RandArray[5];

	return 0;
}