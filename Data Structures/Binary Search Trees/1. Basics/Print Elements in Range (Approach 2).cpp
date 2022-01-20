/*
Code: Print Elements in Range

Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.

Input format:
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. 
If any node does not have left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.

Output Format:
The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
*/

//Time Complexity - O(N)
//Space Complexity - O(H)
//where N is the number of nodes in the input BST and H is the height of the input BST
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
     if(root==NULL){
          return;
     }

     if(root->data>=k1) {
        elementsInRangeK1K2(root->left, k1, k2);
     } 
    
     if(root->data>=k1 && root->data<=k2) {
        cout<<root->data<<" ";
     }
    
     if(root->data<=k2) {
        elementsInRangeK1K2(root->right, k1, k2);
     }
}