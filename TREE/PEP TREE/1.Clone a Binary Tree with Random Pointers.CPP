//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right, *random;//random - a ptr to random node
};

Node *newNode(int x)
{
	Node* temp = new Node;
	temp->random = temp->left = temp->right = NULL;
	temp->data = x;
	return temp;
}

void inorder(Node* node)
{
	if (node == NULL) return NULL;
	inorder(node->left);
	cout << node->data << " ";
	if (node->random == NULL)
		cout << "NULL ";
	else
		cout << node->random->data << " ";
	inorder(node->right);
}
//clonennode - currently visited node in clone tree.
// This function creates clone by copying key and left and right pointers
// This function also stores mapping from given tree node to clone.
Node* clone(Node* treenode, unordered_map<Node*, Node*>&mp)
{
	if (treenode == NULL) return NULL;
	Node* cloneNode = newNode(treenode->data); //created new node i.e clonenode with data as of treenode
	mp[treenode] = cloneNode;
	cloneNode->left = clone(treenode->left, mp);
	cloneNode->right = clone(treenode->right, mp);
	return cloneNode;
}

// This function copies random node by using the hashmap built by
// copyLeftRightNode()
void cloneRandom(Node* treeNode, Node* cloneNode, unordered_map<Node*, Node*>&mymp)
{
	if (cloneNode == NULL) return;

	cloneNode->random = mymp[treeNode->random];
	cloneRandom(treeNode->left, cloneNode->left, mymp);
	cloneRandom(treeNode->right, cloneNode->right, mymp);
}

// This function makes the clone of given tree. It mainly uses
// copyLeftRightNode() and copyRandom()
Node* cloneTree(Node* tree)
{
	if (tree == NULL) return NULL;
	unordered_map<Node*, Node*> mp;
	Node* newTree = clone(tree, mp);
	copyRandom(tree, newTree, mp);
	return newTree;
}

int32_t main()
{
	Node *tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
	tree->left->right = newNode(5);
	tree->random = tree->left->right;
	tree->left->left->random = tree;
	tree->left->right->random = tree->right;

	//  Test No 2
	//    tree = NULL;

	//  Test No 3
	//    tree = newNode(1);

	//  Test No 4
	/*    tree = newNode(1);
	    tree->left = newNode(2);
	    tree->right = newNode(3);
	    tree->random = tree->right;
	    tree->left->random = tree;
	*/

	cout << "Inorder traversal of original binary tree is: \n";
	printInorder(tree);

	Node *clone = cloneTree(tree);

	cout << "\n\nInorder traversal of cloned binary tree is: \n";
	printInorder(clone);

	return 0;
}