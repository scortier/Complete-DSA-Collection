/*
APPROACH:
MORRIS TRAVERSAL
The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.
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

void inorder_MORRIS(Node* root)
{

	while (root != NULL)
	{
		//if left child is null print hte curr node data .move to right child
		if (root->left == NULL) {
			cout << root->data << " ";
			root = root->right;
		}
		else {
			/* Find the inorder predecessor of current */
			Node* curr = root->left;
			while (curr->right and curr->right != root)
				curr = curr->right;

			//if the right child of inorder pred already point to this node
			if (curr->right == root)
			{
				curr->right = NULL;
				root = root->right;
			}

			//if the child doesn't point to this node,then print this node and make right child
			//point ot this node
			else
			{
				cout << root->data << " ";
				curr->right = root;
				root = root->left;
			}
		}

	}
}
// Function for sStandard preorder traversal
void preorder(node* root)
{
	if (root)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

/* Driver program to test above functions*/
int main()
{
	node* root = NULL;

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

	morrisTraversalPreorder(root);

	cout << endl;
	preorder(root);

	return 0;
}