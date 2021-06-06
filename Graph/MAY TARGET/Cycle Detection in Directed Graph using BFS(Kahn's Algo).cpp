/*
Topological sort is only possible in DAG

So try to implement topo sort using kahns here agr hai mtlb cycle hai varna cycle nhi hai.
*/


class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
		queue<int>q;

		//1-based indexing and initialize with 0
		vector<int>indegree(V + 1, 0);

		for (int i = 1; i <= V; i++)
		{
			for (auto ch : adj[i])
			{
				indegree[ch]++;
			}
		}


		for (int i = 0; i < V; i++)
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
		if (cnt == V)
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

