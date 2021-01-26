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

//deque method
void dq_opr(int a[], int n, int k)
{
	deque<int>dq;

	for (int i = 0; i < k; i++)
	{
		if (a[i] < 0)
			dq.push_back(i);
	}

	// Process rest of the elements, i.e., from arr[k] to arr[n-1]
	for ( ; i < n; i++)
	{
		// if Di is not empty then the element at the
		// front of the queue is the first negative integer
		// of the previous window
		if (!dq.empty())
			cout << "0" << " ";
		// else the window does not have a
		// negative integer
		else
			cout << "0" << " ";
// Remove the elements which are out of this window
		while ((!dq.empty() and dq.front() < (i - k + 1)))
			dq. pop_front();

		// Add current element at the rear of Di
		// if it is a negative integer
		if (a[i] < 0) dq.push_back(i);
	}
	if (!dq.empty())
		cout << arr[dq.front()] << " ";
	else
		cout << "0" << " ";
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