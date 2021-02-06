/*
APPROACH:
The idea is to traverse the tree once and get the minimum and maximum horizontal distance with respect to root. For the tree shown above, minimum distance is -2 (for node with value 4) and maximum distance is 3 (For node with value 9).
Once we have maximum and minimum distances from root, we iterate for each vertical line at distance minimum to maximum from root, and for each vertical line traverse the tree and print the nodes which lie on that vertical line.
*/
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

//func to find min and max distance from root
void find(Node* root, int *min, int *max, int hd)
{
	if (!root) return;

	//update min and max
	if (hd < *min) *min = hd;
	else if (hd > *max) *max = hd;

	find(root->left, min, max, hd - 1);
	find(root->right, min, max, hd + 1);

}

// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void print(Node *root, int line_no, int hd)
{
	if (!root) return;

	if (hd == line_no) cout << root->data << " ";

	verticlOrder(root->left, line_no, hd - 1);
	verticlOrder(root->right, line_no, hd + 1);
}

void verticlOrder(Node *root)
{
	int min = 0, max = 0;
	verticlOrder(root, &min, &max, 0);
	for (int i = min; i < max; i++)
	{
		print(root, line_no, 0);
		cout << endl;
	}
}

int32_t main()
{
	Node* root = NULL;

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);

	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);

	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);


	return 0;
} .