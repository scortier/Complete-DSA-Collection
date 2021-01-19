/*
input:
{{1,3}, {2,4}, {5,7}, {6,8}}
o/p:
{{1,4},{5,8}}

METHODS
1.O(N^2)	-
A simple approach is to start from the first interval and compare it with all other intervals
for overlapping, if it overlaps with any other interval, then remove the other interval from
the list and merge the other into the first interval. Repeat the same steps for remaining
intervals after first.


2.O(N)		- using stack
	1. Sort the intervals based on increasing order of
	    starting time.
	2. Push the first interval on to a stack.
	3. For each interval do the following
	   a. If the current interval does not overlap with the stack
	       top, push it.
	   b. If the current interval overlaps with stack top and ending
	       time of current interval is more than that of stack top,
	       update stack top with the ending  time of current interval.
	4. At the end stack contains the merged intervals

3.O(NLOGN)	-

	1) Sort all intervals in increasing order of start time.
	2) Traverse sorted intervals starting from first interval,
   		do following for every interval.
      a) If current interval is not first interval and it
         overlaps with previous interval, then merge it with
         previous interval. Keep doing it while the interval
         overlaps with the previous one.
      b) Else add current interval to output list of intervals.

*/

#include<bits/stdc++.h>
using namespace std;


//Using Stack
struct Interval {
	int start, end;
}

bool compInt(Interval i1, Interval i2) {
	return (i1.start < i2.start);
}

void mergeInt(Interval arr[], int n) {
	if (n <= 0) return;

	stack<Interval>s;

	sort(arr, arr + n, compInt);

	s.push(arr[0]);

	for (int i = 1; i < n; i++)
	{
		Interval top = s.top();

// if current interval is not overlapping with stack top,
		// push it to the stack
//example: {{1,8}{5,12}}
//here s.top is{1,8}
// if(8<5) i.e false
		if (top.end < arr[i].start)
			s.push(arr[i]);

// Otherwise update the ending time of top if ending of current
		// interval is more
//if(8<12) i.e true so update the end and pop the previous end and push the arr which is now top

		if (top.end < arr[i].end)
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

//A O(n Log n) and O(1) Extra Space Solution
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



int32_t main()
{
	Interval arr[] = { {6, 8}, {1, 9}, {2, 4}, {4, 7} };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
	return 0;
}