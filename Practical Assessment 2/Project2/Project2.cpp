// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
template <typename T>
T* remove(T*& array, int& array_len, int pos)
{
	// test
	if (!array || array_len < 1) {
		cout << "invalid array" << endl;
		return NULL;
	}
	if (pos < 0 || pos >= array_len) {
		cout << "pos is out of range" << endl;
		return NULL;
	}
	// value to be removed
	T* value_removed = new T();
	*value_removed = array[pos];
	// new array length after removal
	array_len--;
	// new array
	T* temp = new T[array_len];
	for (int i = 0; i < pos; i++) temp[i] = array[i];
	for (int i = pos; i < array_len; i++) temp[i] = array[i + 1];
	// delete original array
	delete[] array;
	// set the new array
	array = temp;
	return value_removed;
}

template <typename T>
void print_array(T* array,  int len) {
	for (size_t i = 0; i < len; i++){
		cout << *array << endl;
		*array++;
	}
}

int main(){
	int array_len = 5;
	string* array = new string[array_len];
	array[0] = "abc";array[1] = "def";array[2] = "ghi";array[3] = "jkl";array[4] = "mno";
	print_array(array, array_len);
	remove(array, array_len, 3);
	cout << endl << "Value at index 3 removed" << endl << endl;
	print_array(array, array_len);
	delete[] array;
	return 0;
}

