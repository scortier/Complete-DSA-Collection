/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
https://clementmihailescu.github.io/Sorting-Visualizer/

SIMPLEST ALGO that eorks by repeatedly swapping the adj ele if they are in wroong order.
1.iterative
TC:O(n^2) irrespective of sorted array
Two loops will run compare adjacent ele at a time and do reqd opn , at each oter loop itn
last ele get fixed(uski jagah final hogyi).
Jo bhi largest ele hoga vo outer loop k first itn m last m pohoch jaega then sec largest then third largest
piche se array fixed hota jaega.


How to implement it recursively?
Recursive Bubble Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Bubble Sort and recursion.
If we take a closer look at Bubble Sort algorithm, we can notice that in first pass, we move largest element to end (Assuming sorting in increasing order). In second pass, we move second largest element to second last position and so on
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void bubble(int a[], int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}

}

void bubble_recurse(int a[], int n)
{
	//base case
	if (n == 1) return ;

	//do one pass of normal bubble sort,this pass fixes last ele of current subarray
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			swap(a[i], a[i + 1]);

	//largest ele is fixed and recur for remaining ele
	// Recur for all elements except last of current subarray.
	bubble_recurse(a, n - 1);
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