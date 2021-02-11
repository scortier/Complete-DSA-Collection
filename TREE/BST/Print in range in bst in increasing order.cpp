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
void pir(Node* root, int l, int h)
{
	if (l < root->data and h < root->data)
		return pir(root->left, l, h);
	else if (l > root->data and h > root->data)
		return pir(root->right, l, h);
	else {
		pir(root->left, l, h);
		cout << root->data << " ";
		pir(root->right, l, h);
	}
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