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


//M-1 INSERT ELEMENTS OF FIRST TREE TO SECOND.(TC: O(mlogn) to O(mlog(m+n-1)))
//M-2 CONVERT TREE IN TO ARRAY BY INORDER TO MAKE SORTED ARRAY THEN
//MERGE BOTH ARRAYS THEN MAKE BST FROM IT.

int *merge(int a1[], int a2[], int m, int n);

void storeInorder(Node* root, int inorder[], int *index);

Node* sortedArrayToBST(int arr[], int start, int end);


/* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
Node* mergeTrees(node *root1, node *root2, int m, int n)
{
	// Store inorder traversal of
	// first tree in an array arr1[]
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	// Store inorder traversal of second
	// tree in another array arr2[]
	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	// Merge the two sorted array into one
	int *mergedArr = merge(arr1, arr2, m, n);

	// Construct a tree from the merged
	// array and return root of the tree
	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

// A utility unction to merge
// two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n)
{
	// mergedArr[] is going to contain result
	int *mergedArr = new int[m + n];
	int i = 0, j = 0, k = 0;

	// Traverse through both arrays
	while (i < m && j < n)
	{
		// Pick the smaler element and put it in mergedArr
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	// If there are more elements in first array
	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	// If there are more elements in second array
	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}

// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* now recur on right child */
	storeInorder(node->right, inorder, index_ptr);
}






int main()
{
	/* Create following tree as first balanced BST
	    100
	    / \
	    50 300
	/ \
	20 70
	*/
	node *root1 = newNode(100);
	root1->left     = newNode(50);
	root1->right = newNode(300);
	root1->left->left = newNode(20);
	root1->left->right = newNode(70);

	/* Create following tree as second balanced BST
	        80
	    / \
	    40 120
	*/
	node *root2 = newNode(80);
	root2->left     = newNode(40);
	root2->right = newNode(120);

	node *mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Following is Inorder traversal of the merged tree \n";
	printInorder(mergedTree);

	return 0;
}