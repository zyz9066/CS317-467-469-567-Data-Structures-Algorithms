/**
  * File      :   Exercise1.cpp
  * Created   :   Mar 18, 2019
  * Modified  :   Mar 31, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/

#include "LinkedList.h"
#include <cstdio>
using namespace std;

// main function
int main( int argc, char ** argv ) {

	try {
		LinkedList<int> list;
		
		list.appendNode(2);
		list.appendNode(15);
		list.appendNode(7);
		list.appendNode(22);
		
		list.displayList();
		
		list.insertNode(10);
		list.displayList();
	
		list.deleteNode(7);
		list.displayList();
		
		list.pop_front();
		list.displayList();
			
	
			
		list.count(10);
		list.displayList();
			
		list.count(11);
		list.displayList();
			
		list.empty();
		list.displayList();
			
		list.get(1);
		list.displayList();
			
		list.length();
		list.displayList();
	
		list.sortByInsertion();
		list.displayList();
			
		list.sortBySelection();
		list.displayList();
			
		list.top();
		list.displayList();
	
		list.clear();
	
	    puts("Press any key to exit.");
		getchar();
		
	} catch (E & e) {
		printf("Linked List error: %s", e.what());
	}
    	    
    return 0;
}
