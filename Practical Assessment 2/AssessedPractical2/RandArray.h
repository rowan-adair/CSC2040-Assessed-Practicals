#ifndef RANDARRAY_H
#define RANDARRAY_H
class RandArray
{
public:
	// constructor - allocate data array with length = len, and fill in the array 
	// with random numbers within the range [min, max]
	RandArray(int len, int min, int max);

	RandArray(RandArray& r_arr);

	void operator*=(RandArray& r_arr);


	// destructor - free data array
	~RandArray();
	// print - print values in data array
	void print();

private:
	int* data;	// data array
	int length;	// array length
};
#endif // !RANDARRAY_H