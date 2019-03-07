/**
  * File      :   array.h
  * Date      :   Feb 28, 2018
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#ifndef _ARRAY
#define _ARRAY

#include <exception>
#include <iostream>
#include <cstdio>
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
    static const int maxSize = 100000;
    int _len;
    int _size;
    T * _arrayPtr;
    void doubleSize();
public:
    explicit Array(int s = defaultSize);
    ~Array() { delete[] _arrayPtr; }
    T & get( const int );
    void insertLast( const T );
    void insertByOrder( const T );
    void update( const int, const T );
    void insertAt( const int, const T );
    void deleteAt( const int );
    void remove( const T );
    T & removeLast();
    void reverse();
    void display();
    int linearSearch( const T );
    int binarySearch( const T, const int, const int );
    int findMin();
    int findMax();
    int countBetween( const T, const T );
    T mode();
    void checkDuplicate();
    bool isEmpty() const { return _len < 0; }
    bool isFull() const { return _len >= _size - 1; }
    int size() const { return _size; }
    int len() const { return _len; }       
};

// Array<T> constructor
template <typename T>
Array<T>::Array( int s ) {
    if (s > maxSize || s < 1) throw ArrayException("Invalid array size!");
    else _size = s;
    _arrayPtr = new T[_size];
    _len = -1;
}

template <typename T>
T & Array<T>::get( const int pos ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	return _arrayPtr[pos];
}

template <typename T>
void Array<T>::insertLast( const T val ) {
    if (isFull()) throw ArrayException("Array is full!");
    _arrayPtr[++_len] = val;
}

template <typename T>
void Array<T>::update( const int pos, const T i ) {
    if (isEmpty()) throw ArrayException("Array is empty!");
    _arrayPtr[pos] = i;
}

template <typename T>
void Array<T>::insertByOrder( const T val ) {
    if (isFull()) throw ArrayException("Array is full!");
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+_len, * ptr3 = ptr2--;
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
	++_len;
}

template <typename T>
void Array<T>::insertAt( const int idx, const T val ) {
	if (idx > _len+1) throw ArrayException("Invalid index!");
	if (isFull()) {
    	doubleSize();
	}
  if (idx == _len+1) insertLast(val);
  else {
    T * ptr4 = _arrayPtr+idx, * ptr5 = _arrayPtr+_len, * ptr6 = ptr5--;
	insertLast(*ptr6);
	while (ptr6 != ptr4) {
		*ptr6-- = *ptr5--;
	}
	*ptr4 = val;
  }	
}

template <typename T>
void Array<T>::doubleSize() {
	T * newArrPtr = new T[2*_size];
	T * ptr1 = _arrayPtr, * ptr2 = newArrPtr, * ptr3 = ptr1+_len;
	do {
		*ptr2++ = *ptr1;
	} while(ptr1++ != ptr3);
	_arrayPtr = newArrPtr;
	_size *= 2;
}

template <typename T>
void Array<T>::deleteAt( const int idx ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	if (idx > _len) throw ArrayException("Invalid index!");
	else if (idx == _len) removeLast();
	else {
		T * ptr1 = _arrayPtr+idx, * ptr2 = ptr1, * ptr3 = _arrayPtr+_len;
		do {
			*ptr1++ = *++ptr2;
		} while (ptr1 != ptr3);
		--_len;
	}
}

template <typename T>
void Array<T>::remove( const T val ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	int i = linearSearch(val);
	if (i == -1) return;
	else if (i == _len) update(_len, 0);
	else {
		T * ptr1 = _arrayPtr+i, * ptr2 = ptr1, * ptr3 = _arrayPtr+_len;
		do {
			*ptr1++ = *++ptr2;
		} while (ptr1 != ptr3);
		*ptr1 = 0;
	}
	--_len;
}

template <typename T>
T & Array<T>::removeLast() {
    if (isEmpty()) throw ArrayException("Array is empty!");
    return _arrayPtr[_len--];
}

template <typename T>
void Array<T>::display() {
    if (isEmpty()) throw ArrayException("Array is empty!");
    T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+_len;
   	do {
        cout << *ptr1 << " ";
    } while (ptr1++ != ptr2);
}

// swap function
template <typename T>
void Swap(T & a, T & b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Array<T>::reverse() {
    if (isEmpty()) throw ArrayException("Array is empty!");
    T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+_len;
   	while (ptr1 != ptr2 && ptr1 != ptr2+1) {
        Swap(*ptr1++, *ptr2--);
    }
}

template <typename T>
int Array<T>::linearSearch( const T val ) {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+_len;
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
int Array<T>::binarySearch( const T val, const int low, const int high ) {
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
int Array<T>::findMin() {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+_len, value = *ptr1++;
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
int Array<T>::findMax() {
	if (isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+_len;
	T value = *ptr1++;
	int index = 0, i = 1;
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
int Array<T>::countBetween( const T a, const T b ) {
    if (isEmpty()) throw ArrayException("Array is empty!");
    T maxValue = a > b ? a : b, minValue = a < b ? a : b;
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+_len;
    int counter = 0;
    do {
        if (*ptr1 >= minValue && *ptr1 <= maxValue) {
            counter++;
        }
    } while (ptr1++ != ptr2);
    return counter;
}

template <typename T>
T Array<T>::mode() {
	if (isEmpty()) throw ArrayException("Array is empty!");
	Array<T> valueArray(_len+1);
	Array<int> counterArray(_len+1);
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+_len;
	valueArray.insertLast(*ptr1++);
	counterArray.insertLast(1);
	int pos;
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

template <typename T>
void Array<T>::checkDuplicate() {
	if (isEmpty()) throw ArrayException("Array is empty!");
	Array<T> valueArray(_len+1);
	Array<int> counterArray(_len+1);
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+_len;
	valueArray.insertLast(*ptr1++);
	counterArray.insertLast(1);
	int pos, count;
	do {
		pos = valueArray.linearSearch(*ptr1);
		if (pos == -1) {
			valueArray.insertLast(*ptr1);
			counterArray.insertLast(1);
		}
		else {
			if (++counterArray.get(pos) > 1)
				puts("There are one or more duplicates.");
				return;
		}
	} while (ptr1++ != ptr2);
	
	puts("There are no duplicates.");
	return;
}

#endif // _ARRAY
