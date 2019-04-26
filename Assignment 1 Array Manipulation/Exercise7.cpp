// Exercise7.cpp by Tianye Zhao
// IDE: Dev-C++ 5.11
// updated 2019-02-10
#include "Array.h"
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
        	A.push_back(rand() % 10);
        }
        
        // Display array
        cout << "Display array: " << endl;
        A.display();
		
		// Find most existing value
		cout << "The most exsiting value is " << A.findMost() << endl;
        
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
