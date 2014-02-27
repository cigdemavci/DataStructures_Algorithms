#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue
{
	public:

		Queue();
		void enqueue(T data);
		T dequeue();

	private:

		LinkedListNode<T>* head;
};

template <class T>
Queue<T>::Queue()
{
	head = NULL;
}

template <class T>
void Queue<T>::enqueue(T data)
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
T Queue<T>::dequeue()
{
	T returnValue = T();

	if(head != NULL)
	{
		returnValue = head->data;

		deleteHead(head);
	}

	return returnValue;
}

#endif