#include <iostream>
using namespace std;

vector<int>* rootToNodePath(BinaryTreeNode<int>* root, int data) {
	if(root==NULL) {
		return NULL;
	}

	if(root->data==data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* leftChild = rootToNodePath(root->left, data);
	if(leftChild!=NULL) {
		leftChild->push_back(root->data);
		return leftChild;
	}

	vector<int>* rightChild = rootToNodePath(root->right, data);
	if(rightChild!=NULL) {
		rightChild->push_back(root->data);
		return rightChild;
	} else {
		return NULL;
	}
}

