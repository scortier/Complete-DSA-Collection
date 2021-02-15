/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1.heap is slao a complete BT (which has both child or no child)
2.
*/
#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i)
{
	int largest = i; //initialize largest as root
	int l = 2 * i + 1;	//left
	int r = 2 * i + 2;	//right

	if ()
	}


// Function to build a Max-Heap from the given array
void buildHeap(int a[], int n)
{
	//index of least non leaf node
	int startIndex = (n / 2) - 1;


}


int32_t main()
{
// Binary Tree Representation
	// of input array
	// 				1
	//           /     \ 
	// 		  3         5
	//      /    \     /  \ 
	// 		4      6   13  10
	//    / \    / \ 
	// 	 9   8  15 17
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
	// Final Heap:
	// 				17
	//           /      \ 
	// 		  15         13
	//       /    \      /  \ 
	// 		9      6    5   10
	//     / \    /  \ 
	// 	  4   8  3    1

	return 0;
}