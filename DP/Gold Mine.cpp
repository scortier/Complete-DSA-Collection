/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 100


int Gold_topdown(int gold[][], int m, int n)
{
	//base condition
	for (int col = n - 1; col >= 0; col--)
	{
		for (int row = 0; row <= m; row++)
		{
			if (col == n - 1 or row == 0 or row == m - 1) return
			}
	}
}


int Gold_bottom_up(int gold[][], int m, int n)
{
	int t[m + 1][n + 1];
	memset(t, 0, sizeof(t));

	//base condition
	int right, right_up, right_down;
	for (int col = n - 1; col >= 0; col--)
	{
		for (int row = 0; row <= m; row++)
		{
			// Gold collected on going to the cell on the right(->)
			int right = (col == n - 1) ? 0 : t[row][col + 1];

			// Gold collected on going to the cell to right up (/)
			int right_up = (row == 0 || col == n - 1) ? 0 :
			               t[row - 1][col + 1];

			// Gold collected on going to the cell to right down (\)
			int right_down = (row == m - 1 || col == n - 1) ? 0 :
			                 t[row + 1][col + 1];

			// Max gold collected from taking either of the
			// above 3 paths
			t[row][col] = gold[row][col] +
			              max(right, max(right_up, right_down));
		}
	}
// The max amount of gold collected will be the max
	// value in first column of all rows
	int res = t[0][0];
	for (int i = 1; i < m; i++)
		res = max(res, t[i][0]);
	return res;
}

int32_t main()
{

	int gold[MAX][MAX] = { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << Gold_topdown(gold, m, n);
	return 0;
}