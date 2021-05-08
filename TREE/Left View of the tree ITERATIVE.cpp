/*The idea is to do level order traversal of the Tree using a queue and
print the first node at each level.

While doing level order traversal, after traversing all node at each level,
 push a NULL delimiter to mark the end of the current level

 Print the first node at each level in the tree and push the children of all
 nodes at each level in the queue until a NULL delimiter is encountered.
 */
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

void leftview(Node *root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		// number of nodes at current level
		int n = q.size();

		// Traverse all nodes of current level
		for (int i = 1; i <= n; i++)//while(!q.size())
		{
			Node* temp = q.front();
			q.pop();

			// Print the left most element
			// at the level
			if (i == 1)
				cout << temp->data << " ";

			// Add left node to queue
			if (temp->left != NULL)
				q.push(temp->left);

			// Add right node to queue
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}




int main()
{


	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	leftview(root);
	return 0;
}