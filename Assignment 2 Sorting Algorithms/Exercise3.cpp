/**
  * File      :   Exercise3.cpp
  * Date      :   Feb 28, 2018
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#include "Array.h"
#include <cstdio>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
    	
        int size;
    	printf("Please enter integer array size: ");
    	scanf("%d", &size);
    	
        Array<int> A(size), B(size);
        
        // Initialize array
        int value;
        for (int i = 0; i < A.size(); i++) {
        	printf("Please enter integer %d: ", i+1);
        	scanf("%d", &value);
          	A.push_back(value);
          	B.push_back(value);
        } 
        getchar();
        
        // Display array
        puts("\nDisplay values in array:");
        A.display();
        printf("Array length is %d, array size is %d.\n", A.len(), A.size());
        int index;
        
        printf("\nPlease enter the index to delete: ");
        scanf("%d", &index);
        getchar();
        
        puts("\nDisplay values in array after deletion:");
        A.deleteAt(index);
        A.display();
        printf("Array length is %d, array size is %d.\n", A.len(), A.size());

        puts("\nPerform insertion for same array:");
        B.display();
		printf("\nPlease enter a integer to insert: ");
        scanf("%d", &value);
        getchar();

        printf("\nPlease enter the index to insert: ");
        scanf("%d", &index);
        getchar();

        puts("\nDisplay values in array after insertion:");
        B.insertAt(index, value);
        B.display();
        printf("Array length is %d, array size is %d.\n", B.len(), B.size());
        
        puts("\nPress any key to exit.");
		getchar();
        
    } catch (ArrayException & e) {
        cout << "Array error: " << e.what() << endl;
    }
    
    return 0;
}
