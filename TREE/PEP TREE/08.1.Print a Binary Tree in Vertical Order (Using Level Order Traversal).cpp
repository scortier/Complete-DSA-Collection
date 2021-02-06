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

void solve(Node* root)
{
	map<int, vector<int>>mp;
	if (!root) return ;
	int hd = 0; //horizontal distance
	queue<pair<Node*, int>>q; //node and the hd of that node
	q.push(make_pair(root, hd));
	while (!q.empty())
	{
		pair<Node*, int> temp = q.front();
		q.pop();
		hd = temp.second;
		Node* node = temp.first;

		mp[hd].push_back(node->data);

		if (node->left != NULL)
			q.push(make_pair(node->left, hd - 1));
		if (node->right != NULL)
			q.push(make_pair(node->right, hd + 1));
	}


	for (auto x : mp)
	{
		vector<int>v = x.second;
		for (auto y : v)

			cout << y << " ";
		cout << endl;

	}
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

	solve(root);
	return 0;
}