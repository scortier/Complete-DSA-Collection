//BFS SOLUTION
class Solution {
	int x[4] = { -1, 0, 1, 0};
	int y[4] = {0, 1, 0, -1};
public:

	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		queue < pair<int, int>q;
		if (m == 0) return {};
		//matrix for distance with initialization as -1.
		vector<vector<int>>dist(m, vector<int>(n, -1));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
			{	if (matrix[i][j] == 0) {
					q.push({i, j});
					dist[i][j] = 0;
				}
			}
		}

		while (!q.empty())
		{
			pair<int, int>pt = q.front();
			q.pop();
			for (int dirn = 0; dirn < 4; dirn++)
			{
				int xd = pt.first + x[dirn];
				int yd = pt.second + y[dirn];

				if (xd >= 0 and yd >= 0 and xd <= m - 1 and yd <= n - 1 and matrix[xd][yd] == 1 and dist[xd][yd] == -1)
				{
					dist[xd][yd] = dist[pt.first][pt.second] + 1;
					q.push({xd, yd});
				}
			}
		}
		return dist;
	}
};

//DFS SOLUTION

class Solution {
	const int MAX_MATRIX_SIZE = 10000; // as in problem statement
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
	{
		for (int r = 0; r < matrix.size(); ++r)
			for (int c = 0; c < matrix[0].size(); ++c)
				if (matrix[r][c] == 1) matrix[r][c] = MAX_MATRIX_SIZE;

		for (int r = 0; r < matrix.size(); ++r)
			for (int c = 0; c < matrix[0].size(); ++c)
				get_distance(r, c, matrix);
		return matrix;
	}
protected:
	int get_distance(int r, int c,  vector<vector<int>>& matrix)
	{
		if (r >= matrix.size() || r < 0 || c >= matrix[0].size() || c < 0 || matrix[r][c] == -2) return MAX_MATRIX_SIZE;

		if (matrix[r][c] == 0 || matrix[r][c] == 1) return matrix[r][c]; // 1 is min distance - no need to compute further

		int dist =  matrix[r][c];
		matrix[r][c] = -2; // -2 = do not go here again.

		dist = min(dist, get_distance(r + 1, c, matrix) + 1);//DOWN
		dist = min(dist, get_distance(r - 1, c, matrix) + 1);//UP
		dist = min(dist, get_distance(r, c + 1, matrix) + 1);//RIGHT
		dist = min(dist, get_distance(r, c - 1, matrix) + 1);//LEFT

		matrix[r][c] = dist;
		return dist;
	}
};