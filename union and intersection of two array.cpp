//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

void ui(int a[], int b[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m and j < n)
	{
		if (a[i] < b[j])
			cout << a[i++] << " ";
		else if (b[j] < a[i])
			cout << b[j++] << " ";
		else {
			cout << b[j++] << " ";
			i++;
		}
	}
	while (i < m)
		cout << a[i++];
	while (j < n)
		cout << b[j++];
}



int main()
{
	int arr1[] = { 1, 2, 4, 5, 6 };
	int arr2[] = { 2, 3, 5, 7 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	ui(arr1, arr2, m, n);

	return 0;
}

int printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			cout << arr2[j] << " ";
			i++;
			j++;
		}
	}
}