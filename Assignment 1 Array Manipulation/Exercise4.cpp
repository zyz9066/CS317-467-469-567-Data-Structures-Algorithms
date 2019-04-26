// Exercise4.cpp by Tianye Zhao
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
        Array<int> A(15);
        
        // Initialize random seed
  		srand(time(NULL));
        
        // Initialize array with random ascending numbers
        for (int i = 0; i < 10; i++) {
        	A.push_back(i * 10 + rand() % 10);
        }
        
        // Display array
        cout << "Display array: " << endl;
        A.display();
        
        // Ask for number to insert
        int val;
        cout << "Please enter a interger to insert: ";
        cin >> val;
        A.insertByOrder(val);
        
        // Display array after insertion
        cout << "Display array after insert " << val << endl;
        A.display();
        
        cin.get();
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
