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

void mirror(Node* root)
{
	if (root == NULL) return;
	else
	{
		Node* temp;
		mirror(root->left);
		mirror(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void inOrder( Node* node)
{
	if (node == NULL)
		return;

	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}


int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Inorder traversal of the constructed"
	     << " tree is" << endl;
	inOrder(root);

	/* Convert tree to its mirror */
	mirror(root);

	/* Print inorder traversal of the mirror tree */
	cout << "\nInorder traversal of the mirror tree"
	     << " is \n";
	inOrder(root);
	return 0;
}