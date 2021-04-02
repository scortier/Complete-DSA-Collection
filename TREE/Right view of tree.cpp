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

//M-1
void rightutil(Node *root, int level , int *maxl)
{
	if (root == NULL) return;

// If this is the first node of its level
	if (*maxl < level)
	{
		cout << root->data << " ";
		*maxl = level;
	}

	rightutil(root->right, level + 1, maxl);
	rightutil(root->left, level + 1, maxl);
}

void rightview(Node *root)
{
	int maxl = 0;
	rightutil(root, 1, &maxl);
}

//M-2
//alternative for pointer fear
//PURA CODE LIKHO AUR JO VALUE HAR POINT PAR UPDATE HO UUSE & LAGAKE FUNCTION K VAR PART M PASS KARDO

void rightutil_ptr(Node *root, int level , int &maxl)
{
	if (root == NULL) return;

// If this is the first node of its level
	if (maxl < level)
	{
		cout << root->data << " ";
		maxl = level;
	}

	rightutil_ptr(root->right, level + 1, maxl);
	rightutil_ptr(root->left, level + 1, maxl);
}

void rightview_ptr(Node *root)
{
	int maxl = 0;
	rightutil_ptr(root, 1, maxl);
}

//M-3
int maxl = 0;
void right_solve(Node *root, int level)
{
	if (root == NULL) return;

	if (level >= maxl)
	{
		cout << root->data << " ";
		maxl++;
	}

	right_solve(root->right, level + 1);
	right_solve(root->left, level + 1);
}
int main()
{


	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	rightview(root);
	cout << endl;
	rightview_ptr(root);
	cout << endl;
	right_solve(root, 0);
	return 0;
}