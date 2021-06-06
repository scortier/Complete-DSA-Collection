class Solution:
{
	bool util_bipartiteDFS(int src, vector<int> adj[], int color[])
	{
		color[src] = 1;

		for (auto ch : adj[src])
		{
			if (color[ch] == -1) {
				color[ch] = 1 - color[src];
				if (util_bipartiteDFS(ch, adj, color) == false)
					return false;
			}
			else if (color[ch] == color[src])
				return false;
		}
		return true;
	}

public:
	bool checkBipartite(vector<int> adj[], int V)
	{
		vector<int>color(V + 1, -1);

		for (int i = 1; i <= V; i++)
		{
			if (color[i] == -1)
			{
				if (util_bipartiteDFS(i, adj, color) == false)
					return false;
			}
		}
		return true;

	}
};



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