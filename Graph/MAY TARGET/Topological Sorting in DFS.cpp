/*
Approach :
- Stack ka use karenge
https://www.youtube.com/watch?v=6Vi5Td_a8B8&t=168s


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {

		//mark the node as visited here
		vis[node] = 1;

		//now look for its adj nodes whether they have vis or not ,if not then daalo stack m mark visit karwao.
		for (auto ch : adj[node])
		{
			if (!vis[ch])
			{
				findTopoSort(ch, vis, st, adj);
			}
		}

		//pushing it to stack for obtaining final topo sort
		st.push(node);
	}

public:
	vector<int> topoSort(int N, vector<int> adj[]) {
		stack<int>st;
		vector<int>vis(N, 0);

		for (int i = 0; i < N; i++)
		{
			if (!vis[i])
			{
				findTopoSort(i, vis, st, adj);
			}
		}

		// to get the output
		vector<int>topo;
		while (!st.empty())
		{
			topo.push_back(st.top());
			st.pop();
		}
		return topo;
	}
};


// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
	vector<int> map(V, -1);
	for (int i = 0; i < V; i++) {
		map[res[i]] = i;
	}
	for (int i = 0; i < V; i++) {
		for (int v : adj[i]) {
			if (map[i] > map[v]) return 0;
		}
	}
	return 1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, E;
		cin >> E >> N;
		int u, v;

		vector<int> adj[N];

		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector <int> res = obj.topoSort(N, adj);

		cout << check(N, res, adj) << endl;
	}

	return 0;
}  // } Driver Code Ends