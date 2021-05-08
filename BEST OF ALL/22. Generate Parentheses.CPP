//recursive method
/*
l to (
r to )
if l<n then add ( , if r<l then add )
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>result;
		string curr_string = "";
		generate(n, 0, 0, curr_string, result);
		return result;
	}
private:
	void generate(int maxm, int open, int close, string curr_string, vector<string>&result)
	{
		//ending condn check , base condn
		//n=3 final string size will be 6
		if (open == maxm and maxm == r)// or curr_string.size()==maxm*2
			result.push_back(curr_string);

		//descision making statement
		if (open < maxm)
		{
			generate(maxm, open + 1, close, curr_string + '(', result);
		}
		if (close < open)
		{
			generate(maxm, open + 1, close, curr_string + ')', result);
		}
	}


};


//Iterative
//O(n^3)
/*
Intuition

We can generate all 2^(2n) sequences of '(' and ')' characters. Then, we will check if each one is valid.
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n != 0) return "";
		vector<string>result;
		for (int i = 0; i < n; i++)
		{
			for (auto l : generateParenthesis(i))
			{
				for (auto r : generateParenthesis(n - 1 - i)) {
					result.push_back('(' + l + ')' + r);
				}
			}
		}
		return result;
	}
};

//DP
/*
dp[0]=""
dp[i]='('+dp[k]+')'+dp[i-1-k],k=0...i-1
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>>dp(n + 1, vector<string>());
		dp[0].push_back("");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				for (auto s1 : dp[j])
				{	for (auto s2 : dp[i - 1 - k])
						dp[i].push_back("(" + s1 + ")" + s2);
				}
			}
		}
		return dp[n];
	}
};
