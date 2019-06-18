#include "Node.h"

Node::Node(int data) {
	value = data;
	left = NULL;
	right = NULL;
}

Node::~Node() {}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const {
	return true;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild() const {
	if (left == NULL) {
		return NULL;
	}
	else {
		return left;
	}
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild() const {
	if (right == NULL) {
		return NULL;
	}
	else {
		return right;
	}
}
