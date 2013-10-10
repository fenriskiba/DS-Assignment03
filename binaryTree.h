#ifndef BINARY_TREE
#define BINARY_TREE

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class binaryTree
{
	private:
		Node* head;
	
	public:
		binaryTree()
		{
			head = NULL;
		}
};

#endif
