/*
APPROACH:
by stack
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

void inorder(Node* root)
{
	stack<Node*>st;
	Node* temp = root;
	while (temp != NULL or !st.empty())
	{
		while (!temp)
		{
			st.push(temp);
			temp = temp->left;
		}
		temp = st.top();
		st.pop();
		cout << temp->data << " ";
		temp = temp->right;
	}

}

int32_t main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inorder(root);
	return 0;
}