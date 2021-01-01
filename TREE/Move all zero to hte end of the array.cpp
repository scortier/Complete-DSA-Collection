#include<bits/stdc++.h>
using namespace std;

//TC- O(N) SC-O(1)
void zero_shift(int a[], int size)
{
	int count = 0;
	for (int start = 0; start < size; start++)
	{
		if (a[start] != 0)
			a[count++] = a[start];
	}
	while (count < size)
		a[count++] = 0;
}

//TC-O(N) AUXILIARY SPACE-O(1)
void zeroe(int a[], int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] != 0)
			swap(a[cnt++], a[i]);
	}
}

//2 POINTER O(N) O(1)
void zero2ptr(int a[], int n)
{
	int j = 0, temp, i;
	for (i = 0; i < n; i++)
	{
		if (a[i] != 0 and a[j] == 0)
		{
			swap(a[i], a[j]);
		}
		if (a[j] != 0)
			j++;
	}
}

int main() {
	int a[] = {1, 2, 0, 4, 3, 0, 5, 0, -1};
	int n = sizeof(a) / sizeof(a[0]);
	zero_shift(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

}