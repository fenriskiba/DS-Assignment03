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
				cout << "Inserted Successfully\n\n";
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
				cout << "That value is already on the tree.\n\n";
			}
			else if(root->data > newNode->data)
			{
				if(root->left == NULL)
				{
					root->left = newNode;
					cout << "Inserted Successfully\n\n";
				}
				else
					insertNode(root->left, newNode);
			}
			else
			{
				if(root->right == NULL)
				{
					root->right = newNode;
					cout << "Inserted Successfully\n\n";
				}
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
		bool deleteNode(int delValue)
		{
			if(head == NULL)
			{
				return false;
			}
			
			deleteNode(delValue, head);
		}
		bool deleteNode(int delValue, Node* root)
		{
			if(root->data == delValue)
			{
				if(root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
					return true;
				}
				else if(root->left == NULL && root->right != NULL)
				{
					Node* temp = root->right;
					delete root;
					root = temp;
					return true;
				}
				else if(root->left != NULL && root->right == NULL)
				{
					Node* temp = root->left;
					delete root;
					root = temp;
					return true;
				}
				else
				{
					Node* temp;
					temp = findSmallest(root->right);
					root->data = temp->data;
					deleteNode(temp->data, temp);
					temp = NULL;
					return true;
				}
			}
			else if(root->data > delValue)
			{
				if(root->left == NULL)
					return false;
				else
					deleteNode(delValue, root->left);
			}
			else
			{
				if(root->right == NULL)
					return false;
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
		int findDepth(int search)
		{
			return findDepth(search, -1, head); 
		}
		int findDepth(int search, int current, Node* root)
		{
			current++;
			if(root == NULL)
				return -1;
			if(root->data == search)
				return current;
			if(root->data > search)
				return findDepth(search, current, root->left);
			if(root->data < search)
				return findDepth(search, current, root->right);
		}
		int largestCost()
		{
		
		}
		bool isBalanced()
		{
		
		}
};

#endif
