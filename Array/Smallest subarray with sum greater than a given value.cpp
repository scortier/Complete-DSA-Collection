/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&a; , int k)
{
	int n = a.size();
	int min_len = n + 1;

	//pick every ele as startin pt
	for (int start = 0; start < n; start++)
	{
		int curr_sum = a[start];

		//if first ele is itself greater
		if (curr_sum > k) return 1;


		//try diff ending pts for current start
		for (int end = start + 1; end < n; end++)
		{
			//add lasr ele to current sum
			curr_sum += a[end];

			// If sum becomes more than x and length of
			// this subarray is smaller than current smallest
			// length, update the smallest length (or result)
			if (curr_sum > x && (end - start + 1) < min_len)
				min_len = (end - start + 1);
		}
	}
	return min_len;
}


int32_t main()
{

	return 0;
}
/*
Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.

*/