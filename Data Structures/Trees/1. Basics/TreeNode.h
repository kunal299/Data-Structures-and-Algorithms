#include<vector>
using namespace std;

template<typename T> 
class TreeNode{
public: 
	T data; 
	vector<TreeNode<T>*> children;

	//Constructor
	TreeNode(T data) {
		this->data = data;
	}

	//Destructor 
	//Node will not be deleted until it's destructor is not over. 
	//It will keep on calling until it's child's destructor is not over.
	//Finally the root node will be deleted.
	~TreeNode() {
		for(int i=0; i<children.size(); i++) {
			delete children[i];
		}
	}
};
