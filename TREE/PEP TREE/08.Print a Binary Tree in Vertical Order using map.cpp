/*
APPROACH:
1.MAP BASED SOLUTION VERY SIMILAR TO DIAGONAL TRAVERSAL.
Time Complexity of hashing based solution can be considered as O(n) under the assumption that we have good hashing function that allows insertion and retrieval operations in O(1) time. In the above C++ implementation, map of STL is used. map in STL is typically implemented using a Self-Balancing Binary Search Tree where all operations take O(Logn) time. Therefore time complexity of the above implementation is O(nLogn).

2.

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

// d-distance from the top slope
// mp- multimap to store diagonal ele (pass by ref)
void diagonal_UTIL(Node *root , int d, map<int, vector<int>>&mp)
{
	if (!root) return;

	//store the nodes of same slope
	mp[d].push_back(root->data);

//if we move left to root the slope wiill increase therfore d+1
	diagonal_UTIL(root->left, d - 1, mp);

//while for right of root the slope remiain same u can look in the diagram
	diagonal_UTIL(root->right, d + 1, mp);
}

void diagonal(Node *root)
{
	map<int, vector<int>>mp;
	diagonal_UTIL(root, 0, mp);

	cout << "Diagonal Traversal of binary tree" << endl;
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
	// Node* root = NULL;
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);



	diagonal(root);
	return 0;
}