/*
APPROACH:
can start and end at any node and must be downward.
Find the path having sum=k.

1.RECURSION AND STORE ON VECTOR
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

void func(Node *root, vector<int>v, int k)
{
	if (!root) return ;

	// add current node to the path
	v.push_back(root->data);

// check if there's any k sum path
	// in the left sub-tree.
	func(root->left, v, k);

// check if there's any k sum path
	// in the right sub-tree.
	func(root->right, v, k);


	// check if there's any k sum path that
	// terminates at this node
	// Traverse the entire path as
	// there can be negative elements too
	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cnt += v[i];
		// If path sum is k, print the path
		if (cnt == k)
		{
			for (int j = i; j < v.size(); j++)
				cout << v[j] << " ";
			cout << endl;

		}
	}
	// Remove the current element from the path
	v.pop_back();

}


int32_t main()
{
	Node *root = newNode(1);
	root->left = newNode(3);
	root->left->left = newNode(2);
	root->left->right = newNode(1);
	root->left->right->left = newNode(1);
	root->right = newNode(-1);
	root->right->left = newNode(4);
	root->right->left->left = newNode(1);
	root->right->left->right = newNode(2);
	root->right->right = newNode(5);
	root->right->right->right = newNode(2);
	int k = 5;
	vector<int> p;
	func(root, p, k);
	return 0;
}