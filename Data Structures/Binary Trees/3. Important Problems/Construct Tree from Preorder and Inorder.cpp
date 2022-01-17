/*
Code: Construct Tree from Preorder and Inorder

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 

Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/

#include<map>

BinaryTreeNode<int>* helper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd, map<int, int> inMap) {
    if(preStart>preEnd || inStart>inEnd) {
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preStart]);
    
    int inRoot = inMap[root->data];
    int numsLeft = inRoot-inStart;
	    
    root->left = helper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = helper(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    map<int, int> inMap;
    for(int i=0; i<inLength; i++) {
        inMap[inorder[i]] = i;
    }
    
    BinaryTreeNode<int>* root = helper(preorder, 0, preLength-1, inorder, 0, inLength-1, inMap);
    return root;
}
