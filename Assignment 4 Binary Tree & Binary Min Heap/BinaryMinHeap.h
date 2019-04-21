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
#include <math.h>
using namespace std;

// Exception class
class E : public exception {
    const char *msg;
    E(){};    // no default constructor
public:
    explicit E(const char *s) throw() : msg(s) {}
    const char* what() const throw() {return msg;}
};

// BinaryTree template
template <typename T>
class BinaryMinHeap {
private:
	T *array;	// An array to store the binary min-heap
	int capacity;	// the capacity of this array
	int size;	// the current size of this array

public:
	BinaryMinHeap(void) {	// Constructor
		array = NULL;
		capacity = 0;
		size = 0;
	}
	BinaryMinHeap(int Capacity);
	~BinaryMinHeap(void) { delete[] array; }	// Destructor
	void percolate(int);
	T getMin();
	T extractMin();
	void deleteNode(int nodeI);
	//void decreaseKey(int node, int new_val);
	void insertKey(T);
	T getLeftChild(int);
	T getRightChild(int);
	bool empty();
};

template <typename T>
void swap(T *x, T *y) {
	T temp = *x;
	*x = *y;
	*y = temp;
}

template <typename T>
BinaryMinHeap<T>::BinaryMinHeap(int Capacity) {
	array = new T[Capacity];
	capacity = Capacity;
	size = 0;
}

template <typename T>
void BinaryMinHeap<T>::percolate(int nodeI) {
	int minIdx;
	if (2*nodeI+1 <= size) minIdx = getLeftChild(nodeI) < getRightChild(nodeI) ? 2*nodeI : 2*nodeI+1;
	else if(2*nodeI == size) minIdx = 2*nodeI;
	else return;
	if (array[nodeI] > array[minIdx]) {
		swap(array[nodeI], array[minIdx]);
		percolate(minIdx);
	}
}

template <typename T>
T BinaryMinHeap<T>::getMin() {
	return array[1];
}

template <typename T>
bool BinaryMinHeap<T>::empty() {
	return size == 0;
}

template <typename T>
T BinaryMinHeap<T>::extractMin() {
	T temp = array[1];
	array[1] = array[size--];
	percolate(1);
	return temp;
}

template <typename T>
void BinaryMinHeap<T>::deleteNode(int nodeI) {
	array[nodeI] = array[size--];
	percolate(nodeI);
}

template <typename T>
void BinaryMinHeap<T>::insertKey(T val) {
	array[++size] = val;

	int idx = size, parent = floor(idx/2);
	while (idx > 1 && array[parent] > array[idx]) {
		swap(array[parent], array[idx]);
		idx = parent;
		parent = floor(parent/2);
	}
}

template <typename T>
T BinaryMinHeap<T>::getLeftChild(int nodeI) {
	if (nodeI*2 > size) throw E("No left child!");
    return array[nodeI*2];
}

template <typename T>
T BinaryMinHeap<T>::getRightChild(int nodeI) {
    if (nodeI*2+1 > size) throw E("No right child!");
	return array[nodeI*2+1];
}
#endif // _BINARYMINHEAP_H
