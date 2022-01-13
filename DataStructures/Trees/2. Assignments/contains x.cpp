/*
Contains x

Problem Statement: 
Given a generic tree and an integer x, check if x is present in the given tree or not. 
Return true if x is present, return false otherwise.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.

Output format :
The first and only line of output contains true, if x is present and false, otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false
*/

bool contains_x(TreeNode<int>* root, int x) {
	//Edge Case
	if(root==NULL) {
        	return false;
    	}
	
	bool check = false;
	
	//Using the approach of or(|) operator which will keep the true value(if found) till the end.
	if(root->data==x) {
		check |= true;
	}
	
	//Recursion call to check for rest of the nodes of the root
	for(int i=0; i<root->children.size(); i++) {
		check |= contains_x(root->children[i], x);
	}

	return check;
}
