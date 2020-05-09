#include "RandArray.h"
#include <ctime>
#include <iostream>

using namespace std;

RandArray::RandArray(int len, int max_num) : length(len){
	
	if (len < 0) {
		cout << "Length invalid : " << length << endl;
		exit(-1);
	}
	if (max_num < 1){
		cout << "Max_num must be greater than or equal to 1" << endl; exit(-1);
		exit(-1);
	}
	data = new int[len];

	srand(time(NULL));
	for (int i = 0; i < len; i++)
		data[i] = rand() % max_num;
}


RandArray::RandArray() {
	length = 0;
	data = 0;
}

RandArray::~RandArray(){
	delete[] data;
}

void RandArray::print_data(){
	for (int i = 0; i < length; i++)
		cout << data[i] << endl;
}
