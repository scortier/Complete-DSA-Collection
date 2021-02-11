/*
APPROACH:
3 CASES:
1.leaf node delete - just delete and move on
2. node to be deleted has only one child- copy(by pass) the child to the node and delete the node
    		  50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80


3.node to be deleted has 2 children -
	USKE LST KA RIGHT MAX CHILD NIKALO AUR NODE KI JGH RKH DO
	OR
	USKE RST KA LEFT MAX CHILD NIKALO AUR NODE KI JGH RKH DO

	Find inorder successor of the node. Copy contents of the inorder successor to the node
	and delete the inorder successor. Note that inorder predecessor can also be used.
	          50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70
                 /  \                            \
                60   80                           80
	The important thing to note is, inorder successor is needed only when right child is
	 not empty. In this particular case, inorder successor can be obtained by finding the
	 minimum value in right child of the node.
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

void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int min(Node *root)
{
	if (root->right != NULL) return min(root->right);
	else return root->data;
}
int max(Node *root)
{
	if (root->right != NULL) return max(root->right);
	else return root->data;
}

Node* remove(Node* root, int key)
{
	if (root == NULL) return NULL;	//key mila hi nhi

	if (key > root->data)
		root->right = remove(root->right, key);
	else if (key < root->data)
		root->left = remove(root->left, key);
	else	//key==root->data  	MIRACLE MIRACLE....
	{
		if (root->left != NULL and root->right != NULL)//DONO CHILD HAI
			// CAN BE DONE IN TWO WAYS
			// 1. find min child in rst and put it inplace of node.
		{
			int mn = min(root->right);
			root->data = mn;
			root->right = remove(root->right, mn);
			return root;
		}
		// 2. find max child in lst(i.e right most child of lst) and put it inplace of node.
		// {	int mx = max(root->left);
		// 	root->data = mx;
		// 	root->left = remove(root->left, mx);
		// 	return root;
		// }
		else if (root->left != NULL)//SIRF LEFT CHILD HAI
			return root->left;
		else if (root->right != NULL)
			return root->right;// SIRF RIGHT CHILD  HAI
		else
			return NULL;
	}
	return root;//GENERIC NODE NOT A SPECIAL CASE

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
	inorder(root); cout << endl;
	root = remove(root, 1); cout << endl;
	inorder(root);
	return 0;
}