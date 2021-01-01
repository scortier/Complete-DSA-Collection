#include<bits/stdc++.h>
using namespace std;


int kadane(int a[], int n)
{
	int max_sofar = INT_MIN; int max_end = 0;
	for (int i = 0; i < n; i++)
	{
		max_end += a[i];
		if (max_end < 0)
			max_end = 0;

		/* Do not compare for all elements. Compare only
		          when  max_ending_here > 0 */
		else if (max_end > max_sofar)
			max_sofar = max_end;

	}
	return max_sofar;
}


//handle corner case too with all negative no
int kadanesum(int a[], int n)
{
	int max_sofar = a[0];
	int currmax = a[0];

	for (int i = 1; i < n; i++)
	{
		currmax = max(a[i], currmax + a[i]);
		max_sofar = max(max_sofar, currmax);
	}
	return max_sofar;
}
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = kadanesum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}