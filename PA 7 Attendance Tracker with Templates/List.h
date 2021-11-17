#pragma once
#include "Node.h"

template<class T>
class List
{
private:
	Node<T>* pHead;
	void deleteList(Node<T>* pNode);
public:
	List();
	~List();

	/*Member Functions*/
	bool insertAtFront(T* newData);
	Node<T>* getHeadPtr();
	int getSize();
};

template<class T>
List<T>::List()
{
	pHead = nullptr;
}

template<class T>
void List<T>::deleteList(Node<T>* pNode)
{
	if (pNode != nullptr)
	{
		deleteList(pNode->getNext()); //using recursion to delete the list from the node in the back to the front
		delete pNode; 
	}
}

template<class T>
List<T>::~List()
{
	deleteList(pHead);
}

template<class T>
bool List<T>::insertAtFront(T* newData)
{
	bool success = false;
	Node<T>* pMem = new Node<T>(newData); //allocate new node
	if (pMem != nullptr)
	{
		if (pHead != nullptr)
		{
			pMem->setNext(pHead);
		}
		pHead = pMem;
		success = true;
	}
	return true;
}

template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return pHead;
}

template<class T>
int List<T>::getSize()
{
	int size = 1; //setting it to 1 because we'll be off by one if we start from 0;
	Node<T>* pNode = this->getHeadPtr();
	while (pNode != nullptr)
	{
		size++;
		pNode = pNode->getNext();
	}
	return size;
}