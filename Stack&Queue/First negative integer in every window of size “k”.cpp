/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

//naive approach
void firstneg(int a[], int n, int k)
{
	bool flag;
	for (int i = 0; i < (n - k + 1); i++)
	{
		flag = false;

		for (int j = 0; j < k; j++)
		{	// if a negative integer is found, then
			// it is the first negative integer for
			// current window. Print it, set the flag
			// and break
			if (a[i + j] < 0)
			{
				cout << a[i + j] << " ";
				flag = true;
				break;
			}
		}
		// if the current window does not contain a negative integer
		if (!flag)
			cout << "0" << " ";
	}
}

int32_t main()
{
	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	firstneg(arr, n, k);
	return 0;
	return 0;
}