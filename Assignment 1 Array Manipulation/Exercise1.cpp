// Exercise1.cpp by Tianye Zhao
// IDE: Dev-C++
// updated 2019-02-10
#include "Array.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
        Array<int> A(100);
        
        // Initialize array
        for (int i = 0; i < 100; i++) {
            A.insertLast(2 * i + 1);
        } 
        
        // Display array
        cout << "Display values in array: " << endl;
        A.display();
        
        // Count number between 15 and 65
        int a = 15, b = 65;
        cout << "The number of elements between 15 and 65 is " << A.countBetween(a, b) << endl;
        
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
