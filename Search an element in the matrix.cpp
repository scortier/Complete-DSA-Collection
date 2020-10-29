//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

//for square
int search(int k, int a[4][4], int n)
{
	if (n == 0) return -1;
	if (k < a[0][0] || k > a[n - 1][n - 1])
		return -1;

	int i = 0, j = n - 1;
	while (i<n and j >= 0)
	{
		if (a[i][j] == k)
		{	cout << i << j << " ";
			return 1;
		}

		if (a[i][j] > k) j--;
		else i++;
	}

	cout << "Element not found";
	return 0;
}

int main()
{
	int m[4][4] = {
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 27, 29, 37, 48 },
		{ 32, 33, 39, 50 },
	};
	search(29, m, 4);
	return 0;
}