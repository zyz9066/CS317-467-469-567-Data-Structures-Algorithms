/**
  * File      :   BianryMinHeap.h
  * Created   :   Apr 12, 2019
  * Modified  :   Apr 19, 2019
  * Author    :   Tianye Zhao, Wenda Yang
  * IDE    	  :   Dev C++ 5.11
  ***********************************/

#ifndef _BINARYMINHEAP_H
#define _BINARYMINHEAP_H

#include <exception>
#include <iostream>

using namespace std;

// Exception class
class E : public exception {
    const char * msg;
    E(){};    // no default constructor
public:
    explicit E(const char * s) throw() : msg(s) {}
    const char * what() const throw() { return msg; }
};

const E UnderflowException("BinaryMinHeap is empty!");

// BinaryTree template
template <typename T>
class BinaryMinHeap {
private:
	T *array;	// An array to store the binary min-heap
	int capacity;	// the capacity of this array
	int size;	// the current size of this array
	
	void buildHeap();

public:
	BinaryMinHeap(void) {	// Constructor
		array = NULL;	// The heap array
		capacity = 100;
		size = 0;	// Number of elements in heap
	}
	
	BinaryMinHeap(int Capacity);
	// a destructor that remove all elements of the binary min-heap
	~BinaryMinHeap(void) { delete[] array; }
	void percolate(int);
	T getMin();
	T extractMin();
	void deleteNode(int nodeI);
	//void decreaseKey(int node, int new_val);
	void insertKey(T val);
	T getLeftChild(int nodeI);
	T getRightChild(int nodeI);
	bool empty();
};

template <typename T>
void swap(T *x, T *y) {
	T temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time.
 */
template <typename T>
void BinaryMinHeap<T>::buildHeap() {
	for (int i = size/2; i > 0; --i) percolate(i);
}

// the constructor to create a binary min-heap with a capacity
template <typename T>
BinaryMinHeap<T>::BinaryMinHeap(int Capacity) {
	array = new T[Capacity];
	capacity = Capacity;
	size = 0;
}

// to heapify a subtree with the root at given index
template <typename T>
void BinaryMinHeap<T>::percolate(int nodeI) {
	if (nodeI > size || nodeI < 1) throw E("Invalid Index!");
	
	int child;
	T tmp = array[nodeI];
	
	for ( ; nodeI*2 <= size; nodeI=child) {
		child = nodeI*2;
		if (child != size && array[child+1] < array[child]) ++child;
		if (array[child] < tmp) array[nodeI] = array[child];
		else break;
	}
	array[nodeI] = tmp;
}

// gets the minimum value of the binary min-heap
template <typename T>
T BinaryMinHeap<T>::getMin() {
	if (empty()) throw UnderflowException;
	
	return array[1];
}

// tests if the binary min-heap is empty or no
template <typename T>
bool BinaryMinHeap<T>::empty() {
	return size == 0;
}

// removes minimum elements (or root) from the binary min-heap
template <typename T>
T BinaryMinHeap<T>::extractMin() {
	if (empty()) throw UnderflowException;
	
	T minItem = array[1];
	array[1] = array[size--];
	percolate(1);
	return minItem;
}

// deletes key at index nodeI
template <typename T>
void BinaryMinHeap<T>::deleteNode(int nodeI) {
	if (nodeI > size || nodeI < 1) throw E("Invalid Index!");
	
	array[nodeI] = array[size--];
	percolate(nodeI);
}

// inserts a new node which key is val
template <typename T>
void BinaryMinHeap<T>::insertKey(T val) {
	if (size == capacity-1) throw E("Heap is full!");
	
	// percolate up
	int hole = ++size;
	
	for ( ; val < array[hole/2]; hole/=2) array[hole] = array[hole/2];
	array[hole] = val;
}

// gets the left child of nodeI
template <typename T>
T BinaryMinHeap<T>::getLeftChild(int nodeI) {
	if (nodeI*2 > size) throw E("No left child!");
    return array[nodeI*2];
}

// gets the right child of nodeI
template <typename T>
T BinaryMinHeap<T>::getRightChild(int nodeI) {
    if (nodeI*2+1 > size) throw E("No right child!");
	return array[nodeI*2+1];
}

#endif // _BINARYMINHEAP_H
