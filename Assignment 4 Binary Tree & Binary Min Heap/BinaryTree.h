/**
  * File      :   BianryTree.h
  * Created   :   Apr 12, 2019
  * Modified  :   Apr 20, 2019
  * Author    :   Tianye Zhao, Wenda Yang
  * IDE    	  :   Dev C++ 5.11
  ***********************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

// Exception class
class E : public exception {
    const char *msg;
    E(){};    // no default constructor
public:
    explicit E(const char *s) throw() : msg(s) {}
    const char* what() const throw() {return msg;}
};

// BinaryTree template
template <typename T>
class BinaryTree {
private:
	// Declare a structure for the list
	struct TreeNode {
		T value;	// The data in the node
		struct TreeNode *left;	// Left node
		struct TreeNode *right;	// Right node
	};
	TreeNode *root;	// tree root pointer

	// A function to create a node
	TreeNode * createNode(T key) {
		TreeNode *node = new TreeNode;
		node->value = key;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	
	void insert(const T & x, TreeNode * & t);
	void insert(T && x, TreeNode * & t);
	void remove(const T & x, Treeode * & t);
	TreeNode * findMin(TreeNode *t) const;
	TreeNode * findMax(TreeNode *t) const;
	bool contains(const T & x, TreeNode *t) const;
	void makeEmpty(TreeNode * & t);
	TreeNode * clone(TreeNode *t) const;
	
    TreeNode* getRoot() { return root; }
    void preOrder(TreeNode*);
    void inOrder(TreeNode*);
    void postOrder(TreeNode*);
	int count(TreeNode*);
	int h(TreeNode*);
	int countLess(TreeNode*, T);
	int countGreat(TreeNode*, T);
	void mir(TreeNode*);
	bool identical(TreeNode*, TreeNode*);
	int countLeaf(TreeNode*);
	int countSemiLeaf(TreeNode*);

public:
	
	BinaryTree(const BinaryTree & rhs);
	
	BinaryTree(void) { root = NULL; }	// Constructor
	BinaryTree(T);
	~BinaryTree(void);	// Destructor
	T& top();
	T pop_front();
	bool empty();
	void insertNode(T);
	void deleteNode(T, bool = false);
	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();
	int countLesserThan(T);
	int countGreaterThan(T);
	int length();
	int height();
	void clear();
	void mirror();
	bool isIdenticalTo(BinaryTree&);
	bool isIsomorphicWith(BinaryTree&);
	int countLeafNodes();
	int countSemiLeafNodes();
};

/**
 * Copy constructor
 */
BinaryTree(const BinaryTree & rhs) : root{ nullptr } {
	root = clone(rhs.root);
}

/**
 * Internal method to clone subtree
 */
TreeNode * clone(TreeNode *t) const {
	if (t == nullptr) return nullptr;
	else return new TreeNode{ t->value, clone(t->left), clone(t->right) };
}

// the constructor to create a binary tree which first node contains the value info and children are null
template <typename T>
BinaryTree<T>::BinaryTree(T info) {
	TreeNode *newNode = createNode(info);
	root = newNode;
}

// a destructor that remove all elements of binary tree
template <typename T>
BinaryTree<T>::~BinaryTree() {
	makeEmpty(root);
}

/**
 * Internal method to make subtree empty.
 */
template <typename T>
void makeEmpty(TreeNode * & t) {
    if (t != nullptr) {
    	makeEmpty(t->left);
    	makeEmpty(t->right);
    	delete t;
	}
	t = nullptr;
}

// to remove all elements of the binary tree
template <typename T>
void BinaryTree<T>::clear() {
	if (root == NULL) throw E("Binary Tree is empty!");
	clr(root);
	root = NULL;
}

// to get the first element of the binary tree
template <typename T>
T& BinaryTree<T>::top() {
	return root->value;
}

// to remove first node of the binary tree and to return its value
template <typename T>
T BinaryTree<T>::pop_front() {
    if (root != NULL) {
        T temp = root->value;
        TreeNode *tempNode = root, *nodePtr = root->left;
        while (nodePtr->right != NULL) nodePtr = nodePtr->right;
        nodePtr->right = root->right->left;
        root->right->left = root->left;
        root = root->right;
        delete tempNode;
        return temp;
    }
}

// to test if the binary tree is empty or no
template <typename T>
bool BinaryTree<T>::empty() {
	return root == NULL;
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert(const T & x, TreeNode * & t) {
	if (t == nullptr) t = createNode(move(x));
	else if (x < t->value) insert(move(x), t->left);
	else if (t->value < x) insert(move(x), t->right);
}

// to insert a node in the binary tree
template <typename T>
void BinaryTree<T>::insertNode(T info) {
	insert(info, root);
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
bool contains(const T & x, TreeNode *t) const {
	if (t == nullptr) return false;
	else if (x < t->value) return contains(x, t->left);
	else if (t->value < x) return contains(x, t->right);
	else return true;	// Match
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
TreeNode *  findMin(TreeNode *t) const {
	if (t == nullptr) return nullptr;
	if (t->left == nullptr) return t;
	return findMin(t->left);
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
TreeNode *  findMax(TreeNode *t) const {
	if (t != nullptr) return nullptr;
	while (t->right != nullptr) t = t->right;
	return t;
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void remove(const T & x, TreeNode * & t) {
	if (t == nullptr) return;	//Item not found; do nothing
	if (x < t->value) remove(x, t->left);
	else if (t->value < x) remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) {	// Two children
		t->value = findMin(t->right)->value;
	}
}
// to delete a node the binary tree, if removerAll is true, all occurrence of info will be removed,
// otherwise, only the first occurrence of info will be removed
template <typename T>
void BinaryTree<T>::deleteNode(T info, bool removeAll) {
	if (root == NULL) return;
	if (root->value == info) {
		pop_front();
		if (!removeAll) return;
	}
	TreeNode *node = root, *parent;
	while (node != NULL) {
        if (node->value == info) {
            if (node->left == NULL && node->right == NULL) {
                if (parent->value > info) parent->left = NULL;
                else parent->right = NULL;
                delete node;
                return;
            } else if (node->left != NULL && node->right != NULL) {
                TreeNode *tempNode = node, *nodePtr = node->left;
                while (nodePtr->right != NULL) nodePtr = nodePtr->right;
                nodePtr->right = node->right->left;
                node->right->left = node->left;
                node = node->right;
                delete tempNode;
            } else if (node->left == NULL && node->right != NULL) {
                TreeNode *tempNode = node;
                if (parent->value > node->right->value) parent->left = node->right;
                else parent->right = node->right;
                node = node->right;
                delete tempNode;
            } else {
                TreeNode *tempNode = node;
                if (parent->value > node->left->value) parent->left = node->left;
                else parent->right = node->left;
                node = node->left;
                delete tempNode;
            }

            if (!removeAll) return;
        } else if (node->value > info) {
            parent = node;
            node = node->left;
        } else {
            parent = node;
            node = node->right;
        }
	}
}

// to display the binary tree using pre-order traversal
template <typename T>
void BinaryTree<T>::preOrder(TreeNode *node) {
	if (node == NULL) return;
    cout << node->value << endl;
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BinaryTree<T>::preOrderTraversal() {
	if (root == NULL) throw E("Binary Tree is empty!");
	preOrder(root);
}

// to display the binary tree using in-order traversal
template <typename T>
void BinaryTree<T>::inOrder(TreeNode *node) {
	if (node == NULL) return;
    inOrder(node->left);
    cout << node->value << endl;
    inOrder(node->right);
}

template <typename T>
void BinaryTree<T>::inOrderTraversal() {
	if (root == NULL) throw E("Binary Tree is empty!");
	inOrder(root);
}

// to display the binary tree using post-order traversal
template <typename T>
void BinaryTree<T>::postOrder(TreeNode *node) {
	if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << endl;
}

template <typename T>
void BinaryTree<T>::postOrderTraversal() {
	if (root == NULL) throw E("Binary Tree is empty!");
	postOrder(root);
}

// to count the nodes which value is lesser than val in the binary tree
template <typename T>
int BinaryTree<T>::countLess(TreeNode* node, T val) {
    if (node == NULL) return 0;
	if (node->value < val) return 1 + countLess(node->left, val) + countLess(node->right, val);
	else return countLess(node->left, val) + countLess(node->right, val);
}

template <typename T>
int BinaryTree<T>::countLesserThan(T val) {
	return countLess(root, val);
}

// to count the nodes which value is greater than val in the binary tree
template <typename T>
int BinaryTree<T>::countGreat(TreeNode *node, T val) {
    if (node == NULL) return 0;
	if (node->value > val) {
		return 1 + countGreat(node->left, val) + countGreat(node->right, val);
	}
	else return countGreat(node->left, val) + countGreat(node->right, val);
}

template <typename T>
int BinaryTree<T>::countGreaterThan(T val) {
	return countGreat(root, val);
}

// to count the number of nodes in the binary tree
template <typename T>
int BinaryTree<T>::count(TreeNode *node) {
	if (node == NULL) return 0;
	else return 1 + count(node->left) + count(node->right);
}

template <typename T>
int BinaryTree<T>::length() {
	return count(root);
}

// to compute the height of the binary tree
template <typename T>
int BinaryTree<T>::h(TreeNode *node) {
	if (node == NULL) return 0;
	else return h(node->left) > h(node->right) ? 1+h(node->left) : 1+h(node->right);
}

template <typename T>
int BinaryTree<T>::height() {
	return h(root);
}

// swaps the left and right pointers of the tree
template <typename T>
void BinaryTree<T>::mir(TreeNode *node) {
    if (node == NULL) return;
	TreeNode *tempNode = node->right;
	node->right = node->left;
	node->left = tempNode;
	mir(node->left);
	mir(node->right);
}

template <typename T>
void BinaryTree<T>::mirror() {
	mir(root);
}

// determines if the current binary tree is identical to the binary tree B
template <typename T>
bool BinaryTree<T>::identical(TreeNode *nodeA, TreeNode *nodeB) {
	if (nodeA == NULL && nodeB == NULL) return true;
	if (nodeA != NULL && nodeB != NULL) return nodeA->value == nodeB->value && identical(nodeA->left, nodeB->left) && identical(nodeA->right, nodeB->right);
	return false;
}

template <typename T>
bool BinaryTree<T>::isIdenticalTo(BinaryTree &B) {
	return identical(root, B.getRoot());
}

// determines if the current binary tree is siomorphic with the binary tree B
template <typename T>
bool BinaryTree<T>::isIsomorphicWith(BinaryTree &B) {
	B.mirror();
	return isIdenticalTo(B);
}

// counts the number of leaf nodes of the binary tree
template <typename T>
int BinaryTree<T>::countLeaf(TreeNode* node) {
    if (node == NULL) return 0;
	else if (node->left == NULL && node->right == NULL) return 1;
	else return countLeaf(node->left) + countLeaf(node->right);
}

template <typename T>
int BinaryTree<T>::countLeafNodes() {
	return countLeaf(root);
}

// counts the number of semi-leaf nodes in the binary tree
template <typename T>
int BinaryTree<T>::countSemiLeaf(TreeNode* node) {
    if (node == NULL) return 0;
	else if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) return 1;
	else return countSemiLeaf(node->left) + countSemiLeaf(node->right);
}

template <typename T>
int BinaryTree<T>::countSemiLeafNodes() {
	return countSemiLeaf(root);
}

#endif // _BINARYTREE_H
