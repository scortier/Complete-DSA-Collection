/*
APPROACH :
Solved using DFS
strongly connected Graph -  which has only one single comp

no of dfs call take place =  no of island


A cell in 2D matrix can be connected to 8 neighbours. So, unlike standard DFS(), where we recursively call for all adjacent vertices, here we can recursively call for 8 neighbours only. We keep track of the visited 1s so that they are not visited again.



Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5

We can componsate the visited array by allocating the mat[][] as 2
*/

class Solution {
public:
	void DFS(vector<vector<char>>& mat, int i, int j) {
		// boundary checking
		if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
			return;
		// return if current position is of water or is already visited
		if (mat[i][j] == '2' || mat[i][j] == '0')
			return;

		// mark the current as visited
		mat[i][j] = '2';

		// do DFS in all 4 directions
		DFS(mat, i + 1, j);
		DFS(mat, i, j - 1);
		DFS(mat, i - 1, j);
		DFS(mat, i, j + 1);
	}

	int numIslands(vector<vector<char>>& mat) {
		// We can treat the matrix mat as a mat. Each Island is a
		// connected component. The task is to find no. of disconnectedd components
		// in the graph.

		int islands = 0;
		int r = mat.size(), c = mat[0].size();
		// We make each 1 as 2 in when it is visited
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				// do DFS in case has not been visited and there is land
				if (mat[i][j] == '1') {
					DFS(mat, i, j);
					++islands;
				}
			}
		}
		return islands;
	}
};

