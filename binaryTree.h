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
		Node* findSmallest(Node* root)
		{
			if(root->left == NULL)
				return root;
			
			return findSmallest(root->left);
		}
		void deleteNode(int delValue)
		{
			if(head == NULL)
				return;
			
			deleteNode(delValue, head);
		}
		void deleteNode(int delValue, Node* root)
		{
			if(root->data == delValue)
			{
				if(root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
				}
				else if(root->left == NULL && root->right != NULL)
				{
					Node* temp = root->right;
					delete root;
					root = temp;
				}
				else if(root->left != NULL && root->right == NULL)
				{
					Node* temp = root->left;
					delete root;
					root = temp;
				}
				else
				{
					Node* temp;
					temp = findSmallest(root->right);
					root->data = temp->data;
					deleteNode(temp->data, temp);
					temp = NULL;
				}
			}
			else if(root->data > delValue)
			{
				if(root->left == NULL)
					return;
				else
					deleteNode(delValue, root->left);
			}
			else
			{
				if(root->right == NULL)
					return;
				else
					deleteNode(delValue, root->right);
			}
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
