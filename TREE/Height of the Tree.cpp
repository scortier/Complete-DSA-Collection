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

int height(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int ld = height(root->left);
		int rd = height(root->right);

		if (ld > rd) return (ld + 1);
		else return (rd + 1);

		//or
		//// If tree is not empty then height = 1 + max of left
		// height and right heights
		// return 1 + max(height(root->ld), height(root->rd));
	}
}


int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << height(root);
	return 0;
}