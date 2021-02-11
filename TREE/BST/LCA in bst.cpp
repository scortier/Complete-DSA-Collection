/*
APPROACH:
dono ka path visualize karo and from bottom se first common point is lcs
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

int lst(Node* root, int d1, int d2)
{
	if (d1 > root->data and d2 > root->data) return lst(root->right, d1, d2);
	else if (d1 < root->data and d2 < root->data) return lst(root->left, d1, d2);

	else return root->data;
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

	cout << lst(root, 6, 9);
	return 0;
}