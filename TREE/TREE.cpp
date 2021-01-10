/*
o Insertion of Node
o Deletion of Node
o InorderTraversal (Recursive and Iterative)
o Preorder Traversal (Recursive and Iterative)
o Postorder Traversal (Recursive and Iterative)
o Level Order Traversal
o Reverse Level Order traversal
o Searching of ValueoHeight of tree
o Diameter of TreeoMirror of Tree
o Check tree is balanced or not
o Find minimum value in tree
o Find maximum value in tree
*/


#include<bits/stdc++.h>
using namespace std;

struct bbnode
{
	int data;
	bbnode *left, *right;
	bbnode(int x)
	{
		data = x;
		left = right = NULL;
	}
};


// Utility function to create a new tree node
bbnode* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


//to insert bnode in a binary tree
//If we find a node whose left child is empty, we make new key as left child of the node.
//else if we find a node whose right child is empty,
//we make new key as right child. We keep traversing the tree until
//we find a node whose either left or right is empty.
void insert(bbnode *root, int data)
{
	queue<bbnode*>q;
	q.push(root);
//two operators new and delete that perform the
	//task of allocating and freeing the memory in a better and easier way.
//do level order trav (LEVEL BY LEVEL)until find a empty space.
	while (!q.empty()) //jab tak q khali nhi ho jata
	{
		bbnode* temp = q.front();
		q.pop();

		if (!temp->left)	// temp->left is not equal to null.
		{
			temp->left = new bbnode(data);
			break;
		}
		else
			q.push(temp->left);

		if (!temp->right) {
			temp->right = new bbnode(data);
			break;
		}
		else
			q.push(temp->right);

	}
}

//1.select arbitary bnode to be deleted.
//2.replace that bnode with deepest rightmost bnode.
//3.then delete the rightmost deepest element.
void deleteDeepest	(bbnode* root, bbnode* d_bnode)
{
	queue<bbnode*>q;
	q.push(root);

// Do level order traversal until last bnode
	while (!q.empty())
	{
		bbnode* temp = q.front();	//q ka first element temp m store kar diya gya hai
		q.pop();	//us first ele ko pop kardiya hai

		if (temp == d_bnode) {	//root ki baat kar rha
			temp = NULL;
			delete(d_bnode);
			return;
		}
		if (temp->right)	//agr right leaf exist karta hai toh
		{
			if (temp->right == d_bnode)
			{
				temp->right = NULL;
				delete(d_bnode);
				return;
			}
			else q.push(temp->right);
		}

		if (temp->left)
		{
			if (temp->left == d_bnode)
			{
				temp->left = NULL;
				delete(d_bnode);
				return;
			}
			else q.push(temp->left);
		}

	}

}

void deleteinBT(bbnode *root, int data)
{
	if (root == NULL)	return NULL;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->data == data)
			return NULL;
		else
			return root;
	}

	queue<bbnode*>q;
	q.push(root);

	bbnode* temp;
	bbnode* req_bnode = NULL;

	// Do level order traversal to find deepest
	// bnode(temp) and bnode to be deleted (req_bnode)
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->data == data)
			req_bnode = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (req_bnode != NULL) {
		int x = temp->data;
		deleteDeepest(root, temp);
		req_bnode->data = x;
	}
	return root;

}


/////////////////////////////////////////

//inorder recursive
void inorder(bbnode* root)
{
	if (root == NULL) return ;
	else {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);

	}
}

//inorder iterative
///////////LEVEL ORDER TRAVERSAL == height of the tree////////////
// Iterative method to find height of Binary Tree
void LevelOrder(bnode *root)
{
	// Base Case
	if (root == NULL)  return;

	// Create an empty queue for level order traversal
	queue<bnode *> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		bnode *bnode = q.front();
		cout << bnode->data << " ";
		q.pop();

		/* Enqueue left child */
		if (bnode->left != NULL)
			q.push(bnode->left);

		/*Enqueue right child */
		if (bnode->right != NULL)
			q.push(bnode->right);
	}
}


void ReverseLOT(bnode* root, int data)
{
	stack <node *> S;
	queue <node *> q;
	q.push(root);

	// Do something like normal level order traversal order. Following are the
	// differences with normal level order traversal
	// 1) Instead of printing a node, we push the node to stack
	// 2) Right subtree is visited before left subtree
	while (q.empty() == false)
	{
		/* Dequeue node and make it root */
		root = q.front();
		q.pop();
		S.push(root);

		/* Enqueue right child */
		if (root->right)
			q.push(root->right); // NOTE: RIGHT CHILD IS ENqUEUED BEFORE LEFT

		/* Enqueue left child */
		if (root->left)
			q.push(root->left);
	}

	// Now pop all items from stack one by one and print them
	while (S.empty() == false)
	{
		root = S.top();
		cout << root->data << " ";
		S.pop();
	}
}


///////////////////////////////////////////
// Function to traverse the tree in preorder
// and check if the given node exists in it
bool ifNodeExists(bnode* node, int data)
{
	if (node == NULL)
		return false;

	if (node->data == data)
		return true;

	/* then recur on left sutree */
	ifNodeExists(node->left, data);


	/* node is not found in left, so recur on right subtree */
	ifNodeExists(node->right, data);

}
////////////////////////////////////////////
/*  The function Compute the "height" of a tree. Height is the
    number f nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(bnode* node)
{
	/* base case tree is empty */
	if (node == NULL)
		return 0;

	/* If tree is not empty then height = 1 + max of left
	   height and right heights */
	return 1 + max(height(node->left), height(node->right));
}
////////////////////////////////////////////

/* Function to get diameter of a binary tree */
int diameter(bnode * tree)
{
	/* base case where tree is empty */
	if (tree == NULL)
		return 0;

	/* get the height of left and right sub-trees */
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	/* get the diameter of left and right sub-trees */
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	/* Return max of following three
	 1) Diameter of left subtree
	 2) Diameter of right subtree
	 3) Height of left subtree + height of right subtree + 1 */
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

////////////////////////////////////////////
void mirror(bnode* node)
{
	if (node == NULL)
		return;
	else
	{
		struct Node* temp;

		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);

		/* swap the pointers in this node */
		temp     = node->left;
		node->left = node->right;
		node->right = temp;
	}
}





////////////////////////////////////////////
/* Returns true if binary tree
with root as root is height-balanced */
bool isBalanced(bnode* root)
{
	int lh; /* for height of left subtree */
	int rh; /* for height of right subtree */

	/* If tree is empty then return true */
	if (root == NULL)
		return 1;

	/* Get the height of left and right sub trees */
	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	/* If we reach here then
	tree is not height-balanced */
	return 0;
}

////OPTIMISED CODE/////
/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
bool isBalanced_optimized(bnode* root, int* height)
{

	/* lh --> Height of left subtree
	rh --> Height of right subtree */
	int lh = 0, rh = 0;

	/* l will be true if left subtree is balanced
	and r will be true if right subtree is balanced */
	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;
		return 1;
	}

	/* Get the heights of left and right subtrees in lh and rh
	And store the returned values in l and r */
	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	/* Height of current node is max of heights of left and
	right subtrees plus 1*/
	*height = (lh > rh ? lh : rh) + 1;

	/* If difference between heights of left and right
	subtrees is more than 2 then this node is not balanced
	so return 0 */
	if (abs(lh - rh) >= 2)
		return 0;

	/* If this node is balanced and left and right subtrees
	are balanced then return true */
	else
		return l && r;
}

////////////////////////////////////////////
int findMax(bnode* root)
{
	if (root == NULL) return INT_MIN;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = root->data;
	int lres = findMax(root->left);
	int rres = findMax(root->right);
	if (lres > res)
		res = lres;
	else if (rres > res)
		res = rres;
	return res;
}
////////////////////////////////////////////

// Returns minimum value in a given Binary Tree
int findMin(bnode* root)
{
	// Base case
	if (root == NULL)
		return INT_MAX;

	// Return minimum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = root->data;
	int lres = findMin(root->left);
	int rres = findMin(root->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return res;
}


int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->right->left  = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}