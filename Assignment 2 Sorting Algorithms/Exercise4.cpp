/**
  * File      :   Exercise4.cpp
  * Date      :   Feb 28, 2018
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#include "Array.h"
#include "Sorting.h"
#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;

Array<int> createOrderedArray(const int size) {
	Array<int> A(size);
        
    // Initialize array with random ascending numbers
    for (int i = 0; i < size; i++) {
        A.insertLast(i+1);
    }
    
    return A;
}

Array<int> createRandomArray(const int size) {
	Array<int> A(size);
        
    // Initialize random seed
  	srand(time(NULL));
        
    // Initialize array with random ascending numbers
    for (int i = 0; i < size; i++) {
        A.push_back(rand() % (size*10));
    }
    
    return A;
}

// main function
int main( int argc, char ** argv ) {

    try {

        const char *insertionStr = "InsertionSort";
		const char *selectionStr = "SelectionSort";
		const char *bubbleStr = "BubbleSort";
		const char *mergeStr = "MergeSort";
		const char *quickStr1 = "QuickSort1";
		const char *quickStr = "QuickSort";
		
        int size[] = {10, 20, 0};
        
        struct timespec start, finish;
        int *ptr = size, i;
        double elapsed;
        puts("Sorting Type\tArray Type\tNo.\tElapsed Time/ms");
        while (*ptr != 0) { 	
        	
        	for (i = 0; i < 6; i++) {
        		Array<int> A = createOrderedArray(*ptr);
				
				clock_gettime(CLOCK_MONOTONIC, &start);
				switch(i) {
					case 0: InsertionSort(A); printf("%s", insertionStr); break;
					case 1: SelectionSort(A); printf("%s", selectionStr); break;
					case 2: BubbleSort(A); printf("%s", bubbleStr); break;
					case 3: MergeSort(A, 0, A.len()); printf("%s", mergeStr); break;
					case 4: QuickSort1(A, 0, A.len()); printf("%s", quickStr1); break;
					case 5: QuickSort(A, 0, A.len()); printf("%s", quickStr); break;
					default: break;
				}
		        clock_gettime(CLOCK_MONOTONIC, &finish);
		        
		        elapsed = finish.tv_sec - start.tv_sec;
		        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
		        printf("\tOrdered Array\t%d\t%f\n", *ptr, elapsed * 1000);
		        
		        Array<int> B = createRandomArray(*ptr);
		        
		        clock_gettime(CLOCK_MONOTONIC, &start);
				switch(i) {
					case 0: InsertionSort(B); printf("%s", insertionStr); break;
					case 1: SelectionSort(B); printf("%s", selectionStr); break;
					case 2: BubbleSort(B); printf("%s", bubbleStr); break;
					case 3: MergeSort(B, 0, B.len()); printf("%s", mergeStr); break;
					case 4: QuickSort1(B, 0, B.len()); printf("%s", quickStr1); break;
					case 5: QuickSort(B, 0, B.len()); printf("%s", quickStr); break;
					default: break;
				}
		        clock_gettime(CLOCK_MONOTONIC, &finish);
		        
		        elapsed = finish.tv_sec - start.tv_sec;
		        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
		        printf("\tRandom Array\t%d\t%f\n", *ptr, elapsed * 1000);
			}
	        
	        ptr++;
		}	

        puts("\nPress any key to exit.");
		getchar();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
