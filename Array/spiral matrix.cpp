#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 6
//TC:O(M*N) SC:O(1).
void spiral(int m, int n, int a[R][C])
{
	int top = 0, down = m - 1, left = 0, right = n - 1;
	int dir = 0;
	/* top - starting row index
	   down - ending row index
	    left - starting column index
	    right - ending column index
	    i - iterator
	*/
	while (top <= down and left <= right)
	{
		/* Print the first row from
		      the remaining rows */
		if (dir == 0) {
			for (int i = left; i <= right; i++)
				cout << a[top][i] << " ";
			top++;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= down; i++)
				cout << a[i][right] << " ";
			right--;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
				cout << a[down][i] << " ";
			down--;
		}
		else if (dir == 3)
		{
			for (int i = down; i >= top; i--)
				cout << a[left][i] << " ";
			left++;
		}
		dir = (dir + 1) % 4;
	}
}


int main()
{
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
		{ 7, 8, 9, 10, 11, 12 },
		{ 13, 14, 15, 16, 17, 18 }
	};

	// Function Call
	spiral(R, C, a);
	return 0;
}