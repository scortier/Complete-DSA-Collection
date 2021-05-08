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

//m-1
void leftutil(Node *root, int level , int *max_horizontal_level)
{
	if (root == NULL) return;

	if (*max_horizontal_level < level)
	{
		cout << root->data << " ";
		*max_horizontal_level = level;
	}

	leftutil(root->left, level + 1, max_horizontal_level);
	leftutil(root->right, level + 1, max_horizontal_level);
}
void leftview(Node *root)
{
	int max_horizontal_level = 0;
	leftutil(root, 1, &max_horizontal_level);
}

//m-2
int max_horizontal_level;
void leftutil_shortm(Node *root, int level)
{
	if (root == NULL) return;

	if (level >= max_horizontal_level)
	{
		cout << root->data << " ";
		max_horizontal_level++;
	}

	leftutil_shortm(root->left, level + 1);
	leftutil_shortm(root->right, level + 1);
}



int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	leftview(root);
	cout << endl;
	leftutil_shortm(root, 0);
	return 0;
}