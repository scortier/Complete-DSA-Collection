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

void inorder(Node *root)
{
	if (root == NULL) return;
	stack<Node *>s;
	Node* curr = root;

	while (curr != NULL || !s.empty())
	{
		while (curr != NULL)
		{
			/* place pointer to a tree node on the stack before traversing the node's left subtree */
			s.push(curr);
			curr = curr->left;
		}

		/* Current must be NULL at this point */
		curr = s.top();
		s.pop();
		cout << curr->data << endl;
		/* we have visited the node and its left subtree.  Now, it's right subtree's turn */
		curr = curr->right;
	}

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

//optimized soln
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

	cout << "Inorder of tree is " << endl;
	inorder(root);
	cout << "Postorder of tree is " << endl;
	postorder(root);
	cout << "Preorder of tree is " << endl;
	preorder(root);
	return 0;
}