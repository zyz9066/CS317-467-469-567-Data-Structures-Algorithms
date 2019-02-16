// array.h by Tianye Zhao
// IDE: Dev-C++ 5.11
// updated 2019-02-10 for CS469 Assignment 1
#ifndef _ARRAY
#define _ARRAY

#include <exception>
#include <iostream>
using namespace std;

// simple exception class
class ArrayException : public exception {
	const char * msg;
    ArrayException(){}; // no default constructor
public:
	explicit ArrayException(const char * s) throw() : msg(s) { }
	const char * what() const throw() { return msg; }
};

// simple fixed-size array template
template <typename T>
class Array {
private:
	static const int defaultSize = 10;
    static const int maxSize = 1000;
    int _end;
    int _size;
    T * _arrayPtr;
public:
    explicit Array(int s = defaultSize);
    ~Array() { delete[] _arrayPtr; }
    T & get( const int );
    void insertLast( const T );
    void insertByOrder( const T );
    void update( const int, const T );
    void remove( const T );
    T & removeLast();
    void display();
    int linearSearch( const T );
    void selectionSort();
    //void quickSort( const int, const int );
    int binarySearch( const T, const int, const int );
    int findMin();
    int findMax();
    int countBetween( const T, const T );
    T findMost();
    bool isEmpty() const { return _end < 0; }
    bool isFull() const { return _end >= _size - 1; }
    int size() const { return _size; }
    int end() const { return _end; }       
};

// Array<T> constructor
template <typename T>
Array<T>::Array ( int s ) {
    if (s > maxSize || s < 1) throw ArrayException("Invalid array size!");
    else _size = s;
    _arrayPtr = new T[_size];
    _end = -1;
}

template <typename T>
T & Array<T>::get( const int pos ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	return _arrayPtr[pos];
}

template <typename T>
void Array<T>::insertLast ( const T val ) {
    if (isFull()) throw ArrayException("Array is full!");
    _arrayPtr[++_end] = val;
}

template <typename T>
void Array<T>::update ( const int pos, const T i ) {
    if (isEmpty()) throw ArrayException("Array is empty!");
    _arrayPtr[pos] = i;
}

template <typename T>
void Array<T>::insertByOrder ( const T val ) {
    if (isFull()) throw ArrayException("Array is full!");
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+end(), * ptr3 = ptr2--;
	while (*ptr1 < val && ptr1 != ptr3) {
		ptr1++;
	}
	if (ptr1 == ptr3)
		insertLast(val);
	else {
		insertLast(*ptr3);
		while (ptr3 != ptr1) {
		*ptr3-- = *ptr2--;
		}
		*ptr1 = val;
	}
}

template <typename T>
void Array<T>::remove ( const T val ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	int i = linearSearch(val);
	if (i == -1) return;
	else if (i = end()) update(end(), 0);
	else {
		T * ptr1 = _arrayPtr+i, * ptr2 = ptr1, * ptr3 = _arrayPtr+end();
		do {
			*ptr1++ = *++ptr2;
		} while (ptr1 != ptr3);
		*ptr1 = 0;
	}
}

template <typename T>
T & Array<T>::removeLast () {
    if (isEmpty()) throw ArrayException("Array is empty!");
    return _arrayPtr[_end--];
}

template <typename T>
void Array<T>::display () {
    if (isEmpty()) throw ArrayException("Array is empty!");
    T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+end();
   	do {
        cout << *ptr1 << endl;
    } while (ptr1++ != ptr2);
}

template <typename T>
int Array<T>::linearSearch ( const T val ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+end();
	int i = 0;
    do {
    	if (*ptr1 == val) {
    		return i;
		}
		i++;
    } while (ptr1++ != ptr2);
    return -1;
}

template <typename T>
void Array<T>::selectionSort () {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1, * ptr3 = _arrayPtr+end(), * ptr4, temp;
	while (ptr2 != ptr3) {
		ptr4 = ptr2;
		ptr1 = ptr2+1;
		do {
			if (*ptr1 < *ptr4) {
				ptr4 = ptr1;
			}
		} while (ptr1++ != ptr3);
		temp = *ptr2;
		*ptr2++ = *ptr4;
		*ptr4 = temp;
	}	
}

/*
template <typename T>
void Array<T>::quickSort ( const int low, const int high ) {
	if(isEmpty()) throw ArrayException("Array is empty!");
	if(low >= high) return;
	int pivot;
	T * ptr1 = _arrayPtr+low, * ptr2 = ptr1+high, * ptr3 = ptr1++, temp;
	int i = low+1, j = high;
	while(i <= j) {
		while(i <= j && *ptr1 < *ptr3) {
			ptr1++;
			i++;
		}
		while(i <= j && *ptr2 > *ptr3) {
			ptr2--;
			j--;
		}
		if(i < j) {
			temp = *ptr1;
			*ptr1++ = *ptr2;
			i++;
			*ptr2-- = temp;
			j--;
		}		
	}
	temp = *ptr3;
	*ptr3 = *ptr2;
	*ptr2 = temp;
	pivot = j;
	cout << "test" << endl;
	display();
	quickSort(low, pivot-1);
	quickSort(pivot+1, high);
}*/

template <typename T>
int Array<T>::binarySearch ( const T val, const int low, const int high ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	if (low > high)
		return -1;
	int mid = static_cast<int>((low+high)/2);
	T * ptr = _arrayPtr;
	if (*(ptr+mid) == val)
		return mid;
	if (*(ptr+mid) < val)
		binarySearch(val, mid+1, high);
	else
		binarySearch(val, low, mid-1);
}

template <typename T>
int Array<T>::findMin () {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+end(), value = *ptr1++;
	int index, i = 1;
	do {
    	if (*ptr1 < value) {
    		value = *ptr1;
    		index = i;
		}
		i++;
    } while (ptr1++ != ptr2);
    return index;
}

template <typename T>
int Array<T>::findMax () {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+end(), value = *ptr1++;
	int index, i = 1;
	do {
    	if (*ptr1 > value) {
    		value = *ptr1;
    		index = i;
		}
		i++;
    } while (ptr1++ != ptr2);
    return index;
}

template <typename T>
int Array<T>::countBetween ( const T a, const T b ) {
    if (isEmpty()) throw ArrayException("Array is empty!");
    T maxValue = a > b ? a : b, minValue = a < b ? a : b;
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+end();
    int counter = 0;
    do {
        if (*ptr1 >= minValue && *ptr1 <= maxValue) {
            counter++;
        }
    } while (ptr1++ != ptr2);
    return counter;
}

template <typename T>
T Array<T>::findMost () {
	if (isEmpty()) throw ArrayException("Array is empty!");
	Array<T> valueArray(end());
	Array<int> counterArray(end());
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+end();
	valueArray.insertLast(*ptr1++);
	counterArray.insertLast(1);
	int pos, counter;
	do {
		pos = valueArray.linearSearch(*ptr1);
		if (pos == -1) {
			valueArray.insertLast(*ptr1);
			counterArray.insertLast(1);
		}
		else {
			counterArray.get(pos)++;
		}
	} while (ptr1++ != ptr2);
	pos = counterArray.findMax();
	return valueArray.get(pos);
}

#endif // _ARRAY
