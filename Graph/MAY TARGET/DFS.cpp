/*Approach -  depth first search
pehle dfs kisi node par hua toh usko
1. visited mark kardo
2. ab check karo kya uske adj nodes visotes hue hai agr nhi hue to unpe dfs lagao
just like backtracking -  recursive tree banao aur aage badte jao

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
	//dfs utility func
	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {

		storeDfs.push_back(node);

		//mark node as visited
		vis[node] = 1;

		//go to every adj list
		for (auto child : adj[node])
		{
			if (!vis[child])
			{
				dfs(child, vis, adj, storeDfs);
			}
		}
	}

public:
	vector<int> dfsOfGraph(int V, vector<int>adj[])
	{
		vector<int>storeDfs;
		vector<int>vis(V + 1, 0);

		//this is for multiple comp
		for (int i = 1; i <= V; i++)
		{
			if (!vis[i])
			{
				dfs(i, vis, adj, storeDfs);
			}
		}
		return storeDfs;
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int>ans = obj.dfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends