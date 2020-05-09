#include <iostream>
#include <ctime>

using namespace std;

int linearSearch_r(int* a, int value, int N) {
	int res = -1;
	for (int i = N; i > -1; i--) {
		if (a[i] == value) {
			res = i;
			break;
		}
	}
	return res;
}
void testSearch(int res, int val) {
	if (res >= 0)
		cout << "The value " << val << " can be found at " << res << endl;
	else
		cout << "The value " << val << " cannot be found. " << endl;
}


int main()
{
	int sortedArray[] = { 14, 15, 20, 21, 24, 25, 30, 31, 34, 35, 40, 41, 44, 45, 50,51, 64, 65, 70, 71, 74, 75, 80, 84, 84, 84, 90, 91, 94, 95, 100, 101 };
	testSearch(linearSearch_r(sortedArray, -1, 32), -1);
	testSearch(linearSearch_r(sortedArray, 84, 32), 84);


}

