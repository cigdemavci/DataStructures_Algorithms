#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class LinkedListNode
{
	public:

		LinkedListNode(T data);
		LinkedListNode<T>* nodeNext;
		T data;
		void addToTail(T data);
		int nextCount();
		T head();
		T tail();
		void addToTailWithoutDuplication(T data);
		bool flag;
};

template <class T>
T LinkedListNode<T>::tail()
{
	T returnValue = this->data;

	LinkedListNode<T>* temp = NULL;

	if(nodeNext != NULL)
	{
		temp = nodeNext;
	
		while(temp->nodeNext != NULL)
		{
			temp = temp->nodeNext;
		}

		returnValue = temp->data;
	}

	return this->data;
}

template <class T>
T LinkedListNode<T>::head()
{
	return this->data;
}

template <class T>
void deleteHead(LinkedListNode<T>*& head)
{
	if(head != NULL)
	{
		LinkedListNode<T>* temp = head;

		head = head->nodeNext;

		delete temp;
	}
}

template <class T>
T deleteTail(LinkedListNode<T>*& head)
{
	T returnValue = T();

	LinkedListNode<T>* temp = head;

	if(head != NULL)
	{
		if(head->nodeNext == NULL)
		{
			returnValue = head->data;

			LinkedListNode<T>* dummy = head;

			head = NULL;

			delete dummy;

		}
		else
		{
			LinkedListNode<T>* prev = NULL;

			while(temp->nodeNext != NULL)
			{
				prev = temp;
				temp = temp->nodeNext;
			}

			returnValue = temp->data;
			delete temp;

			prev->nodeNext = NULL;
		}
	}

	return returnValue;
}

template <class T>
int LinkedListNode<T>::nextCount()
{
	int count = 1;

	if(nodeNext != NULL)
	{
		LinkedListNode<T>* temp = nodeNext;
		
		count++;

		while(temp->nodeNext != NULL)
		{
			temp = temp->nodeNext;

			count++;
		}
	}

	return count;
}

template <class T>
void LinkedListNode<T>::addToTailWithoutDuplication(T data)
{
	if(this->data != data && nodeNext != NULL)
	{
		LinkedListNode<T>* temp = nodeNext;

		while(temp->data != data && temp->nodeNext != NULL)
		{
			temp = temp->nodeNext;
		}

		if(temp->data != data && temp->nodeNext == NULL)
		{
			temp->nodeNext = new LinkedListNode<T>(data);
		}
	}

	if(this->data != data && nodeNext == NULL)
	{
		nodeNext = new LinkedListNode<T>(data);
	}
}

template <class T>
LinkedListNode<T>::LinkedListNode(T data)
{
	this->data = data;
	nodeNext = NULL;
	flag = false;
}

template <class T>
void LinkedListNode<T>::addToTail(T data)
{
	if(nodeNext == NULL)
	{
		nodeNext = new LinkedListNode<T>(data);
	}
	else
	{
		LinkedListNode<T>* tail = nodeNext;
	
		while(tail->nodeNext != NULL)
		{
			tail = tail->nodeNext;
		}
		
		tail->nodeNext = new LinkedListNode<T>(data);
	}
}

template <class T>
void deleteNode(LinkedListNode<T>*& head, T data)
{
	LinkedListNode<T>* temp = head;

	if(head != NULL && head->data == data)
	{
		head = head->nodeNext;
		delete temp;
		temp = head;
	}

	while(temp != NULL && temp->nodeNext != NULL)
	{
		if(temp->nodeNext->data == data)
		{
			LinkedListNode<T>* dummy = temp->nodeNext;
			temp->nodeNext = temp->nodeNext->nodeNext;

			delete dummy;
		}
		
		temp = temp->nodeNext;
	}

	if(temp != NULL && temp->data == data)
	{
		LinkedListNode<T>* dummy = temp;

		temp = NULL;

		delete dummy;
	}
}

#endif