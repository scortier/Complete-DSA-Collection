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

/*You’ll dequeue nodes from the current_queue, print the node’s data, and enqueue the node’s
 children to the next_queue. Once the current_queue becomes empty, you have processed all
 nodes for the current level_number. To indicate the new level, print a line break (’\n’),
  swap the two queues, and continue with the above-mentioned logic.

After printing the leaf nodes from the current_queue, swap current_queue and next_queue.
Since the current_queue would be empty, you can terminate the loop.
*/
void lotqueue(Node *root)
{
	if (root == NULL) return;

	queue<Node*>arr[2];
	//declaring two queue
	queue<Node*> *currlevel = &arr[0];
	queue<Node*> *nextlevel = &arr[1];

	currlevel->push(root);
	int level = 0;
	bool lefttoright = true;
	while (!currlevel->empty())
	{
		//pop out of queue
		Node* temp = currlevel->front();
		currlevel->pop();

		//if temp is not null

		cout << temp->data << " ";

		//store data acc to current order

		if (temp->left != NULL)
			nextlevel->push(temp->left);
		if (temp->right != NULL)
			nextlevel->push(temp->right);


		if (currlevel->empty())
		{
			cout << endl;
			++level;
			currlevel = &arr[level % 2];
			nextlevel = &arr[(level + 1) % 2];
		}
	}
	cout << endl;

}

int main()
{

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "ZigZag Order traversal of binary tree is \n";

	lotqueue(root);
	return 0;
}