/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
STABLE VERSION OF SELECTION SORT
JITNA BHI ARRAY ITERATE KAR RHE HO UUSE SORT KARTE CHALO AND NEW ELE AE TOH UUSE BAAKI AAGE WALO SE COMPARE KARKE PLACE KARDO
*/
#include<bits/stdc++.h>
using namespace std;
//example a[]:{6}
void insertion(int a[], int n)
{
	int key;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;

		while (j >= 0 and a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void insertion_recurse(int a[],int n)
{
	//base condition
	if (n <= 1) return;

	insertion_recurse(a, n - 1);

	int last = a[n - 1];
	int j = n - 2;

	while (j >= 0 and a[j] > last)
	{
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = last;

}

int32_t main()
{	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	insertion(arr, n);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}