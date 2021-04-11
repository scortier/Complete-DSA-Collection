class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& a) {
		int longestPath = 1;

		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[0].size(); j++)
			{
				longestPath = max(longestPath, solve(matrix, vis, i, j, -1));
			}
		}
		return cnt;
	}


	int solve(vector<vector<int>>& mat, vector<vector<bool> > &vis, int i, int j) {
		int max = 1;

		for (int k = 0; k < 4; k++)
		{
			int new_i = i + moves[k][0], new_j = j + moves[k][1];

			if (new_i<0 or new_j<0  or new_i >= size(m)or new_j >= size(m[0]))
			}


	}
};