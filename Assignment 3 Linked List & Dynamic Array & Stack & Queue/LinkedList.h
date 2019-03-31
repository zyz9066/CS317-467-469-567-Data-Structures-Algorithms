/**
  * File      :   LinkedList.h
  * Created   :   Mar 17, 2019
  * Modified  :   Mar 31, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <exception>
#include <iostream>
using namespace std;

// Exception class
class E : public exception {
    const char *msg;
    E(){};    // no default constructor
public:
    explicit E(const char *s) throw() : msg(s) {}
    const char* what() const throw() {return msg;}
};

// LinkedList template
template <typename T>
class LinkedList {
private:
	// Declare a structure for the list
	struct ListNode {
		T value;
		struct ListNode *next;
	};

	ListNode *head;	//List head pointer
public:
	LinkedList(void) { head = NULL; }	// Constructor
	LinkedList(T);
	~LinkedList(void);	// Destructor
	void appendNode(T const &);

	T& top() const;

	T pop_front();

	bool empty() const;
	void insertNode(T const &);
	void deleteNode(T const &, bool = false);
	void displayList(void);
	int count(T const &) const;
	int length() const;
	void sortBySelection();
	void sortByInsertion();

	ListNode *getNode(int) const;

	T& get(int);

	void clear();

	void reverse();
};

// Constructor to create a linked list which first node contains
// the value info and the next pointer is null
template <typename T>
LinkedList<T>::LinkedList(T info) {

	ListNode *newNode = new ListNode;
	newNode->value = info;
	newNode->next = NULL;
	head = newNode;
}

// Destructor that remove all elements of the linked list
template <typename T>
LinkedList<T>::~LinkedList() {

	ListNode *nodePtr = head, *nextNode;
	while (nodePtr != NULL) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

// Append a node at the end of the linked list
template <typename T>
void LinkedList<T>::appendNode(T const &info) {

	// Allocate a new node & store info
	ListNode *newNode = new ListNode;
	newNode->value = info;
	newNode->next = NULL;
	// If there are no nodes in the list make newNode the first node
	if (!head) head = newNode;
	else {	// Otherwise, insert newNode at end

		// Initialize NodePtr to head of list
		ListNode *nodePtr = head;

		// Find the last node in the list
		while (nodePtr->next) nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

// Get the first element of the linked list
template <typename T>
T& LinkedList<T>::top() const {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");
	return head->value;
}

// Remove first node of the linked list and return its value
template <typename T>
T LinkedList<T>::pop_front() {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");
	ListNode *tempNode = head;
	T tempVal = head->value;
	head = head->next;
	delete tempNode;
	return tempVal;
}

// Test if the linked list is empty or not
template <typename T>
bool LinkedList<T>::empty() const {
	return !head;
}

// Insert a node in the beginning of the linked list
template <typename T>
void LinkedList<T>::insertNode(T const &info) {

	// Allocate a new node & store info
	ListNode *newNode = new ListNode;
	newNode->value = info;

	// If there are no nodes in the list make newNode the first node
	if (!head) {
		head = newNode;
		newNode->next = NULL;
	} else {	// Otherwise, insert newNode in the beginning
		newNode->next = head;
		head = newNode;
	}
}

// Delete a node from the linked list, if removeAll is true, all occurrence
// of info will be removed, otherwise only first occurrence.
template <typename T>
void LinkedList<T>::deleteNode(T const &info, bool removeAll) {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr;

	//Determine if the first node is the one
	if (head->value == info) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		if (!removeAll) return;
	}
	// Initialize nodePtr to head of list
	nodePtr = head;
	ListNode *prevNode = new ListNode, *tempNode = new ListNode;

	if (removeAll) {
		// Search all nodes whose value member is equal to info
		while (nodePtr != NULL) {
			if (nodePtr->value == info) {
				tempNode = nodePtr;
				nodePtr = nodePtr->next;
				prevNode->next = nodePtr;
				delete tempNode;
				continue;
			}
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	} else {
		// Skip all nodes whose value member is not equal to info
		while (nodePtr != NULL && nodePtr->value != info) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Link previous node to the node after nodePtr, then delete nodePtr
		if (nodePtr != NULL) {
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

// Display all elements of the linked list
template <typename T>
void LinkedList<T>::displayList(void) {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr = head;

	while (nodePtr) {
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

// Count the occurrence of val in the linked list
template <typename T>
int LinkedList<T>::count(T const &val) const {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr = head;

	int count = 0;
	while (nodePtr) {
		if (nodePtr->value == val) ++count;
		nodePtr = nodePtr->next;
	}

	return count;
}

// Count the number of nodes in the linked list
template <typename T>
int LinkedList<T>::length() const {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr = head;

	int length = 0;
	while (nodePtr) {
		++length;
		nodePtr = nodePtr->next;
	}

	return length;
}


// Get the i-th node of the linked list
template <typename T>
typename LinkedList<T>::ListNode *LinkedList<T>::getNode(int i) const {

	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	if (i < 0 || i >= length()) throw E("Invalid index!");

	ListNode *nodePtr = head;

	int count = 0;
	while (count != i) {
		++count;
		nodePtr = nodePtr->next;
	}

	return nodePtr;
}


// Get element of the i-th node of the linked list
template <typename T>
T& LinkedList<T>::get(int i) {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	if (i < 0 || i >= length()) throw E("Invalid index!");

	ListNode *nodePtr = head;

	int count = 0;
	while (count != i) {
		++count;
		nodePtr = nodePtr->next;
	}

	return nodePtr->value;

}

// Remove all elements of the linked list
template <typename T>
void LinkedList<T>::clear() {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is already empty!");
	
	ListNode *nodePtr = head, *nextNode = new ListNode;
	while (nodePtr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	
	head = NULL;
}

// Sort the linked list using the principle of sorting by selection
template <typename T>
void LinkedList<T>::sortBySelection() {

	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr = new ListNode, *prevPtr = new ListNode;
	ListNode *currPtr = head, *currPrevPtr = head;
	ListNode *minPtr = new ListNode, *minPrevPtr = head;

	while (currPtr->next) {
		prevPtr = currPtr;
		nodePtr = currPtr->next;
		minPtr = currPtr;
		while (nodePtr) {
			if (minPtr->value > nodePtr->value) {
				minPtr = nodePtr;
				minPrevPtr = prevPtr;
			}
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if (currPtr == minPtr) {
			currPrevPtr = currPtr;
			currPtr = currPtr->next;
			continue;
		}
		
		if (currPtr == head) head = minPtr;
		else currPrevPtr->next = minPtr;
		
		minPrevPtr->next = minPtr->next;
		minPtr->next = currPtr;
		
		currPrevPtr = minPtr;
	}

}

// Sort the linked list using the principle of sorting by insertion
template <typename T>
void LinkedList<T>::sortByInsertion() {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");

	ListNode *nodePtr = new ListNode, *prevPtr = new ListNode, *endPtr = head;

	while (endPtr->next) {
		nodePtr = head;
		while (nodePtr->value < endPtr->next->value && nodePtr != endPtr) {
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if (nodePtr == head && head->value > endPtr->next->value) {
			head = endPtr->next;
			endPtr->next = endPtr->next->next;
			head->next = nodePtr;
		} else if (nodePtr == endPtr && nodePtr->value < endPtr->next->value) endPtr = endPtr->next;
		else {
			prevPtr->next = endPtr->next;
			endPtr->next = endPtr->next->next;
			prevPtr->next->next = nodePtr;
		}
	}
}

// Reverse the elements of the linked list without intermediary linked list
template <typename T>
void LinkedList<T>::reverse() {
	
	// If list is empty, throw exception
	if (!head) throw E("Linked List is empty!");
	
	ListNode *nodePtr = head->next, *prevPtr = head, *nextPtr = head->next->next;
	prevPtr->next = NULL;
	while (nextPtr) {
		nodePtr->next = prevPtr;
		prevPtr = nodePtr;
		nodePtr = nextPtr;
		nextPtr = nextPtr->next;		
	}
	nodePtr->next = prevPtr;
	head = nodePtr;
}

#endif // _LINKEDLIST_H
