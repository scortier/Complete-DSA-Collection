class Solution {
private :
    struct Comp
    {
        bool operator()(pair<char, int> &a, pair<char, int> &b)
        {
            return a.second < b.second;
        }
    };
public:
    string reorganizeString(string S)
    {
        map<char, int> mp;
        for (auto it : S)
        {
            mp[it]++;
        }
        priority_queue<pair<char, int> , vector<pair<char, int>>, Comp> pq;
        for (auto it : mp)
        {
            pq.push({it.first, it.second});
        }

        string res = "";
        pair<char, int> top1, top2;
        while (pq.size() >= 2)
        {
            top1 = pq.top(); pq.pop();
            top2 = pq.top(); pq.pop();
            res += top1.first;
            res += top2.first;
            top1.second--;
            top2.second--;
            if (top1.second > 0)
                pq.push({top1.first, top1.second});
            if (top2.second > 0)
                pq.push({top2.first, top2.second});
        }
        if (!pq.empty())
        {
            auto last = pq.top(); pq.pop();
            res += last.first;
        }

        return res.size() == S.size() ? res : "";
    }


};