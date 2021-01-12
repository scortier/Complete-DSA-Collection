/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1. O(n^2) BRUTE FORCE
	find all substring and check string is valid or not if it is greater than length then update the max length

2.O(n)
Using Stack
Store the index of starting index.

*/
#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
	int n = str.size();
	stack<int>s;
	s.push(-1);	//first ele to provide base to next  valid string

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			s.push(i);
		else
		{
			// bracket's index
			if (!s.empty())
			{
				s.pop();
			}

			// Check if this length formed with base of
			// current valid substring is more than max
			// so far
			if (!s.empty())
				result = max(result, i - s.top());

			// If stack is empty. push current index as
			// base for next valid substring (if any)
			else
				s.push(i);
		}
	}
	return result;
}

int32_t main()
{
	string str = "((()()";

	// Function call
	cout << findMaxLen(str) << endl;

	str = "()(()))))";

	// Function call
	cout << findMaxLen(str) << endl;

	return 0;
}