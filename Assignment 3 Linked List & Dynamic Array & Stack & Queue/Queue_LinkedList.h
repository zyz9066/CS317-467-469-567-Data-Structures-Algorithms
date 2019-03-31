/**
  * File      :   Queue_LinkedList.h
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 31, 2019
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
	bool empty() const;
	T front() const;
	void push(T const &);
	T pop();
};

// Empty and Push functions just call the appropriate functions
// of LinkedList class
template <typename T>
bool Queue_LinkedList<T>::empty() const {
	return list.empty();
}

template <typename T>
void Queue_LinkedList<T>::push(T const &obj) {
	list.appendNode(obj);
}

// Top and Pop functions must check the boundary case
template <typename T>
T Queue_LinkedList<T>::front() const {
	if (empty()) throw E("Queue_LinkedList is empty!");
	return list.top();
}

template <typename T>
T Queue_LinkedList<T>::pop() {
	if (empty()) throw E("Queue_LinkedList is empty!");
	return list.pop_front();
}

#endif // _QUEUE_LINKEDLIST_H
