/**
  * File      :   Sorting.h
  * Date      :   Feb 28, 2018
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#ifndef _SORTING
#define _SORTING

#include "Array.h"
#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Insertion Sort
template <typename T>
void InsertionSort( Array<T> & A ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	T *ptr1 = &A.get(0); 		// value to sort
	T *ptr2 = ptr1+A.len(); 	// end of array
	T *ptr3 = ptr1++; 			// end of sorted range
	T *ptr4 = ptr3;				// begining of array
	T *ptr5 = ptr3, temp;
	if (*ptr5 > *ptr1) Swap(*ptr5, *ptr1);
	ptr1++; ptr3++;
	do {
		ptr5 = ptr3;
		temp = *ptr1;
		while (*ptr5 > temp && ptr5 != ptr4-1) *(ptr5+1) = *ptr5--;
		*(ptr5+1) = temp;
		ptr3++;
	} while(ptr1++ != ptr2);
}

// Selection Sort
template <typename T>
void SelectionSort( Array<T> & A ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	T * ptr1 = &A.get(0), * ptr2 = ptr1, * ptr3 = ptr1+A.len(), * ptr4;
	while (ptr2 != ptr3) {
		ptr4 = ptr2;
		ptr1 = ptr2+1;
		do {
			if (*ptr1 < *ptr4) {
				ptr4 = ptr1;
			}
		} while (ptr1++ != ptr3);
		Swap(*ptr2, *ptr4);
		ptr2++;
	}
}

// Bubble Sort
template <typename T>
void BubbleSort( Array<T> & A ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	T *ptr1 = &A.get(0), *ptr2 = ptr1+A.len(), *ptr3 = ptr1, *ptr4 = ptr3++;
	while(ptr2 != ptr1) {
		while(ptr4 != ptr2) {
			if(*ptr4 > *ptr3) Swap(*ptr4, *ptr3);
			ptr4++; ptr3++;
		}
		ptr2--;
		ptr3 = ptr1; ptr4 = ptr3++;
	}
}

// Mergesort
template <typename T>
void MergeSort( Array<T> & A, const int low, const int high ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	if (low < high) {
		int mid = static_cast<int>((low + high)/2);
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		Merge(A, low, mid, high);
	}
}

template <typename T>
void Merge( Array<T> & A, const int low, const int mid, const int high ) {

	Array<T> B(high - low + 1);
	T *ptr = &A.get(low);
	do {
		B.insertLast(*ptr);
	} while(ptr++ != &A.get(high));
	
	int Bmid = static_cast<int>(B.len()/2);
	T *ptr1 = &B.get(0), *ptr2 = &B.get(Bmid), *ptr3 = ptr2++, *ptr4 = ptr1+B.len(), *ptr5 = &A.get(low);
	while (ptr1 != ptr3+1 && ptr2 != ptr4+1) {
		if (*ptr1 < *ptr2) *ptr5++ = *ptr1++;
		else *ptr5++ = *ptr2++;
	}
	while (ptr1 != ptr3+1) *ptr5++ = *ptr1++;
	while (ptr2 != ptr4+1) *ptr5++ = *ptr2++;
}

// Quicksort
template <typename T>
void QuickSort( Array<T> & A, const int low, const int high ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	if (low < high) {
		int pivotIdx = Partition(A, low, high);
		QuickSort(A, low, pivotIdx-1);
		QuickSort(A, pivotIdx+1, high);
	}
}

// Quicksort1
template <typename T>
void QuickSort1( Array<T> & A, const int low, const int high ) {
	if (A.isEmpty()) throw ArrayException("Array is empty!");
	if (low < high) {
		int pivotIdx = Partition1(A, low, high);
		QuickSort(A, low, pivotIdx-1);
		QuickSort(A, pivotIdx+1, high);
	}
}

// Choose first element as pivot
template <typename T>
int Partition1(Array<T> & A, const int low, const int high) {

	T * ptr1 = &A.get(low), * ptr2 = &A.get(high), * pivot = ptr1++;
	while (ptr2 != ptr1-1) {
		while (ptr2 != ptr1-1 && *ptr1 <= *pivot) ptr1++;
		while (ptr2 != ptr1-1 && *ptr2 > *pivot) ptr2--;
		if (ptr2 != ptr1-1) Swap(*ptr1++, *ptr2--);
	}
	if (pivot != ptr2) Swap(*pivot, *ptr2);
	return ptr2-&A.get(0);
}

// Choose random element as pivot
template <typename T>
int Partition(Array<T> & A, const int low, const int high) {
	
	srand(time(NULL));
	T a = low + rand() % (high - low), b = low + rand() % (high - low), c = low + rand() % (high - low), median;
	if (a >= b && a < c) median = a;
	else if (b > a && b < c) median = b;
	else median = c;
	Swap(A.get(low), A.get(median));
	T * ptr1 = &A.get(low), * ptr2 = &A.get(high), * pivot = ptr1++;
	while (ptr2 != ptr1-1) {
		while (ptr2 != ptr1-1 && *ptr1 <= *pivot) ptr1++;
		while (ptr2 != ptr1-1 && *ptr2 > *pivot) ptr2--;
		if (ptr2 != ptr1-1) Swap(*ptr1++, *ptr2--);
	}
	if (pivot != ptr2) Swap(*pivot, *ptr2);
	return ptr2-&A.get(0);
}

#endif // _SORTING
