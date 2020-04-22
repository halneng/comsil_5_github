#ifndef __LINK__
#define __LINK__

#include <iostream>
using namespace std;


// Linked List Node
template <class T>
class Node
{
	public:
		T data;
		Node *link;
		Node(T element)
		{
			data = element;
			link = 0;
		}
};

// Linked List Class
template <class T>
class LinkedList
{
	protected:
		Node<T> *first;
		int current_size;
	public:
		LinkedList();
		int GetSize(); // 리스트의 노드 개수를 리턴
		void Insert(T element); // 맨 앞에 원소를 삽입
		virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제
		void Print(); // 리스트를 출력
};

template <class T>
LinkedList<T>::LinkedList()
{
        first = 0;
        current_size = 0;
}

template <class T>
int LinkedList<T>::GetSize()
{
        return current_size;
}

template <class T>
void LinkedList<T>::Insert(T element)
{
	Node<T> *newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <class T>
bool LinkedList<T>::Delete(T &element)
{
        if(first == 0)
                return false;
        Node<T> *current = first;
        Node<T> *previous = NULL;
        while(1)
        {
	        if(current->link == 0) // node의 끝 찾기
	        {
	        	if(previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
        }
	element = current->data;
	delete current;
	current_size--;
	return true;
}

template <class T>
void LinkedList<T>::Print()
{
        if(first == 0)
	        return;
	Node<T> *current = first;
	int i = 1;
	while(current != 0)
		{
			if(i == 1)
			{
				cout << "[" << i << "|" << current -> data << "]";
			}
			else
			{
				cout << "->[" << i << "|" << current -> data << "]";
		        }
		        i++;
		        current = current -> link;
		}
	cout << endl;
}

#endif
