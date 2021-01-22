/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

void long_subs_bu(int a[], int n)
{
	int t[n];
	for (int i = 0; i < n; i++)
		t[i] = 1;

	int res = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((a[i] == a[j] + 1) or (a[i] == a[j] - 1) )
				t[i] = max(t[i], t[j] + 1);
		}
		res = max(res, t[i]);
	}

	return res;
}

int32_t main()
{
	int arr[] = {1, 2, 3, 4, 5, 3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << long_subs_bu(arr, n);
	return 0;
}