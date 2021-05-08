/*
IN this soln TLE will come test case 94/200
reason becoz unecessary

*/
vector<int> Solution::solve(vector<int> &a, vector<int> &b) {

	priority_queue<pair<int, pair<int, int>>>pq;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			pq.push({a[i] + b[j], {a[i], b[j]}});
	}
	vector<int>arr(n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = pq.top().first;
		pq.pop();
	}
	return arr;

}

/*
Sort both the arrays in ascending order.
Let us take priority queue (heap).
First max element is going to be the sum of the last two elements of array A and B i.e. (A[n-1] + B[n-1]).
Insert that in heap with indices of both array i.e (n-1, n-1).
Start popping from heap (n-iterations).
And insert the sum (A[L-1]+A[R]) and (A[L]+B[R-1]).
Take care that repeating indices should not be there in the heap (use map for that).
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	priority_queue<pair<int, pair<int, int> > > min_pq;
	set<pair<int, int> > S;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	min_pq.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));
	S.insert(make_pair(n - 1, n - 1));

	vector<int> ans;
	int k = n;
	while (k--) {
		pair<int, pair<int, int> > top = min_pq.top();
		min_pq.pop();
		ans.push_back(top.first);
		int L = top.second.first;
		int R = top.second.second;

		if ( R > 0 && L >= 0  && S.find(make_pair(L, R - 1)) == S.end() ) {
			min_pq.push(make_pair(A[L] + B[R - 1], make_pair(L, R - 1)));
			S.insert(make_pair(L, R - 1));
		}
		if ( R >= 0  && L > 0 && S.find(make_pair(L - 1, R)) == S.end()) {
			min_pq.push(make_pair(A[L - 1] + B[R], make_pair(L - 1, R)));
			S.insert(make_pair(L - 1, R));
		}
	}
	return ans;
}


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	vector<int> ans;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	priority_queue <int, vector<int>, greater<int>> min_pq;
	int i = n - 1;
	for (int k = 0; k < n; k++) {
		min_pq.push(A[i] + B[k]);
	}
	i--;
	while (i >= 0) {
		int j = B.size() - 1;
		while (j >= 0) {
			int t = A[i] + B[j];
			if (t < min_pq.top())
				break;
			else {
				min_pq.pop();
				min_pq.push(t);
			}
			j--;
		}
		i--;
	}
	vector<int> result(n);
	for (int k = n - 1; k >= 0; k--) {
		result[k] = min_pq.top();
		min_pq.pop();
	}
	return result;
}


