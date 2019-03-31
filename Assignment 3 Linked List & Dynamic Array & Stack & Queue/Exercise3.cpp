/**
  * File      :   Exercise3.cpp
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 31, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#include "Stack_LinkedList.h"
#include "Stack_DynamicArray.h"
#include <cstdio>
using namespace std;

// main function
int main( int argc, char ** argv ) {

	try {
		Stack_LinkedList<int> slist1;
		slist1.empty(); 
		slist1.empty();
		slist1.push(13);
		slist1.top();
		slist1.top();
		slist1.pop();    	
		
		Stack_DynamicArray<int> list;
		list.empty();
		list.push(13);
		list.top();
		list.pop();
	    	
	    puts("Press any key to exit.");
		getchar();
		
	} catch (E & e) {
		printf("Stack Error: %s", e.what());
	}
	    
    return 0;
}
