#include "BST.h"


BST::BST() {
	this->root = NULL;
	this->size = 0;
}


BST::~BST() {
	this->clear();
}

bool find(Node *node, int num) {
	if (node == NULL) {
		return false;
	}
	if (node->value == num) {
		return true;
	}
	if (num < node->value) {
		return find(node->left, num);
	}
	if (num > node->value) {
		return find(node->right, num);
	}
}

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() const {
	return root;
}

bool BST::insert(Node*& node, int num) {
	if (find(node, num)) {
		return false;
	}
	if (node == NULL) {
		node = new Node(num);
		size++;
		return true;
	}
	else {
		if (num < node->value) {
			return insert(node->left, num);
		}
		else if (num > node->value) {
			return insert(node->right, num);
		}
		else {
			return false;
		}
	}
}
/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data) {
	return insert(root, data);
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data) {
	return takeOut(root, data);
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {
	while (root != NULL) {
		remove(root->value);
	}
}

bool noChildren(Node* curr){
	if (curr->left == NULL && curr->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool twoChildren(Node* curr) {
	if (curr->left != NULL && curr->right != NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool leftChild(Node* curr) {
	if (curr->left != NULL && curr->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool rightChild(Node* curr) {
	if (curr->right != NULL && curr->left == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int getHighest(Node* node) {
	if (node->right == NULL) {
		return node->value;
	}
	else {
		return getHighest(node->right);
	}
}


bool BST::takeOut(Node* &getRidOf, int data) {
	if (!find(getRidOf, data)) {
		return false;
	}
	else {
		if (getRidOf == NULL) {
			return false;
		}
		else {
			if (getRidOf->value < data) {
				return takeOut(getRidOf->right, data);
			}
			else if (getRidOf->value > data) {
				return takeOut(getRidOf->left, data);
			}
			else {
				if (noChildren(getRidOf)) {
					delete getRidOf;
					getRidOf = NULL;
					size--;
					return true;
				}
				else if (twoChildren(getRidOf)) {
					int number = getHighest(getRidOf->left);
					takeOut(getRidOf->left, number);
					getRidOf->value = number;
					size--;
					return true;
				}
				else if (leftChild(getRidOf)) {
					Node *curr = getRidOf;
					getRidOf = curr->left;
					delete curr;
					size--;
					return true;
				}
				else if (rightChild(getRidOf)) {
					Node *curr = getRidOf;
					getRidOf = curr->right;
					delete curr;
					size--;
					return true;
				}
			}
		}
	}
}

