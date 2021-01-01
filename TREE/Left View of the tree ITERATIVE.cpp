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
	if (root == NULL)
		return;

	queue<Node*>q;

	// Push root
	q.push(root);

	// Delimiter
	q.push(NULL);


	while (!q.empty()) {
		Node* temp = q.front();

		if (temp) {

			// Prints first node
			// of each level
			cout << temp->data << " ";

			// Push children of all nodes at
			// current level
			while (q.front() != NULL) {

				// If left child is present
				// push into queue
				if (temp->left)
					q.push(temp->left);

				// If right child is present
				// push into queue
				if (temp->right)
					q.push(temp->right);

				// Pop the current node
				q.pop();

				temp = q.front();
			}

			// Push delimiter
			// for the next level
			q.push(NULL);
		}

		// Pop the delimiter of
		// the previous level
		q.pop();
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