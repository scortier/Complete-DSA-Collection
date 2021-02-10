/*
APPROACH:
to use queue and stack
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

bool util(vector<stack<int>>&t1, vector<queue<int>> &t2)
{
	for (int i = 0; i < t1.size(); i++)
	{
		stack<int>st = t1[i];
		queue<int>q = t2[i];

		while (!st.empty() and !q.empty())
		{
			if (st.top() != q.front())
				return false;
			st.pop();
			q.pop();
		}

		if (!st.empty() or !q.empty())
			return false;
	}
	return true;
}

void areMirrors(int m, int n, int u1[], int v1[],
                int u2[], int v2[])
{
	vector<stack<int> > tree1(m + 1);
	vector<queue<int> > tree2(m + 1);

	// Pushing node in the stack of first tree.
	for (int i = 0; i < n; i++)
		tree1[u1[i]].push(v1[i]);

	// Pushing node in the queue of second tree.
	for (int i = 0; i < n; i++)
		tree2[u2[i]].push(v2[i]);


	util(tree1, tree2) ? (cout << "Yes" << endl) :
	(cout << "No" << endl);
}

// Driver code
int main()
{
	int M = 3, N = 2;

	int u1[] = { 1, 1 };
	int v1[] = { 2, 3 };

	int u2[] = { 1, 1 };
	int v2[] = { 3, 2 };

	areMirrors(M, N, u1, v1, u2, v2);

	return 0;
}