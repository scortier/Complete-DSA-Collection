/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

struct Interval
{
	int start, end;
};

bool compareInt(Interval i1, Interval i2 )
return (i1.start < i2.start);

//O(nlogn)
void mergeInt(Interval arr[], int n)
{
	if (n <= 0)
		return;

	stack<Interval>s;

	sort(arr, arr + n, compareInt);

	s.push(arr[0]);

	// Start from the next interval and merge if necessary
	for (int i = 1 ; i < n; i++)
	{
		// get interval from stack top
		Interval top = s.top();

		// if current interval is not overlapping with stack top,
		// push it to the stack
		if (top.end < arr[i].start)
			s.push(arr[i]);

		// Otherwise update the ending time of top if ending of current
		// interval is more
		else if (top.end < arr[i].end)
		{
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}

	cout << "\n The Merged Intervals are: ";
	while (!s.empty())
	{
		Interval t = s.top();
		cout << "[" << t.start << "," << t.end << "] ";
		s.pop();
	}
	return;
}

//O(logn)


void mergeIntervals(Interval arr[], int n)
{
	// Sort Intervals in increasing order of
	// start time
	sort(arr, arr + n, mycomp);

	int index = 0; // Stores index of last element
	// in output array (modified arr[])

	// Traverse all input Intervals
	for (int i = 1; i < n; i++)
	{
		// If this is not first Interval and overlaps
		// with the previous one
		if (arr[index].e >=  arr[i].s)
		{
			// Merge previous and current Intervals
			arr[index].e = max(arr[index].e, arr[i].e);
			arr[index].s = min(arr[index].s, arr[i].s);
		}
		else {
			index++;
			arr[index] = arr[i];
		}
	}

	// Now arr[0..index-1] stores the merged Intervals
	cout << "\n The Merged Intervals are: ";
	for (int i = 0; i <= index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}



int main()
{
	Interval arr[] =  { {6, 8}, {1, 9}, {2, 4}, {4, 7} };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}