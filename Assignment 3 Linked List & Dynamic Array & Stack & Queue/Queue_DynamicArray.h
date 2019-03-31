/**
  * File      :   Queue_DynamicArray.h
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#ifndef _QUEUE_DYNAMICARRAY_H
#define _QUEUE_DYNAMICARRAY_H

using namespace std;

// Queue_DynamicArray template
template <typename T>
class Queue_DynamicArray {
private:
	int queue_size;	// the number of objects currently in the queue
	int ifront;	// index of the front entry
	int iback;	// index of the back entry
	int array_capacity;	// the capacity of the array
	T *array;	// store the address of the first entry
public:
	Queue_DynamicArray(int = 10);
	~Queue_DynamicArray();
	bool empty() const;
	T front() const;
	void push(T const &);
	T pop();
};

// Constructor allocates memory for the array and initialize the member variables
// in the order in which they are defined
template <typename T>
Queue_DynamicArray<T>::Queue_DynamicArray(int n):
	queue_size(0),
	ifront(0),
	iback(-1),
	array_capacity(1 > n ? 1 : n),
	array(new T[array_capacity]) {	// Empty constructor
	}
	

// Destructor returns the memory to the operating system
template <typename T>
Queue_DynamicArray<T>::~Queue_DynamicArray(){
	delete [] array;
}

// Empty if the queue size is zero
template <typename T>
bool Queue_DynamicArray<T>::empty() const {
	return queue_size == 0;
}

// Front: get the first object in the queue
template <typename T>
T Queue_DynamicArray<T>::front() const {
	if (empty()) throw E("Queue_DynamicArray is empty!");
	return array[ifront];
}

// Pop the first object
template <typename T>
T Queue_DynamicArray<T>::pop() {
	if (empty()) throw E("Queue_DynamicArray is empty!");
	--queue_size;
	return array[ifront++];
}

// Push an object onto the queue
template <typename T>
void Queue_DynamicArray<T>::push(T const &obj) {
	if (queue_size == array_capacity) {
		T *temp_array = new T[2*array_capacity];
		
		for (int i = 0; i < array_capacity; ++i)
			temp_array[i] = array[i];
			
		delete [] array;
		array = temp_array;
		
		array_capacity *= 2;
	}
	
	array[++iback] = obj;
	++queue_size;
}

#endif // _QUEUE_DYNAMICARRAY_H
