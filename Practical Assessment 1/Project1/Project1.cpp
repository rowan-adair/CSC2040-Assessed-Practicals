#include "my_functions.h"
#include <iostream>

using namespace std;

int main() {
	
	// Standard Numbers
	most_leat_diff(10, 20, 3);
	// Extreme Values
	most_leat_diff(-2000,1000,34072);
	// All Negative
	most_leat_diff(-1092, -2034, -500);


	int credits = 7;
	int num_admissions = 0;
	while (admission(credits)) num_admissions++;
	cout << "number of admissions " << num_admissions << endl;
	cout << "credit points left " << credits << endl;

	return 0;
}

