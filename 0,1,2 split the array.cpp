#include<bits/stdc++.h>
using namespace std;
//BOTH METHOD TC-O(N) SC-O(1)

//3 way partitioning or dutch national flag algo
void sort012(int a[], int n)
{
	int l = 0, h = n - 1, mid = 0;

	while ( mid <= h)
	{
		switch (a[mid])
		{
		case 0:
			swap(a[l++], a[mid++]);
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap( a[mid], a[h--]);
			break;
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}


//m-2 counting
void sortArr(int arr[], int n)
{
	int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

	// Count the number of 0s, 1s and 2s in the array
	for (i = 0; i < n; i++) {
		switch (arr[i]) {
		case 0:
			cnt0++;
			break;
		case 1:
			cnt1++;
			break;
		case 2:
			cnt2++;
			break;
		}
	}

	// Update the array
	i = 0;

	// Store all the 0s in the beginning
	while (cnt0 > 0) {
		arr[i++] = 0;
		cnt0--;
	}

	// Then all the 1s
	while (cnt1 > 0) {
		arr[i++] = 1;
		cnt1--;
	}

	// Finally all the 2s
	while (cnt2 > 0) {
		arr[i++] = 2;
		cnt2--;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int a[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(a) / sizeof(a[0]);

	sort012(a, n);

	cout << "array after segregation " << endl;

	sortArr(a, n);



	return 0;
}
