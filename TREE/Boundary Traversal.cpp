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

//Recursion approach
/*
TC:O(n) SC:O(n)
divided into 4 parts:
1. root node
2. left boundary -
3. leaf node
4.right boundary

*/
// vector<int>ans;

void leftBoundary(Node* root, vector<int>&ans)
{
	if (root == NULL or (root->left == NULL and root->right == NULL)) return;

	ans.push_back(root->data);

	if (root->left != NULL)
		leftBoundary(root->left, ans);
	else
		leftBoundary(root->right, ans);
}

void rightBoundary(Node* root, vector<int>&ans)
{
	if (root == NULL or (root->left == NULL and root->right == NULL)) return;

	ans.push_back(root->data);

	if (root->right != NULL)
		rightBoundary(root->right, ans);
	else
		rightBoundary(root->right, ans);
}

void leafNodes(Node* root, vector<int>&ans) {
	if (root == NULL) return;

	if (root->left == NULL and root->right == NULL)
	{	ans.push_back(root->data);
		return;
	}

	leafNodes(root->left, ans);
	leafNodes(root->right, ans);
}

void boundary_recurse(Node* root, vector<int>&ans)
{
	if (root == NULL) return ans;

	ans.push_back(root->data);
	//traverse left boundary
	leftBoundary(root->left, ans);

	//traverse leave nodes
	leafNodes(root->left, ans);
	leafNodes(root->right, ans);

	//traverse right boundary
	rightBoundary(root->right, ans);

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