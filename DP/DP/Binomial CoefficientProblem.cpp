/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
re-computations of the same subproblems can be avoided by constructing a temporary 2D-array C[][]
in a bottom-up manner.
*/
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int bincoeff(int n, int k)
{
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	// Recur
	return bincoeff(n - 1, k - 1)
	       + bincoeff(n - 1, k);
}


//bottom up
int binomial(int n, int k)
{	int t[n + 1][k + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, k); j++)
		{	if (j == 0 or j == i)
				t[i][j] = 1;
			else
				t[i][j] = t[i - 1][j - 1] + t[i - 1][j];

		}
	}
	return t[n][k];
}
int32_t main()
{
	int n = 5, k = 2;
	cout << binomial(n, k);
	return 0;
}