/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Bitonic : monotonically increasing then monotonically decreasing

so first find key in ascc order array ,if found return it else return -1;
search same key in decsc array . if found return it else return -1;

*/
#include<bits/stdc++.h>
using namespace std;

int ascBS(int a[], int l, int h, int key)
{
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (a[mid] == key)
			return mid;
		if (a[mid] > key)
			h = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int descBS(int a[], int l, int h, int key)
{
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (a[mid] == key)
			return mid;
		if (a[mid] < key)
			h = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int findPoint(int a[], int n, int l, int h)
{
	int mid;
	int bitonicPoint = 0;
	mid = l + (h - l) / 2;
	if (a[mid] > a[mid - 1] and a[mid] > a[mid + 1])
		return mid;
	else if (a[mid] > a[mid - 1] and a[mid] < a[mid + 1]) //mid jo mila hai vo chota hia
		bitonicPoint = findPoint(a, n, mid, h);
	else if (a[mid] < a[mid - 1] and a[mid] > a[mid + 1])
		bitonicPoint = findPoint(a, n, l, mid);
	return bitonicPoint;

}

int searchBitonic(int arr[], int n,
                  int key, int index)
{
	if (key > arr[index])
		return -1;

	else if (key == arr[index])
		return index;

	else {
		int temp = ascendingBinarySearch(arr, 0, index - 1, key);
		if (temp != -1) {
			return temp;
		}

		// Search in right of k
		return descendingBinarySearch(arr, index + 1, n - 1, key);
	}
}

int32_t main()
{

	int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
	int key = 1;
	int n, l, r;
	n = sizeof(arr) / sizeof(arr[0]);
	l = 0;
	r = n - 1;
	int index;

	// Function call
	index = findPoint(arr, n, l, r);

	int x = searchBitonic(arr, n, key, index);

	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;

	return 0;
}