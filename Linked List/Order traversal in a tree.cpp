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

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder (root->left);
	cout << root->data << " ";
	inorder (root->right);
}

void preorder(Node *root)
{	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder (root->left);
	preorder(root->right);

}

void postorder(Node *root)
{	if (root == NULL)
		return;
	postorder (root->left);
	postorder(root->right);
	cout << root->data << " ";

}


int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Inorder of tree is " << endl;
	inorder(root);
	cout << "Postorder of tree is " << endl;
	postorder(root);
	cout << "Preorder of tree is " << endl;
	preorder(root);
	return 0;
}