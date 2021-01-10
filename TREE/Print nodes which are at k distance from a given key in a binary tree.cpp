#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}


void printkdistanceNodeDown(struct Node *root, int k)
{
	// Base Case
	if (root == NULL || k < 0)  return;
	if (k == 0)
	{
		printf("%d", root->data);
		return;
	}

	printkdistanceNodeDown(root->left, k - 1);
	printkdistanceNodeDown(root->right, k - 1);
}
int printkdistanceNode(struct Node* root, struct Node* target , int k)
{
	if (root == NULL) return -1;
	if (root == target)
	{
		printkdistanceNodeDown(root, k);
		return 0;
	}

	int dl = printkdistanceNode(root->left, target, k);
	if (dl != -1)
	{
		if (dl + 1 == k)
			printf("%d", root->data);
		else
			printkdistanceNodeDown(root->right, k - dl - 2);
		return 1 + dl;
	}

	int dr = printkdistanceNode(root->right, target, k);
	if (dr != -1)
	{
		if (dr + 1 == k)
			printf("%d", root->data);
		else
			printkdistanceNodeDown(root->left, k - dr - 2);
		return 1 + dr;
	}
	return -1;
}


int main()

{

	struct Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	struct Node *target = root->left->right;
	printkdistanceNode(root, target, 2);
	return 0;
}