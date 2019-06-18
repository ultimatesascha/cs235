#ifndef BST_H
#define BST_H

#include <iostream>
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST :	public BSTInterface {
public:
	BST();
	~BST();
	NodeInterface * getRootNode() const;
	bool insert(Node* &node, int data);
	bool add(int data);
	bool remove(int data);
	void clear();
	bool takeOut(Node* &node, int data);
private:
	Node* root;
	int size;
};

#endif