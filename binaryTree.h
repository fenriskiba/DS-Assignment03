#ifndef BINARY_TREE
#define BINARY_TREE

#include <cmath>

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
		
		Node* smallestOnRight(Node* root)
		{
			if(root->left == NULL)
				return root;
			
			return smallestOnRight(root->left);
		}
		int height(Node* root)
		{
			int leftHeight;
			int rightHeight;
			
			if(root == NULL)
				return -1;
			else
			{
				leftHeight = height(root->left);
				rightHeight = height(root->right);
				
				if(leftHeight > rightHeight)
					return leftHeight + 1;
				else
					return rightHeight + 1;
			}
		}
	
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
		bool deleteNode(int delValue)
		{
			Node* temp;
			if(head == NULL)
				return false;
			
			if(head->data == delValue)
			{
				if(head->right == NULL && head->left == NULL)//No Child
				{
					delete head;
					head = NULL;
					return true;
				}
				else if(head->right == NULL && head->left != NULL)//Left Child
				{
					temp = head;
					head = head->left;
					delete temp;
					return true;
				}
				else if(head->right != NULL && head->left == NULL)//Right Child
				{
					temp = head;
					head = head->right;
					delete temp;
					return true;
				}
				else //Two Children
				{
					temp = smallestOnRight(head->right);
					head->data = temp->data;
					deleteNode(head->data, head->right);
					return true;
				}
			}
			else
			{
				return deleteNode(delValue, head);
			}
		}
		bool deleteNode(int delValue, Node* root)
		{
			Node* delNode;
			Node* temp;
			
			if(root->data > delValue)
				delNode = root->left;
			else
				delNode = root->right;
			
			if(delNode == NULL)
				return false;
			
			if(delNode->data == delValue)
			{
				if(delNode->left == NULL && delNode->right == NULL)//No Children
				{
					if(delNode == root->left)
					{
						root->left = NULL;
						delete delNode;
						return true;
					}
					else
					{
						root->right = NULL;
						delete delNode;
						return true;
					}
				}
				else if(delNode->left == NULL && delNode->right != NULL)//Right Child
				{
					if(delNode == root->left)
					{
						root->left = delNode->right;
						delete delNode;
						return true;
					}
					else
					{
						root->right = delNode->right;
						delete delNode;
						return true;
					}
				}
				else if(delNode->left != NULL && delNode->right == NULL)//Left Child
				{
					if(delNode == root->left)
					{
						root->left = delNode->left;
						delete delNode;
						return true;
					}
					else
					{
						root->right = delNode->left;
						delete delNode;
						return true;
					}
				}
				else //Two Children
				{
					temp = smallestOnRight(delNode->right);
					delNode->data = temp->data;
					deleteNode(delNode->data, delNode->right);
					return true;
				}
			}
			else
			{
				return deleteNode(delValue, delNode);
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
			return largestCost(head);
		}
		int largestCost(Node* root)
		{
			int rightCost = 0;
			int leftCost = 0;
			
			if(root->left != NULL)
				leftCost = largestCost(root->left);
			if(root->right != NULL)
				rightCost = largestCost(root->right);
			
			if(rightCost > leftCost)
				return (rightCost + root->data);
			else
				return (leftCost + root->data);
		}
		bool isBalanced()
		{
			return isBalanced(head);
		}
		bool isBalanced(Node* root)
		{
			bool leftBalanced = true;
			bool rightBalanced = true;
			int leftHeight;
			int rightHeight;
			
			if(root->left != NULL)
				leftBalanced = isBalanced(root->left);
			if(root->right != NULL)
				rightBalanced = isBalanced(root->right);
				
			if(!leftBalanced || !rightBalanced)
				return false;
			
			leftHeight = height(root->left);
			rightHeight = height(root->right);
			
			if(abs(leftHeight - rightHeight) > 1)
				return false;
			return true;
		}
};

#endif
