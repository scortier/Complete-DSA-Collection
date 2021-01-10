#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define pr(gg)          cout<<gg<<endl

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********============########################============***********/

struct node {

	int data;
	struct node *left, *right;

};

int sum(struct node *root)
{
	if (root == NULL)
		return 0;
	return sum(root->left) + root->data + sum(root->right);
}

int isLeaf(struct node *node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	return 0;
}
int isSumTree(struct node* node)
{
	int ls, rs;

	/* If node is NULL or it's a leaf node then
	   return true */
	if (node == NULL ||
	        (node->left == NULL && node->right == NULL))
		return 1;

	/* Get sum of nodes in left and right subtrees */
	ls = sum(node->left);
	rs = sum(node->right);

	/* if the node and both of its children satisfy the
	    property return 1 else 0*/
	if ((node->data == ls + rs) &&
	        isSumTree(node->left) &&
	        isSumTree(node->right))
		return 1;

	return 0;
}

struct node* newNode(int data)
{
	struct node* node =
	    (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}




void solve()
{
	struct node *root  = newNode(26);
	root->left         = newNode(10);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(6);
	root->right->right = newNode(3);
	if (isSumTree(root))
		printf("The given tree is a SumTree ");
	else
		printf("The given tree is not a SumTree ");

	getchar();

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}