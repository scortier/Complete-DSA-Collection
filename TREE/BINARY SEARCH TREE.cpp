/*
o Insertion into BST
o Deletion from BST
o Level order print
o Traversal(inorder , preorder and postorder)
o Searching a value in BST
o Check if is BST or not
o Find inorder successor and inorder predecessor
o Print all root node to leaf node paths
o Find min and max value in BST
*/

#include<bits/stdc++.h>
using namespace std;

struct bstnode
{
	int data;
	bstnode* left, *right;
	bstnode(int x)
	{
		data = x;
		left = right = NULL;
	}
};

//////////////////////INSERTION//////////////////////////////
bstnode* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
		return root;

	// Key is greater than root's key
	if (root->key < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

/////////////////////////DELETION///////////////////////////////
/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}


//////////////////////BST OR NOT///////////////////////////
int isBST(node* node)
{
	return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
	/* an empty tree is BST */
	if (node == NULL)
		return 1;

	/* false if this node violates
	the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return
	    isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
	    isBSTUtil(node->right, node->data + 1, max); // Allow only distinct values
}

/////////////////////////////////////////////

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	// Base case
	if (root == NULL)  return ;

	// If key is present at root
	if (root->key == key)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			Node* tmp = root->left;
			while (tmp->right)
				tmp = tmp->right;
			pre = tmp ;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			Node* tmp = root->right ;
			while (tmp->left)
				tmp = tmp->left ;
			suc = tmp ;
		}
		return ;
	}

	// If key is smaller than root's key, go to left subtree
	if (root->key > key)
	{
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	else // go to right subtree
	{
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
}

/////////////////////ITERATIVE MANNER PREDECESSOR///////////////////////

// Function that finds predecessor and successor of key in BST.
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	if (root == NULL)
		return;

	// Search for given key in BST.
	while (root != NULL) {

		// If root is given key.
		if (root->key == key) {

			// the minimum value in right subtree
			// is predecessor.
			if (root->right) {
				suc = root->right;
				while (suc->left)
					suc = suc->left;
			}

			// the maximum value in left subtree
			// is successor.
			if (root->left) {
				pre = root->left;
				while (pre->right)
					pre = pre->right;
			}

			return;
		}

		// If key is greater than root, then
		// key lies in right subtree. Root
		// could be predecessor if left
		// subtree of key is null.
		else if (root->key < key) {
			pre = root;
			root = root->right;
		}

		// If key is smaller than root, then
		// key lies in left subtree. Root
		// could be successor if right
		// subtree of key is null.
		else {
			suc = root;
			root = root->left;
		}
	}
}

////////////////////////////////////////////

/* Given a binary tree, print out
all of its root-to-leaf paths,
one per line. Uses a recursive helper
to do the work.*/
void printPaths(node* node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

/* Recursive helper function -- given
a node, and an array containing the
path from the root node up to but not
including this node, print out all the
root-leaf paths. */
void printPathsRecur(node* node, int path[], int pathLen)
{
	if (node == NULL) return;

	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;

	/* it's a leaf, so print the path that led to here */
	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

////////////////////////////////
/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int minValue(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
	{
		current = current->left;
	}
	return (current->data);
}

///////////////////////////////////

int mAXValue(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->right != NULL)
	{
		current = current->right;
	}
	return (current->data);
}

/////////////////////////////////////
