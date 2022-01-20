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
//Space Complexity - O(1)

#include<climits>

//Helper Function
bool isBSTHelper(BinaryTreeNode<int> *root, int min, int max) {
	//If no nodes are present, then a Binary Tree is same as BST
	if(root==NULL) {
		return true;
	}

	//If the value gets out of the range
	if(root->data<=min || root->data>=max) {
		return false;
	}

	//Taking 'and' logical operation to get the answer true only if all the recursive functions returns true or else false
	return isBSTHelper(root->left, min, root->data) && isBSTHelper(root->right, root->data, max);
}

//Main Function
bool isBST(BinaryTreeNode<int> *root) {

	//Passing the minimum value and maximum value possible 
	return isBSTHelper(root, INT_MIN, INT_MAX);
}