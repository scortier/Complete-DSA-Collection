/*
APPROACH:

*/
//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node *newNode(int x)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = x;
	return temp;
}


void printb_left(Node *root)
{
	if (!root) return;
	if (root->left)
	{
		cout << root->data << " ";
		printb_left(root->left);
	}

}


void printleaves(Node *root)
{
	if (!root) return;

//as anticlockwse hai toh left k leave pehle aenge
	printleaves(root->left);

	if (!(root->left) and !(root->right))
		cout << root->data << " ";
	printleaves(root->right);
}

//BOTTOM UP MANNER AS ANTICLOCKWISE JA RHE HAI
void printb_right(Node *root)
{
	if (!root) return;
	if (root->right)
	{
		//to ensure bottomm up order so call first then print
		printb_right(root->right);
		cout << root->data << " ";
	}
	// else if (root->left)
	// {

	// }
}



void boundary(Node* root)
{
	if (!root) return;
	cout << root->data << " ";

	printb_left(root->left);

	printleaves(root->left);
	printleaves(root->right);

	printb_right(root->right);
}

int32_t main()
{
	Node* root = NULL;

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);

	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);

	root->left->right->left = newNode(10);
	// root->left->right->right = newNode(11);g

	boundary(root);

	return 0;
}

