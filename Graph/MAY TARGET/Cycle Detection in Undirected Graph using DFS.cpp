#include<bits/stdc++.h>
using namespace std;

// 1- based indexing code


class Solution {

private:
	//Checking cycle using DFS
	bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
		vis[node] = 1;

		for (auto ch : adj[node])
		{
			if (vis[ch] == 0)//(!vis[ch])
			{
				// this cycle will go deeper n deeper and some node insied if return true tab toh baat ban gyi na
				if (checkForCycle(ch, node, vis, adj))
					return true;
			}
			else if (ch != parent)
				return true;
		}
		return false;
	}

public:
	bool isCycle(int V, vector<int>adj[])
	{
		//make a visited array initialized with 0
		vector<int>vis(V + 1, 0);

		//iterating over each vertex
		for (int i = 1; i <= V; i++)
		{
			if (!vis[i])
				if (checkForCycle(i, -1, vis, adj))
					return true;
		}
		return false;
	}

};



// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends