/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1.O(N^2)
Traverse the input price array. For every element being visited,
traverse elements on left of it and increment the span value of it while elements
on the left side are smaller.

2.STACK METHOD [FIND CONSECUTIVE SMALLER OR EQUAL TO]
arr={100,80,60,70,60,75,85}
o/p:{1,1,1,2,1,4,6}
For 75 ans is 4 as (75,60,70,60) are smaller left
For 70 ans is 2 as (70,60 (of index 2)) are smaller left
STEPS:
1.SIMILAR TO NGL(NEXT GREATER LEFT)
SOLUTION = (index of NGL - i); samjh na ae toh pen paper uthhao aur dekhlo

To store the index of NGL ,make pair in stack itself.
Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look,
 we can observe that every element of the array is added and removed from the stack at
 most once. So there are total 2n operations at most. Assuming that a stack operation
 takes O(1) time, we can say that the time complexity is O(n).

*/
#include<bits/stdc++.h>
using namespace std;

void brute(int price[], int n, int span[])
{	// Span value of first day is always 1
	s[0] = 1;

	for (int i = 0; i < n; i++)
	{
		s[i] = 1; // Initialize span value

// Traverse left while the next element
		// on left is smaller than price[i]
		for (int j = i - 1; j >= 0 and (price[i] >= price[j]));
		j--;
		s[i]++;
	}
}


void stack_method(int a[])
{
	vectot<int>v;
	stack<pair<int, int>>s; //(ngl,index)
	for (int i = 0; i < a_size; i++)
	{
		if (s.empty())	//base condn
			v.push_back(-1);
		else if (s.size() > 0 and s.top().first > a[i])
		{
			v.push_back(s.top().second);//index
		}
		else if (s.size() > 0 and s.top().first <= a[i])
		{
			while (s.size() > 0 and s.top().first <= a[i])
				s.pop();

			if (s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top().second);
		}
		s.push({a[i], i});
	}
	for (int i = 0; i < v.size(); i++)
		v[i] = i - v[i];;
	return v;
}

//M-3 without stack
// An efficient method to calculate stock span values
// implementing the same idea without using stack
void calculateSpan(int A[], int n, int ans[])
{
	// Span value of first element is always 1
	ans[0] = 1;

	// Calculate span values for rest of the elements
	for (int i = 1; i < n; i++) {
		int counter = 1;
		while ((i - counter) >= 0 && A[i] >= A[i - counter]) {
			counter += ans[i - counter];
		}
		ans[i] = counter;
	}
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int32_t main()
{
	int a[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];

	// Fill the span values in array S[]
	calculateSpan(price, n, S);

	// print the calculated span values
	printArray(S, n);

	return 0;
}