/*
APPROACH:
Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where
every node has either 0 or 2 children. One more array ‘preLN[]’ is given which has only
two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.


The first element in pre[] will always be root. So we can easily figure out root. If left subtree is empty, the right subtree must also be empty and preLN[] entry for root must be ‘L’. We can simply create a node and return it. If left and right subtrees are not empty, then recursively call for left and right subtrees and link the returned nodes to root.
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

Node *util(int pre[], char preln[], int *index_ptr, int n)
{
	int index = *index_ptr;

	if (index == n)
		return NULL;

	Node* temp = newNode(pre[index]);
	(*index_ptr)++;

	if (preln[index] == 'N')
	{
		temp->left = util(pre, preln, index_ptr, n);
		temp->right = util(pre, preln, index_ptr, n);
	}
	return temp;
}
Node *solve(int pre[], char preln[], int n)
{
	int index = 0;
	return util(pre, preln, &index, n);
}
void printInorder ( Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder (node->left);

	/* then print the data of node */
	printf("%d ", node->data);

	/* now recur on right child */
	printInorder (node->right);
}
int32_t main()
{
	Node* root = NULL;
	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int n = sizeof(pre) / sizeof(pre[0]);

	root = solve (pre, preLN, n);

	// Test the constructed tree
	printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder (root);
	return 0;
}