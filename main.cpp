#include <iostream>
#include "binaryTree.h"

using namespace std;

bool run();

binaryTree tree;

int main()
{
	bool running = true;
	
	while(running)
	{
		running = run();
	}
	
	return 0;
}

bool run()
{
	int option;
	int value;
	int depth;
	bool deleted;
	bool balanced;
	
	cout << "*************************************" << endl
		<< "Please Choose an operation to perform on the tree" << endl << endl
		<< "1. Search for a value on the tree" << endl
		<< "2. Insert a value on the tree" << endl
		<< "3. Delete a value on the tree" << endl
		<< "4. Print the values on the tree from highest to lowest" << endl
		<< "5. Find the depth of a node" << endl
		<< "6. Find the greatest cost" << endl
		<< "7. Find out of the tree is balanced" << endl
		<< "8. Exit" << endl << endl;
	cin >> option;
	cout << endl;
	
	switch(option)
	{		
		case 1:
			cout << "What value would you like to search for?\n";
			cin >> value;
			cout << endl;
			if(tree.findNode(value))
				cout << "That number is on the tree.\n\n";
			else
				cout << "That number is NOT on the tree\n\n";
			break;
		case 2:
			cout << "What value would you like to place on the tree?\n";
			cin >> value;
			cout << endl;
			tree.insertNode(value);
			break;
		case 3:
			cout << "What value would you like to delete?\n";
			cin >> value;
			cout << endl;
			deleted = tree.deleteNode(value);
			if(deleted)
				cout << "Deleted Successfully\n\n";
			else
				cout << "That value isn't on the tree\n\n";
			break;
		case 4:
			cout << "The values on the tree are:\n";
			tree.printTree();
			cout << endl;
			break;
		case 5:
			cout << "What is the value of the node to find the depth of?\n";
			cin >> value;
			depth = tree.findDepth(value);
			if(depth == -1)
				cout << "The value isn't on the tree.\n\n";
			else
				cout << "The depth is " << depth << endl << endl;
			break;
		case 6:
				cout << "The greatest cost is " << tree.largestCost() << endl << endl;
			break;
		case 7:
			balanced = tree.isBalanced();
			if(balanced)
				cout << "The tree is balanced.\n\n";
			else
				cout << "The tree is not balanced.\n\n";
			break;
		case 8:
			return false;
			break;
		default:
			cout << "Invalid Input\nPlease try again\n\n";
	}
	return true;	
}

