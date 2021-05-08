/*
APPROACH:
1.Traverse the tree in inorder fashion.
2.While visiting each node, keep track of DLL’s head and tail pointers,
insert each visited node to the end of DLL using tail pointer.
3.Return head of the list.
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

Node* solve(Node* root, Node* head, Node* tail)
{
	if (root == NULL) return NULL;

	Node* left = root->left;
	Node* right = root->right;

	solve(root->left, head, tail);

	if (head == NULL)
		head = root;

	root->left = tail;

	if (tail != NULL)
		tail->right = root;

	tail = root;


	solve(root->right, head, tail);

	return head;

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