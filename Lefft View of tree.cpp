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


void leftutil(Node *root, int level , int *maxl)
{
	if (root == NULL) return;

	if (*maxl < level)
	{
		cout << root->data << " ";
		*maxl = level;
	}

	leftutil(root->left, level + 1, maxl);
	leftutil(root->right, level + 1, maxl);
}

void leftview(Node *root)
{
	int maxl = 0;
	leftutil(root, 1, &maxl);
}

int main()
{


	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	leftview(root);
	return 0;
}