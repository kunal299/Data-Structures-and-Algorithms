template <typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	//Constructor
	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	//Destructor
	~BinaryTreeNode() {
		/*
		Don't worry about the case where there is no left and right.
		As we have initiated left and right with NULL value in the constructor, 
		in that case it will call delete NULL, which has no effect and is ignored.
		*/
		delete left;
		delete right;
	}
};
