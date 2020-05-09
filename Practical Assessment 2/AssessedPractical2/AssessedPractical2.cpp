#include "Shape.h"
#include "RandArray.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {

	RandArray x(10, -5, 5);
	// print x three times
	for (int n = 0; n < 3; n++) {
		RandArray y = x;
		y.print();
	}
	cout << endl;
	x.print();
	x *= x;
	x.print();

	return 0;
}