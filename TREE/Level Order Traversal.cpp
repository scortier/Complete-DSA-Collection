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

void LevelOrder_linebyline(Node* root)
{
	if (root == NULL) return;
	queue<Node*>q;
	q.push(root);

	while (true) {
		int size = q.size();
		if (size == 0) break;

//dhyan de y size hai(constant) naaki q.size() jo update ho rha ,size ko line 53 m har baar updare karenge
		while (size > 0)//for(int i=0;i<n;i++) look left view iteraive soln
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

			size--;

		}
		cout << endl;
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
	cout << endl;
	LevelOrder_linebyline(root);
	return 0;
}
//java
/*
public void levelOrderTraversalUsingQueueLineByLine(Node node) {
	if (node == null) {
		return;
	}

	Queue<Node> a = new LinkedList<Node>();
	a.add(node);

	while (true) {

		int queueSize = a.size();
		if (queueSize == 0) {
			break;
		}

		while (queueSize > 0) {

			Node temp = a.peek();
			System.out.print(temp.data + " ");

			a.remove();

			if (temp.left != null) {
				a.add(temp.left);
			}

			if (temp.right != null) {
				a.add(temp.right);
			}

			queueSize--;
		}

		System.out.println();
	}
}
*/