#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface {

public:
	int value;
	Node *left, *right;

	Node(int data);
	~Node();
	int getData() const;
	NodeInterface* getLeftChild() const;
	NodeInterface* getRightChild() const;
private:
	void setValue(int data) {
		value = data;
	}

	void setLeftChild(Node* data) {
		left = data;
	}

	void setRightChild(Node* data) {
		right = data;
	}
};

#endif