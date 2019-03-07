/**
  * File      :   Exercise1.cpp
  * Date      :   Feb 24, 2018
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#include "array.h"
#include <cstdio>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
    	
    	int size;
    	printf("Please enter integer array size: ");
    	scanf("%d", &size);
    	
        Array<int> A(size);
        
        // Initialize array
        int value;
        for (int i = 0; i < A.size(); i++) {
        	printf("Please enter integer %d: ", i+1);
        	scanf("%d", &value);
            A.insertLast(value);
        } 
        getchar(); 
        
        // Display array
        puts("\nDisplay values in array:");
        A.display();
        
        puts("\nDisplay values in array after reversion:");
        A.reverse();
        A.display();
        
        puts("\nPress any key to exit.");
		getchar();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
