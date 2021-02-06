/*
APPROACH:
https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
1.We can do standard level order traversal here too but instead of printing nodes directly, we have to store nodes in current level in a temporary array or list 1st and then take nodes from alternate ends (left and right) and print nodes. Keep repeating this for all levels.
This approach takes more memory than standard traversal.

Approach 2:
The standard level order traversal idea will slightly change here. Instead of processing ONE node at a time, we will process TWO nodes at a time. And while pushing children into queue, the enqueue order will be: 1st node’s left child, 2nd node’s right child, 1st node’s right child and 2nd node’s left child.
BASE CASE IN THIS SITUTATION
1. FOR ROOT
2. ROOT->LEFT AND ROOT->RIGHT

MAIN CONDITION
Just imagine for the one more level of base condition means 2nd level where roor->left->left and root->left->right bhi honge
uus case m kese processing hogi queue ko use karke.

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

void specificLevelOrder(Node *root)
{
//BASE CONDITION
	if (!root) return;

// Let us print root and next level first
	cout << root->data << " ";

	// / Since it is perfect Binary Tree, right is not checked
	if (root->left != NULL)
		cout << " " << root->left->data << " " << root->right->data;

	if (root->left->left == NULL) return;

//MAIN CONDITION
	queue<Node*>q;
	q.push(root->left);
	q.push(root->right);
	Node* first = NULL, *second = NULL;

	while (!q.empty())
	{
		first = q.front();
		q.pop();
		second = q.front();
		q.pop();

// Print children of first and second in reverse order
		cout << first->left->data << " " << second->right->data;
		cout << first->right->data << " " << second->left->data;

		// If first and second have grandchildren, enqueue them
		// in reverse order
		if (first->left != NULL)
		{
			q.push(first->left);
			q.push(second->right);
			q.push(first->right);
			q.push(second->left);
		}


	}
}

int32_t main()
{
	// Node* root = NULL;

	Node *root = newNode(1);

	root->left        = newNode(2);
	root->right       = newNode(3);

	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->right->left  = newNode(6);
	root->right->right = newNode(7);

	root->left->left->left  = newNode(8);
	root->left->left->right  = newNode(9);
	root->left->right->left  = newNode(10);
	root->left->right->right  = newNode(11);
	root->right->left->left  = newNode(12);
	root->right->left->right  = newNode(13);
	root->right->right->left  = newNode(14);
	root->right->right->right  = newNode(15);

	root->left->left->left->left  = newNode(16);
	root->left->left->left->right  = newNode(17);
	root->left->left->right->left  = newNode(18);
	root->left->left->right->right  = newNode(19);
	root->left->right->left->left  = newNode(20);
	root->left->right->left->right  = newNode(21);
	root->left->right->right->left  = newNode(22);
	root->left->right->right->right  = newNode(23);
	root->right->left->left->left  = newNode(24);
	root->right->left->left->right  = newNode(25);
	root->right->left->right->left  = newNode(26);
	root->right->left->right->right  = newNode(27);
	root->right->right->left->left  = newNode(28);
	root->right->right->left->right  = newNode(29);
	root->right->right->right->left  = newNode(30);
	root->right->right->right->right  = newNode(31);

	specificLevelOrder(root);

	return 0;
}