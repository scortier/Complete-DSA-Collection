#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n, m, source;
	cin >> n >> m >> source;

//n->nodes
	vector<pair<int, int>> g[n + 1];	// 1-indexed adjacency list for of graph (node,weight)

	int a, b, wt;

//undirected graph
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b, wt));
		g[b].push_back(make_pair(a, wt));

	}

	cin >> source;

	//Dijkstra Algo starrt from here
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // (dist,node)min heap (store smallest on top)
	vector<pair<int, int>> distTo(n + 1, INT_MAX);// 1-indexed array for calculating shortest paths;

	distTo[src] = 0;
	pq.push(0, src);


	while ( !pq.empty() )
	{
		int dist = pq.top().first;	//dist is also equal to distTo[prev_node]
		int prev_node = pq.top().second;

		pq.pop();
		// vector<pair<int, int>>::iterator it;
		for (auto x : g[prev_node])
		{
			int neighbor = x.first;
			int next_dist = x.second;

			if (distTo[neighbor] > dist + next_dist )
			{	distTo[neighbor] = dist + next_dist;
				pq.push(make_pair(distTo[neighbor], neighbor));
			}

		}
	}

	cout << "The distances from source, " << source << ", are : \n";
	for (int i = 1 ; i <= n ; i++)	cout << distTo[i] << " ";
	cout << "\n";

	return 0;
}