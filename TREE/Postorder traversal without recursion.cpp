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

void postorder_itr(Node *root)
{
	if (root == NULL) return;

	stack<Node*>s1;
	stack<Node*>s2;

	s1.push(root);

	while (s1.size())
	{
		Node* tmp = s1.top();
		s1.pop();
		if (tmp->left) s1.push(tmp->left);
		if (tmp->right) s1.push(tmp->right);

		s2.push(tmp);
	}

	while (s2.size() > 0) {
		cout << s2.top()->data << " ";
		s2.pop();
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

	postorder_itr(root);
	return 0;
}