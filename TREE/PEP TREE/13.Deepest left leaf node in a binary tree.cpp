/*
APPROACH:
sabse niche wala left leaf node

The idea is to recursively traverse the given binary tree and while traversing, maintain “level” which will store the current node’s level in the tree. If current node is left leaf, then check if its level is more than the level of deepest left leaf seen so far. If level is more then update the result. If current node is not leaf, then recursively find maximum depth in left and right subtrees, and return maximum of the two depths.
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


void deep_util(Node* root, int level, int *maxl, bool isLeft, Node **restptr)
{
	if (root == NULL) return;

	if (isLeft and !root->left and !root->right and level > *maxl)
	{
		*restptr = root;
		*maxl = level;
		return;
	}

	deep_util(root->left, level + 1, maxl, true, restptr);
	deep_util(root->right, level + 1, maxl, false, restptr);

}
Node* deep(Node *root)
{
	int maxl = 0;
	Node* result = NULL;
	deep_util(root, 0, &maxl, false, &result);
	return result;
}


int32_t main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(8);
	root->right->left->right->left = newNode(9);
	root->right->right->right->right = newNode(10);

	Node* result = deep(root);
	if (result)
		cout << "The deepest left child is " << result->data;
	else
		cout << "There is no left leaf in the given tree";
	return 0;
}