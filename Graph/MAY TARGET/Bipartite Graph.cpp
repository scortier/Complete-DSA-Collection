/*
Approach :
that can be colored using 2 colors such that no 2 adjacent nodes have same color.
- any odd length cannot be a bipartite graph
- a graph which doesn't have odd length cycle its bipartite graph
*/
//there will be two color - 0 and 1
#include <bits/stdc++.h>
using namespace std;

bool util_bipartiteBfs(int src, vector<int> adj[], int color[]) {
	queue<int>q;
	q.push(src);

	//intialize with color =1;
	color[src] = 1;


	while (!q.empty())
	{
		int node = q.front;
		q.pop();

		for (auto c : adj[node])
		{
			if (color[ch] == -1)
			{
				color[ch] = 1 - color[node];
				q.push(ch);
			}
			else if (color[ch] == color[node])
				return false;
		}
	}
	return true;
}




bool checkBipartite(vector<int> adj[], int n) {

	vector<int>color; (n, -1)
	for (int i = 0; i < n; i++)
	{
		if (color[i] == -1)
			if (!util_bipartiteBfs(i, adj, color))
				return false;
	}
	return true;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (checkBipartite(adj, n)) {
		cout << "yes";
	} else {
		cout << "No";
	}
	return 0;
}

/*
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

// bipartite graph example
*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
// not bipartite example
*/

