#include <iostream>
#include <queue>

//This custom header file contains the class for the TreeNode
#include "TreeNode.h"

using namespace std;

//Function used to get the input of a tree from the user
TreeNode<int>* takeInput() {
	int rootData;
	cout<<"Enter the data: ";
	cin>>rootData;

	//Creating a root node dynamically
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int noc; 
	cout<<"Enter the no. of children: ";
	cin>>noc;

	//Recursively calling the function to take the input of the child nodes
	for(int i=0; i<noc; i++) {
		TreeNode<int>* child = takeInput();

		//Inserting the child node in the vector
		root->children.push_back(child);			
	}

	return root;
}

//Function used to print the data of the Tree Node
void PrintTree(TreeNode<int>* root) {
	//This is not a base case, it's an edge case.
	//It will not call the recursion until it enters the for loop written below.
	//So the for loop handles the base case implicitly, we don't have to write an 
	//explicite code for it.
	if(root==NULL) {
		return;
	}

	cout<<root->data<<": ";

	for(int i=0; i<root->children.size(); i++) {
		cout<<root->children[i]->data<<",";
	}

	cout<<endl;

	//Recursively printing the children of the root
	for(int i=0; i<root->children.size(); i++) {
		PrintTree(root->children[i]);
	}
}

//Function used to get the input from the user in the better way.
//It gets the data from the user Level Wise.
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<<"Enter the data: ";
	cin>>rootData;
	cout<<endl;

	TreeNode<int>* root = new TreeNode<int>(rootData);

	//Creating a queue to store the data in the FIFO(First In First Out) manner
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0) {
		//Returns the front/first node present in the queue
		TreeNode<int>* front = pendingNodes.front();

		//Removes the front/first element in the queue
		pendingNodes.pop();

		int noc; 
		cout<<"Enter the no. of children of "<<front->data<<": ";
		cin>>noc;

		for(int i=0; i<noc; i++) {
			int nodedata; 
			cout<<"Enter the "<<i<<"th value of "<<front->data<<": ";
			cin>>nodedata;

			TreeNode<int>* child = new TreeNode<int>(nodedata);
			pendingNodes.push(child);
			front->children.push_back(child);
		}

		cout<<endl;
	}

	return root;
}

//Function used to print the data of the Tree Node Level Wise
void PrintTreeLevelWise(TreeNode<int>* root) {
	if(root==NULL) {
		return;
	}

	queue<TreeNode<int>* > pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<<front->data<<": ";

		for(int i=0; i<front->children.size(); i++) {
			cout<<front->children[i]->data<<",";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

//Function used to get the total number of nodes in a tree
int noOfNodes(TreeNode<int>* root) {
	//Remember that this is not any kind of a base case, it's just an edge case 
	if(root==NULL) {
		return 0;
	}

	int ans = 1;
	for(int i=0; i<root->children.size(); i++) {
		ans += noOfNodes(root->children[i]);
	}

	return ans;
}

//Function used to get the sum of the data of all the tree nodes present 
int sumOfNodes(TreeNode<int>* root) {
	if(root==NULL) {
		return 0;
	}

	int sum = root->data;
	for(int i=0; i<root->children.size(); i++) {
		sum += sumOfNodes(root->children[i]);
	}

	return sum;
}

/*
Function used to return the node containing the maximum data value 
Approach - 
1. Create two nodes: 
		Temp1 -> containing the root node
		Temp2 -> containing the child node
2. Compare the data of both the nodes and then store the max in Temp1.
*/
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

//Function used to find the height of the whole tree
int heightOfTree(TreeNode<int>* root) {
	if(root==NULL) {
		return 0;
	}	

	int maxHeight = 0;

	for(int i=0; i<root->children.size(); i++) {
		//Storing the maximum height of the child nodes
		maxHeight = max(maxHeight, heightOfTree(root->children[i]));
	}

	//Adding 1 as we finally include the height of the root node also 
	return maxHeight+1;
} 
	
//Function used to print all the nodes which are below the given depth 
void printAtLevelK(TreeNode<int>* root, int k) {
	//Edge case
	if(root==NULL) {
		return;
	}

	//Base case
	if(k==0) {
		cout<<root->data<<endl;
		return;
	}

	for(int i=0; i<root->children.size(); i++) {
		printAtLevelK(root->children[i], k-1);
	}

}

/*
	Function used to get the count of the leaf nodes
	Approach: 
		Each time incrementing 1 in the count when it's the last child node 
		else returning 0;
*/
int getLeafNodeCount(TreeNode<int>* root) {
	if(root==NULL) {
		return 0;
	}

	int cnt = 0;
	if(root->children.size()==0) {
		cnt++;
	}

	for(int i=0; i<root->children.size(); i++) {
		cnt += getLeafNodeCount(root->children[i]);
	}

	return cnt;
}

/*
	Function used to print the data of the tree in pre-order traversal manner
	Priority: 
		1. Root Node
		2. Left Node
		3. Right Node
*/
void preorder(TreeNode<int>* root) {
	if(root==NULL) {
		return;
	}

	cout<<root->data<<",";

	for(int i=0; i<root->children.size(); i++) {
		preorder(root->children[i]);
	}
}

/*
	Function used to print the data of the tree in post-order traversal manner
	Priority: 
		1. Left Node
		2. Right Node 
		3. Root Node 
*/
void postorder(TreeNode<int>* root) {
	if(root==NULL) {
		return;
	}

	for(int i=0; i<root->children.size(); i++) {
		postorder(root->children[i]);
	}

	cout<<root->data<<",";
}

//Function used to de-allocate the dynamically allocated memory while creating a tree
//Approach: Traverse in a post-order manner, first delete the child nodes and then delete the root node
void deleteTree(TreeNode<int>* root) {
	if(root==NULL) {
		return;
	}

	for(int i=0; i<root->children.size(); i++) {
		deleteTree(root->children[i]);
	}

	delete root;
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
//You can directly paste this while running the program on the terminal
int main() {
	// #ifndef ONLINE_JUDGE
	// 	freopen("Input.txt", "r", stdin);
	// 	freopen("Output.txt", "w", stdout);
	// 	freopen("Error.txt", "r", stderr);
	// #endif

	// Basic way of creating a root and child nodes
	// TreeNode<int> *root = new TreeNode(1);
	// TreeNode<int> *node1 = new TreeNode(2);
	// TreeNode<int> *node2 = new TreeNode(3);

	// Connecting the child nodes to the root node
	// root->children.push_back(node1);
	// root->children.push_back(node2);

	// Taking input and priting the node in the basic way
	// TreeNode<int> *root = takeInput();
	// PrintTree(root);

	TreeNode<int>* root = takeInputLevelWise();
	PrintTreeLevelWise(root);
	cout<<endl;
	cout<<"Total no. of nodes in the given tree: "<<noOfNodes(root);
	cout<<endl;
	cout<<"Maximum data of the node in the given tree: "<<maxDataNode(root)->data;
	cout<<endl;
	cout<<"Sum of all the nodes in the given tree: "<<sumOfNodes(root);
	cout<<endl;
	cout<<"The Maximum height of the given tree: "<<heightOfTree(root);
	cout<<endl;
	printAtLevelK(root, 3);
	cout<<endl;
	cout<<"Total no. of leaf nodes in the given tree: "<<getLeafNodeCount(root);
	cout<<endl;
	cout<<"PRE-ORDER TRAVERSAL: ";
	preorder(root);
	cout<<endl;
	cout<<"POST-ORDER TRAVERSAL: ";
	postorder(root);
	cout<<endl;

	// TODO delete the tree
	//Method 1 - Deleting the nodes of the tree in the post-order traversal form
	// deleteTree(root);

	//Method 2 - Deleting the nodes of the tree using the help of a Destructor
	delete root;
}