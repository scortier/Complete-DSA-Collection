/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

//recursion expo time
//L[i]=1+max(L[j]) where 0<j<i and a[j]<a[i]
// or
// L[i]=1 ,if no such j exist.
int lis_recursion_util(int a[], int n, int *max_ref)
{
	if (n == 1) return 1;

	int res, max_end = 1;
	for (int i = 1; i < n; i++)
	{
		res = lis_recursion_util(a, n, max_ref);
		if (a[i - 1] < a[n - 1] and res + 1 > max_end)
			max_end = res + 1;
	}
	// Compare max_ending_here with the overall
	// max. And update the overall max if needed
	if (*max_ref < max_end)
		*max_ref = max_end;

	// Return length of LIS ending with arr[n-1]
	return max_end;
}

int lis_recursion(int a[], int n)
{
	int mx = 1;
	lis_recursion_util(a, n, &mx);
	return mx;
}


//BOTTOM UP
//USING SINGLE 1D MATRIX
int LIS_BottomUp(int a[], int n)
{
	int LIS_BottomUp[n];
	LIS_BottomUp[0] = 1;
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		LIS_BottomUp[i] = 1; //initialization
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] and LIS_BottomUp[i] < LIS_BottomUp[j] + 1)
				LIS_BottomUp[i] = LIS_BottomUp[j] + 1;
		}
		mx = max(mx, LIS_BottomUp[i]);
	}

	free(LIS_BottomUp);
	return mx;


}
int32_t main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << LIS_BottomUp( arr, n );

	return 0;
}