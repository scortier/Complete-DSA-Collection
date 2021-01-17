/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
The idea is to create a lookup table and follow the recursive top-down approach.
Before computing any value, we check if it is already in the lookup table.
If yes, we return the value. Else we compute the value and store it in the lookup table.
Following is the Top-down approach of dynamic programming to finding the value of the Binomial
Coefficient.
*/
#include<bits/stdc++.h>
using namespace std;

int t[6][3];
int binomial_memoize(int n, int k)
{
	if (k == 0 or k == n)
		return 1;

	if (t[n][k] != -1)
		return t[n][k];
	else
		t[n][k] = binomial_memoize(n - 1, k - 1) + binomial_memoize(n - 1, k);
	return t[n][k];
}

int32_t main()
{
	int n = 5, k = 2;

	memset(t, -1, sizeof(t));
	cout << binomial_memoize(n, k);
	return 0;
}