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
		Node* findNode(int search, Node* root = head)
		{
			if(root == NULL)
				return NULL;
			if(root.data == search)
				return root;
			if(root.data > search)
				return findNode(search, root.left)
			if(root.data < search)
				return findNode(search, root.right)
		}
		void insertNode(int newValue)
		{
		
		}
		void deleteNode(Node* delNode)
		{
		
		}
		void printTree()
		{
		
		}
		int findDepth()
		{
		
		}
		int largestCost()
		{
		
		}
		bool isBalanced()
		{
		
		}
};

#endif
