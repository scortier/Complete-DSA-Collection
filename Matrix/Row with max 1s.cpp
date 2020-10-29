//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
// SORTED MATRIX GIVEN HAI
// m - 1 O(m*n)
// // 1.do row wise traversal,count the no 1's in each row and compare the count with max

// m - 2 Use Binary Search
// We find the index of first instance of 1 in each row. The count of 1s will be equal to
// total number of columns minus the index of first 1.


int search(bool a[], int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if ((mid == 0 || a[mid - 1] == 0) and a[mid] == 1)
			return mid;

// If the element is 0, recur for right side
		else if (a[mid] == 0)
			return search(a, (mid + 1), high);

		else
			return search(a, low, (mid - 1));
	}
	return -1;
}

int rowWithMax1s(bool mat[R][C])
{
	// Initialize max values
	int max_row_index = 0, max = -1;

	// Traverse for each row and count number of 1s
	// by finding the index of first 1
	int i, index;
	for (i = 0; i < R; i++)
	{
		index = search(mat[i], 0, C - 1);
		if (index != -1 && C - index > max)
		{
			max = C - index;
			max_row_index = i;
		}
	}

	return max_row_index;
}


int main()
{
	bool mat[R][C] = { {0, 0, 0, 1},
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};

	cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

	return 0;
}