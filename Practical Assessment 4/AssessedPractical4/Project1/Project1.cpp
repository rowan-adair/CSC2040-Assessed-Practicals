#include <iostream>
#include <ctime>

using namespace std;

double func(int N) {
	double total = 0.;
	for (int i = 0; i < N; i++)
		total += i * N;
	cout << "The total is " << total << endl;
	cout << "The complexity of this loop structure is O(n)" << endl;
	return total;
}


int main(){
	int M = 100; // for example
	for (int N = 0; N < M; N++)
		cout << func(N) << endl;
	cout << "The complexity of this loop structure is O(N^2)" << endl;
}

