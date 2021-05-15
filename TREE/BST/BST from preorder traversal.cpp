/*
APPROACH:
The trick is to set a range {min .. max} for every node. Initialize the range as
{INT_MIN .. INT_MAX}. The first node will definitely be in range, so create a root node.
To construct the left subtree, set the range as {INT_MIN …root->data}.
If a value is in the range {INT_MIN .. root->data}, the values are part of the left subtree.
To construct the right subtree, set the range as {root->data..max .. INT_MAX}.
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

Node* constTreeUtil(int pre[], int &preIndex, int key, int minm, int maxm, int size)
{
	if (preIndex == NULL) return NULL;

	Node* root = NULL;

	if (key > minm and key < maxm)
	{
		root = newNode(key);
		preIndex = preIndex + 1;
		if (preIndex < size)
		{
			root->left = constTreeUtil(pre, preIndex, pre[preIndex], minm, key, size);
		}
		if (preIndex < size)
		{
			root->right = constTreeUtil(pre, preIndex, pre[preIndex], key, maxm, size);
		}

	}
	return root;

}
Node* constTree(int pre[], int size)
{
	int preIndex = 0;
	return constTreeUtil(pre, preIndex, pre[0], INT_MIN, INT_MAX, size);
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