/*
Node with maximum child sum

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space. 

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/

//Function used to get the sum of the node itself with all it's children
int sum(TreeNode<int>* root) {
    int store = root->data;
    for(int i=0; i<root->children.size(); i++) {
        store += root->children[i]->data;
    }
    
    return store;
} 

//Creating a helper function
pair<TreeNode<int>*, int> helper(TreeNode<int>* root) {
    pair<TreeNode<int>*, int> ans;
    
    if(root==NULL) {
        ans.first = NULL;
        ans.second = 0;
    }
    
    ans.first = root;
    ans.second = sum(root);
    
    //Recursively call for the child nodes and then compare the data
    for(int i=0; i<root->children.size(); i++) {
        pair<TreeNode<int>*, int> compare = helper(root->children[i]);
        
        if(compare.second > ans.second) {
            ans.first = compare.first; //Storing the Tree Node
            ans.second = compare.second; //Storing the sum 
        }
    }
    
    //Returning the whole pair
    return ans;
}
 
TreeNode<int>* maxSumNode(TreeNode<int>* root){
    //Creating a pair and calling the helper function 
    pair<TreeNode<int>*, int> ans = helper(root);
    
    //Return the Tree Node only
    return ans.first;
}