/*
Topological sort is only possible in DAG

So try to implement topo sort using kahns here agr hai mtlb cycle hai varna cycle nhi hai.
*/


class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
		queue<int>q;

		vector<int>indegree(N, 0);

		for (int i = 0; i < N; i++)
		{
			for (auto ch : adj[i])
			{
				indegree[ch]++;
			}
		}


		for (int i = 0; i < N; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}


		// vector<int>topo;
		int cnt = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			// topo.push_back(node);
			cnt++;
			for (auto ch : adj[node])
			{
				indegree[ch]--;
				if (indegree[ch] == 0)
				{
					q.push(ch);
				}
			}
		}
		// return topo;
		if (cnt == N)
			return false;
		return true;
	}
};

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.isCyclic(V, adj) << "\n";
	}

	return 0;
}

