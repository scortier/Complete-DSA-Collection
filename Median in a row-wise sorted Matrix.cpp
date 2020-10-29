//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

//M-1 O(r*clog(r*c))
//BRUTE FORCE APPROACH : Searching the element in the set.

/*m-2 binary search
1. find min and max in matrix
2. then apply bsearch to find min and max
3.For a number to be median, there should be (r*c)/2 numbers smaller than that number.
So for every number, we get the count of numbers less than that by using upper_bound() in each row
of the matrix, if it is less than the required count, the median must be greater than the selected
number, else the median must be less than or equal to the selected number. */
int m2(int m[][100], int r, int c)
{
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < r; i++)
	{
		// Finding the minimum element
		if (m[i][0] < min)
			min = m[i][0];

		// Finding the maximum element
		if (m[i][c - 1] > max)
			max = m[i][c - 1];
	}
	int desired = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = min + (max - min) / 2;
		int place = 0;

		// Find count of elements smaller than mid
		for (int i = 0; i < r; ++i)
			place += upper_bound(m[i], m[i] + c, mid) - m[i];
		if (place < desired)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}

int main() {
	int r = 3, c = 3;
	int m[][100] = { {1, 3, 5}, {2, 6, 9}, {3, 6, 9} };
	cout << "Median is " << m2(m, r, c) << endl;
	return 0;
}