/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;


//BOTTOM UP (USING ONLY t)
int m = 3, n = 4;
int static t[5][4];
int coin_change(int a[], int m, int n)
{
	int i, j, x, y;

	// We need n+1 rows as the t
	// is constructed in bottom up
	// manner using the base case 0
	// value case (n = 0)
	int t[n + 1][m];

	// Fill the enteries for 0
	// value case (n = 0)
	for (i = 0; i < m; i++)
		t[0][i] = 1;

	// Fill rest of the t entries
	// in bottom up manner
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i - a[j] >= 0) ? t[i - a[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? t[i][j - 1] : 0;

			// total count
			t[i][j] = x + y;
		}
	}
	return t[n][m - 1];
}
int32_t main()
{
	// memset(t, -1, sizeof(t));

	int a[m] = {1, 2, 3};
	// int m = a.size();
	cout << coin_change(a, m, n);
	return 0;

}