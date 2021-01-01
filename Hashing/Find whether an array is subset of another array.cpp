//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

bool isSubset(int a[], int b[], int m, int n)
{
	// Using STL set for hashing
	set<int>s;

	for (int i = 0; i < m; i++)
	{
		s.insert(a[i]);
	}

// loop to check if all elements of arr2 also
	// lies in arr1
	for (int i = 0; i < n; i++)
	{
		if (s.find(b[i]) == s.end())
			return false;
	}
	return true;
}
//To pass edge case of having duplicate elements in array.
bool isSubset(int arr1[], int m,
              int arr2[], int n)
{
	// Create a Frequency Table using STL
	map<int, int> frequency;

	// Increase the frequency of each element
	// in the frequency table.
	for (int i = 0; i < m; i++)
	{
		frequency[arr1[i]]++;
	}
	// Decrease the frequency if the
	// element was found in the frequency
	// table with the frequency more than 0.
	// else return 0 and if loop is
	// completed return 1.
	for (int i = 0; i < n; i++)
	{
		if (frequency[arr2[i]] > 0)
			frequency[arr2[i]]--;
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		cout << "arr2[] is subset of arr1[] "
		     << "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
		     << "\n";
	return 0;
}