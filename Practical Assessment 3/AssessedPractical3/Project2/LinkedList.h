#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void addAtFront(T item);
	void addAtEnd(T item);
	void addAt(int p, T i);

	T* removeAtFront();
	T* removeAtEnd();
	T* removeAt(int p);

	T* getAtFront();
	T* getAtEnd();
	T* getAt(int p);

	void setAtStart();
	void setAtEnd();

	T* getNext();
	T* getPrevious();

	int size;	// current number of items in the list

private:
	ListNode<T> *first, *current, *last;	// pointers to the 1st, current & last node in the link
	ListNode<T>* findAt(int p);	// return pointer to the node at location p
	T temp_item;	// storage, for the item to return 
};

template <typename T>
LinkedList<T>::LinkedList()
{
	first = current = last = NULL;
	size = 0;
}

template <typename T>
ListNode<T>* LinkedList<T>::findAt(int p)
{
	if (p < 0 || p >= size) {
		cout << "List item does not exist at position " << p << endl;
		return NULL;
	}
	int n = 0;
	ListNode<T>* ptr = first;
	while (n < p && ptr != NULL) {
		ptr = ptr->next;
		n++;
	}
	if (ptr == NULL)
		cout << "List item does not exist at position " << p << endl;
	return ptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* l = first;
	while (l != NULL) {
		ListNode<T>* n = l->next;
		delete l;
		l = n;
	}
}

template <typename T>
void LinkedList<T>::addAtFront(T item)
{
	ListNode<T>* l = new ListNode<T>(item, NULL, first);
	if (first != NULL) first->previous = l;
	first = l;
	if (last == NULL)
		last = l;
	size += 1;
}

template <typename T>
void LinkedList<T>::addAtEnd(T item)
{
	if (size == 0)
		addAtFront(item);
	else {
		ListNode<T> *l = new ListNode<T>(item, last, NULL);
		last->next = l;
		last = l;
		size++;
	}
}

template <typename T>
void LinkedList<T>::addAt(int p, T i)
{
	if (p == 0)
		addAtFront(i);
	else if (p == size)
		addAtEnd(i);
	else {
		ListNode<T>* temp = findAt(p);
		if (temp != NULL) {
			ListNode<T>* l = new ListNode<T>(i, temp->previous, temp);
			temp->previous->next = l;
			temp->previous = l;
			size++;
		}
	}
}

template <typename T>
T* LinkedList<T>::removeAtFront()
{
	if (size == 0) {
		cout << "No item to be removed at front of list" << endl;
		return NULL;
	}
	temp_item = first->item;
	ListNode<T>* temp = first;
	if (first->next != NULL)
		first->next->previous = NULL;
	first = first->next;
	size--;
	if(size == 0) last = NULL;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::removeAtEnd()
{
	if (size == 0) {
		cout << "No item to be removed at end of list" << endl;
		return NULL;
	}
	temp_item = last->item;
	ListNode<T>* temp = last;
	if (last->previous != NULL)
		last->previous->next = NULL;
	last = last->previous;
	size--;
	if (size == 0) first = NULL;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::removeAt(int p)
{
	if (p < 0 || p >= size) {
		cout << "No item to be removed at list position " << p << endl;
		return NULL;
	}
	if (p == 0)
		return removeAtFront();
	if (p == size - 1)
		return removeAtEnd();
	// Otherwise...
	ListNode<T>* temp = findAt(p);
	temp_item = temp->item;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	size--;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::getAt(int p)
{
	if (p < 0 || p >= size) return NULL;

	if (p == 0)
		return getAtFront();
	if (p == size - 1)
		return getAtEnd();
	// Otherwise...
	ListNode<T>* temp = findAt(p);
	current = temp;
	return &current->item;
}

template <typename T>
T* LinkedList<T>::getAtFront()
{
	if (size > 0) {
		current = first;
		return &first->item;
	}
	return NULL;
}

template <typename T>
T* LinkedList<T>::getAtEnd()
{
	if (size > 0) {
		current = last;
		return &last->item;
	}
	return NULL;
}

template <typename T>
void LinkedList<T>::setAtStart()
{
	current = first;
}

template <typename T>
void LinkedList<T>::setAtEnd()
{
	current = last;
}

template <typename T>
T* LinkedList<T>::getNext()
{
	if (current != NULL) {
		ListNode<T> *temp = current;
		current = current->next;
		return &temp->item;
	}
	return NULL;
}

template <typename T>
T* LinkedList<T>::getPrevious()
{
	if (current != NULL) {
		ListNode<T> *temp = current;
		current = current->previous;
		return &temp->item;
	}
	return NULL;
}

#endif
