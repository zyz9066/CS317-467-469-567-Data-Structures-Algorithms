/**
  * File      :   Exercise2.h
  * Created   :   Apr 12, 2019
  * Modified  :   Apr 19, 2019
  * Author    :   Tianye Zhao, Wenda Yang
  * IDE    	  :   Dev C++ 5.11
  ***********************************/

#include "BinaryMinHeap.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {

	try {
		BinaryMinHeap<int> heap(10);

		heap.insertKey(5);
		heap.insertKey(4);
		heap.insertKey(3);
		heap.insertKey(2);
		heap.insertKey(1);
		
		heap.percolate(1);
		heap.getMin();
		heap.extractMin();
		
		heap.getLeftChild(1);
		heap.getRightChild(1);
		
		cout << heap.getRightChild(1) << endl;
		cout << heap.getLeftChild(1) << endl;
		cout << heap.getMin() << endl;
		
		//cout << heap.empty() << endl;
		heap.deleteNode(1);
		cout << heap.extractMin() << endl;
		
		
		cout << "Press any key to exit." << endl;
		cin.get();
	} catch (E & e) {
		cout << "BinaryMinHeap error: " << e.what() << endl;
	}


    return 0;
}
