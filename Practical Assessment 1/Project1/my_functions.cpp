#include "my_functions.h"

#include <iostream>

using namespace std;

void most_leat_diff(double a, double b, double c)
{

	double max_diff_num1;
	double max_diff_num2;

	if (fabs(a - b) > fabs(b - c) && fabs(a - b) > fabs(a - c)){
		max_diff_num1 = a;
		max_diff_num2 = b;
	}
	else if (fabs(b - c) > fabs(a - b) && fabs(b - c) > fabs(a - c)){
		max_diff_num1 = b;
		max_diff_num2 = c;
	}
	else {
		max_diff_num1 = a;
		max_diff_num2 = c;
	}
	
	double min_diff_num1;
	double min_diff_num2;

	if (fabs(a - b) < fabs(b - c) && fabs(a - b) < fabs(a - c)) {
		min_diff_num1 = a;
		min_diff_num2 = b;
	}
	else if (fabs(b - c) < fabs(a - b) && fabs(b - c) < fabs(a - c)) {
		min_diff_num1 = b;
		min_diff_num2 = c;
	}
	else {
		min_diff_num1 = a;
		min_diff_num2 = c;
	}


	double max_diff = fabs(max_diff_num1 - max_diff_num2);
	double min_diff = fabs(min_diff_num1 - min_diff_num2);
	
	cout << "Most different: " << max_diff_num1 << " " << max_diff_num2 << " with difference = " << max_diff << endl;
	cout << "Least different: " << min_diff_num1 << " " << min_diff_num2 << " with difference = " << min_diff << endl;

}

bool admission(int& credit)
{
	if (credit >= 3) {
		credit -= 3;
		return true;
	}
	return false;
}
