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

void flatten(Node *root)
{
	if (root == NULL || root->left == NULL and root->right == NULL)
		return;

	if (root->left != NULL)
	{
		flatten(root->left);


	}
}

int32_t main()
{

	return 0;
}