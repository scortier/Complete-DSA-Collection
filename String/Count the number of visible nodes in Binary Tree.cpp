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

//TC:O(n) SC:O(n)
int cnt = 0;
void visible_node(Node *root, int mx)
{
	if (root == NULL)
		return;

	if (root->data >= mx)
	{
		cnt++;
		mx = max(root->data, mx);
	}

	visible_node(root->left, mx);
	visible_node(root->right, mx);
}

int main() {
	Node *root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(11);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(2);

	cout << "Visible Node of tree is " << endl;
	visible_node(root, INT_MIN);
	cout << cnt << endl;
	return 0;
}