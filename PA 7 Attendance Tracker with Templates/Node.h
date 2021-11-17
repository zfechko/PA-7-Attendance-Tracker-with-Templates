#pragma once
#include "libraries.h"

template<class T>
class Node
{
private:
	T* data;
	Node<T>* pNext;
public:
	Node(T* newData);
	~Node();
	Node<T>* getNext();
	void setNext(Node<T>* newNode);
	T* getData();
};

template<class T>
Node<T>::Node(T* newData)
{
	data = newData;
	pNext = nullptr;
}

template<class T>
Node<T>::~Node()
{
	delete data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return pNext;
}

template<class T>
void Node<T>::setNext(Node<T>* newNode)
{
	pNext = newNode;
}

template<class T>
T* Node<T>::getData()
{
	return data;
}