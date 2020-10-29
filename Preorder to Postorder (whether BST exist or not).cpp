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


void postopre(int pre[], int n, int minm, int maxm, int &preindex)
{
	if (preindex == 0) return;

	if (pre[preindex]<minm or pre[preindex]>maxm)
	{
		return ;
	}

	int val = pre[preindex];
	preindex++;


	postopre(pre, n, minm, val, preindex);
	postopre(pre, n, val, maxm, preindex);

	cout << val << " ";
}

void finfpost(int pre[], int n)
{
	int preindex = 0;
	finfpost(pre, n, INT_MIN, INT_MAX, preindex);
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