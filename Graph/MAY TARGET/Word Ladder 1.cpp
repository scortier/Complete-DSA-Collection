/*
TC: O( BeginWordLeng * 26 * EndWordLength *W )
n -> length of string
W -> total no of words that can be pr in singe level of bfs call
for each letter of word doing 26 transformation and checking each transformation with end word
*/

int Solution::solve(string begin, string end, vector<string> &dict) {
    int n = dict.size();
    unordered_set<string>st;
    for (int i = 0; i < n; i++)
        st.insert(dict[i]);

    if (begin == end) return 0;

    if (st.find(end) == st.end()) return 0;

    queue<string>q;
    q.push(begin);
    int depth = 0;
    while (!q.empty())
    {
        depth++;
        int tot_nodes = q.size();

        while (tot_nodes--)
        {
            string curr = q.front();
            q.pop();

            //check for all possible 1 depth word
            for (int i = 0; i < curr.size(); i++)
            {
                string temp = curr;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch;

                    if (curr.compare(temp) == 0)
                        continue;

                    if (temp.compare(end) == 0)
                        return depth + 1;

                    if (st.find(temp) != st.end())
                    {
                        q.push(temp);
                        st.erase(temp);
                    }
                }
            }
        }



    }

    return 0;

}

//optimised ones
class Solution {
public:
    int ladderLength(string beginW, string endW, vector<string>& dict) {
        int n = dict.size();
        unordered_set<string>st;
        for (int i = 0; i < n; i++)
            st.insert(dict[i]);

        if (beginW == endW) return 0;

        if (st.find(endW) == st.end()) return 0;

        queue<pair<string, int>>q;
        q.push(make_pair(beginW, 1));
        while (!q.empty())
        {
            auto node = q.front(); //it is form of pair
            string curr_string = node.first;
            int duri = node.second;
            q.pop();

            if (curr_string == endW)
                return duri;
            for (int i = 0; i < curr_string.size(); i++)
            {
                string tmp = curr_string;

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    // char x=tmp[i];
                    tmp[i] = ch;
                    if (st.find(tmp) != st.end())
                    {
                        q.push({tmp, node.second + 1});
                        st.erase(tmp);
                    }
                    // tmp[i]=x; isse jo ele erase hua vhi firse jud jaa rha so no use
                }
            }
        }

        return 0;
    }
};


//map for more optimise