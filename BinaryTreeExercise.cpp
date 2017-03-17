// BinaryTreeExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


struct node {
	int data;
	struct node* left;
	struct node* right;
};

node* NewNode(int data) {
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

static int lookup(node* node, int target) {
	//Base case - empty tree
	if (node == NULL) {
		return false;
	}
	else if (target == node->data){
			return true;
	}
	else {
		if (target < node->data) {
			return lookup(node->left, target);
		}
		else {
			return lookup(node->right, target);
		}
	}
}

node* insert(node* n, int data) {
	if (n == NULL) {
		return NewNode(data);
	}
	else if (n->data == data) {
		return n;
	} else {
		if (data < n->data) {
			n->left = insert(n->left, data);
		}
		else {
			n->right = insert(n->right, data);
		}
		return n;
	}
}

int size(node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return (size(node->left) + 1 + size(node->right));
	}
}

int maxDepth(struct node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return std::max(maxDepth(node->left), maxDepth(node->right)) + 1;
	}
}

int minValue(struct node* node) {
	if (node->left == NULL) {
		return node->data;
	}
	else {
		return minValue(node->left);
	}
}

void printTree(struct node* node) {
	//in order
	if (node == NULL) {
		return;
	}
	else {
		printTree(node->left);
		cout << node->data << " ";
		printTree(node->right);
	}
}

void printPostOrder(struct node* node) {
	if (node == NULL) {
		return;
	}
	else {
		printPostOrder(node->left);
		printPostOrder(node->right);
		cout << node->data << " ";
	}
}

node* build123() {
	node* n = NULL;
	n = insert(n, 2);
	n = insert(n, 1);
	n = insert(n, 3);
	return n;
}

node* buildOne123() {
	node* n = NewNode(2);
	n->left = NewNode(1);
	n->right = NewNode(3);
	return n;
}

node* testCase1() {
	node* n = NULL;
	n = insert(n, 7);
	n = insert(n, 8);
	n = insert(n, 5);
	n = insert(n, 4);
	n = insert(n, 3);
	n = insert(n, 2);
	return n;
}

node* testCase2() {
	node* n = NULL;
	return n;
}

node* testCase3() {
	node* n = NULL;
	n = insert(n, 5);
	n = insert(n, 6);
	n = insert(n, 7);
	n = insert(n, 8);
	//n = insert(n, 0);
	return n;
}

node* testCase4() {
	node* n = NULL;
	n = insert(n, 5);
	n = insert(n, 3);
	n = insert(n, 9);
	n = insert(n, 6);
    n = insert(n, 1);
	n = insert(n, 4);
	return n;
}

int main()
{
	node* nodeA = buildOne123();
	cout << "Size buildOne123(): " << size(nodeA) << endl;
	node* node1 = testCase1();
	cout << "Size testCase1(): " << size(node1) << endl;
	node* nodeB = build123();
	cout << "Size build123(): " << size(nodeB) << endl;
	node* node2 = testCase2();
	cout << "Size testCase2(): " << size(node2) << endl;
	node* node3 = testCase3();
	cout << "Size testCase3(): " << size(node3) << endl;
	node* node4 = testCase4();
	cout << "maxDepth testCase3(): " << maxDepth(node3) << endl;
	cout << "maxDepth testCase4(): " << maxDepth(node4) << endl;
	cout << "minValue buildOne123(): " << minValue(nodeA) << endl;
	cout <<  "minValue testCase1(): " << minValue(node1) << endl;
	cout << "minValue testCase3(): " << minValue(node3) << endl;
	cout << "minValue testCase4(): " << minValue(node4) << endl;
	
	cout << "printTree buildOne123(): ";
	printTree(nodeA);
	cout << endl;
	cout << "printTree testCase1(): ";
	printTree(node1);
	cout << endl;
	cout << "printTree testCase2(): ";
	printTree(node2);
	cout << endl;
	cout << "printTree testCase3(): ";
	printTree(node3);
	cout << endl;
	cout << "printTree testCase4(): ";
	printTree(node4);
	cout << endl;

	cout << "printPostOrder buildOne123(): ";
	printPostOrder(nodeA);
	cout << endl;
	cout << "printPostOrder testCase1(): ";
	printPostOrder(node1);
	cout << endl;
	cout << "printPostOrder testCase2(): ";
	printPostOrder(node2);
	cout << endl;
	cout << "printPostOrder testCase3(): ";
	printPostOrder(node3);
	cout << endl;
	cout << "printPostOrder testCase4(): ";
	printPostOrder(node4);
	cout << endl;
    return 0;
}

