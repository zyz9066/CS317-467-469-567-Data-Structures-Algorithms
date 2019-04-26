// Array.h by Tianye Zhao
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
	static const int SPARE_CAPACITY = 16;
    static const int maxSize = 1000;
    int _size;
    int _capacity;
    T * _arrayPtr;
    
public:
	// Constructor
    explicit Array ( int initSize = 0 ) : _size{ initSize },
			_capacity{ initSize + SPARE_CAPCITY }
		{ _arrayPtr = new T[_capacity]; }
	
    Array( const Array & rhs ) : _size{ rhs.size() },
		_capacity{ rhs.capacity() }, _arrayPtr{ nullptr }
	{	
		_arrayPtr = new T[_capacity];
		for (int k = 0; k < _size; ++k) _arrayPtr[k] = rhs.get(k);
	}
	
    Array & operator= (const Array & rhs) {
		Array copy = rhs;
		swap(*this, copy);
		return *this;
	}
    
    ~Array() { delete[] _arrayPtr; }
    
    Array(Array && rhs) : _size{ rhs.size() },
    	_capacity{ rhs.capacity() }, _arrayPtr{ rhs._arrayPtr }
    {
    	rhs._arrayPtr = nullptr;
    	rhs._size = 0;
    	rhs._capacity = 0;
	}
	
	Array & operator= (Array && rhs) {
		swap(_size, rhs._size);
		swap(_capacity, rhs._capacity);
		swap(_arrayPtr, rhs._arrayPtr);
		
		return *this;
	}
	
	void resize( in newSize ) {
		if (newSize > _capacity) reserve(newSize*2);
		_size = newSize;
	}
	
	void reserve( int newCapacity ) {
		if (newCapacity < _size) return;
		T *newArray = new T[newCapacity];
		for (int k = 0; k < _size; ++k) newArray[k] = _arrayPtr[k];
		
		_capacity = newCapacity;
		swap(_arrayPtr, newArray);
		delete[] newArray;
	}
	
	T & operator[]( int index ) { return _arrayPtr[index]; }
	const T & operator[]( int index ) const { return _arrayPtr[index]; }
	
	bool empty() const { return size() == 0; }
    int size() const { return _size; }
	int capacity() const { return _capacity; }
	
    T & get( const int );
    void push_back( const T & x ) {
    	if (_size == _capacity) reserve(2*_capacity+1);
    	arrayPtr[_size++] = x;
	}
	
	void pop_back() { --_size; }
	
	const T & back() const { return arrayPtr[_size-1]; }
	
	typedef T * iterator;
	typedef const T * const_iterator;
	
	iterator begin() { return &_arrayPtr[0]; }
	const_iterator begin() const { return &_arrayPtr[0]; }
	iterator end() { return &_arrayPtr[size()]; }
	const_iterator end() const { return &_arrayPtr[size()]; }
	
    void insertByOrder( const T );
    void update( const int, const T );
    void remove( const T );
    void display();
    int linearSearch( const T );
    void selectionSort();
    //void quickSort( const int, const int );
    int binarySearch( const T, const int, const int );
    int findMin();
    int findMax();
    int countBetween( const T, const T );
    T findMost(); 
};

// Swapping by three copies
template <typename T>
void swap(T & x, T & y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T & Array<T>::get( const int pos ) {
	if (empty()) throw ArrayException("Array is empty!");
	return _arrayPtr[pos];
}

template <typename T>
void Array<T>::update ( const int pos, const T i ) {
    if (empty()) throw ArrayException("Array is empty!");
    _arrayPtr[pos] = i;
}

template <typename T>
void Array<T>::insertByOrder ( const T val ) {
    if (_size == _capacity) reserve(2*_capacity+1);
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+end(), * ptr3 = ptr2--;
	while (*ptr1 < val && ptr1 != ptr3) {
		ptr1++;
	}
	if (ptr1 == ptr3)
		push_back(val);
	else {
		push_back(*ptr3);
		while (ptr3 != ptr1) {
		*ptr3-- = *ptr2--;
		}
		*ptr1 = val;
	}
}

template <typename T>
void Array<T>::remove ( const T val ) {
	if (empty()) throw ArrayException("Array is empty!");
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
void Array<T>::display () {
    if (empty()) throw ArrayException("Array is empty!");
    T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+size();
   	do {
        cout << *ptr1 << endl;
    } while (ptr1++ != ptr2);
}

template <typename T>
int Array<T>::linearSearch ( const T val ) {
	if (empty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+size();
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
	if (empty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1, * ptr3 = _arrayPtr+size(), * ptr4, temp;
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

template <typename T>
int Array<T>::binarySearch ( const T val, const int low, const int high ) {
	if (empty()) throw ArrayException("Array is empty!");
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
	if (empty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+size(), value = *ptr1++;
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
	if (empty()) throw ArrayException("Array is empty!");
	T * ptr1 = _arrayPtr, * ptr2 = ptr1+size(), value = *ptr1++;
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
    if (empty()) throw ArrayException("Array is empty!");
    T maxValue = a > b ? a : b, minValue = a < b ? a : b;
    T * ptr1 = _arrayPtr, * ptr2 = ptr1+size();
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
	if (empty()) throw ArrayException("Array is empty!");
	Array<T> valueArray(size());
	Array<int> counterArray(size());
	T * ptr1 = _arrayPtr, * ptr2 = _arrayPtr+size();
	valueArray.push_back(*ptr1++);
	counterArray.push_back(1);
	int pos, counter;
	do {
		pos = valueArray.linearSearch(*ptr1);
		if (pos == -1) {
			valueArray.push_back(*ptr1);
			counterArray.push_back(1);
		}
		else {
			counterArray.get(pos)++;
		}
	} while (ptr1++ != ptr2);
	pos = counterArray.findMax();
	return valueArray.get(pos);
}

#endif // _ARRAY
