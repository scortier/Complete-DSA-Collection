#define MOD 1000000007;
int Solution::nchoc(int a, vector<int> &b) {
    int n = b.size();
    priority_queue<int>pq;
    for (long long int i = 0; i < n; i++)
        pq.push(b[i]);
    long long int sum = 0;
    while (a--)
    {
        long long int x = pq.top();
        pq.pop();
        pq.push(floor(x / 2));
        sum += x;
    }
    sum = sum % MOD;
    return sum;
}