/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;


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