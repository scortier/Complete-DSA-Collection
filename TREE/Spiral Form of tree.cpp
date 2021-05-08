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

//TC :O(n) SC:O(n)
void Spiral_using_stacknqueue(Node* root)
{
	if (root == NULL) return;

	stack<int>st;
	queue<Node*>q;

	bool reverse = true;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		while (size)
		{
			Node* p = q.front();
			q.pop();


		}
	}
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