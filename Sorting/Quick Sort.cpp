/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1.DIVIDE AND CONQUER BASED
2.SELECT PIVOT
	2.1 IN START
	2.2 IN END
	2.3 IN MIDDLE
	2.4 RANDOM
3. MAKE FOCUS PARTITION AROUND PIVOT I.E ON LEFT OF PIVOT SMALL ELE THAN PIVOT AND ON RIGHT > THAN PIVOT

*/
#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high)
{
	//pivot(element to be placed at right position)
	int pivot = a[high];

	int i = (low - 1); //index of smaller ele

	for (int j = low; j <= high - 1; j++)
	{
		//if curr ele is smaller than pivot
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return (i + 1);
}

void quick(int a[], int low, int high)
{
	if (high > low)
	{
		//pi = partitioning index
		int pi = partition(a, low, high);

		quick(a, low, pi - 1); //before pivot
		quick(a, pi + 1, high); //after pivot
	}
}

int32_t main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quick(arr, 0, n - 1);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}