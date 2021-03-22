/*
APPROACH:
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
Above question implementation using all path of tree

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

int ans = 0;
int convert_decimal(vector<int> v)
{
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		n = n * 2 + v[i];
	return n;
}
void findpath(TreeNode* root, vector<int> t)
{
	if (!root)return;
	t.push_back(root->val);
	if (!root->left && !root->right)ans += convert_decimal(t);
	findpath(root->left, t);
	findpath(root->right, t);
}
int sumRootToLeaf(TreeNode* root) {
	if (!root)return 0;
	vector<int> t;
	findpath(root, t);
	return ans;
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