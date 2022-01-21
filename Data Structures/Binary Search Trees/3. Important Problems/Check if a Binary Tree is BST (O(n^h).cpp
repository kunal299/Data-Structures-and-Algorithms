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

//Time Complexity - O(n^h)

//Function used to give the maximum value under the given root
int maximum(BinaryTreeNode<int>* root) {
	if(root==NULL) {
		return INT_MIN;
	}

	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

//Function used to give the minimum value under the given root
int minimum(BinaryTreeNode<int>* root) {
	if(root==NULL) {
		return INT_MAX;
	}

	return min(root->data, max(minimum(root->left), minimum(root->right)));
}

//Main Function
bool isBST(BinaryTreeNode<int> *root) {
	if(root==NULL) {
		return true;
	}
	
	bool leftMax = maximum(root->left);
	bool rightMin = mimimum(root->right);

	bool output = root->data > leftMax && root->data <=rightMin && isBST(root->left) & isBST(root->right);
	return output;
}