/*
https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/
APPROACH:
Write a function to connect all the adjacent nodes at the same level in a binary tree.

*/
//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left, *right, *nextRight;
};

// Sets nextRight of all nodes of a tree
void connect(struct Node* root)
{
	queue<Node*> q;
	q.push(root);

	// null marker to represent end of current level
	q.push(NULL);

	// Do Level order of tree using NULL markers
	while (!q.empty()) {
		Node *p = q.front();
		q.pop();
		if (p != NULL) {

			// next element in queue represents next
			// node at current Level
			p->nextRight = q.front();

			// push left and right children of current
			// node
			if (p->left)
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}

		// if queue is not empty, push NULL to mark
		// nodes at this level are visited
		else if (!q.empty())
			q.push(NULL);
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newnode(int data)
{
	struct Node* node = (struct Node*)
	                    malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = node->nextRight = NULL;
	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			10
			/ \
		8	 2
		/		 \
	3		 90
	*/
	struct Node* root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->right->right = newnode(90);

	// Populates nextRight pointer in all nodes
	connect(root);

	// Let us check the values of nextRight pointers
	printf("Following are populated nextRight pointers in \n"
	       "the tree (-1 is printed if there is no nextRight) \n");
	printf("nextRight of %d is %d \n", root->data,
	       root->nextRight ? root->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->left->data,
	       root->left->nextRight ? root->left->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->right->data,
	       root->right->nextRight ? root->right->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->left->left->data,
	       root->left->left->nextRight ? root->left->left->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->right->right->data,
	       root->right->right->nextRight ? root->right->right->nextRight->data : -1);
	return 0;
}
