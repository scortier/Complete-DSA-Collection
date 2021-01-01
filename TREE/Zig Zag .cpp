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

void zigzag(Node *root)
{
	if (root == NULL) return;

	//declaring two stack
	stack<Node*> currlevel;
	stack<Node*> nextlevel;

	currlevel.push(root);

	bool lefttoright = true;
	while (!currlevel.empty())
	{
		//pop out of stack
		Node* temp = currlevel.top();
		currlevel.pop();

		//if temp is not null
		if (temp) {
			cout << temp->data << " ";

			//store data acc to current order
			if (lefttoright) {
				if (temp->left)
					nextlevel.push(temp->left);
				if (temp->right)
					nextlevel.push(temp->right);
			}
			else
			{
				if (temp->right)
					nextlevel.push(temp->right);
				if (temp->left)
					nextlevel.push(temp->left);
			}
		}
		if (currlevel.empty())
		{
			lefttoright = !lefttoright;
			swap(currlevel, nextlevel);
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

	cout << "ZigZag Order traversal of binary tree is \n";

	zigzag(root);
	return 0;
}