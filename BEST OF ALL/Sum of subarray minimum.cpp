class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        int MOD = 1e7;
        stack<int>s1, s2;
        vector<int>prev_smaller(n), next_smaller(n);
        //initialisation for the base case
        for (int i = 0; i < n; i++)
        {
            next_smaller[i] = n - i - 1;
            prev_smaller[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            while (!s1.empty() and a[i] < a[s1.top()])
            {
                next_smaller[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }

            s1.push(i);

        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (s2.empty() and a[i] < a[s2.top()])
            {
                prev_smaller[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }

        long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (a[i] * (prev_smaller[i] + 1) * (next_smaller[i] + 1));
            ans %= MOD;
        }
        return ans;
    }
};