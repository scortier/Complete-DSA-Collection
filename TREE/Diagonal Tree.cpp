/*
APPROACH:

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

//M-1
//Using Map and vector
/*
The idea is to use a map. We use different slope distances and use them as key
in the map. Value in the map is a vector (or dynamic array) of nodes.
We traverse the tree to store values in the map. Once map is built,
we print the contents of it.
*/
void diag_map_util(Node* root, int level, map<int, vector<int>>&mp)
{
	if (root == NULL) return;

	mp[level].push_back(root->data);

//if left child is present then add it in new level
	diag_map_util(root->left, level + 1, mp);

//if the right child is present then only add it in vector ,no need to increase
//the level as baad m process karne ka koi use nhi.
	diag_map_util(root->right, level, mp);

}

vector<vector<int>>diag_map(Node*root)
{
	// vector<vector<int>>ans;
	// vector<int>path;

	map<int, vector<int>>mp;
	diag_map_util(root, 0, mp);
	for (auto ele : mp)
	{
		// x.first->level
		// x.second->all the nodes present on that level
		vector<int>p = x.second;
		for (auto it : p)
			cout << it << " ";
		cout << endl;
	}
	/*
		for(auto ele:mp)
		{
			ans.push_back(ele.second);
		}
		return ans;
	*/

}


/*M-2
ITERATIVE APPROACH
The idea is to use a queue to store only the left child of current node.
After printing the data of current node make the current node to its right child,
if present.A delimiter NULL is used to mark the starting of next diagonal.
*/
void diag_itr(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*>q;
	q.push(root);

	//push delimiter
	q.push(NULL);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			// if queue is empty return
			if (q.empty())
				return;

			// output nextline
			cout << endl;

			// push delimiter again
			q.push(NULL);
		}
		else {
			while (temp) {
				cout << temp->data << " ";

				// if left child is present
				// push into queue
				if (temp->left)
					q.push(temp->left);

				// current equals to right child
				temp = temp->right;

			}
		}
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

	// root->left->left->left = newNode(8);
	// root->left->left->right = newNode(9);

	// root->left->right->left = newNode(10);
	// root->left->right->right = newNode(11);

	diag_itr(root);
	diag_map(root);
	return 0;
}