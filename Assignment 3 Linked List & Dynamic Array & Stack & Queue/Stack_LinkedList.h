/**
  * File      :   Stack_LinkedList.h
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 31, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _STACK_LINKEDLIST_H
#define _STACK_LINKEDLIST_H

#include "LinkedList.h"
using namespace std;

// Stack_LinkedList template
template <typename T>
class Stack_LinkedList {
private:
	LinkedList<T> list;	// a singly linked list
public:
	// Constructor and destructor is not needed because the complier will call the
	// constructor of the LinkedList class when Stack_LinkedList is constructed
	bool empty() const;
	T top() const;
	void push(T const &);
	T pop();
};

// Empty and Push functions just call the appropriate functions
// of LinkedList class
template <typename T>
bool Stack_LinkedList<T>::empty() const {
	return list.empty();
}

template <typename T>
void Stack_LinkedList<T>::push(T const &obj) {
	list.insertNode(obj);
}

// Top and Pop functions must check the boundary case
template <typename T>
T Stack_LinkedList<T>::top() const {
	if(empty()) throw E("Stack_LinkedList is empty!");
	return list.top();
}

template <typename T>
T Stack_LinkedList<T>::pop() {
	if(empty()) throw E("Stack_LinkedList is empty!");
	
	return list.pop_front();
}

#endif // _STAKC_LINKEDLIST_H
