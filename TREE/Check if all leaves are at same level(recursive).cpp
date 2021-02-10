/*
APPROACH:

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

int ans;//if ans =0 then all leaf are at same level
//if ans!=0 then all leaf are not on same level
void util(Node *root, int level, int &leaflevel)
{
	if (!root) return ;
	if (ans == 0) return;
//if leaf node is encountered
	if (root->left == NULL and root->right == NULL)
	{
		//when a leaf node is found
		//first time
		if (leaflevel == -1)
		{
			leaflevel = level; //set first found leaf's level
			return ;
		}
		else
		{
			if (leaflevel != level)
				ans = 0;
		}
		return;
	}

	//tab tk chalate rho jab tk leaf node na aajae
	util(root->left, level + 1, leaflevel);
	util(root->right, level + 1, leaflevel);
}

bool check(Node *root)
{
	int level = 0, leaflevel = -1;
	ans = 1;
	util(root, level, leaflevel);
	return ans;
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
	// root->left->left->right = newNode(9);

	// root->left->right->left = newNode(10);
	// root->left->right->right = newNode(11);

	if (check(root))
		cout << "Leaves are at same level\n";
	else
		cout << "Leaves are not at same level\n";
	return 0;
}