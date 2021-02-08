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

void mirror(Node *root)
{
	if (root == NULL) return;
	else
	{
		Node* temp;

		mirror(root->left);
		mirror(root->right);

		temp = root->left;
		root->left = root->right;
		rroot->right = temp;
	}
}

void isStructSame(Node* a, Node* b)
{
	if (a == NULL and b == NULL)
		return true;

	if (a != NULL and b != NULL and isStructSame(a->left, b->left) and isStructSame(a->right, b->right))
		return true;

	return false;
}

void isFold(Node* root)
{
	bool res;
	if (root == NULL) return true;

	mirror(root->left);

	res = isStructSame(root->left, root->right);

	mirror(root->left);

	return res;
}
int32_t main()
{
	/* The constructed binary tree is
	        1
	    / \
	    2 3
	    \ /
	    4 5
	*/
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->left->right = newNode(5);

	if (isFold(root) == 1) {
		cout << "tree is foldable";
	}
	else {
		cout << "\ntree is not foldable";
	}
	return 0;


	return 0;
}