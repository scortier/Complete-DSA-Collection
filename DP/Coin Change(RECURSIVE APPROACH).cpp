/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
UNBOUNDED KNAPSACK (SUPPLY IS UNLIMITED)


*/
#include<bits/stdc++.h>
using namespace std;

//n is the req sum
//m is no of coin
//RECURSIVE APPROACH
int coin_change(int a[], int m, int n)
{
	//no coin include only one soln
	if (n == 0 ) return 1;
	//
	if (n < 0 ) return 0;

	//if there are no coins and n is greater than 0 , then no soln exist.
	if (m <= 0 and n > 0) return 0;

// count is sum of solutions (i)
	// including S[m-1] (ii) excluding S[m-1]
	return coin_change(a, m - 1, n) + coin_change(a, m, n - a[m - 1]);
}




int32_t main()
{
	int m = 3;
	int a[m] = {1, 2, 3};
	// int m = a.size();
	cout << coin_change(a, m, 4);
	return 0;
}