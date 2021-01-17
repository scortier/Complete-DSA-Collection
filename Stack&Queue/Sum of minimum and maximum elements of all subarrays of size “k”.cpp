/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1. brute force
2. Using dequeue
The idea is to use Dequeue data structure and sliding window concept. We create two empty
double ended queues of size k (‘S’ , ‘G’) that only store indexes of elements of current
window that are not useless. An element is useless if it can not be maximum or minimum of
 next subarrays.
*/
#include<bits/stdc++.h>
using namespace std;

//brute
// void sub(int a[], int n, int k)
// {
// 	int j = 0, sum = 0, x = 0, minm = 10000000, maxm = 0;
// 	while (k + j < n) {
// 		for (int i = j; i < k + j; i++)
// 		{
// 			maxm = max(maxm, a[i]);
// 			minm = min(minm, a[i]);

// 		}

// 		sum = minm + maxm;
// 		x += sum;

// 	}
// 	cout << x;

// }


//M-2
int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0;  // Initialize result

	// The queue will store indexes of useful elements
	// in every window
	// In deque 'G' we maintain decreasing order of
	// values from front to rear
	// In deque 'S' we  maintain increasing order of
	// values from front to rear
	deque< int > S(k), G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous greater elements
		// that are useless.
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Process rest of the Array elements
	for (  ; i < n; i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += arr[S.front()] + arr[G.front()];

		// Remove all elements which are out of this
		// window
		while ( !S.empty() && S.front() <= i - k)
			S.pop_front();
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();

		// remove all previous greater element that are
		// useless
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// remove all previous smaller that are elements
		// are useless
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += arr[S.front()] + arr[G.front()];

	return sum;
}
int32_t main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	sub(arr, n, k) ;
	return 0;
}