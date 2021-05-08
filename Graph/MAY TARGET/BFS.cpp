/*
Approach - Breadth first earch
0 node se uske adj jo bhi honge pehle vo visite honge jese pehle dst=1 wale pehle visite honge saare then dist=2 wale
*/
class Solution {
public:
	vector<int>bfs(int V, vector<int>adj[])
	{
		vector<int>bfs;
		//to mark visited nodes
		vector<int>vis(V, 0);

		// for processing
		queue<int>q;

		//jaha se start kar rhee uuse q m insert kardo and mark as visited
		q.push(0);
		vis[0] = 1;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			bfs.push_back(node);


			for (auto child : adj[node])
			{
				if (!vis[child])
				{
					q.push(child);
					vis[child] = 1;
				}
			}
		}
		return bfs;
	}
}


// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	// for multiple graphs
	while (tc--) {
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			// 		adj[v].push_back(u); // uncomment this for undirected graoh
		}
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int>ans = obj.bfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends