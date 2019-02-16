// Exercise3.cpp by Tianye Zhao
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
        }
        
        // Display array
        cout << "Display array: " << endl;
        A.display();
        
        // Find minimum and maximum value
        int minPos = A.findMin(), maxPos = A.findMax();
        cout << "The minimum value is " << A.get(minPos) << " and the first occurence is in position " << minPos << endl;
        cout << "The maximum value is " << A.get(maxPos) << " and the first occurence is in position " << maxPos << endl;
        
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
