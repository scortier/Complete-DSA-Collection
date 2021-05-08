/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Similar to Minimum no of reqqd railway platform

given
starting time - A[i][0] ,ending time - A[i][1]
*/


/*
Approach 1 : Naive soln / brute force approach
Take evry interval one by one and find no of interval which overlap with it.Keep track of maxm no of intervals that overlap with an interval.finaly return the maximum value.

1.Run two nested loops the outer loop from start to end and the inner loop from i+1 to end.
2.For every iteration of the outer loop find the count of intervals that intersect with the current interval.
3.Update the answer with the maximum count of overlap in each iteration of the outer loop.
4.Print the answer.
*/
int minNumber(vector<vector<int>>&A)
{
	int n = A.size();
	vector<int>arr(n, 0);
	vector<int>dep(n, 0);
	for (int i = 0; i < n; i++) {
		arr[i] = A[i][0];
		dep[i] = A[i][1];
	}

	int room_needed = 1, result = 1;
	int i = 1, j = 0;

	for (int i = 0; i < n; i++)
	{
		room_needed = 1;
		for (int j = i + 1; j < n; j++)
		{
			//ek meeting agr dusri meeting k andar ghusi hui mili toh ek aur room chahiye.
			if ((arr[i] >= arr[j] and arr[i] <= dep[j]) or (arr[j] >= arr[i] and arr[j] <= dep[i]))
				room_needed++;
		}
		result = max(result, room_needed);
	}

	return result;
}


/*
Approach -2 Using Min heap (Min priority queue)
 Use min heap to store the meeting rooms end time. If new meeting start time is greater or equal than least element, update it.
If not, open a new meeting room. Report the min heap size at the end.
Time Complexity : O(NlogN).
*/

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	sort(A.begin(), A.end(),
	[](vector<int> a, vector<int> b) {
		return a[0] < b[0];
	});
	priority_queue<int, vector<int>, greater<int>> pq; //min heap -iske top p min ele aega
	pq.push(A[0][1]);
	for (int i = 1; i < n; i++) {
		if (A[i][0] >= pq.top()) {
			pq.pop();
		}
		pq.push(A[i][1]);
	}
	return pq.size();
}

/*
Approach -3
Two sorted array of start time and end time. Two pointers to iterator start array and end array. Iterate the time line, the current time active meeting is num of start minus num of end.
Since need sort, still O(nlogn) solution, but fast than solution 1.

1.Sort the arrival and departure times of trains.
2.Create two pointers i=0, and j=0 and a variable to store ans and current count plat
3.Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
4.If the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
5.Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat– and increment j
6.Update the ans, i.e ans = max(ans, plat).


*/





int minNumber(vector<vector<int>>&A)
{
	int n = A.size();
	vector<int>arr(n, 0);
	vector<int>dep(n, 0);
	for (int i = 0; i < n; i++) {
		arr[i] = A[i][0];
		dep[i] = A[i][1];
	}
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int rooms = 0;
	int i = 0 , j = 0;
	int ans = INT_MIN;
	while (i < n and j < n) {
		if (arr[i] < dep[j]) {
			rooms++;
			i++;
		}
		else {
			j++;
			rooms--;
		}
		ans = max(ans, rooms);
	}
	return ans;
}

/*
Approach -4
Map based approach
If its arrival then do increment by 1 otherwise decrease value by 1. If we are taking the input from STDIN then we can directly insert the times in the multimap and no need to store the times in the array.
*/
int Solution::solve(vector<vector > &A) {
	map<int, int>mp;
	int c = 0, max1 = -1;
	for (int i = 0; i < A.size(); i++) {
		mp[A[i][0]]++;
		mp[A[i][1]]–;
	}
	for (auto it : mp) {
		c = c + it.second;
		max1 = max(c, max1);
	}
	return max1;
}