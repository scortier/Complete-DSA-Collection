// Author : Aditya Singh Sisodiya (Scortier)

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

void topview(Node *root)
{
	if (root == NULL) return;
	queue<Node*>q;
	map<int, int>m;
	int hd = 0;	//height of the tree
	root->hd = hd;

	q.push(root);

	cout << "The top view of tree is \n";
	while (q.size())
	{
		hd = root->hd;

//count return 1 when containeer contains an element whose
//key is equi to hd or return 0
		if (m.count(hd) == 0)
			m[hd] = root->data;
		if (root->left)
		{
			root->left->hd = hd - 1;
			q.push(root->left);
		}
		if (root->right)
		{
			root->right->hd = hd + 1;
			q.push(root->right);
		}
		q.pop();
		root = q.front();
	}

}

void bottom(Node* root)
{
	if (root == NULL) return;

	map<int, int>mp;
	queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		int hd == temp->height;

		if (mp.find(hd) == NULL)
			mp[hd] = temp->data;
		if (temp->left != NULL)
		{
			temp->left->height = hd - 1;
			q.push(temp->left);
		}

		if (temp->right != NULL)
		{
			temp->right->height = hd + 1;
			q.push(temp->right);
		}
	}
	cout << mp.second << " ";

}
int main()
{


	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	rightview(root);
	return 0;
}