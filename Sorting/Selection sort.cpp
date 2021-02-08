/*
A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order
in sorted output as they appear in the input array to be sorted.
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
UNSTABLE SORTING(AS SWAPPING IS INVOLVED) BUT CAN BE MADE STABLE

FIND MINIMUM ELE IN EVERY ITERATION AND PUTTING ON BEGINNING OF ARRAY.
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Time Complexity: O(n2) as there are two nested loops.

Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.



*/
#include<bits/stdc++.h>
using namespace std;

void unstable_selection_sort(int a[],int n)
{
	int min_index;
	for (int i = 0; i < n; i++)
	{
		min_index = i;
		//find the minm ele in unsorted array
		for (int j = i + 1; j < n; j++)	// sabse chota ele dhundo
		{
			if (a[j] < a[min_index])
				min_index = j;
		}

		//swap the founded minm ele with first ele.
		swap(a[min_index], a[i]);
	}
}

void stable_selecion(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minm])
				minm = j;
		}

		//similar to insertion sort , chota ele jagh se uthao aut aage  rakh do;
		int key = a[minm];
		while (minm > i)
		{
			a[minm] = a[minm - 1]; //basically minm ele jaha par hai uuse hatao aurr baaki uske aage saare ele ko one position shift kardo
			minm--;
		}
		a[i] = key; //chote ele ko aage daldo.
	}
}
int32_t main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, n);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}