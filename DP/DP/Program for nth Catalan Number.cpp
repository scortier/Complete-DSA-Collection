/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

int catalan(int n)
{
	if (n <= 1) return 1;

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += catalan(i) + catalan(n - i - 1);
	}
	return result;
}

unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n + 1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i = 2; i <= n; i++)
	{
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j]
			              * catalan[i - j - 1];
	}

	// Return last entry
	return catalan[n];
}

int32_t main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}