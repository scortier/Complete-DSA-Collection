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
void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

Node* add(Node* root, int key)
{
	if (root == NULL)
		return newNode(key);

	if (key > root->data)
		root->right = add(root->right, key); // that equal is to attach new node with its parent.
	else if (key < root->data)
		root->left = add(root->left, key);

	return root;//return root after insertion
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
	inorder(root);
	cout << endl;
	add(root, 5);

	inorder(root);
	return 0;
}