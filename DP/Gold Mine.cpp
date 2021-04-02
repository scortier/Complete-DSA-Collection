/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
int t matrix each grid represent ki agr us grid se start karta toh kitna maximum gold ikkatha kar pataa
vo value store hogi.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//sirf table no recursion
int Gold_topdown(int gold[MAX][MAX], int m, int n)
{
	//base condition
	for (int col = n - 1; col >= 0; col--)
	{
		for (int row = 0; row <= m; row++)
		{
			if (col == n - 1 or row == 0 or row == m - 1) return 0;
		}
	}
}

int Gold_ans(int gold[][], int m, int n)
{
	int dp[m][n];
	memset(t, 0, sizeof(t));

	for (int col = n - 1; col >= 0; col--)
	{
		for (int row = m - 1; row >= 0; row--)
		{
			/* 3 cases:
			last col no changes simply copy
			first row only have 2 option : right and right up
			last row only have 2 option : right and right down*/
			if (col == n - 1)
			{
				t[row][col] = gold[row][col];
			}
			else if (row == 0)
			{
				t[row][col] = gold[row] + max(gold[row + 1][col + 1], gold[row][col + 1]);
			}
			else if (row == m - 1)
			{
				t[row][col] = gold[row] + max(gold[row - 1][col + 1], gold[row][col + 1]);
			}
			else
			{
				t[row][col] = gold[row] + max(max(gold[row + 1][col + 1], gold[row - 1][col + 1]), gold[row][col + 1]);

			}
		}
	}

	int mx = t[0][0];
	for (int row = 0; row < n; row++)
	{
		if (t[row][0] > mx)
			mx = t[mx][0];
	}
	return mx;
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
	/*
	FINAL MATRIX WHICH GETS FORMED:
	int t[m+1][n+1] =
		{	{13, 12, 6, 5},
			{14, 11, 9, 1},
			{15, 9, 5, 3},
			{11, 11, 4, 2}
		};
	The max amount of gold collected will be the max value in first column of all rows.
	As matrix last col se first col taraf form hua tha
	example : t[1][3]=9 (4 + max(5,1,3));//t[1][3] se agr start karta toh kitna max gold
	ikkatha kar pata i.e (4 + max(5,1,3)).
	*/
	int res = t[0][0];
	for (int i = 1; i < m; i++)
		res = max(res, t[i][0]);
	return res;
}

int32_t main()
{

	int gold[MAX][MAX] =
	{	{1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << Gold_topdown(gold, m, n);
	return 0;
}