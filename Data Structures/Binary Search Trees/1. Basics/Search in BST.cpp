/*
Code: Search in BST

Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.

Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.

Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise. 

Constraints:
Time Limit: 1 second

Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true

Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false
*/

//Time Complexity - O(H)
//Space Complexity - O(H)
//where H is the height of the input BST
bool searchInBST(BinaryTreeNode<int>* root, int k) {
	if(root==NULL) {
		return false;
	}

	if(root->data==k) {
		return true;
	} else if(root->data<k) {
		return searchInBST(root->right, k);
	} else {
		return searchInBST(root->left, k);
	}
}