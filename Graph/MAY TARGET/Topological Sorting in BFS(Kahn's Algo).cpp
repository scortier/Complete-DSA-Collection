#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
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

		vector<int>topo;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			topo.push_back(node);

			for (auto ch : adj[node])
			{
				indegree[ch]--;
				if (indegree[ch] == 0)
				{
					q.push(ch);
				}
			}
		}
		return topo;


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
			adj[u].push_back(v); //as directed graph hai
		}

		Solution obj;
		cout << obj.topo(V, adj) << "\n";
	}

	return 0;
}