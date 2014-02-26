#ifndef ARRAY_LIST
#define ARRAY_LIST

template <class T>
class ArrayList
{
	public:
		ArrayList(int capacity);
		void add(T newItem);
		T getElementAtIndex(int index);
		T& operator[](int index);

	private:
		int capacity;
		int size;
		T* list;

};

template <class T>
ArrayList<T>::ArrayList(int capacity)
{
	this->capacity = capacity;
	size = 0;
	list = new T[capacity];
}

template <class T>
void ArrayList<T>::add(T newItem)
{
	if(size == capacity)
	{
		T* dummy = list;

		list = new T[capacity*=2];

		for(int i=0; i<size; i++)
		{
			list[i] = dummy[i];
		}

		delete dummy;
	}

	list[size] = newItem;

	size++;
}

template <class T>
T ArrayList<T>::getElementAtIndex(int index)
{
	return list[index];
}

template <class T>
T& ArrayList<T>::operator[](int index)
{
	return list[index];
}

#endif