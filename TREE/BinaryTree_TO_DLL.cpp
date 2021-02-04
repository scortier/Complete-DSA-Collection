/*
APPROACH :
TC:O(n2) //T(N/2)+T(N/2)+O(N)
1. convert each tree node to dll nodes with left and right pointer then convert the left and right tree with
dll then combining both dll with root by shifting the pointer of left tree to end of it and
for right tree towards the starting of it.

*/
#include <stdio.h>
#include <stdlib.h>
// building a BT
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
// constructing newnode.
struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
//RECURSION USED
struct node *convertBSTtoDLL(struct node *root)
{
	if (root->left)
	{
		//LST TO DLL BUT middle node return to node.
		struct node *lTree = convertBSTtoDLL(root->left);
		//as long as there is right element  move towards it.
		for (; lTree->right; lTree = lTree->right); //inorder predecesor
		lTree->right = root; //point rightmost element to root.
		root->left = lTree;	//return ptr from left tree root ptr to rightmost element of LST.
	}
	if (root->right)	//check whether RST exist or not.
	{
		//RST TO DLL BUT middle node return to node.
		struct node *rTree = convertBSTtoDLL(root->right);
		//as long as there is left element move towards it.
		for (; rTree->left; rTree = rTree->left); //inorder successor
		rTree->left = root; //point leftmost element to root.
		root->right = rTree; //return ptr from root right ptr to leftmost element of RST.
	}
	return root;
}

void printDLL(struct node *head)
{
	struct node *temp = head;
	while (temp)
	{
		printf("%d\t", temp->data);
		temp = temp->left;
	}
}

int main()
{
	struct node *root, *lca, *head;
	root = newNode(25);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->left->right = newNode(15);
	root->left->right->left = newNode(12);
	head = convertBSTtoDLL(root);
	printDLL(head);
	return 0;
}