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

int getMin(Node *root)
{
	if (root = NULL)
	{
		cout << "Tree is empty";
		return -1;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int getMax(Node* root)
{
	if (root == NULL)
	{
		cout << "Tree is empty";
		return -1;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
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
	root->left->right->right = newNode(11);
	cout << getMax(root);
	cout << getMin(root);

	return 0;
}