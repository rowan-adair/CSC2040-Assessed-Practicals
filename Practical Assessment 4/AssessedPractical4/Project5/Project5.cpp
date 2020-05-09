#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& v, int first, int last, int value)
{
	sort(v.begin(), v.end());
	if (first > last)
		return -1;
	int mid = (first + last) / 2;
	if (v[mid] == value)
		return mid;
	else if (value < v[mid])
		return binarySearch(v, first, mid - 1, value);
	else
		return binarySearch(v, mid + 1, last, value);
}

int main()
{
	cout << "Data size examples. N = ";
	int N;
	cin >> N;
	
	if (N <= 0) {
		cout << "Invalid array size N = " << N << ". Return 1." << endl;
		return 1;
	}

	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) v.push_back(rand() % 1000);

	clock_t begin = clock();
	cout << "value found at " << binarySearch(v, 0, N - 1, v[N - 1]) << endl;
	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl << endl;

	return 0;
}
