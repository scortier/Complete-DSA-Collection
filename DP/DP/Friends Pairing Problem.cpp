/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


//ITERATIVE APPROACH
// Returns count of ways n people
// can remain single or paired up.
int fp_iterative(int n)
{
	long long a = 1, b = 2, c = 0;
	if (n <= 2) {
		return n;
	}
	for (int i = 3; i <= n; i++)
	{
		// using modular arithmentic properties.
		c = ( b % MOD + ( ( (i - 1) % MOD  *  a % MOD ) % MOD ) % MOD ) % MOD ;
		a = b;
		b = c;
	}
	return c;
}

//RECURSION APPROACH
int fp_recursive(int n)
{
	if (n <= 0) return 0;
	if (n == 1 or n <= 2) return n;
	else
		return fp_recursive(n - 1) + (n - 1) * fp_recursive(n - 2);
}


//TOP-DOWN or memoization
//storing the repetitive values in a 1D matrix for further use and reduce
int fp_topDown(int n)
{
	int t[n + 1];

	memset(t, -1, sizeof(t));
	if (t[n] != -1) return t[n];
	// if (n > 2) return t[n] = t[n - 1] + (n - 1) * t[n - 2];
	if (n > 2) return t[n] = fp_topDown(n - 1) + (n - 1) * fp_topDown(n - 2);
	else return t[n] = n;
}


//BOTTOM-UP
//jo bhi hoga sab matrix m hoga - initialization se end result tak no recursion of function.
int fp_bottomUp(int n)
{
	int t[n + 1];

	for (int i = 0; i <= n; i++)
	{
		if (i <= 2)
			t[i] = i;
		else
			t[i] = t[i - 1] + (i - 1) * t[i - 2];
	}
	return t[n];//last block of matrix
}



int32_t main()
{
	int n = 4;
	cout << fp_recursive(n) << endl;
	cout << fp_topDown(n) << endl;
	cout << fp_topDown(n);
	return 0;
}