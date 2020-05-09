#include <iostream>
#include <ctime>
#include "LinkedStack.h"
using namespace std;

void randNumStack(LinkedStack<int>& s, int num, int upper) {
	srand((unsigned)NULL);
	for (int i = 0; i < num; i++)
		s.push(std::rand() % upper + 1);
}

void printStack(LinkedStack<int>& s, int num) {
	LinkedStack<int> temp_stack;
	while(!s.isEmpty()){
		int val = *s.pop();
		cout << val << endl;
		temp_stack.push(val);
	}
	while(!temp_stack.isEmpty())
		s.push(*temp_stack.pop());
}

int countNumStack(LinkedStack<int>& s, int lower, int upper) {
	int count = 0;
	LinkedStack<int> temp_stack;
	while (!s.isEmpty()) {
		int val = *s.pop();
		count += (val >= lower && val <= upper) ? 1 : 0;
		temp_stack.push(val);
	}
	while (!temp_stack.isEmpty()) 
		s.push(*temp_stack.pop());
	return count;
}

int main(){
	int num = 1000, upper = 100;
	LinkedStack<int> s;
	randNumStack(s, num, upper);
	cout << countNumStack(s, 0, 100) << endl;
	return 0;
}

