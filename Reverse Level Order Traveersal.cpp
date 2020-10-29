//M-1
/*
	Print node at a given level then decrease the level
	TC:O(n)+O(n-1)+...= O(n^2).
*/

//M-2
// Using queue FIFO TC-O(N) SC-O(N)
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
// Do something like normal level order traversal order. Following are the
// differences with normal level order traversal
// 1) Instead of printing a node, we push the node to stack
// 2) Right subtree is visited before left subtree
void ReverseLevelOrder(Node *root)
{
	queue<Node*>q;
	stack<Node*>s;

	q.push(root);

	while (!q.empty())
	{
		Node*temp = q.front();
		q.pop();
		s.push(temp);

		if (temp->right)
			q.push(root->right);
		if (temp->left)
			q.push(root->left);

	}

	// Now pop all items from stack one by one and print them
	while (!s.push())
	{
		Node*toh = s.top();
		cout << toh->data << " ";
		s.pop();
	}

}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Reverse Level Order traversal of binary tree is \n";
	ReverseLevelOrder(root);
	return 0;
}