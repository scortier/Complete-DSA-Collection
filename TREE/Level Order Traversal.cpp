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

void LevelOrder(Node *root)
{
	if (root == NULL) return;
	queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		Node *temp = q.front();
		cout << temp->data << " ";
		q.pop();

		//Enqueue left child
		if (temp->left != NULL)
			q.push(temp->left);

		//Ennqueue right child
		if (temp->right != NULL)
			q.push(temp->right);
	}
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	LevelOrder(root);
	return 0;
}