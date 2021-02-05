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

Node *getNode(int x)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = x;
	return temp;
}

int countSum(Node* root, int& count, int x)
{
	if (root == NULL) return 0;
// sum of nodes in the left n right subtree
	int ls = countSum(root->left, count, x);
	int rs = countSum(root->right, count, x);
// sum of nodes in the subtree rooted
	// with 'root->data'
	int sum = ls + rs + root->data;
	if (sum == x) count++;
	// return subtree's nodes sum
	return sum;
}
int util(Node* root, int x)
{
	int count = 0;
	if (root == NULL) return 0;

	int ls = countSum(root->left, count, x);
	int rs = countSum(root->right, count, x);


	if ((ls + rs + root->data) == x)
		count++;
	return count;
}

//alter approach
int countUtil(Node* root, int x)
{
	//without adding static the ans will always be 0.
	static int count = 0;
	static Node* ptr = root;
	int l = 0, r = 0;
	if (root == 0) return 0;

	l += countUtil(root->left, x);
	r += countUtil(root->right, x);

	if (l + r + root->data == x)
		count++;

	if (ptr != root) return l + r + root->data;
	return count;
}`

int32_t main()
{
	/* binary tree creation
	           5
	         /   \
	      -10     3
	      /  \   /  \
	     9    8 -4   7
	*/
	Node* root = getNode(5);
	root->left = getNode(-10);
	root->right = getNode(3);
	root->left->left = getNode(9);
	root->left->right = getNode(8);
	root->right->left = getNode(-4);
	root->right->right = getNode(7);

	int x = 7;

	cout << "Count = "
	     << util(root, x);
	cout << countUtil(root, x);
	return 0;
}