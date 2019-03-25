/**
  * File      :   Stack_DynamicArray.h
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _STACK_DYNAMICARRAY_H
#define _STACK_DYNAMICARRAY_H

#include <exception>
using namespace std;

// Stack_DynamicArray template
template <typename T>
class Stack_DynamicArray {
private:
	int stack_size;	// the number of objects currently in the stack
	int array_capacity;	// the capacity of the array
	T *array;	// store the address of the first entry
public:
	Stack_DynamicArray(int = 10);
	~Stack_DynamicArray();
	bool empty();
	T top();
	void push(T);
	T pop();
};

// Constructor allocates memory for the array and initialize the member variables
// in the order in which they are defined
template <typename T>
Stack_DynamicArray<T>::Stack_DynamicArray(int n):
	stack_size(0),
	array_capacity(1 > n ? 1 : n),
	array(new T[array_capacity]) {	// Empty constructor
	}
	

// Destructor returns the memory to the operating system
template <typename T>
Stack_DynamicArray<T>::~Stack_DynamicArray(){
	delete [] array;
}

// Empty if the stack size is zero
template <typename T>
bool Stack_DynamicArray<T>::empty() {
	return stack_size == 0;
}

// Top: get the last object which located at index n-1 if there are n objects in the stack
template <typename T>
T Stack_DynamicArray<T>::top() {
	return array[stack_size - 1];
}

// Pop an object by simply reducing the size 
template <typename T>
T Stack_DynamicArray<T>::pop() {
	return array[--stack_size];
}

// Push an object onto the stack
template <typename T>
void Stack_DynamicArray<T>::push(T obj) {
	if (stack_size == array_capacity) {
		T *temp_array = new T[2*array_capacity];
		
		for (int i = 0; i < array_capacity; ++i)
			temp_array[i] = array[i];
			
		delete [] array;
		array = temp_array;
		
		array_capacity *= 2;
	}
	
	array[stack_size++] = obj;
}

#endif // _STACK_DYNAMICARRAY_H
