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


void preorder(Node *root)
{
	if (root == NULL) return ;

	stack<Node*>s;
	s.push(root);
	while (!s.empty())
	{
		Node* temp = s.top();
		cout << temp->data < endl;

		s.pop();
		if (temp->right) s.push(temp->right);
		if (temp->left) s.push(temp->left);
	}
}

//The idea is to start traversing the tree from root node,
//and keep printing the left child while exists and simultaneously,
//push right child of every node in an auxiliary stack. Once we reach a null node,
//pop a right child from the auxiliary stack and repeat the process while the
//auxiliary stack is not-empty.
//optimized soln
//space : O(h)
void preorderIterative(Node* root)
{
	if (root == NULL)
		return;

	stack<Node*> st;

	// start from root node (set current node to root node)
	Node* curr = root;

	// run till stack is not empty or current is
	// not NULL
	while (!st.empty() || curr != NULL) {
		// Print left children while exist
		// and keep pushing right into the
		// stack.
		while (curr != NULL) {
			cout << curr->data << " ";

			if (curr->right)
				st.push(curr->right);

			curr = curr->left;
		}

		// We reach when curr is NULL, so We
		// take out a right child from stack
		if (st.empty() == false) {
			curr = st.top();
			st.pop();
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


	cout << "Preorder of tree is " << endl;
	preorder(root);
	return 0;
}