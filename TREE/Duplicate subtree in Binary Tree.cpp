/*
APPROACH:
Form a string  from root then left then right and store this subtree count in mp ,
if mp==2 mtlb repeat hua hai subtree.

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

unordered_map<string, int>mp;
string util(Node *root)
{
	if (!root) return "$";
	string v ;
	if (!root->left and !root->right)
	{	v = (to_string(root->data));
		return v;
	}

	v += to_string(root->data);
	v += (util(root->left));
	v += (util(root ->right));
	mp[v]++;
	return v;
}

bool dupSub(Node *root)
{
	mp.clear();
	util(root);
	for (auto x : mp)
		if (x.second >= 2) return true;
	return false;
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

	if (dupSub(root)) cout << "Shi samjhe present hai";
	else cout << "Nikal";
	return 0;
}