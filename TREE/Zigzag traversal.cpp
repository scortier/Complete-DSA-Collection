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

/*
1. two stack used currl,nextl and var to kepp track on level.
2. We pop from the currentlevel stack and print the nodes value. Whenever the current level order is from left to right, push the nodes left child, then its right child to the stack nextlevel. Since a stack is a LIFO(Last-In-First_out) structure, next time when nodes are popped off nextlevel, it will be in the reverse order. On the other hand, when the current level order is from right to left, we would push the nodes right child first, then its left child. Finally, do-not forget to swap those two stacks at the end of each level
*/
void zigzag(Node*root)
{
	if (!root) return;

	stack<Node*> currl_st;
	stack<Node*> nextl_st;

	//push the root
	currl_st.push(root);

	//check if stack is empty
	bool lefttoright = true;
	while (!currl_st.empty())
	{
		Node* temp = currl_st.top();
		currl_st.pop();

		if (temp) {

			cout << temp->data << " ";

			if (lefttoright)
			{
				if (temp->left)
					nextl_st.push(temp->left);
				if (temp->right)
					nextl_st.push(temp->right);
			}
			else

			{
				if (temp->right)
					nextl_st.push(temp->right);
				if (temp->left)
					nextl_st.push(temp->left);
			}
		}

		if (currl_st.empty()) {
			lefttoright = !lefttoright;
			swap(currl_st, nextl_st);
		}
	}
}



int main()
{

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);

	cout << "ZigZag Order traversal of binary tree is \n";

	zigzag(root);
	return 0;
}