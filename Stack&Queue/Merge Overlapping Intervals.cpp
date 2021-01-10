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




int32_t main()
{

	return 0;
}