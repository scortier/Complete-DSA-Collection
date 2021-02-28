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

void util(Node* temp, int k, int &min_diff, int & min_diff_key)
{
	if (temp == NULL) return;

	//if k itdelf is present
	if (temp->key == k)
	{
		min_diff_key = k; //as k itself is present in tree
		return;
	}

	//update the min_diff and min_diff_key by checking curr node value
	if (min_diff > abs(temp->key - k))
	{
		min_diff = abs(temp->key - k);
		min_diff_key = temp->key;
	}

	//
	if (k < temp->key)
		util(temp->left, k, min_diff, min_diff_key);
	else
		util(temp->right, k, min_diff, min_diff_key);
}

int maxDiff(Node* root, int k)
{
	int min_diff = INT_MAX, min_diff_key = -1;

	//find the value of min_diff_key
	maxDiff(root, k, min_diff, min_diff_key);

	return min_diff_key;
}

int32_t main()
{
	struct Node *root = newnode(9);
	root->left    = newnode(4);
	root->right   = newnode(17);
	root->left->left = newnode(3);
	root->left->right = newnode(6);
	root->left->right->left = newnode(5);
	root->left->right->right = newnode(7);
	root->right->right = newnode(22);
	root->right->right->left = newnode(20);
	int k = 18;
	cout << maxDiff(root, k);
	return 0;
}