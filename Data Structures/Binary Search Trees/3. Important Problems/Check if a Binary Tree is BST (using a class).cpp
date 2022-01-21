/*
Check if a Binary Tree is BST

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.

Constraints :
Time Limit: 1 second

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/


//Time Complexity - O(n)

#include <climits>

//Triplet class 
class isBSTReturn{
public: 
	bool isBST;
	int minimum;
	int maximum;
};

//Function used to return the isBSTReturn class object
isBSTReturn isBST3(BinaryTreeNode<int>* root) {
	if(root==NULL) {
		isBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	//Recursively calling for both left and right sub tree
	isBSTReturn leftPart = isBST3(root->left);
	isBSTReturn rightPart = isBST3(root->right);

	//Saving the maximum and minimum 
	int minimum = min(root->data, min(leftPart.minimum, rightPart.minimum));
	int maximum = max(root->data, max(leftPart.maximum, rightPart.maximum));

	bool isBSTFinal = (root->data > leftPart.maximum) && (root->data <= rightPart.minimum) && (leftPart.isBST) && (rightPart.isBST);

	//Making an object
	isBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;

	return output;
}	

//Main Function
bool isBST(BinaryTreeNode<int> *root) {

	return isBST3(root).isBST;
}