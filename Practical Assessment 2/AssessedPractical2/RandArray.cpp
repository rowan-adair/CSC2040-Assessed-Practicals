#include "RandArray.h"
#include <iostream>

using namespace std;

RandArray::RandArray(int len, int min, int max)
	: length(len)
{
	if (len < 0) {
		data = NULL;
		return;
	}
	else {
		data = new int[length];
		for (int i = 0; i < length; i++)
			data[i] = rand() % (max - min + 1) + min;
	}
}

// COPY CONSTRUCTOR
RandArray::RandArray(RandArray &r_arr)
{
	this->length = r_arr.length;
	this->data = new int[length];	
	for (int i = 0; i < length; i++)
		this->data[i] = r_arr.data[i];
}

// OPERATOR OVERLOADING
void RandArray::operator*=(RandArray& r_arr) {
	int size = (this->length < r_arr.length) ? this->length : r_arr.length;
	for (int i = 0; i < size; i++)
		this->data[i] *= r_arr.data[i];
}

RandArray::~RandArray()
{
	if (data) delete[] data;
}

void RandArray::print()
{
	if (data) {
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
		cout << endl;
	}
}

int* remove(int*& array, int& array_len, int pos)
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
	int* value_removed = new int;
	*value_removed = array[pos];

	// new array length after removal
	array_len--;
	// new array
	int* temp = new int[array_len];
	for (int i = 0; i < pos; i++) temp[i] = array[i];
	for (int i = pos; i < array_len; i++) temp[i] = array[i + 1];

	// delete original array
	delete[] array;
	// set the new array
	array = temp;

	return value_removed;
}
