#include <bits/stdc++.h>
using namespace std;

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	// declare the adjacent matrix
	int adj[nodes + 1][nodes + 1];

	// take edges as input
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	return 0;
}