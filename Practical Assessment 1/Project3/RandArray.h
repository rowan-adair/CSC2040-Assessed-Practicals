class RandArray {
private:
	int* data;	// private data, an integer array
	int length;	// private data, length of the data array

public:
	// constructor, which sets length to the given len, allocates memory 
	// for the data array to the given length, and sets all elements of the 
	// array to random numbers within the range [0, max_num - 1], by calling 
	// function rand() % max_num available by #include <iostream>
	RandArray(int len, int max_num);
	RandArray();
	// destructor, to free the memory allocated for the data array
	~RandArray();

	// function, to print the data array
	void print_data();
};