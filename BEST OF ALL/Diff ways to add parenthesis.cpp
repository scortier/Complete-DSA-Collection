class Solution {
public:
    vector<int> diffWaysToCompute(string expn) {
        int n = expn.size();
        vector<int>ans;
        for (int i = 0; i < n; i++)
        {
            char curr = expn[i];
            if (curr == '+' or curr == '-' or curr == '*')
            {
                vector<int>r1 = diffWaysToCompute(expn.substr(0, i));
                vector<int>r2 = diffWaysToCompute(expn.substr(i + 1));
                for (auto n1 : r1)
                {
                    for (auto n2 : r2)
                    {
                        if (curr == '+')
                            ans.push_back(n1 + n2);
                        else if (curr == '-')
                            ans.push_back(n1 - n2);
                        else
                            ans.push_back(n1 * n2);
                    }
                }
            }
        }

        //if expression only contain number
        if (ans.empty())
            ans.push_back(atoi(expn.c_str()));
        return ans;
    }
};

//Above soln contain repeating subsequence ,so lets do it with dp

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }

    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = computeWithDP(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = computeWithDP(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
    }
};