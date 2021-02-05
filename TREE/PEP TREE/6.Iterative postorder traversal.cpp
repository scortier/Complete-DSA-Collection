/*
APPROACH:
Use two stack
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

void postorder_itr(Node* root)
{
	stack<Node*>st1;
	stack<Node*>st2;
	st1.push(root);
	while (!st1.empty())
	{
		Node *temp = st1.top();
		st1.pop();
		st2.push(temp);

		if (temp->left)
			st1.push(temp->left);
		if (temp->right)
			st1.push(temp->right);
	}
	while (!st2.empty())
	{
		Node* curr = st2.top();
		st2.pop();
		cout << curr->data << " ";
	}
}
//USING ONLY ONE STACK
void postorder_oneStack(Node* root)
{
	if (root == NULL) return;

	stack<Node*>st;
	while (!st.empty())
	{
		while (root != NULL)
		{
			if (root->right)
				st.push(root->right);
			st.push(root);

			//set root as roots left child
			root = root->left;
		}
		root = st.top();
		st.pop();

		if (root->right and (st.top() == root->right))
		{
			st.pop();
			st.push(root);
			root = root->right;
		}
		else
		{
			cout << root->data << " ";
			root = NULL;
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

	// postorder_itr(root);
	postorder_oneStack(root);
	return 0;
}