/*
Approach :
1.bfs traversal m root node(start node) se dist=1 wale simultaneously ssaare visit honge fir dist=2 then so on
2. ab agr traversal karte karte pata chale ki koi adj node pehle se visted bas baat khtm mtlb cycle hai.
*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {

public:
	bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
	{
		//saare node ko -1 se initialize
		vector<int>parent(V, -1);

		//create a queue for bfs in pair of (node,parent of the node)
		queue<pair<int, int>>q;

		//node ko vis mark karo
		visited[s] = true;
		//q m puh karo with parent koi nhi as parent ka parent nhi hai
		q.push(s, -1);

		//jab tk q bhari hai trvaersal karte rho
		while (!q.empty())
		{

			int node = q.front().first;
			int par = q.front().second;
			q.pop();

			//dekho agr node k adj node vis hai ya nhi
			for (auto child : adj[node])
			{
				//agr vis nhi hai toh vis karao aur q m bhi push kar do
				if (!visited[child])
				{	visited[child] = 1;
					q.push({child, node});
				}
				//agr vis hai and par!=chils toh badiya hai badhai ho
				else if (par != child)
					return true;
			}
		}
		return false;
	}
public:
	bool isCycle(int V, vector<int>adj[])
	{
		//make visited array and initialize all weit 0
		vector<int>vis(V, 0);

		//trevaerse trought each vertex one by one
		for (int i = 0; i < V; i++)
		{
			//agr node vis nhi hai toh visite karao aur uske adj node ko bhi vis karao
			if (!vis[i])
				//aur agr adj node pehle viss nikla mtlb cycle hai
				if (checkForCycle(i, V, adj, vis))
					return true;
		}
	}//sab vi karliye par koi bhi adj node vis nhi mila hence cycle nhi hai
	return false;
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
