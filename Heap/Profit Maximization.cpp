
//TC :O(nlogn)
int Solution::solve(vector &A, int B) {
    int sum = 0, i = A.size() - 1;
    while (B–)
    {
        sort(A.begin(), A.end());
        sum += A[i];
        A[i] = A[i] - 1;
    }
    return sum;
}


//TC : O(n logk)
/*
You can use a heap or a priority_queue to maintain the number of seats left in each of the
rows. Then you can for each person to be served, pop the item
and add this to the cost and update the number of seats left in this row.
All the persons can be sold a seat ticket until there are vacant seats.
*/
int Solution::solve(vector<int> &a, int b) {
    priority_queue<int>pq;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)pq.push(a[i]);
    for (int i = 0; i < b; i++) {
        int a = pq.top();
        pq.pop();
        ans += a;
        pq.push(a - 1);

    }
    return ans;
}
