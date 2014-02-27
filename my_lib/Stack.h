#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class T>
class Stack
{
	public:
		Stack();
		void push(T data);
		T pop();
		T top();

	private:

		LinkedListNode<T>* head;
};

template <class T>
Stack<T>::Stack()
{
	head = NULL;
}

template <class T>
void Stack<T>::push(T data)
{
	if(head == NULL)
	{
		head = new LinkedListNode<T>(data);
	}
	else
	{
		head->addToTail(data);
	}
}

template <class T>
T Stack<T>::pop()
{
	T returnValue = T();

	if(head != NULL)
	{
		returnValue = deleteTail(head);
	}

	return returnValue;
}

template <class T>
T Stack<T>::top()
{
	return head->tail();
}

#endif