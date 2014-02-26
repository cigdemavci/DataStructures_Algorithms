#ifndef HASH_TABLE
#define HASH_TABLE

#include <vector>

using namespace std;

template <class K, class T>
class HashObject
{
	public:
		HashObject(K key, T data);
		K key;
		T data;
		HashObject* next;
};

template <class K, class T>
class HashTable
{
	public:

		HashTable();
		~HashTable();
		bool insert(K key, T data);
		bool remove(K key, T data);
		void empty();
		void setHashFunction(int (*function)(K key));

	private:

		int (*hash)(K key);
		int size;
		vector<HashObject<K,T>*> list;
};

template<class K, class T>
HashObject<K,T>::HashObject(K key, T data)
{
	this->key = key;
	this->data = data;
	this->next = NULL;
}

template<class K, class T>
HashTable<K,T>::HashTable()
{
	size = 1000;
	list.resize(1000,NULL);
}

template<class K, class T>
HashTable<K,T>::~HashTable()
{
	empty();
}

template<class K, class T>
bool HashTable<K,T>::insert(K key, T data)
{
	int index = hash(key);

	if(list[index] == NULL)
	{
		list[index] = new HashObject<K,T>(key,data);
	}
	else
	{
		HashObject<T,K>* current = list[index];

		HashObject<T,K>* previous; 

		while(current != NULL)
		{
			previous = current;
			current = current->next;
		}

		previous->next = new HashObject<K,T>(key,data);
	}
	return true;
}

template<class K, class T>
bool HashTable<K,T>::remove(K key, T data)
{
	int index = hash(key);

	if(list[index] != NULL)
	{

		HashObject<T,K>* current = list[index]; 

		HashObject<T,K>* prev = NULL;

		while(current != NULL )
		{
			if(current->data == data)
			{
				HashObject<T,K>* temp = current;

				if(prev == NULL)
				{
					list[index] = current->next;
				}
				else
				{
					prev->next = current->next;
				}

				current = current->next;

				delete temp;
			}
			else
			{
				prev = current;
				current = current->next;
			}

		}
	}

	return true;
}

template<class K, class T>
void HashTable<K,T>::empty()
{
	for(int i=0;i<size;i++)
	{
		HashObject<K,T>* current = list[i];

		while(current != NULL)
		{
			HashObject<K,T>* temp = current;
			current = current->next;
			delete temp;
		}
	}
}

 template<class K, class T>
void HashTable<K,T>::setHashFunction(int (*function)(K key))
{
	hash = function;
}

#endif