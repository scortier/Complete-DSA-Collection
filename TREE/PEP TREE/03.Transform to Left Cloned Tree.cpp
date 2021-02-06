/*
APPROACH:
https://www.youtube.com/watch?v=TO7trQloRXc


*/
//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node *newNode(int x, Node* left, Node* right)
{

	Node* temp = new Node;
	temp->left = left = NULL;
	temp->right = right = NULL;
	temp->data = x;
	return temp;
}

void createLeftClone(Node* root)
{
	if (root == NULL) return NULL;
//postorder chal rha hia y
	Node* lcr = createLeftClone(root->left);
	Node* rcr = createLeftClone(root->right);

	Node* neww = newNode(root->data, lcr, NULL);
	root->left = neww;
	root->right = rcr;
}

int32_t main()
{

	return 0;
}