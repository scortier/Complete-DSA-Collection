// The diameter of a tree is the number of nodes on the longest path
//between two leaves in the tree.
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

int height(Node *root)
{
	if (root == NULL) return 0;
	else
	{
		return (1 + max(height(root->left), height(root->right)));
	}
}

int diameter(Node *root)
{
	if (root == NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	return max(lh + rh + 1,
	           max(ld, rd));
}

//OPTIMIZED
void dia_opt(Node* root, int h)
{
	int lh = 0, rh = 0;

	int ld = 0, rd = 0;

	if (root == NULL) {
		*h = 0;
		return 0;
	}
	ld = dia_opt(root->left, &lh);
	rd = dia_opt(root->right, &rh);

	*h = max(lh, rh) + 1;

	return max(lh + rh + 1, max(ld, rd));

}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "diameter of tree is " << diameter(root);
	return 0;
}