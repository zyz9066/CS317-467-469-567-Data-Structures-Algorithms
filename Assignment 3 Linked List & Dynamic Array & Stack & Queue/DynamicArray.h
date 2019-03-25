/**
  * File      :   DynamicArray.h
  * Created   :   Mar 17, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H

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

template <typename T>
class DynamicArray {
private:
	T *array;
	int size;	// current size of the array
	int capacity;	// the total capacity to be allocated for the array
	
public:
	DynamicArray(int Capacity);	// Constructor
	~DynamicArray();	// Destructor
	void add(T elem);
	void remove(T elem);
	void display();
};

// Constructor
template <typename T>
DynamicArray<T>::DynamicArray(int Capacity){
	array = new T[Capacity];
	capacity = Capacity;
	size = 0;
}

// Destructor to destroy the array
template <typename T>
DynamicArray<T>::~DynamicArray(){
	delete [] array;
}

// Function add to insert an elem in the dynamic array
template <typename T>
void DynamicArray<T>::add(T elem){
	
	if (size == capacity) {
		T *temp_array = new T[2*capacity];
		
		for (int i = 0; i < capacity; ++i)
			temp_array[i] = array[i];
		
		delete [] array;
		array = temp_array;
		
		capacity *= 2;
	}
	
	array[size++] = elem;
}

// Function remove to search for an element and to delete it from the dynamic array
template <typename T>
void DynamicArray<T>::remove(T elem){
	
	// If list is empty, throw exception
	if (size == 0) throw E("Dynamic Array is empty!");
	
	T *temp_array = new T[size-1];
	bool found = false;
	
	for (int i = 0, j = 0; i < size; ++i, ++j) {
		if (array[i] == elem && !found) {
			--j; found = true;	
		} else temp_array[j] = array[i];
	}
	
	delete [] array;
	array = temp_array;
	
	if (found == true) capacity = --size;
} // End of remove

// Display
template <typename T>
void DynamicArray<T>::display() {
	
	for (int i = 0; i < size; ++i)
		cout << array[i] << endl;
}

#endif // _DYNAMICARRAY_H
