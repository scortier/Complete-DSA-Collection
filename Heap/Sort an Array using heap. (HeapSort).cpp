/*
1. Heap sort is similar to selection sort in which fibd max ele and place
it at last.
2. Binary heap is similar to comp binary tree (which last level is filled
with left side)

CONVERT INTO ARRAY (INDEX START FROM 0)
-- left: 2i+1 ; right: 2i+2 ; parent : i



*/

#include<bits/stdc++.h>
using namespace std;

/*
1.heapify each level
2. index start with 0
3.
*/

void heapify(int arr[], int n, int i)
{

	int largest = i; //largest as root
	int l = 2 * i + 1; //left
	int r = 2 * i + 2; //right

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}


}

void heapsort(int arr[], int n)
{
	// Index of last non-leaf node
	int start_index = (n / 2) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for (int i = start_index; i >= 0; i--)
	{
		heapify(arr, n, i);
	}


//this part is diff for heap sort from max/min heap
// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}

}


// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
	cout << "Array representation of Heap is:\n";

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}





int main()
{
	// Binary Tree Representation
	// of input array
	// 1
	//           /     \ 
	// 3         5
	//      /    \     /  \ 
	// 4      6   13  10
	//    / \    / \ 
	// 9   8  15 17
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

	int n = sizeof(arr) / sizeof(arr[0]);

	heapsort(arr, n);

	printHeap(arr, n);
	// Final Heap:
	// 17
	//           /      \ 
	// 15         13
	//       /    \      /  \ 
	// 9      6    5   10
	//     / \    /  \ 
	// 4   8  3    1

	return 0;
}