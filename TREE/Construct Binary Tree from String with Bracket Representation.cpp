/*

The whole input represents a binary tree. It contains an integer followed by zero,
one or two pairs of parenthesis. The integer represents the root’s value and a pair
of parenthesis contains a child binary tree with the same structure. Always start to
construct the left child node of the parent first if it exists.

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

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int findindex(string s, int l, int h)
{
	if (l > h) return -1;

	stack<char>st;

	for (int i = l; i <= h; i++) {
		//if open paren then
		if (s[i] == '(')
			st.push(s[i]);

		//if close paren
		else if (s[i] == ')')
		{
			if (s.top() == '(')
				s.pop();

			if (st.empty()) return i; //this is required index
		}
	}
	return -1;
}


Node* treeFromString(string str, int si, int ei)
{
	// Base case
	if (si > ei)
		return NULL;

	// new root
	Node* root = newNode(str[si] - '0');
	int index = -1;

	// if next char is '(' find the index of
	// its complement ')'
	if (si + 1 <= ei && str[si + 1] == '(')
		index = findIndex(str, si + 1, ei);

	// if index found
	if (index != -1) {

		// call for left subtree
		root->left = treeFromString(str, si + 2, index - 1);

		// call for right subtree
		root->right
		    = treeFromString(str, index + 2, ei - 1);
	}
	return root;
}



int32_t main()
{

	return 0;
}