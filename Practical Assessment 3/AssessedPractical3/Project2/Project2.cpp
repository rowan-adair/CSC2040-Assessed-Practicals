#include <iostream>
#include <ctime>
#include "LinkedList.h"
#include "ListNode.h";

using namespace std;

template <typename T>
void array2list(T* array, int num_items, LinkedList<T>& list, int list_p) {
	for (int i = 0; i < num_items; i++){
		list.addAt(list_p, array[i]);
		list_p++;
	}
}

template <typename T>
void printList(LinkedList<T>& list, int list_p, int num_items) {
	for (int i = 0; i < num_items; i++) {
		T* item = list.getAt(list_p + i);
		if (item != NULL) cout << *item << endl;
		else break;
	}cout << endl;
	
	// GET NEXT QUICKER FOR LARGER LISTS
	list.getAt(list_p);
	T* item = list.getNext();
	for (int i = 0; i < num_items; i++) {
		if (item != NULL) cout << *item << endl;
		else break;
		T* item = list.getNext();
	}cout << endl;
}


void setRandIntArray(int* &array, int num, int upper) {
	srand((unsigned)NULL);
	for (int i = 0; i < num; i++)
		array[i] = std::rand() % upper;
}

int main(){
	int num_items = 100, upper = 20;
	int* array_int = new int[num_items];
	setRandIntArray(array_int, num_items, upper);

	LinkedList<int> list;
	int list_p = 50;
	array2list(array_int, num_items, list, list_p);
	printList(list, 50, list.size);

	return 0;
}

