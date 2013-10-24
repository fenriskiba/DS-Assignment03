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
		bool findNode(int search)
		{
			return findNode(search, head);
		}
		bool findNode(int search, Node* root)
		{
			if(root == NULL)
				return false;
			if(root->data == search)
				return true;
			if(root->data > search)
				return findNode(search, root->left);
			if(root->data < search)
				return findNode(search, root->right);
		}
		void insertNode(int newValue)
		{
			Node* newNode = new Node;
			newNode->data = newValue;
			
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				insertNode(head, newNode);
			}
		}
		void insertNode(Node* root, Node* newNode)
		{
			if(root->data == newNode->data)
			{
				delete newNode;
			}
			else if(root->data > newNode->data)
			{
				if(root->left == NULL)
					root->left = newNode;
				else
					insertNode(root->left, newNode);
			}
			else
			{
				if(root->right == NULL)
					root->right = newNode;
				else
					insertNode(root->right, newNode);
			}
		}
		void deleteNode(int delValue)
		{
		
		}
		void printTree()
		{
			printTree(head);
			cout << endl;
		}
		void printTree(Node* root)
		{
			if(root == NULL)
				return;
			
			printTree(root->right);
			cout << root->data << " ";
			printTree(root->left);
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
