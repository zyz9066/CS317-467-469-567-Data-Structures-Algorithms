// Exercise6.cpp by Tianye Zhao
// IDE: Dev-C++ 5.11
// updated 2019-02-10
#include "array.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
        Array<int> A(10);
        
        // Initialize random seed
  		srand(time(NULL));

        // Initialize array with random numbers
        for (int i = 0; i < 10; i++) {
        	A.insertLast(rand() % 100);
        	//A.insertLast(i * 10 + rand() % 10); // Initialize array with random ascending numbers
        }
        
        // Display array
        cout << "Display array: " << endl;
        A.display();
        
        // Sort array
        A.selectionSort();
        cout << "Display array after sorting: " << endl;
        A.display();
		
		// Ask for value to search
        int val;
        cout << "Please enter a interger to search: ";
        cin >> val;
        
        // Search value
        int pos1, pos2;
        pos1 = A.linearSearch(val);
        pos2 = A.binarySearch(val, 0, A.end());
        
        if (pos1 != -1) {
        	cout << "Value found by linear search in position " << pos1 << endl;
		} else {
			cout << "Value not found by linear search, position returns " << pos1 << endl;
		}
		
		if (pos2 != -1) {
        	cout << "Value found by binary search in position " << pos2 << endl;
		} else {
			cout << "Value not found by binary search, position returns " << pos2 << endl;
		}
        
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
