/**
  * File      :   Exercise3.cpp
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 24, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
#include "Stack_LinkedList.h"
#include "Stack_DynamicArray.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {

	Stack_LinkedList<int> slist1;
	slist1.empty(); 
	cout << slist1.empty() << endl;
	slist1.push(13);
	slist1.top();
	cout << slist1.top() << endl;
	cout << slist1.pop() << endl;    	
	
	Stack_DynamicArray<int> list;
	list.empty();
	list.push(13);
	list.top();
	list.pop();
	list.~Stack_DynamicArray();
    	
    cout << "Press any key to exit." << endl;
	cin.get();
        

    
    return 0;
}
