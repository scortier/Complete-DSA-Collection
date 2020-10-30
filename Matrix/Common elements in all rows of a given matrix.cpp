//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;
#define m 4
#define n 5

void printcommon(int m[m][n])
{
	unordered_map<int, int>mp;

	for (int i = 0; i < n; i++)
		mp[m[0][i]] = 1;


	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mp[m[i][j]] == i)
			{
				mp[m[i][j]] = i + 1;

				if (i == m - 1)
					cout << m[i][j] << " ";
			}
		}
	}
}
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}