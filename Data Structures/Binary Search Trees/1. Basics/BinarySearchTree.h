#include "BinaryTreeNode.h"

class BST{
	BinaryTreeNode<int>* root;

public: 
	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}
private:
	void deleteData(int data, BinaryTreeNode<int>* node) {
		if(node==NULL) {
			return;
		}

		if(node->data==data) {
			if(node->left==NULL && node->right==NULL) {
				node = NULL;
			} else if(node->left!=NULL && node->right==NULL) {
				node = node->left;
			} else if(node->left==NULL && node->right!=NULL) {
				node = node->right;
			}
		} else if(node->data>data) {
			deleteData(data, node->left);
		} else {
			deleteData(data, node->right);
		}
	}

public:
	void deleteData(int data) {
		deleteData(data, root);
	}

private:
	void insert(int data, BinaryTreeNode<int>* node) {
		if(node==NULL) {
			BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
			return root;
		} 

		if(node->data>data) {
			insert(data, node->left);
		} else {
			insert(data, node->right);
		}
	}

public:
	void insert(int data) {
		insert(data, root);
	}

private: 
	bool hasData(int data, BinaryTreeNode<int>* node) {
		if(node==NULL) {
			return false;
		}

		if(node->data==data) {
			return true;
		} else if(data<node->data) {
			return hasData(data, node->left);
		} else {
			return hasData(data, node->right);
		}
	}

public: 
	bool hasData(int data) {
		return hasData(data, root);
	}
};