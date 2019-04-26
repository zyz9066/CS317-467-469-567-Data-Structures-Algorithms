// Exercise2.cpp by Tianye Zhao
// IDE: Dev-C++ 5.11
// updated 2019-02-10
#include "Array.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
        Array<int> A(10);
        
        // Ask for user input
        int number, val, pos;
        cout << "Please enter 10 integers" << endl;
        for (int i = 0; i < 10; i++) {
        	cout << "Integer " << i+1 << ": ";
        	cin >> number;
        	A.insertLast(number);
        } 
        
        // Ask for number to delete
        cout << "Please enter a integer to delete: ";
        cin >> val;
        
        // Check and remove number
		pos = A.linearSearch(val);
        if (pos != -1) {
        	A.remove(val);
        	cout << "Value is found and first occurence is deleted." << endl;
		} else {
			cout << "Value not found." << endl;
		}
        
        // Display array
        cout << "Display array after deletion: " << endl;
        A.display();
        
        cin.get();
        cin.get();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
