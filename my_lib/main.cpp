#include <iostream>
#include <string>
#include "HashTable.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

int hashFunction(string key)
{
	int returnValue = 0;

	for(int i=0; i< key.length(); i++)
	{
		returnValue += key[i];
	}

	return returnValue;
}

void stackTest()
{
	Stack<int> stack;

	stack.push(1);
	int top = stack.pop();
	stack.push(2);
	top = stack.pop();
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	top = stack.pop();
	top = stack.pop();
	stack.push(7);
	top = stack.pop();
	stack.push(8);
	top = stack.pop();
	stack.push(9);
	top = stack.pop();

}

void hashTest()
{
		//HASH EXAMPLE
	HashTable<string,string> table;
	table.setHashFunction(hashFunction);

	table.insert("avcisalma","cigdem");
	table.insert("salma","volkan");
	table.insert("salma","metin");
	table.insert("avci","hasan");
	table.insert("avci","hasan");
	table.insert("avci","hasan");

	table.remove("avcisalma","cigdem");
	table.remove("salma","volkan");
	table.remove("salma","metin");
	table.remove("avci","hasan");
	table.remove("avci","hasan");
	table.remove("avci","hasan");
	//HASH EXAMPLE

}

void arrayTest()
{
	ArrayList<int> arrayList(32);
	
	for(int i=0; i<32; i++)
	{
		arrayList.add(i);
	}

	cout << arrayList[31] << endl;

	cout << (arrayList[31] = 102) << endl;

}

void linkedListTest()
{
	LinkedListNode<int>* head = new LinkedListNode<int>(0);

	for(int i=1; i<32; i++)
	{
		head->addToTail(i);
	}

	for(int i=30; i>10; i--)
	{
		deleteNode(head, i);
	}

 	deleteNode(head, 0);
}

void removeDuplicatesLinkedListTest()
{
	LinkedListNode<int>* head = new LinkedListNode<int>(0);

	for(int i=1; i<32; i++)
	{
		head->addToTail(1);
	}

	int count = head->nextCount(); 
	
	for(int i=0; i<count; i++)
	{
		int data = head->head();

		deleteHead(head);

		head->addToTailWithoutDuplication(data);
	}
}

void deleteThis(LinkedListNode<int>*& temp)
{
	while(temp->nodeNext != NULL)
	{
		temp->data = temp->nodeNext->data;

		temp = temp->nodeNext;
	}

	LinkedListNode<int>* dummy = temp;

	temp = NULL;

	delete dummy;
}

void deleteThisTest()
{
	LinkedListNode<int>* head = new LinkedListNode<int>(0);
	LinkedListNode<int>* temp = head;

	for(int i=1; i<10; i++)
	{
		head->addToTail(i);
	}

	for(int i=0; i<5; i++)
	{
		temp = temp->nodeNext;
	}

	cout << "to be deleted : " << temp->data << endl;

	deleteThis(temp);

}

void stringAllUnique(string inString)
{
	unsigned int hashInt1 = 0x0000;
	unsigned int hashInt2 = 0x0000;
	unsigned int hashInt3 = 0x0000;
	unsigned int hashInt4 = 0x0000;
	
	int returnValue = 0;

	for(int i=0;i<inString.length();i++)
	{
		int index = inString[i];



		int hashSwitch = index/32;

		index = index % 32;

		cout << "actual " << inString[i] << endl;
		cout << "switch " << hashSwitch << endl;
		cout << "index  " << index << endl;

		cout << endl;

		unsigned int mask = 0x0001;

		mask = mask << index;

		unsigned int* hashDummy = NULL;

		switch(hashSwitch)
		{
			case 0:
			{
				hashDummy = &hashInt1;
				break;
			}
			case 1:
			{
				hashDummy = &hashInt2;
				break;
			}
			case 2:
			{
				hashDummy = &hashInt3;
				break;
			}
			case 3:
			{
				hashDummy = &hashInt4;
				break;
			}
		}
		unsigned int result = mask & (*hashDummy);

		if(result != 0)
		{
			returnValue = 1;
			break;
		}

		(*hashDummy) = (*hashDummy) | mask;
	}

	if(returnValue != 0)
	{
		cout << "not unique" << endl;
	}
	else
	{
		cout << "unique" << endl;
	}
}

void anagrams(string string1, string string2)
{
	int hash[128];

	int result = 0;

	for(int i=0; i<128; i++)
	{
		hash[i] = 0;
	}

	for(int i=0; i<string1.length(); i++)
	{
		(hash[string1[i]])++;
	}

	for(int i=0; i<string2.length(); i++)
	{
		(hash[string2[i]])--;
	}

	for(int i=0; i<128; i++)
	{
		if(hash[i] != 0)
		{
			result = 1;
			break;
		}
	}

	if(result != 0)
	{
		cout << "not anagrams" << endl;
	}
	else
	{
		cout << "anagrams" << endl;
	}

}

void rotatedCheck(string string1, string string2)
{

	    int result = 1;

		if(string1.length() == string2.length())
		{
			int length = string1.length();
			for(int i=0; i<length;i++)
			{
				if(string2[0] == string1[i])
				{
					int index = 1;

					while((i+index) < length && string2[index] == string1[i+index]) //!!
					{
						index++;
					}

					if(i+index < length)
					{
						continue;
					}
					else
					{
						string str1 = string2.substr(length - i, i); //!!
						string str2 = string1.substr(0, i);

						result = str1.compare(str2);

						if(result == 0)
						{
							break;
						}
					}
				}
			}
		}

		if(!result)
		{
			cout << "rotated" << endl;
		}
		else
		{
			cout << "not rotated" << endl;
		}
}

template <class T>
LinkedListNode<T>* findCircle(LinkedListNode<T>*& head)
{
	LinkedListNode<T>* returnValue = NULL;

	if(head != NULL)
	{
		LinkedListNode<T>* temp = head;

		temp->flag = true;

		while(temp->nodeNext != NULL && temp->nodeNext->flag != true)
		{
			temp->nodeNext->flag = true;
			temp = temp->nodeNext;
		}

		if(temp->nodeNext != NULL && temp->nodeNext->flag == true)
		{
			returnValue = temp->nodeNext;
		}

	}

	return returnValue;
}


void findCircleTest()
{
	LinkedListNode<int>* head = new LinkedListNode<int>(0);

	LinkedListNode<int>* temp = head;

	LinkedListNode<int>* tail = head;

	for(int i=1; i<10; i++)
	{
		head->addToTail(i);
	}

	for(int i=0; i<5; i++)
	{
		temp = temp->nodeNext;
	}

	for(int i=1; i<10; i++)
	{
		tail = tail->nodeNext;
	}

	tail->nodeNext = temp;

	findCircle(head);
}

int main()
{
	stackTest();
	return 0;
}