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


int findmaxutil(Node* root, int &res)
{
	if (root == NULL) return 0;

	int l = findmaxutil(root->left, res);
	int r = findmaxutil(root->right, res);

	int max_single = max(max(l, r) + root->data, root->data);

	int max_top = max(max_single, l + r + root->data);

	res = max(res, max_top);

	return max_single;
}

int findMaxSum(Node *root)
{
	int res = INT_MIN;
	findmaxutil(root, res);
	return res;
}


int main()
{

	Node *root = newNode(10);
	root->left        = newNode(2);
	root->right       = newNode(10);
	root->left->left  = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left   = newNode(3);
	root->right->right->right  = newNode(4);
	cout << "Max path sum is " << findMaxSum(root);

	return 0;
}