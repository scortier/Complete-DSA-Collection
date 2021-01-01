//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int a[], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > k) a[i] = a[i] - k;
		else a[i] += k;
	}
	sort(a, a + n);
	int diff = a[n - 1] - a[0];
	return diff;

}


int main()
{
	int arr[] = {4, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 10;
	cout << "\nMaximum difference is "
	     << getMinDiff(arr, n, k);
	return 0;
}