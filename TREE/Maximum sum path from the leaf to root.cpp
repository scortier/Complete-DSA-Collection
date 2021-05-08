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

//m-1
//recursive
vector<int> maxsum(Node* root)
{
	if (root == NULL) return {};

	vector<int>leftPath = maxsum(root->left);
	vector<int>rightPath = maxsum(root->right);

	leftPath.push(root->data);
	rightPath.push(root->data);

	int leftsum = 0, rightsum = 0;

	for (int i = 0; i < leftPath.size(); i++)
		leftsum += leftPath[i];

	for (int i = 0; i < rightPath.size(); i++)
		rightsum += rightPath[i];
	if ((leftsum >= rightsum and root->left != NULL) or root->right == NULL)
		return leftPath;

	return rightPath;

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