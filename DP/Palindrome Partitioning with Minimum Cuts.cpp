class Solution {
public:
	vector<vector<string>> partition(string s) {
		int n = s.size();
		int dp[n][n];
//gap method
		for (int g = 0; g < n; g++) {
			for (int i = 0, j = g; g < dp.size(); i++, j++)
			{
				if (g == 0) {
					dp[i][j] = true;
				}
				else if (g == 1) {
					dp[i][j] = s[i] == s[j];
				}
				else {
					//bich wala part
					if (s[i] == s[j] and dp[i + 1][j - 1] == true)
						dp[i][j] = true;
					else
						dp[i][j] = false;
				}
			}
		}

		int store[n][n];
		for (int g = 0; g < n; g++) {
			for (int i = 0, j = g; g < store.size(); i++, j++)
			{
				if (g == 0) {
					store[i][j] = 0;
				}
				else if (g == 1) {
					if (s[i] == s[j])
						store[i][j] = 0;
					else
						store[i][j] = 1; //char baraber ni toh ek cut.
				}
				else {
					if (dp[i][j]) {
						store[i][j] = 0;
					}
					else {
						int mn = INT_MAX;
						for (int k = i; k < j; k++)
						{
							int left = store[i][k];
							int right = store[k + 1][j];

							if (left + right + 1 < mn) {
								mn = left + right + 1;
							}
						}
						store[i][j] = mn;
					}
				}
			}
		}
		return store[0][s.size() - 1];

	}
};