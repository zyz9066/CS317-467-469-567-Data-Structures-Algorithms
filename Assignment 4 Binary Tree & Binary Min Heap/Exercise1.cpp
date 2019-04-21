/**
  * File      :   Exercise1.h
  * Created   :   Apr 12, 2019
  * Modified  :   Apr 20, 2019
  * Author    :   Tianye Zhao, Wenda Yang
  * IDE    	  :   Dev C++ 5.11
  ***********************************/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// main function
int main( int argc, char ** argv ) {

	try {
		BinaryTree<int> tree;
		BinaryTree<int> tree2;

		tree.insertNode(4);
		tree.insertNode(5);
		tree.insertNode(3);
		tree2.insertNode(4);
		tree2.insertNode(5);
		tree2.insertNode(3);
		
		tree2.mirror();
		tree.isIsomorphicWith(tree2);
		//cout << tree.isIsomorphicWith() << endl;
		
		tree.insertNode(8);
		tree.insertNode(8);
		tree.insertNode(15);
		tree.insertNode(17);
		tree.insertNode(21);
		tree.insertNode(21);
		tree.insertNode(39);
		
	    tree.inOrderTraversal();

		
		tree.deleteNode(21, true);
		tree.deleteNode(8);
		tree.postOrderTraversal();	
		tree.length();
		tree.length();
		tree.countLeafNodes();
		tree.countSemiLeafNodes();
		
		//cout << tree.length() << endl;
		//cout << tree.height() << endl;
	    //cout << tree.countLeafNodes() << endl;
		//cout << tree.countSemiLeafNodes() << endl;

		tree.top();
		tree.pop_front();
		tree.empty();

		//cout << tree.top() << endl;
		//cout << tree.pop_front() << endl;
		//cout << tree.empty() << endl;

		tree.countGreaterThan(3);
		tree.countLesserThan(5);
		
		//cout << tree.countGreaterThan(3) << endl;
		//cout << tree.countLesserThan(5) << endl;
		
		tree.preOrderTraversal();
		
		//cout << tree.empty() << endl;
		
		tree.inOrderTraversal();
		tree.isIdenticalTo(tree2);
		
		//cout << tree.isIdenticalTo(tree2) << endl;
		
		
		tree.clear();
	    cout << "Press any key to exit." << endl;
		cin.get();
	} catch (E & e) {
		cout << "Binary Tree error: " << e.what() << endl;
	}
	
    return 0;
}
