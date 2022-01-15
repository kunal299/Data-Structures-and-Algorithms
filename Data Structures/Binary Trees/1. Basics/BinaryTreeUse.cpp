#include<iostream> 
#include<queue>

//This custom header file contains the class for the BinaryTreeNode
#include "BinaryTreeNode.h"

using namespace std;

//Function used to print all the nodes of the Binary Tree
void printTree(BinaryTreeNode<int>* root) {
	//As this is not a Generic Tree, we have to give a base case as
	//here we have at max two nodes: left and right.
	//Here, there is no for loop which will handle it implicity.

	//Base Case not an edge case
	if(root==NULL) {
		return;
	}

	cout<<root->data<<": ";
	if(root->left != NULL) {
		cout<<"L"<<root->left->data<<", ";
	} 

	if(root->right != NULL) {
		cout<<"R"<<root->right->data;
	}

	cout<<endl;

	//Recursively call for the left and right nodes
	printTree(root->left);
	printTree(root->right);
}

//Function used to get the input of the Binary Tree from the user
BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout<<"Enter the data: ";
	cin>>rootData;

	//If user enters -1, that means previous node has no further (left|right) child node or both (left&right) child nodes
	if(rootData==-1) {
		return NULL;
	}

	//Creating a new node
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	//Creating new nodes for the left and right child nodes
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	//Connecting the child nodes to the root
	root->left = leftChild;
	root->right = rightChild;

	return root;

}

//Function used to get the input from the user in the better way.
//It gets the data from the user Level Wise.
BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<<"Enter the root data: ";
	cin>>rootData;

	cout<<endl;

	//Initially creating a root node of the binary tree
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	//Creating a queue to store the data in the FIFO manner
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		//Creating the left node of the root
		int leftChildData;
		cout<<"Enter the left child of "<<front->data<<": ";
		cin>>leftChildData;

		if(leftChildData!=-1) {
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}

		//Creating the right node of the root
		int rightChildData;
		cout<<"Enter the right child of "<<front->data<<": ";
		cin>>rightChildData;

		if(rightChildData!=-1) {
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
		cout<<endl;
	}

	return root;
}

//Function used to print the data of the Binary Tree Node Level Wise
void printTreeLevelWise(BinaryTreeNode<int>* root) {
	if(root==NULL) {
		return;
	}

	//Creating a queue to store the node pointers in a FIFO manner
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0) {
		//Storing the front node
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
 		
		cout<<front->data<<": ";

		//Printing for the left node
		if(front->left!=NULL) {
			cout<<"L"<<front->left->data<<", ";
			pendingNodes.push(front->left);
		}

		//Printing for the right node
		if(front->right!=NULL) {
			cout<<"R"<<front->right->data;
			pendingNodes.push(front->right);
		}

		cout<<endl;
	}
}

//You can directly paste this while running the program on the terminal: 
//1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 
int main() {
	//Basic way of creating root and nodes
	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

	//Connecting the child nodes to the rood node
	// root->left = node1;
	// root->right = node2;

	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	delete root;
}