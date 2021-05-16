#include <bits/stdc++.h>
using namespace std;

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	// declare the adjacent matrix
	//vector at every index
	//at every index we can store a vector
	vector<int> adj[nodes + 1];

	// take edges as input
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}