/*
Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40 
*/

//Function used to get the node with the maximum data
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==NULL) {
        return NULL;
    }
    
    TreeNode<int>* temp1 = root;
    
    for(int i=0; i<root->children.size(); i++) {
        TreeNode<int>* temp2 = maxDataNode(root->children[i]);
        
        if(temp2->data > temp1->data) {
            temp1 = temp2;
        }
    }
    
    return temp1;
}

//A helper function which is used return the second largest node.
//It's just the variation of Next Larger Problem. Just reverse the compare signs.
TreeNode<int>* helper(TreeNode<int>* root, int x) {
    if(root==NULL) {
        return NULL;
    }
    
    TreeNode<int>* ans = NULL;
    
    //Change 1
    if(root->data < x) {
        ans = root;
    }
    
    for(int i=0; i<root->children.size(); i++) {
        TreeNode<int>* temp = helper(root->children[i], x);
        
        if(ans==NULL) {
            ans = temp;
        } else if(temp!=NULL && temp->data > ans->data) { //Change2
        	ans = temp;
        }
    }
    
    return ans;
}

//Main Funtion
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root==NULL) {
        return NULL;
    }
    
    //It stores the data value of the maximum node
	int store = maxDataNode(root)->data;

	//Calling the helper function 
    return helper(root, store);
}