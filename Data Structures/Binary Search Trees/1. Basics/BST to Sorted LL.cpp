/*
Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Input format:
The first and only line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. 
If any node does not have left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/


//Time Complexity - O(n)
//Space Complexity - O(h) 
//where h is the height of input BST

class Pair{
public:
    Node<int> *head;
    Node<int> *tail;
};

//Helper Function
Pair Helper(BinaryTreeNode<int>* root) {
    if(root==NULL) {
        Pair output;
        output.head = NULL;
        output.tail = NULL;
        return output;
    }
    
    //Recursive calls for both left and right child
    Pair leftChild = Helper(root->left);
    Pair rightChild = Helper(root->right);
    
    //Creating the linked list node
    Node<int> *root1 = new Node<int>(root->data);

    //Basic conditions
    Pair ans;
    if(leftChild.head==NULL && rightChild.head==NULL) {
		ans.head = root1;
        ans.tail = root1;
    } else if(leftChild.head==NULL && rightChild.head!=NULL) {
        ans.head = root1;
        root1->next = rightChild.head;
        ans.tail = rightChild.tail;
    } else if(leftChild.head!=NULL && rightChild.head==NULL) {
        ans.head = leftChild.head;
        leftChild.tail->next = root1;
        ans.tail = root1;
        root1->next = NULL;
    } else {
        ans.head = leftChild.head;
        leftChild.tail->next = root1;
        root1->next = rightChild.head;
        ans.tail = rightChild.tail;
    }
    
    return ans;
}

//Main Function
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return Helper(root).head;
}
