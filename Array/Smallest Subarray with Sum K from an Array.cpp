/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

int subArraylen(int a[], int n, int k)
{
	unordered_map<int, int>mp;

	mp[a[0]] = 0;

// Stores the frequency of
	// prefix sums in the array
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i] + a[i - 1];
		mp[a[i]] = i;
	}

	int len = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		//if sum of array till ith index is less than k
		if (a[i] < k)
			continue;
		else
		{
			//find the exceeded value
			int x = a[i] - k;

			//if exceede value is 0
			if (x == 0)
				len = min(len, i);

			if (mp.find(x) == mp.end())
				continue;
			else
				len = min(len, i - mp[x]);

		}
	}
	return len;
}

int32_t main()
{

	return 0;
}
/*
Examples:

Input: arr[] = {2, 4, 6, 10, 2, 1}, K = 12
Output: 2
Explanation:
All possible subarrays with sum 12 are {2, 4, 6} and {10, 2}.

Input: arr[] = { 1, 2, 4, 3, 2, 4, 1 }, K = 7
Output: 2

*/