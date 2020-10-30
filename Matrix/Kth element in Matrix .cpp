//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;
/*
The idea is to use min heap. Create a Min-Heap to store the elements
Traverse the first row from start to end and build a min heap of elements from first row. A heap entry also stores row number and column number.
Now Run a loop k times to extract min element from heap in each iteration
Get minimum element (or root) from Min-Heap.
Find row number and column number of the minimum element.
Replace root with the next element from same column and min-heapify the root.
Print the last extracted element, which is the kth minimum element
*/
struct HeapNode {
	int val;
	int r, c;
};


void swap(HeapNode *x, HeapNode *y)
{
	HeapNode z = *x;
	*x = *y;
	*y = z;
}

void minHeapify(HeapNode harr[], int i, int heap_size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int smallest = i;
	if (l < heap_size and harr[l].val < harr[smallest].val)
		smallest = l;
	if (r < heap_size && harr[r].val < harr[smallest].val)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		minHeapify(harr, smallest, heap_size);
	}
}

void buildHeap(HeapNode harr[], int n)
{
	int i = (n - 1) / 2;
	while (i >= 0)
	{
		minHeapify(harr, i, n);
		i--;
	}
}

int kthSmallest(int mat[4][4], int n, int k)
{
	// k must be greater than 0 and smaller than n*n
	if (k <= 0 || k > n * n)
		return INT_MAX;

	// Create a min heap of elements from first row of 2D array
	HeapNode harr[n];
	for (int i = 0; i < n; i++)
		harr[i] = {mat[0][i], 0, i};
	buildHeap(harr, n);

	HeapNode hr;
	for (int i = 0; i < k; i++)
	{
		// Get current heap root
		hr = harr[0];

		// Get next value from column of root's value. If the
		// value stored at root was last value in its column,
		// then assign INFINITE as next value
		int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c] : INT_MAX;

		// Update heap root with next value
		harr[0] = {nextval, (hr.r) + 1, hr.c};

		// Heapify root
		minHeapify(harr, 0, n);
	}

	// Return the value at last extracted root
	return hr.val;
}

int main()
{
	int mat[4][4] =
	{	{10, 20, 30, 40},
		{15, 25, 35, 45},
		{25, 29, 37, 48},
		{32, 33, 39, 50},
	};
	cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
	return 0;
}