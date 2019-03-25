/**
  * File      :   Queue_LinkedList.h
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _QUEUE_LINKEDLIST_H
#define _QUEUE_LINKEDLIST_H

#include "LinkedList.h"
using namespace std;

// Queue_LinkedList template
template <typename T>
class Queue_LinkedList {
private:
	LinkedList<T> list;	// a singly linked list
public:
	// Constructor and destructor is not needed because the complier will call the
	// constructor of the LinkedList class when Queue_LinkedList is constructed
	bool empty();
	T front();
	void push(T);
	T pop();
};

// Empty and Push functions just call the appropriate functions
// of LinkedList class
template <typename T>
bool Queue_LinkedList<T>::empty() {
	return list.empty();
}

template <typename T>
void Queue_LinkedList<T>::push(T obj) {
	list.appendNode(obj);
}

// Top and Pop functions must check the boundary case
template <typename T>
T Queue_LinkedList<T>::front() {
	return list.top();
}

template <typename T>
T Queue_LinkedList<T>::pop() {
	return list.pop_front();
}

#endif // _QUEUE_LINKEDLIST_H
