#pragma once
#include "Node.h"

template <class T>
class Stack
{
private:
	vector<T> stack;
		
public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(const T& newData);
	void pop();
	T peek();

	/*Deep copy assignment operator*/
	Stack<T>& operator= (const Stack& rhs);
};

template<class T>
Stack<T>::Stack()
{
	//implicit
}

template<class T>
Stack<T>::~Stack()
{
	stack.clear();
}

template<class T>
bool Stack<T>::isEmpty()
{
	return stack.empty();
}

template<class T>
void Stack<T>::push(const T& newData)
{
	stack.push_back(newData);
}

template<class T>
void Stack<T>::pop()
{
	stack.pop_back();
}

template<class T>
T Stack<T>::peek()
{
	return stack.back();
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
	for (int i = 0; i < stack.size(); ++i)
	{
		this->stack.push_back(rhs.stack.at(i)); //deep copy assignment
	}
	return *this;
}