/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

int max_sum_subs(int a[], int n)
{
	int i, j, mx = 0;
	int t[n];

	for (int i = 0; i < n; i++)
		t[i] = a[i];

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] > a[j] and t[i] < t[j] + a[i])//bas a[i]jodna hai lis m
				t[i] = t[j] + a[i];
		}
		mx = max(mx, t[i]);
	}
	return mx;

}

int32_t main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum of maximum sum increasing "
	     "subsequence is " << maxSumIS( arr, n ) << endl;
	return 0;
}