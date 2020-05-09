#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int* a, int N) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

int main1(){
	// read the array size
	cout << "Array size example.N = ";
	int N = 0;
	cin >> N;
	if (N <= 0) return 1;

	// create an array of N random integers
	int* array = new int[N];
	srand((unsigned)time(NULL));
	for (int n = 0; n < N; n++)
		array[n] = rand() % 10000;
	// your code to test the algorithm using the array goes here...
	bubbleSort(array, N);
	return 0;
}

int main() {
	for (int i = 5000; i <= 30000; i+=5000){

		int* array = new int[i];
		srand((unsigned)time(NULL));
		for (int n = 0; n < i; n++)
			array[n] = rand() % 10000;

		clock_t begin = clock();
		bubbleSort(array, i);
		clock_t end = clock();

		double elapsed = double(end - begin);
		cout << "Array of " <<  i << " elements sorted." << "Time taken = " << elapsed << " ms = " << elapsed / 1000.0 << " s" << endl;
	}
	return 0;
}

