/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2]
sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
sum[i] = max(sum[i-1], sum[i-2] + arr[i],
             sum[i-3] + arr[i] + arr[i-1])
*/
//both have tc:O(n) space:O(n)
#include<bits/stdc++.h>
using namespace std;

int arr[] = {100, 1000, 100, 1000, 1};
int sum[10000];

//iterative approach
void solve_rec(int a[], int n)
{
	int sum[n];

	//base case till 2
	if (n >= 1) sum[0] = a[0];

	if (n >= 2)
		sum[1] = a[0] + a[1];

	if (n > 2)
		sum[2] = max(sum[1], max(a[1] + a[2], a[0] + a[2]));


	for (int i = 3; i < n; i++)
		sum[i] = max(max(sum[i - 1], sum[i - 2] + a[i]),
		             a[i] + a[i - 1] + sum[i - 3]);

	return sum[n - 1];
}

//recursive approach
int maxSumWO3Consec(int n)
{
	memset(sum, -1, sizeof(sum));//generally initialized in main function
	if (sum[n] != -1)
		return sum[n];

	//Base cases (process first three elements)

	if (n == 0)
		return sum[n] = 0;

	if (n == 1)
		return sum[n] = arr[0];

	if (n == 2)
		return sum[n] = arr[1] + arr[0];

	// Process rest of the elements
	// We have three cases
	return sum[n] = max(max(maxSumWO3Consec(n - 1),
	                        maxSumWO3Consec(n - 2) + arr[n - 1]),
	                    arr[n - 2] + arr[n - 1] + maxSumWO3Consec(n - 3));


}


int32_t main()
{

	return 0;
}