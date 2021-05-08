class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        unordered_map<int, int>mp;
        int right = 0, left = 0, res = INT_MIN;
        for (int right = 0; right < n; right++)
        {
            mp[tree[right]]++;
            //to reduce the window size based on constraint and 2 bucket hai
            while (left<n and mp.size()>2)
            {
                mp[tree[left]]--;

                if (mp[tree[left]] == 0)
                    mp.erase(tree[left]);
                left++;
            }
            //max val of window storing
            res = max(res, right - left + 1);
        }
        return res == INT_MIN ? (mp.size() > 0  ? n : 0) : res;
    }
};