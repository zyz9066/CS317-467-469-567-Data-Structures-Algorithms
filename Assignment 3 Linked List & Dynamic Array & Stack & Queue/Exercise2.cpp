/**
  * File      :   Exercise2.cpp
  * Created   :   Mar 23, 2019
  * Modified  :   Mar 31, 2019
  * Author    :   Tianye Zhao
  * IDE    	  :   Dev C++ 5.11
  ***********************************/
  
#include "DynamicArray.h"
#include <cstdio>
using namespace std;

// main function
int main( int argc, char ** argv ) {

    try {
    	
    	DynamicArray<int> a(10);
		a.add(3);
		a.add(5);
		a.add(7);
		a.add(8);
		a.add(13);
		a.add(20);
		a.add(1);
		a.add(6);
		a.add(9);
		a.add(15);
		a.add(21);
		a.add(34);
		a.add(42);
		a.add(22);
		a.add(10);
		a.add(11);
		a.add(17);
		a.add(30);
		a.add(16);
		a.remove(3);
		a.remove(4);
		a.remove(5);
		a.remove(16);
		a.remove(108);
		a.display();

    	
        puts("Press any key to exit.");
		getchar();
        
    } catch (E & e) {
        printf("Dynamic Array error: %s", e.what());
    }
    
    return 0;
}
