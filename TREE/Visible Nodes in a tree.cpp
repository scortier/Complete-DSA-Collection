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

int cnt = 0;
void visible(Node *root, int mx)
{
	if (root == NULL) return;

	if (root->data >= mx)
	{
		cnt++;
		mx = max(root->data, mx);
	}
	visible(root->left, mx);
	visible(root->right, mx);
}

int32_t main()
{
	Node* root = newNode(5);

	/*
	        5
	       /  \
	     3     10
	    /  \   /
	   20   21 1
	*/

	root->left = newNode(3);
	root->right = newNode(10);

	root->left->left = newNode(20);
	root->left->right = newNode(21);

	root->right->left = newNode(1);

	visible(root, INT_MIN);

	cout << cnt;
	return 0;
}