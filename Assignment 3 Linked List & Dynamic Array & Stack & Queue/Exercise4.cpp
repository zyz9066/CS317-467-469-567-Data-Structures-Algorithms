/**
  * File      :   Exercise4.cpp
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#include "Queue_LinkedList.h"
#include "Queue_DynamicArray.h"
#include "Queue_Circular_DynamicArray.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {


    	Queue_LinkedList<int> test;
		test.empty();
		test.push(2);
		test.push(22);
		test.push(23);
		test.push(24);
		test.front();
		test.pop();

		Queue_DynamicArray<int> test1;
		test1.empty();
		test1.push(2);
		test1.push(22);
		test1.push(23);
		test1.push(24);
		test1.~Queue_DynamicArray();
		test1.front();
		test1.pop();

		Queue_Circular_DynamicArray<int> test2;
		test2.empty();
		test2.push(2);
		test2.push(22);
		test2.push(23);
		test2.push(24);
		test2.~Queue_Circular_DynamicArray();
		test2.front();
		test2.pop();
    	
    cout << "Press any key to exit." << endl;
	cin.get();
        
    
    return 0;
}
