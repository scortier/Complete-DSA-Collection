/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

int minm(int a[], int n, int k)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		// Buy current candy
		res += arr[i];

		// And take k candies for free
		// from the last
		n = n - k;
	}
	return res;
}

int mx(int a[], int n, int k)
{
	int res = 0, index = 0;

	for (int i = n - 1; i >= index; i--)
	{
		// Buy candy with maximum amount
		res += arr[i];

		// And get k candies for free from
		// the starting
		index += k;
	}
	return res;
}

int32_t main()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cout << minm(a, n, k) << " " << mx(a, n, k) << endl;
	return 0;
}

/*
Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7
*/