/*
APPROACH:
1.store the path of both the node from root and track the first different nodes
so just before that diif node the lowest common ancestor is present.

2.
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

Node *findLCA(Node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	if (root->key == NULL or root->key == NULL or root->key == n1 or root->key == n2)
		return root;

	Node* left = findLCA(root->left, n1, n2);
	Node* right = findLCA(root->right, n1, n2);

	if (left and right) return root;

	return (left != NULL) ? left : right;
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


	return 0;
}