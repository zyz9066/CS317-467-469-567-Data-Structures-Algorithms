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
		T value;
		struct TreeNode *left;
		struct TreeNode *right;
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

    void clr(TreeNode*);
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

template <typename T>
BinaryTree<T>::BinaryTree(T info) {
	TreeNode *newNode = createNode(info);
	root = newNode;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	clear();
}

template <typename T>
void BinaryTree<T>::clr(TreeNode *node) {
    if (node == NULL) return;
	clr(node->left);
	clr(node->right);
	delete node;
	node = NULL;
}
template <typename T>
void BinaryTree<T>::clear() {
	if (root == NULL) throw E("Binary Tree is empty!");
	clr(root);
	root = NULL;
}

template <typename T>
T& BinaryTree<T>::top() {
	return root->value;
}

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

template <typename T>
bool BinaryTree<T>::empty() {
	return root == NULL;
}

template <typename T>
void BinaryTree<T>::insertNode(T info) {
	TreeNode *newNode = createNode(info);
	if (root == NULL) {
		root = newNode;
		return;
	}
	TreeNode *nodePtr = root, *parentNode;
	while (nodePtr != NULL) {
		parentNode = nodePtr;
		if (nodePtr->value > info) {
			nodePtr = nodePtr->left;
		} else {
			nodePtr = nodePtr->right;
		}
	}
	if (parentNode->value > info) {
		parentNode->left = newNode;
	} else {
		parentNode->right = newNode;
	}
}

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

template <typename T>
int BinaryTree<T>::count(TreeNode *node) {
	if (node == NULL) return 0;
	else return 1 + count(node->left) + count(node->right);
}

template <typename T>
int BinaryTree<T>::length() {
	return count(root);
}

template <typename T>
int BinaryTree<T>::h(TreeNode *node) {
	if (node == NULL) return 0;
	else return h(node->left) > h(node->right) ? 1+h(node->left) : 1+h(node->right);
}

template <typename T>
int BinaryTree<T>::height() {
	return h(root);
}

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

template <typename T>
bool BinaryTree<T>::isIsomorphicWith(BinaryTree &B) {
	B.mirror();
	return isIdenticalTo(B);
}

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
