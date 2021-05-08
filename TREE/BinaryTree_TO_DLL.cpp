/*
APPROACH :
TC:O(n^ 2) //T(N/2)+T(N/2)+O(N)
1.
- Convert LST into DLL
- Convert RST into DLL
- Join three lists(lst,rst,root)
convert each tree Node to dll Nodes with left and right pointer then
convert the left and right tree with
dll then combining both dll with root by shifting the pointer of left tree to end of it
and for right tree towards the starting of it.

2.TC:O(N) not so easy
That pointer shifting from root to end or head takes O(n) .So we can reduce it to O(1)
by alloting to pointer to the head and tail of each Node.

//1st approach code
*/
#include <stdio.h>
#include <stdlib.h>
// building a BT
struct Node {
	int data;
	Node *left, *right;
};

Node *newNode(int x)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = x;
	return temp;
}
//RECURSION USED
Node *convertBSTtoDLL( Node *root)
{
	if (root->left)
	{
		//LST TO DLL BUT middle Node return to Node.
		Node *lTree = convertBSTtoDLL(root->left);
		//as long as there is right element  move towards it. or going till right end
		for (; lTree->right; lTree = lTree->right); //inorder predecesor
		lTree->right = root; //point rightmost element of lTree to root.
		// root ka left ptr point to rigghtmost ele of lTree.
		root->left = lTree;	//return ptr from left tree root ptr to rightmost element of LST.
	}
	if (root->right)	//check whether RST exist or not.
	{
		//RST TO DLL BUT middle Node return to Node.
		Node *rTree = convertBSTtoDLL(root->right);
		//as long as there is left element move towards it.
		for (; rTree->left; rTree = rTree->left); //inorder successor
		rTree->left = root; //point leftmost element to root.
		root->right = rTree; //return ptr from root right ptr to leftmost element of RST.
	}
	return root;
}

void printDLL( Node *head)
{
	Node *temp = head;
	while (temp)
	{
		printf("%d\t", temp->data);
		temp = temp->left;
	}
}

int main()
{
	Node *root, *lca, *head;
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