#ifndef STACKNODE_H
#define STACKNODE_H

template <typename T>
class StackNode
{
public:
	StackNode(T i, StackNode<T>* nxt);
	~StackNode() {};

	T item;
	StackNode<T>* next;

private:
};

template <typename T>
StackNode<T>::StackNode(T i, StackNode<T>* nxt)
	: item(i), next(nxt)
{
}

#endif
